#include <cstring>
#include <stdexcept>
#include "STRING.h"
/* Έχουμε γράψει στο αρχείο STRING.h τις δηλώσεις μας και στο STRING.cpp θα γράψουμε
το σώμα των δηλώσεών μας. Ο συνδέτης αντικαθιστά το #include "STRING.h" με τα περιεχόμενα του αρχείου. */

/* Θα πρέπει ότι γράφουμε να μπορεί να αντιστοιχιστεί με τη σωστή κλάση, επομένως πριν απο κάθε μέθοδο
θα πρέπει να γράφουμε το όνομα της κλάσης ακολουθούμενο απο το δείκτη εμβέλειας :: */

// Το this είναι δείκτης στο αντικείμενο και το *this επιστρέφει το ίδιο το αντικείμενο μέσα στο κώδικα της κλα΄ση.
// Μία κλάση έχει πάντα απεφθείας πρόσβαση στις μεταβλητές τις μέσα στον κώδικά της.
// π.χ.: θα πούμε value = something, δεν χρειάζεται να γράψουμε this->value = something.

// default κατασκευαστής
STRING::STRING(/* int val */): m(42 /* val */){    // το : m(42) αρχικοποιεί το αντικείμενο m που υπάρχει στην κλάση STRING
    n=0;                    // Θα μπορούσαμε να του δώσουμε και τιμή αρχικοποίησης κατα την κατασκευή του αντικειμένου
    str=NULL;               // όπως φαίνεται με το σχόλιο αντί για το 42.
};

// κατασκευαστές με ορίσματα
STRING::STRING(char *in_str): m(42){
    /* Όταν κάνουμε δυναμική διαχείρηση μνήμης όπως εδώ, θα χρησιμοποιούμε το:
    new για να δεσμεύουμε χώρο (συνήθως στον κατασκευαστή) 
    variable = new type για απλή μεταβλητή ή variable = new type[n] για πίνακα μήκους n
    και το
    delete για να τον αποδεσμεύουμε (συνήθως στον καταστροφέα)
    delete variable για απλή ή delete [] variable για πίνακα
    όπως φαίνεται παρακάτω: */
    n=strlen(in_str);
    str=new char[n+1]; // n+1 so we have enough space for '/0'
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, in_str);
};
STRING::STRING(const char *in_str): m(42){
    n=strlen(in_str);
    str=new char[n+1];
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, in_str);
};

// κατασκευαστής αντιγράφου
STRING::STRING(const STRING &obj): m(42){
    n=obj.n;
    str=new char[n+1];
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, obj.str);
};

// καταστροφέας
STRING::~STRING(){
    // Πάντα μα Πάντα αποδεσμεύουμε δεσμευμένο χώρο. Πάντα!!!!!
    delete [] str;
};

// getters
int STRING::get_n() const{
    return n;
};
char *STRING::get_string() const{
    return str;
};

// setters
void STRING::set_string(char *in_str){
    if(str!=NULL) delete [] str;
    n=strlen(in_str);
    str=new char[n+1];
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, in_str);
};
void STRING::set_string(const char *in_str){
    if(str!=NULL) delete [] str;
    n=strlen(in_str);
    str=new char[n+1];
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, in_str);
};

// Υπερφόρτωση τελεστών Κλάσης
STRING &STRING::operator=(const char *right){
    //
    if(str!=NULL){
        if(strcmp(str, right)==0){ 
            return *this;
        }else{
            delete [] str;
        };
    };
    n=strlen(right);
    str=new char[n+1];
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, right);
    return *this;
    /* Επιστρέφουμε αναφορά στο αντικείμενο και όχι αντίγραφο για να μπορούμε να πούμε a = b = c = .... 
    διότι η πράξη γίνεται απο τα δεξιά προς τα αριστερά... */
};
STRING &STRING::operator=(const STRING &right){
    if(this==&right) return *this;
    if(str!=NULL) delete [] str;
    n=strlen(right.str);
    str=new char[n+1];
    if (!str) throw out_of_range("Allocation Error");
    strcpy(str, right.str);
    return *this; 
};
STRING &STRING::operator+=(char right){
    char *p = new char[n];
    strcpy(p, str);
    n++;
    str = new char[n];
    strcpy(str, p);
    delete [] p;
    str[n-1] = right;
    str[n]= '\0';
    return *this;
};
STRING STRING::operator+(const STRING &right){
    STRING s;
    s.n = n + right.n;
    s.str = new char[s.n+1];
    int i;
    for(i=0;i<=n;i++){
        s.str[i]=str[i];
    };
    for(i=0;i<=right.n;i++){
        s.str[n+1+i]=right.str[i];
    };
    s.str[s.n+1]='\0';
    return s;
};
bool STRING::operator<(const STRING &right){
    if(strcmp(str, right.str)<0){
        return true;
    };
    return false;
};
bool STRING::operator>(const STRING &right){
    if(strcmp(str, right.str)>0){
        return true;
    };
    return false;
};
bool STRING::operator==(const STRING &right){
    if(strcmp(str, right.str)==0){
        return true;
    };
    return false;
};
char &STRING::operator[](int i){
    /* Επιστρέφουμε αναφορά στο στοιχείο του πίνακα έτσι ώστε το επιστρεφόμενο στοιχείο να μην
    είναι ένα απλό αντίγραφο και οι αλλαγές που θα κάνουμε σε αυτό εκτός συνάρτησης να γίνουν στοιχείο
    ίδιο το στοιχείο.
    π.χ.: αν πούμε obj[i] = 7; το obj[i] θα μας επιστρέψει μία αναφορά στο ίδιο το στοιχείο του πίνακα και το = 7
    θα αλλάξει την τιμή του. */
    if(i>=0 && i<n){
        return str[i];
    }else{
        throw out_of_range("Index out of bounds");
    };
};

/* Οι παρακάτω συναρτήσεις δεν είναι μέθοδοι της κάσης, είναι global συναρτήσεις και εμείς απλά
τις υπερφορτώνουμε, για αυτό δεν χρειάζονται το STRING:: στην αρχή τους.
δηλώνουμε απλά ότι είναι φιλικές προς την κλάση μας για να μπορούν να τη διαχειριστούν. */
ostream &operator<<(ostream &left, const STRING &right){
    int i;
    for(i=0;i<right.n+1;i++){
        left<<right.str[i];
    };
    left<<endl;
    return left;
};
istream &operator>>(istream &left, STRING &right){
    char new_str[80];
    if(right.str!=NULL) delete [] right.str;
    left.getline(new_str, sizeof(new_str));
    right.n=strlen(new_str);
    right.str = new char[right.n+1];
    strcpy(right.str, new_str);
    return left;
};

// Στατική μεταβλητή
int STRING::max_length = 325;

// Στατική μέθοδος
int STRING::get_max_length(){
    return max_length;
};