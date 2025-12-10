#include <iostream>
#include <string>
#include <list>
using namespace std;


class ServiceRequest;
class GovernmentOfficial;

// ==================== DOCUMENTS CLASS ====================
class Documents {
public:
    int documentID;
    string documentName;
    string fileType;
    string uploadDate;
    string verificationStatus;

    bool uploadDocument() { cout << "uploadDocument done\n"; return true; }
    bool verifyDocument() { cout << "verifyDocument done\n"; return true; }
};

// ==================== PAYMENT CLASS ====================
class Payment {
public:
    string applicationID;
    int paymentID;
    double amount;
    string method;
    string transactionId;
    string paymentDate;
    string status;

    bool processPayment() { cout << "processPayment done\n"; return true; }
    bool confirmPayment() { cout << "confirmPayment done\n"; return true; }
    void generateReceipt() { cout << "generateReceipt done\n"; }
};

// ==================== NOTIFICATION CLASS ====================
class Notification {
public:
    int notificationID;
    string type;
    string message;
    string sendDate;

    bool sendNotification() { cout << "sendNotification done\n"; return true; }
    bool receiveNotification() { cout << "receiveNotification done\n"; return true; }
};

// ==================== REPORT CLASS ====================
class Report {
    
private:
    string generatedByAdminID;
    list<Report*> Administrator;
public:
    int reportID;
    string reportType;
    string generatedDate;

    bool generateReport() { cout << "generateReport done\n"; return true; }
    bool exportReport() { cout << "exportReport done\n"; return true; }
};

// ==================== CITIZEN CLASS ====================
class Citizen {
private:
    list<ServiceRequest*> serviceRequests;
    list<Notification*> notifications;
public:
    int citizenID;
    string fullName;
    string CNIC;
    string dateOfBirth;
    string email;
    string address;
    string password;

    bool registerCitizen() { cout << "registerCitizen done\n"; return true; }
    bool login() { cout << "login done\n"; return true; }
    bool updateProfile() { cout << "updateProfile done\n"; return true; }
    int applyForCNIC() { cout << "applyForCNIC done\n"; return 1; }
    int applyForPassport() { cout << "applyForPassport done\n"; return 1; }
    bool uploadDocuments() { cout << "uploadDocuments done\n"; return true; }
    int makePayment() { cout << "makePayment done\n"; return 12345; }
    void viewReceipt() { cout << "viewReceipt done\n"; }
    string trackApplication() { cout << "trackApplication done\n"; return "In Progress"; }
    list<Notification*> receiveNotifications() { 
        cout << "receiveNotifications done\n"; 
        return notifications; 
    }
};

// ==================== ADMINISTRATOR CLASS ====================
class Administrator {
private:
    list<Citizen*> allCitizens;
    list<GovernmentOfficial*> allOfficials;
    list<Report*> systemReports;
public:
    string adminID;
    string name;
    string email;
    string username;
    string password;

    bool manageCitizenAccounts() { cout << "manageCitizenAccounts done\n"; return true; }
    bool manageOfficialAccounts() { cout << "manageOfficialAccounts done\n"; return true; }
    bool assignRolesAndPermissions() { cout << "assignRolesAndPermissions done\n"; return true; }
    string monitorSystemPerformance() { 
        cout << "monitorSystemPerformance done\n"; 
        return "System OK"; 
    }
    list<Report*> generateReports() { 
        cout << "generateReports done\n"; 
        return systemReports; 
    }
    bool exportReports() { cout << "exportReports done\n"; return true; }
};

// ==================== SERVICE REQUEST CLASS ====================
class ServiceRequest {
public:
    string applicationID;
    int citizenID;
    string applicationType;
    string submissionDate;
    string status;
    string remarks;

    list<Documents> documents;
    Payment payment;

    int submitApplication() { cout << "submitApplication done\n"; return 1; }
    bool attachDocuments() { cout << "attachDocuments done\n"; return true; }
    bool updateStatus() { cout << "updateStatus done\n"; return true; }
    bool assignToOfficial() { cout << "assignToOfficial done\n"; return true; }
    bool processPayment() { cout << "processPayment done\n"; return true; }
    bool verifyAllDocuments() { cout << "verifyAllDocuments done\n"; return true; }
};

// ==================== GOVERNMENT OFFICIAL CLASS ====================
class GovernmentOfficial {
public:
    int officialID;
    string name;
    string role;
    string department;
    string username;
    string password;

    list<ServiceRequest*> assignedApplications;
    list<Documents*> processedDocuments;

    bool login() { cout << "login done\n"; return true; }
    list<ServiceRequest*> viewApplications() { 
        cout << "viewApplications done\n"; 
        return assignedApplications; 
    }
    bool verifyDocuments() { cout << "verifyDocuments done\n"; return true; }
    bool approveApplication() { cout << "approveApplication done\n"; return true; }
    bool rejectApplication() { cout << "rejectApplication done\n"; return true; }
    bool requestAdditionalDocuments() { cout << "requestAdditionalDocuments done\n"; return true; }
    bool updateApplicationStatus() { cout << "updateApplicationStatus done\n"; return true; }
    bool manageWorkflow() { cout << "manageWorkflow done\n"; return true; }
};

