import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.scene.control.*;
import javafx.geometry.Pos;
import javafx.geometry.Insets;

public class HospitalManagementSystem extends Application {
    private PatientDatabase<Patient> patientDatabase = new PatientDatabase<>();
    private DoctorDatabase<Doctor> doctorDatabase = new DoctorDatabase<>();
    private int availableBeds = 20;  m
    private Label mainTitle;
    private GridPane actionPane;
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Hospital Management System");
        GridPane mainLayout = new GridPane();
        mainLayout.setVgap(10);
        mainLayout.setHgap(10);
        mainLayout.setAlignment(Pos.CENTER);
        mainLayout.setPadding(new Insets(15));
        mainTitle = new Label("Welcome to the Hospital Management System");
        GridPane.setConstraints(mainTitle, 0, 0, 2, 1);
        Button registerBtn = new Button("Register Patient");
        Button dischargeBtn = new Button("Discharge Patient");
        Button doctorAvailabilityBtn = new Button("Doctor Availability");
        Button realTimeDataBtn = new Button("Real-Time Data");
        Button communicationBtn = new Button("Patient-Doctor Communication");
        Button monitorBtn = new Button("Patient Monitoring and Reporting");

        registerBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                showPatientRegistration();
            }
        });

        dischargeBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                dischargePatient();
            }
        });

        doctorAvailabilityBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                showDoctorAvailability();
            }
        });

        realTimeDataBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                showRealTimeData();
            }
        });

        communicationBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                initiateCommunication();
            }
        });

        monitorBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                monitorPatients();
            }
        });
        GridPane.setConstraints(registerBtn, 0, 1);
        GridPane.setConstraints(dischargeBtn, 1, 1);
        GridPane.setConstraints(doctorAvailabilityBtn, 0, 2);
        GridPane.setConstraints(realTimeDataBtn, 1, 2);
        GridPane.setConstraints(communicationBtn, 0, 3);
        GridPane.setConstraints(monitorBtn, 1, 3);

        actionPane = new GridPane();
        actionPane.setVgap(10);
        actionPane.setHgap(10);
        GridPane.setConstraints(actionPane, 0, 4, 2, 1);

        mainLayout.getChildren().addAll(mainTitle, registerBtn, dischargeBtn, doctorAvailabilityBtn, realTimeDataBtn, communicationBtn, monitorBtn, actionPane);
        Scene mainScene = new Scene(mainLayout, 600, 500);
        primaryStage.setScene(mainScene);
        primaryStage.show();
    }

    private void showPatientRegistration() {
        actionPane.getChildren().clear();

        Label nameLabel = new Label("Enter Patient Name:");
        TextField nameField = new TextField();
        Label ageLabel = new Label("Enter Patient Age:");
        TextField ageField = new TextField();
        Label conditionsLabel = new Label("Enter Patient Conditions:");
        TextField conditionsField = new TextField();
        Button submitBtn = new Button("Register");

        submitBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                try {
                    String name = nameField.getText();
                    int age = Integer.parseInt(ageField.getText());
                    String conditions = conditionsField.getText();

                    Patient newPatient = new Patient(name, age, conditions);
                    patientDatabase.addPatient(newPatient);
                    availableBeds--;

                    Alert alert = new Alert(Alert.AlertType.INFORMATION, "Patient Registered Successfully!\n" +
                            "Beds remaining: " + availableBeds);
                    alert.show();
                } catch (NumberFormatException ex) {
                    Alert alert = new Alert(Alert.AlertType.ERROR, "Invalid age format. Please enter a number.");
                    alert.show();
                }
            }
        });

        actionPane.add(nameLabel, 0, 0);
        actionPane.add(nameField, 1, 0);
        actionPane.add(ageLabel, 0, 1);
        actionPane.add(ageField, 1, 1);
        actionPane.add(conditionsLabel, 0, 2);
        actionPane.add(conditionsField, 1, 2);
        actionPane.add(submitBtn, 1, 3);
    }

    private void dischargePatient() {
        actionPane.getChildren().clear();

        if (availableBeds < 20) {
            availableBeds++;
            Alert alert = new Alert(Alert.AlertType.INFORMATION, "A patient has been discharged.\nBeds remaining: " + availableBeds);
            alert.show();
        } else {
            Alert alert = new Alert(Alert.AlertType.WARNING, "No patients to discharge.");
            alert.show();
        }
    }

    private void showDoctorAvailability() {
        actionPane.getChildren().clear();

        Label title = new Label("Available Doctors:");
        ListView<String> doctorListView = new ListView<>();

        doctorDatabase.addDoctor(new Doctor("Dr. Smith", true));
        doctorDatabase.addDoctor(new Doctor("Dr. Jones", false));
        doctorDatabase.addDoctor(new Doctor("Dr. Emily", true));

        String[] doctors = doctorDatabase.getDoctorList();
        doctorListView.getItems().addAll(doctors);

        actionPane.add(title, 0, 0);
        actionPane.add(doctorListView, 0, 1, 2, 1);
    }

    private void showRealTimeData() {
        actionPane.getChildren().clear();
        Label treatmentsLabel = new Label("Treatments Available: Vaccination, Surgery, Therapy");
        Label bedsLabel = new Label("Bed Facility: " + availableBeds + " Beds Available");
        Label exercisesLabel = new Label("Remote Exercises: Breathing Exercises, Joint Mobility Exercises");
        actionPane.add(treatmentsLabel, 0, 0);
        actionPane.add(bedsLabel, 0, 1);
        actionPane.add(exercisesLabel, 0, 2);
    }

    private void initiateCommunication() {
        actionPane.getChildren().clear();
        Label patientLabel = new Label("Enter Patient Name:");
        TextField patientField = new TextField();
        Label doctorLabel = new Label("Enter Doctor Name:");
        TextField doctorField = new TextField();
        TextField messageArea = new TextField();
        messageArea.setPromptText("Enter Message Here...");
        Button sendBtn = new Button("Send Message");
        sendBtn.setOnAction(new javafx.event.EventHandler<javafx.event.ActionEvent>() {
            public void handle(javafx.event.ActionEvent event) {
                String patientName = patientField.getText();
                String doctorName = doctorField.getText();
                String message = messageArea.getText();
                CommunicationTask task = new CommunicationTask(patientName, doctorName, message);
                Thread thread = new Thread(task);
                thread.start();

                Alert alert = new Alert(Alert.AlertType.INFORMATION, "Message Sent Successfully!\nDoctor response: We will assist you shortly.");
                alert.show();
            }
        });

        actionPane.add(patientLabel, 0, 0);
        actionPane.add(patientField, 1, 0);
        actionPane.add(doctorLabel, 0, 1);
        actionPane.add(doctorField, 1, 1);
        actionPane.add(messageArea, 0, 2, 2, 1);
        actionPane.add(sendBtn, 1, 3);
    }

    private void monitorPatients() {
        actionPane.getChildren().clear();

        Label monitorLabel = new Label("Monitoring Patients and Reporting Emergencies:");
        ListView<String> reportView = new ListView<>();

        String[] reports = patientDatabase.getPatientReport();
        for (String report : reports) {
            reportView.getItems().add(report);
        }
        reportView.getItems().add("Emergency: Road Accident - Immediate Assistance Required!");

        actionPane.add(monitorLabel, 0, 0);
        actionPane.add(reportView, 0, 1, 2, 1);
    }

    public static void main(String[] args) {
        launch(args);
    }
}
class DoctorDatabase<T> {
    private Doctor[] doctors = new Doctor[10];
    private int count = 0;

