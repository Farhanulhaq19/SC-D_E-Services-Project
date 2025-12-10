#include <iostream>
#include <string>
#include <list>
using namespace std;

// Forward declarations
class ServiceRequest;
class Citizen;
class GovernmentOfficial;
class Administrator;
class Documents;
class Payment;
class Notification;
class Report;

// ========================================
// 1. Documents
// ========================================
class Documents {
public:
    ServiceRequest* belongsToRequest = nullptr;

    bool uploadDocument()    { cout << "Documents::uploadDocument() - done\n";    return true; }
    bool verifyDocument()    { cout << "Documents::verifyDocument() - done\n";    return true; }
};

// ========================================
// 2. Payment
// ========================================
class Payment {
public:
    ServiceRequest* forRequest = nullptr;

    bool processPayment()    { cout << "Payment::processPayment() - done\n";      return true; }
    bool confirmPayment()    { cout << "Payment::confirmPayment() - done\n";      return true; }
    void generateReceipt()   { cout << "Payment::generateReceipt() - done\n"; }
};

// ========================================
// 3. Notification
// ========================================
class Notification {
public:
    Citizen* sentTo = nullptr;

    bool sendNotification()     { cout << "Notification::sendNotification() - done\n";     return true; }
    bool receiveNotification()  { cout << "Notification::receiveNotification() - done\n";  return true; }
};

// ========================================
// 4. Report
// ========================================
class Report {
public:
    Administrator* generatedBy = nullptr;

    bool generateReport() { cout << "Report::generateReport() - done\n"; return true; }
    bool exportReport()   { cout << "Report::exportReport() - done\n";   return true; }
};

// ========================================
// 5. ServiceRequest
// ========================================
class ServiceRequest {
public:
    list<Documents> documents;
    Payment payment;
    Citizen* applicant = nullptr;
    GovernmentOfficial* assignedOfficial = nullptr;

    int  submitApplication()     { cout << "ServiceRequest::submitApplication() - done\n";     return 1; }
    bool attachDocuments()       { cout << "ServiceRequest::attachDocuments() - done\n";       return true; }
    bool updateStatus()          { cout << "ServiceRequest::updateStatus() - done\n";          return true; }
    bool assignToOfficial()      { cout << "ServiceRequest::assignToOfficial() - done\n";      return true; }
    bool processPayment()        { cout << "ServiceRequest::processPayment() - done\n";        return true; }
    bool verifyAllDocuments()    { cout << "ServiceRequest::verifyAllDocuments() - done\n";    return true; }
};

// ========================================
// 6. Citizen - FIXED: missing } and ;
// ========================================
class Citizen {
private:
    list<ServiceRequest*> serviceRequests;
    list<Notification*> notifications;
public:
    bool registerCitizen()       { cout << "Citizen::registerCitizen() - done\n";       return true; }
    bool login()                { cout << "Citizen::login() - done\n";                return true; }
    bool updateProfile()         { cout << "Citizen::updateProfile() - done\n";         return true; }
    int  applyForCNIC()         { cout << "Citizen::applyForCNIC() - done\n";         return 1; }
    int  applyForPassport()     { cout << "Citizen::applyForPassport() - done\n";     return 1; }
    bool uploadDocuments()       { cout << "Citizen::uploadDocuments() - done\n";       return true; }
    int  makePayment()          { cout << "Citizen::makePayment() - done\n";          return 123; }
    void viewReceipt()          { cout << "Citizen::viewReceipt() - done\n"; }
    string trackApplication()    { cout << "Citizen::trackApplication() - done\n";      return "In Progress"; }
    list<Notification*> receiveNotifications() {
        cout << "Citizen::receiveNotifications() - done\n";
        return notifications;
    }
}; // ← This semicolon was missing!

// ========================================
// 7. GovernmentOfficial
// ========================================
class GovernmentOfficial {
public:
    list<ServiceRequest*> assignedApplications;

    bool login()                     { cout << "GovernmentOfficial::login() - done\n";                     return true; }
    list<ServiceRequest*> viewApplications() { cout << "GovernmentOfficial::viewApplications() - done\n"; return assignedApplications; }
    bool verifyDocuments()            { cout << "GovernmentOfficial::verifyDocuments() - done\n";            return true; }
    bool approveApplication()         { cout << "GovernmentOfficial::approveApplication() - done\n";         return true; }
    bool rejectApplication()          { cout << "GovernmentOfficial::rejectApplication() - done\n";          return true; }
    bool requestAdditionalDocuments() { cout << "GovernmentOfficial::requestAdditionalDocuments() - done\n"; return true; }
    bool updateApplicationStatus()    { cout << "GovernmentOfficial::updateApplicationStatus() - done\n";    return true; }
    bool manageWorkflow()             { cout << "GovernmentOfficial::manageWorkflow() - done\n";             return true; }
};

