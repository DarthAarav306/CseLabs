import java.util.Scanner;

class InvalidDayException extends Exception {
    public InvalidDayException(String message) {
        super(message);
    }
}

class InvalidMonthException extends Exception {
    public InvalidMonthException(String message) {
        super(message);
    }
}

class CurrentDate {
    private int day, month, year;

    public void createDate() throws InvalidDayException, InvalidMonthException {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter day: ");
        day = scanner.nextInt();
        System.out.println("Enter month: ");
        month = scanner.nextInt();
        System.out.println("Enter year: ");
        year = scanner.nextInt();

        if (month < 1 || month > 12) {
            throw new InvalidMonthException("Invalid Month: " + month);
        }

        if (day < 1 || day > daysInMonth(month, year)) {
            throw new InvalidDayException("Invalid Day: " + day);
        }
        System.out.println("Date is valid: " + this);
    }

    private int daysInMonth(int month, int year) {
        switch (month) {
            case 4: case 6: case 9: case 11: return 30; // April, June, September, November
            case 2: return (isLeapYear(year) ? 29 : 28); // February with leap year check
            default: return 31; // All other months
        }
    }

    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Overriding toString to display the date in day/month/year format
    public String toString() {
        return day + "/" + month + "/" + year;
    }
}

public class DateDemo {
    public static void main(String[] args) {
        CurrentDate currentDate = new CurrentDate();
        try {
            currentDate.createDate(); 
        } catch (InvalidDayException | InvalidMonthException exc) {
            System.out.println(exc);  // This will print exception class and message
        }
    }
}


