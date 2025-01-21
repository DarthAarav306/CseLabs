import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

interface HospitalOperations {
    void registerPatient(Patient patient) throws Exception;

    void assignDoctor(Patient patient) throws Exception;

    void addDoctor(Doctor doctor) throws Exception;

    void generateReport(); // For monitoring and reporting
}

class Person<T> {
    public String name;
    public int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

class Patient extends Person<String> {
    public String disease;
    public String status;
    public String personalizedUpdate;

    public Patient(String name, int age, String disease) {
        super(name, age);
        this.disease = disease;
        this.status = "admitted"; // default status
    }

    public void dischargePatient() {
        this.status = "discharged";
    }

    public void setPersonalizedUpdate(String update) {
        this.personalizedUpdate = update;
    }

    @Override
    public String toString() {
        return "Patient: " + name + ", Age: " + age + ", Disease: " + disease + ", Status: " + status + ", Update: "
                + personalizedUpdate;
    }
}

class Doctor extends Person<String> {
    public String specialization;
    public boolean isAvailable;

    public Doctor(String name, int age, String specialization) {
        super(name, age);
        this.specialization = specialization;
        this.isAvailable = true; // doctors are available by default
    }

    public void changeAvailability() {
        this.isAvailable = !this.isAvailable;
    }

    @Override
    public String toString() {
        return "Doctor: " + name + ", Specialization: " + specialization + ", Available: " + isAvailable;
    }
}

class Hospital implements HospitalOperations {
    private static final int MAX_PATIENTS = 10;
    private static final int MAX_DOCTORS = 5;
    private static final int MAX_BEDS = 5; // For bed facility
    private static final int MAX_EMERGENCIES = 5;

    private Patient[] patients = new Patient[MAX_PATIENTS];
    private Doctor[] doctors = new Doctor[MAX_DOCTORS];
    private int patientCount = 0;
    private int doctorCount = 0;
    private int bedCount = MAX_BEDS;
    private String[] emergencyCases = new String[MAX_EMERGENCIES];
    private int emergencyCount = 0;

    @Override
    public synchronized void registerPatient(Patient patient) throws Exception {
        if (patient.age <= 0) {
            throw new Exception("Invalid age. Age must be positive.");
        }
        if (patientCount < MAX_PATIENTS) {
            patients[patientCount++] = patient;
            patient.setPersonalizedUpdate("Welcome to the hospital. Updates on doctors and schemes will follow.");
            System.out.println("Patient " + patient.name + " registered successfully.");
        } else {
            throw new Exception("Patient registration full.");
        }
    }

    @Override
    public void assignDoctor(Patient patient) throws Exception {
        // Start a new thread for assigning the doctor
        new Thread(() -> {
            synchronized (this) {
                try {
                    boolean doctorAssigned = false;
                    for (int i = 0; i < doctorCount; i++) {
                        if (doctors[i].isAvailable && doctors[i].specialization.equalsIgnoreCase(patient.disease)) {
                            // Doctor found and assigned
                            System.out.println("Doctor " + doctors[i].name + " (Specialization: "
                                    + doctors[i].specialization + ") assigned to patient " + patient.name);
                            doctors[i].changeAvailability();
                            doctorAssigned = true;
                            break;
                        }
                    }

                    if (!doctorAssigned) {
                        // No doctor available
                        System.out.println("No available doctor for the disease: " + patient.disease);
                    }
                } catch (Exception e) {
                    System.out.println("Error assigning doctor: " + e.getMessage());
                }
            }
        }).start(); // Start the thread and let it run without blocking the UI
    }

    @Override
    public synchronized void addDoctor(Doctor doctor) throws Exception {
        if (doctor.age <= 0) {
            throw new Exception("Invalid age. Age must be positive.");
        }
        if (doctorCount < MAX_DOCTORS) {
            doctors[doctorCount++] = doctor;
            System.out.println("Doctor " + doctor.name + " added successfully.");
            notify(); // Notify that a new doctor is available
        } else {
            throw new Exception("Doctor list full.");
        }
    }