// ========================================
// 8. Administrator
// ========================================
class Administrator {
private:
    list<Citizen*>             allCitizens;
    list<GovernmentOfficial*>   allOfficials;
    list<Report*>              systemReports;
public:
    bool manageCitizenAccounts()      { cout << "Administrator::manageCitizenAccounts() - done\n";      return true; }
    bool manageOfficialAccounts()     { cout << "Administrator::manageOfficialAccounts() - done\n";     return true; }
    bool assignRolesAndPermissions() { cout << "Administrator::assignRolesAndPermissions() - done\n"; return true; }
    string monitorSystemPerformance() { cout << "Administrator::monitorSystemPerformance() - done\n";   return "OK"; }
    list<Report*> generateReports()  { cout << "Administrator::generateReports() - done\n";           return systemReports; }
    bool exportReports()             { cout << "Administrator::exportReports() - done\n";             return true; }
};

// ========================================
// MAIN MENU
// ========================================
int main() {
    Documents          d;
    Payment           p;
    Notification       n;
    Report            r;
    ServiceRequest     sr;
    Citizen           c;
    GovernmentOfficial gov;
    Administrator      admin;

    while (true) {
        cout << "\n══════════════════════════════════════\n";
        cout << "     E-GOVERNMENT SERVICE PLATFORM\n";
        cout << "══════════════════════════════════════\n";
        cout << "1. Citizen\n2. Government Official\n3. Administrator\n4. Service Request\n";
        cout << "5. Documents\n6. Payment\n7. Notification\n8. Report\n0. Exit\n";
        cout << "Select class: ";
        int choice;
        cin >> choice;
        if (choice == 0) break;

        switch (choice) {
            case 1: {
                cout << "\nCitizen → 1.reg 2.login 3.update 4.CNIC 5.Passport 6.upload 7.pay 8.receipt 9.track 10.notif\n> ";
                int m; cin >> m;
                if(m==1) c.registerCitizen();
                else if(m==2) c.login();
                else if(m==3) c.updateProfile();
                else if(m==4) c.applyForCNIC();
                else if(m==5) c.applyForPassport();
                else if(m==6) c.uploadDocuments();
                else if(m==7) c.makePayment();
                else if(m==8) c.viewReceipt();
                else if(m==9) c.trackApplication();
                else if(m==10) c.receiveNotifications();
                break;
            }
            case 2: {
                cout << "\nOfficial → 1.login 2.view 3.verify 4.approve 5.reject 6.request 7.update 8.workflow\n> ";
                int m; cin >> m;
                if(m==1) gov.login();
                else if(m==2) gov.viewApplications();
                else if(m==3) gov.verifyDocuments();
                else if(m==4) gov.approveApplication();
                else if(m==5) gov.rejectApplication();
                else if(m==6) gov.requestAdditionalDocuments();
                else if(m==7) gov.updateApplicationStatus();
                else if(m==8) gov.manageWorkflow();
                break;
            }
            case 3: {
                cout << "\nAdmin → 1.manageCitizens 2.manageOfficials 3.assignRoles 4.monitor 5.reports 6.export\n> ";
                int m; cin >> m;
                if(m==1) admin.manageCitizenAccounts();
                else if(m==2) admin.manageOfficialAccounts();
                else if(m==3) admin.assignRolesAndPermissions();
                else if(m==4) admin.monitorSystemPerformance();
                else if(m==5) admin.generateReports();
                else if(m==6) admin.exportReports();
                break;
            }
            case 4: {
                cout << "\nServiceRequest → 1.submit 2.attach 3.update 4.assign 5.pay 6.verifyAll\n> ";
                int m; cin >> m;
                if(m==1) sr.submitApplication();
                else if(m==2) sr.attachDocuments();
                else if(m==3) sr.updateStatus();
                else if(m==4) sr.assignToOfficial();
                else if(m==5) sr.processPayment();
                else if(m==6) sr.verifyAllDocuments();
                break;
            }
            case 5: cout << "1.upload 2.verify → "; int m; cin>>m; (m==1?d.uploadDocument():d.verifyDocument()); break;
            case 6: cout << "1.process 2.confirm 3.receipt → "; int m; cin>>m;
                     if(m==1) p.processPayment(); else if(m==2) p.confirmPayment(); else p.generateReceipt(); break;
            case 7: cout << "1.send 2.receive → "; int m; cin>>m; (m==1?n.sendNotification():n.receiveNotification()); break;
            case 8: cout << "1.generate 2.export → "; int m; cin>>m; (m==1?r.generateReport():r.exportReport()); break;
        }
    }
    cout << "\nThank you! System closed.\n";
    return 0;
}