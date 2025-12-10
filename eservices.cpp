#include <iostream>
#include <string>
#include <list>
using namespace std;

// ================== FORWARD DECLARATIONS ==================
class ServiceRequest;
class Documents;
class Payment;
class Notification;
class Citizen;
class GovernmentOfficial;
class Administrator;
class Report;

// ========================== REPORT ========================
class Report {
public:
    int generatedByAdminID;
    int reportID;
    string reportType;
    string generateDate;

    bool generateReport() { cout << "generateReport : done\n"; return true; }
    bool exportReport() { cout << "exportReport : done\n"; return true; }

    // Bidirectional association with Administrator
    Administrator* adminPtr = nullptr;  
};

// ======================= NOTIFICATION =====================
class Notification {
public:
    int notificationID;
    string type;
    string message;
    string sendDate;

    bool sendNotification() { cout << "sendNotification : done\n"; return true; }
    bool receiveNotification() { cout << "receiveNotification : done\n"; return true; }

    // Bidirectional association with Citizen
    Citizen* citizenPtr = nullptr;  
};

// ========================= DOCUMENTS ======================
class Documents {
public:
    int documentID;
    string documentName;
    string fileType;
    string uploadDate;
    string verificationStatus;

    bool uploadDocument() { cout << "uploadDocument : done\n"; return true; }
    bool verifyDocument() { cout << "verifyDocument : done\n"; return true; }

    // Composition: belongs to ServiceRequest
    ServiceRequest* requestPtr = nullptr;  

    // Bidirectional association with Citizen
    Citizen* citizenPtr = nullptr;  
};

// ========================== PAYMENT =======================
class Payment {
public:
    int applicationID;
    int paymentID;
    double amount;
    string method;
    string status;
    string transactionDate;

    bool processPayment() { cout << "processPayment : done\n"; return true; }
    bool confirmPayment() { cout << "confirmPayment : done\n"; return true; }
    string generateReceipt() { cout << "generateReceipt : done\n"; return "receipt"; }

    // Composition: belongs to ServiceRequest
    ServiceRequest* requestPtr = nullptr;  
};

// ====================== SERVICE REQUEST ===================
class ServiceRequest {
public:
    int citizenID;
    int applicationID;
    string applicationType;
    string submissionDate;
    string status;

    // Composition: ServiceRequest owns its payment
    Payment payment;

    // Composition: ServiceRequest owns documents
    list<Documents> documents;

    // Bidirectional association: GovernmentOfficial reviewing
    GovernmentOfficial* officialPtr = nullptr;  

    bool submitApplication() { cout << "submitApplication : done\n"; return true; }
    bool getApplicationStatus() { cout << "getApplicationStatus : done\n"; return true; }
    bool processRequest() { cout << "processRequest : done\n"; return true; }
    bool verifyAllDocuments() { cout << "verifyAllDocuments : done\n"; return true; }
};

// ========================== CITIZEN =======================
class Citizen {
public:
    int citizenID;
    string fullName;
    string CNIC;
    string email;
    string phone;
    string address;

    // Aggregation: Citizen has multiple service requests
    list<ServiceRequest*> serviceRequests;

    // Bidirectional association: notifications
    list<Notification*> notifications;

    // Bidirectional association: documents
    list<Documents*> documents;

    bool registerCitizen() { cout << "registerCitizen : done\n"; return true; }
    bool login() { cout << "login : done\n"; return true; }
    bool applyForPassport() { cout << "applyForPassport : done\n"; return true; }
    bool applyForNIC() { cout << "applyForNIC : done\n"; return true; }
    bool uploadDocuments() { cout << "uploadDocuments : done\n"; return true; }
    bool makePayment() { cout << "makePayment : done\n"; return true; }
    string viewReceipt() { cout << "viewReceipt : done\n"; return "receipt"; }
    string trackApplication() { cout << "trackApplication : done\n"; return "status"; }
    list<string> receiveNotifications() { cout << "receiveNotifications : done\n"; return {}; }
};

// =================== GOVERNMENT OFFICIAL ==================
class GovernmentOfficial {
public:
    int officialID;
    string name;
    string role;
    string department;
    string email;
    string password;

    // Bidirectional association: reviews requests
    list<ServiceRequest*> applications;

    // Bidirectional association: verifies documents
    list<Documents*> documentsToVerify;

    bool login() { cout << "login : done\n"; return true; }
    bool reviewDocuments() { cout << "reviewDocuments : done\n"; return true; }
    bool approveApplication() { cout << "approveApplication : done\n"; return true; }
    bool rejectApplication() { cout << "rejectApplication : done\n"; return true; }
    bool requestAdditionalDocuments() { cout << "requestAdditionalDocuments : done\n"; return true; }
    bool updateApplicationStatus() { cout << "updateApplicationStatus : done\n"; return true; }
    bool manageWorkflow() { cout << "manageWorkflow : done\n"; return true; }
    list<ServiceRequest*> viewApplications() { cout << "viewApplications : done\n"; return {}; }
};

// ====================== ADMINISTRATOR =====================
class Administrator {
public:
    int adminID;
    string name;
    string email;
    string username;
    string password;

    // Bidirectional associations
    list<Citizen*> allCitizens;
    list<GovernmentOfficial*> allOfficials;
    list<Report*> systemReports;
    list<ServiceRequest*> allRequests; // optional

    bool manageCitizenAccounts() { cout << "manageCitizenAccounts : done\n"; return true; }
    bool manageOfficialAccounts() { cout << "manageOfficialAccounts : done\n"; return true; }
    bool assignRolesAndPermissions() { cout << "assignRolesAndPermissions : done\n"; return true; }
    string monitorSystemUptime() { cout << "monitorSystemUptime : done\n"; return "uptime"; }
    bool generateReports() { cout << "generateReports : done\n"; return true; }
    bool exportReports() { cout << "exportReports : done\n"; return true; }
};