    public void updateRealTimeData() {
        Thread realTimeUpdater = new Thread(() -> {
            try {
                while (true) {
                    Thread.sleep(5000); // Update real-time data every 5 seconds
                    System.out.println("Updating real-time data for treatments, bed facility, and remote exercises...");
                    System.out.println("Available beds: " + bedCount);
                }
            } catch (InterruptedException e) {
                System.out.println("Error in real-time data update.");
            }
        });
        realTimeUpdater.start();
    }

    public void handleEmergency(String emergency) {
        if (emergencyCount < MAX_EMERGENCIES) {
            emergencyCases[emergencyCount++] = emergency;
            System.out.println("Emergency case logged: " + emergency);
        } else {
            System.out.println("Emergency capacity full.");
        }
    }

    @Override
    public void generateReport() {
        System.out.println("---- Hospital Report ----");
        System.out.println("Number of Patients: " + patientCount);
        System.out.println("Number of Doctors: " + doctorCount);
        System.out.println("Available Beds: " + bedCount);
        System.out.println("Emergency Cases:");
        for (int i = 0; i < emergencyCount; i++) {
            System.out.println("Emergency " + (i + 1) + ": " + emergencyCases[i]);
        }
    }
}

public class App extends Application {
    Hospital hospital = new Hospital();

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Hospital Management System");

        // Create UI elements
        Label nameLabel = new Label("Name:");
        TextField nameInput = new TextField();

        Label ageLabel = new Label("Age:");
        TextField ageInput = new TextField();

        Label specializationOrDiseaseLabel = new Label("Specialization/Disease:");
        TextField specializationOrDiseaseInput = new TextField();

        Button addPatientButton = new Button("Register Patient");
        Button addDoctorButton = new Button("Add Doctor");
        Button reportButton = new Button("Generate Report");

        // GridPane layout
        GridPane gridPane = new GridPane();
        gridPane.setPadding(new Insets(10, 10, 10, 10));
        gridPane.setVgap(8);
        gridPane.setHgap(10);

        // Add components to gridPane
        gridPane.add(nameLabel, 0, 0);
        gridPane.add(nameInput, 1, 0);
        gridPane.add(ageLabel, 0, 1);
        gridPane.add(ageInput, 1, 1);
        gridPane.add(specializationOrDiseaseLabel, 0, 2);
        gridPane.add(specializationOrDiseaseInput, 1, 2);
        gridPane.add(addPatientButton, 1, 3);
        gridPane.add(addDoctorButton, 1, 4);
        gridPane.add(reportButton, 1, 5);

        addPatientButton.setOnAction(e -> {
            try {
                String name = nameInput.getText();
                int age = Integer.parseInt(ageInput.getText());
                String disease = specializationOrDiseaseInput.getText();
                Patient patient = new Patient(name, age, disease);
                hospital.registerPatient(patient);
                hospital.assignDoctor(patient);
            } catch (Exception ex) {
                showAlert("Error", ex.getMessage());
            }
        });

        addDoctorButton.setOnAction(e -> {
            try {
                String name = nameInput.getText();
                int age = Integer.parseInt(ageInput.getText());
                String specialization = specializationOrDiseaseInput.getText();
                Doctor doctor = new Doctor(name, age, specialization);
                hospital.addDoctor(doctor);
            } catch (Exception ex) {
                showAlert("Error", ex.getMessage());
            }
        });

        reportButton.setOnAction(e -> hospital.generateReport());

        Scene scene = new Scene(gridPane, 400, 300);
        primaryStage.setScene(scene);
        primaryStage.show();

        // Real-time updates and handling emergencies
        hospital.updateRealTimeData();
        hospital.handleEmergency("Road accident at Highway 45");
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
