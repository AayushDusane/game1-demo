#include <stdio.h>

#define MAX_PATIENTS 5
#define MAX_APPOINTMENTS 5

// Structure to store patient information
struct Patient {
    int id;
    char name[100];
    int age;
};

// Structure to store appointment information
struct Appointment {
    int patientId;
    char date[20];   // Date format can be "DD/MM/YYYY"
    char doctor[100];  // Doctor's name
};

// Function to add a new patient
void addPatient(struct Patient patients[], int *patientCount) {
    if (*patientCount >= MAX_PATIENTS) {
        printf("Hospital is full. Cannot add more patients.\n");
        return;
    }

    printf("Enter patient ID: ");
    scanf("%d", &patients[*patientCount].id);
    printf("Enter patient name: ");
    scanf("%s", patients[*patientCount].name);
    printf("Enter patient age: ");
    scanf("%d", &patients[*patientCount].age);

    (*patientCount)++;
    printf("Patient added successfully.\n");
}

// Function to display all patients
void displayPatients(struct Patient patients[], int patientCount) {
    if (patientCount == 0) {
        printf("No patients in the hospital.\n");
        return;
    }

    printf("\nList of Patients:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", patients[i].id, patients[i].name, patients[i].age);
    }
}

// Function to book an appointment
void bookAppointment(struct Appointment appointments[], struct Patient patients[], int *appointmentCount, int patientCount) {
    if (*appointmentCount >= MAX_APPOINTMENTS) {
        printf("No more appointments can be booked.\n");
        return;
    }

    int patientId;
    printf("Enter patient ID to book an appointment: ");
    scanf("%d", &patientId);

    int patientExists = 0;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == patientId) {
            patientExists = 1;
            break;
        }
    }

    if (!patientExists) {
        printf("Patient with ID %d does not exist.\n", patientId);
        return;
    }

    printf("Enter appointment date (DD/MM/YYYY): ");
    scanf("%s", appointments[*appointmentCount].date);
    printf("Enter doctor's name: ");
    scanf("%s", appointments[*appointmentCount].doctor);

    appointments[*appointmentCount].patientId = patientId;
    (*appointmentCount)++;

    printf("Appointment booked successfully.\n");
}

// Function to display all appointments
void displayAppointments(struct Appointment appointments[], int appointmentCount) {
    if (appointmentCount == 0) {
        printf("No appointments booked.\n");
        return;
    }

    printf("\nList of Appointments:\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Patient ID: %d, Date: %s, Doctor: %s\n",
               appointments[i].patientId, appointments[i].date, appointments[i].doctor);
    }
}

int main() {
    struct Patient patients[MAX_PATIENTS];
    struct Appointment appointments[MAX_APPOINTMENTS];
    int patientCount = 0;
    int appointmentCount = 0;
    int choice;

    do {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add a New Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Book an Appointment\n");
        printf("4. Display All Appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                bookAppointment(appointments, patients, &appointmentCount, patientCount);
                break;
            case 4:
                displayAppointments(appointments, appointmentCount);
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