// ============================ MENU ========================
void showMethodsCitizen(Citizen &c) {
    int choice;
    do {
        cout << "\nCITIZEN METHODS MENU:\n";
        cout << "1. registerCitizen\n2. login\n3. applyForPassport\n4. applyForNIC\n5. uploadDocuments\n6. makePayment\n7. viewReceipt\n8. trackApplication\n9. receiveNotifications\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: c.registerCitizen(); break;
            case 2: c.login(); break;
            case 3: c.applyForPassport(); break;
            case 4: c.applyForNIC(); break;
            case 5: c.uploadDocuments(); break;
            case 6: c.makePayment(); break;
            case 7: c.viewReceipt(); break;
            case 8: c.trackApplication(); break;
            case 9: c.receiveNotifications(); break;
        }
    } while(choice != 0);
}

void showMethodsServiceRequest(ServiceRequest &sr) {
    int choice;
    do {
        cout << "\nSERVICE REQUEST METHODS MENU:\n";
        cout << "1. submitApplication\n2. getApplicationStatus\n3. processRequest\n4. verifyAllDocuments\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: sr.submitApplication(); break;
            case 2: sr.getApplicationStatus(); break;
            case 3: sr.processRequest(); break;
            case 4: sr.verifyAllDocuments(); break;
        }
    } while(choice != 0);
}

void showMethodsPayment(Payment &p) {
    int choice;
    do {
        cout << "\nPAYMENT METHODS MENU:\n";
        cout << "1. processPayment\n2. confirmPayment\n3. generateReceipt\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: p.processPayment(); break;
            case 2: p.confirmPayment(); break;
            case 3: p.generateReceipt(); break;
        }
    } while(choice != 0);
}

void showMethodsDocuments(Documents &d) {
    int choice;
    do {
        cout << "\nDOCUMENTS METHODS MENU:\n";
        cout << "1. uploadDocument\n2. verifyDocument\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: d.uploadDocument(); break;
            case 2: d.verifyDocument(); break;
        }
    } while(choice != 0);
}

void showMethodsNotification(Notification &n) {
    int choice;
    do {
        cout << "\nNOTIFICATION METHODS MENU:\n";
        cout << "1. sendNotification\n2. receiveNotification\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: n.sendNotification(); break;
            case 2: n.receiveNotification(); break;
        }
    } while(choice != 0);
}

void showMethodsGovernmentOfficial(GovernmentOfficial &g) {
    int choice;
    do {
        cout << "\nGOVERNMENT OFFICIAL METHODS MENU:\n";
        cout << "1. login\n2. reviewDocuments\n3. approveApplication\n4. rejectApplication\n5. requestAdditionalDocuments\n6. updateApplicationStatus\n7. manageWorkflow\n8. viewApplications\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: g.login(); break;
            case 2: g.reviewDocuments(); break;
            case 3: g.approveApplication(); break;
            case 4: g.rejectApplication(); break;
            case 5: g.requestAdditionalDocuments(); break;
            case 6: g.updateApplicationStatus(); break;
            case 7: g.manageWorkflow(); break;
            case 8: g.viewApplications(); break;
        }
    } while(choice != 0);
}

void showMethodsAdministrator(Administrator &a) {
    int choice;
    do {
        cout << "\nADMINISTRATOR METHODS MENU:\n";
        cout << "1. manageCitizenAccounts\n2. manageOfficialAccounts\n3. assignRolesAndPermissions\n4. monitorSystemUptime\n5. generateReports\n6. exportReports\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: a.manageCitizenAccounts(); break;
            case 2: a.manageOfficialAccounts(); break;
            case 3: a.assignRolesAndPermissions(); break;
            case 4: a.monitorSystemUptime(); break;
            case 5: a.generateReports(); break;
            case 6: a.exportReports(); break;
        }
    } while(choice != 0);
}

void showMethodsReport(Report &r) {
    int choice;
    do {
        cout << "\nREPORT METHODS MENU:\n";
        cout << "1. generateReport\n2. exportReport\n0. Back\n";
        cout << "Enter choice: "; cin >> choice;
        switch(choice) {
            case 1: r.generateReport(); break;
            case 2: r.exportReport(); break;
        }
    } while(choice != 0);
}

int main() {
    Citizen citizen;
    ServiceRequest sr;
    Payment payment;
    Documents doc;
    Notification notif;
    GovernmentOfficial official;
    Administrator admin;
    Report report;

    int mainChoice;
    do {
        cout << "\n=== E-SERVICES PLATFORM MENU ===\n";
        cout << "Select a class to interact:\n";
        cout << "1. Citizen\n2. ServiceRequest\n3. Payment\n4. Documents\n5. Notification\n6. GovernmentOfficial\n7. Administrator\n8. Report\n0. Exit\n";
        cout << "Enter choice: "; cin >> mainChoice;

        switch(mainChoice) {
            case 1: showMethodsCitizen(citizen); break;
            case 2: showMethodsServiceRequest(sr); break;
            case 3: showMethodsPayment(payment); break;
            case 4: showMethodsDocuments(doc); break;
            case 5: showMethodsNotification(notif); break;
            case 6: showMethodsGovernmentOfficial(official); break;
            case 7: showMethodsAdministrator(admin); break;
            case 8: showMethodsReport(report); break;
        }
    } while(mainChoice != 0);

    cout << "Exiting platform.\n";
    return 0;
}