// ==================== MAIN MENU ====================
int main() {
    Documents d; 
    Payment p; 
    Notification n; 
    Report rep;
    Administrator a; 
    GovernmentOfficial g; 
    ServiceRequest r; 
    Citizen c;

    while (true) {
        cout << "\n============ MAIN MENU ============\n";
        cout << "1. Citizen\n";
        cout << "2. GovernmentOfficial\n";
        cout << "3. Administrator\n";
        cout << "4. Notification\n";
        cout << "5. Payment\n";
        cout << "6. Documents\n";
        cout << "7. ServiceRequest\n";
        cout << "8. Report\n";
        cout << "0. Exit\n";
        cout << "Select a class: ";
        
        int cls;
        cin >> cls;

        if (cls == 0) break;
        int method;

        switch (cls) {
        case 1:
            cout << "\n--- Citizen Methods ---\n";
            cout << "1. registerCitizen\n";
            cout << "2. login\n";
            cout << "3. updateProfile\n";
            cout << "4. applyForCNIC\n";
            cout << "5. applyForPassport\n";
            cout << "6. uploadDocuments\n";
            cout << "7. makePayment\n";
            cout << "8. viewReceipt\n";
            cout << "9. trackApplication\n";
            cout << "10. receiveNotifications\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: c.registerCitizen(); break;
                case 2: c.login(); break;
                case 3: c.updateProfile(); break;
                case 4: c.applyForCNIC(); break;
                case 5: c.applyForPassport(); break;
                case 6: c.uploadDocuments(); break;
                case 7: c.makePayment(); break;
                case 8: c.viewReceipt(); break;
                case 9: c.trackApplication(); break;
                case 10: c.receiveNotifications(); break;
            }
            break;

        case 2:
            cout << "\n--- GovernmentOfficial Methods ---\n";
            cout << "1. login\n";
            cout << "2. viewApplications\n";
            cout << "3. verifyDocuments\n";
            cout << "4. approveApplication\n";
            cout << "5. rejectApplication\n";
            cout << "6. requestAdditionalDocuments\n";
            cout << "7. updateApplicationStatus\n";
            cout << "8. manageWorkflow\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: g.login(); break;
                case 2: g.viewApplications(); break;
                case 3: g.verifyDocuments(); break;
                case 4: g.approveApplication(); break;
                case 5: g.rejectApplication(); break;
                case 6: g.requestAdditionalDocuments(); break;
                case 7: g.updateApplicationStatus(); break;
                case 8: g.manageWorkflow(); break;
            }
            break;

        case 3:
            cout << "\n--- Administrator Methods ---\n";
            cout << "1. manageCitizenAccounts\n";
            cout << "2. manageOfficialAccounts\n";
            cout << "3. assignRolesAndPermissions\n";
            cout << "4. monitorSystemPerformance\n";
            cout << "5. generateReports\n";
            cout << "6. exportReports\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: a.manageCitizenAccounts(); break;
                case 2: a.manageOfficialAccounts(); break;
                case 3: a.assignRolesAndPermissions(); break;
                case 4: a.monitorSystemPerformance(); break;
                case 5: a.generateReports(); break;
                case 6: a.exportReports(); break;
            }
            break;

        case 4:
            cout << "\n--- Notification Methods ---\n";
            cout << "1. sendNotification\n";
            cout << "2. receiveNotification\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: n.sendNotification(); break;
                case 2: n.receiveNotification(); break;
            }
            break;

        case 5:
            cout << "\n--- Payment Methods ---\n";
            cout << "1. processPayment\n";
            cout << "2. confirmPayment\n";
            cout << "3. generateReceipt\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: p.processPayment(); break;
                case 2: p.confirmPayment(); break;
                case 3: p.generateReceipt(); break;
            }
            break;

        case 6:
            cout << "\n--- Documents Methods ---\n";
            cout << "1. uploadDocument\n";
            cout << "2. verifyDocument\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: d.uploadDocument(); break;
                case 2: d.verifyDocument(); break;
            }
            break;

        case 7:
            cout << "\n--- ServiceRequest Methods ---\n";
            cout << "1. submitApplication\n";
            cout << "2. attachDocuments\n";
            cout << "3. updateStatus\n";
            cout << "4. assignToOfficial\n";
            cout << "5. processPayment\n";
            cout << "6. verifyAllDocuments\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: r.submitApplication(); break;
                case 2: r.attachDocuments(); break;
                case 3: r.updateStatus(); break;
                case 4: r.assignToOfficial(); break;
                case 5: r.processPayment(); break;
                case 6: r.verifyAllDocuments(); break;
            }
            break;

        case 8:
            cout << "\n--- Report Methods ---\n";
            cout << "1. generateReport\n";
            cout << "2. exportReport\n";
            cout << "Select method: ";
            cin >> method;

            switch (method) {
                case 1: rep.generateReport(); break;
                case 2: rep.exportReport(); break;
            }
            break;
        }
    }

    return 0;
}