    public void addDoctor(Doctor doctor) {
        doctors[count++] = doctor;
    }

    public String[] getDoctorList() {
        String[] list = new String[count];
        for (int i = 0; i < count; i++) {
            list[i] = doctors[i].getName() + " - " + (doctors[i].isAvailable() ? "Available" : "Not Available");
        }
        return list;
    }
}

class Patient {
    private String name;
    private int age;
    private String conditions;

    public Patient(String name, int age, String conditions) {
        this.name = name;
        this.age = age;
        this.conditions = conditions;
    }

    public String getName() { return name; }
    public int getAge() { return age; }
    public String getConditions() { return conditions; }

    public void receiveUpdate(String update) {
        System.out.println("Update for " + name + ": " + update);
    }
}

class Doctor {
    private String name;
    private boolean isAvailable;

    public Doctor(String name, boolean isAvailable) {
        this.name = name;
        this.isAvailable = isAvailable;
    }

    public String getName() { return name; }
    public boolean isAvailable() { return isAvailable; }
}


class CommunicationTask implements Runnable {
    private String patientName;
    private String doctorName;
    private String message;

    public CommunicationTask(String patientName, String doctorName, String message) {
        this.patientName = patientName;
        this.doctorName = doctorName;
        this.message = message;
    }

    public void run() {
        System.out.println("Message from " + patientName + " to " + doctorName + ": " + message);
    }
}

class PatientDatabase<T> {
    private Patient[] patients = new Patient[100];
    private int count = 0;

    public void addPatient(Patient patient) {
        patients[count++] = patient;
    }

    public String[] getPatientReport() {
        String[] reports = new String[count];
        for (int i = 0; i < count; i++) {
            reports[i] = "Patient: " + patients[i].getName() + ", Conditions: " + patients[i].getConditions();
        }
        return reports;
    }
}
