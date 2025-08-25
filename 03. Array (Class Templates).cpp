/* Templates */

#include <iostream>
using namespace std;

/* Χρυσιμοποιούμε τα template έτσι ώστε να έχουμε πρώτυπα κλάσεων τα οποία να έχουν την ίδια λειτουργικότητα
   για διαφορετικούς τύπους δεδομένων */

   /* Το είναι ένας γενικός τύπος δεδομένων
      Αντικαθίστατε απο τον τύπο δεδομένων κατά τη δημιουργία του αντικειμένου της κλάσης 
      Με λίγα λόγια, όπου βλέπουμε Τ μέσα στην κλάση θα αντικατασταθεί απο τον τύπο δεδομένων κατα την δημιοιυργία του αντικειμένου */
template <typename T> 
class ARRAY {
  public:
    ARRAY(int in_n);
    ARRAY(const ARRAY<T> &ob);
    ~ARRAY();
    int get_n() const; 
    T &operator[] (int i);
    ARRAY<T> &operator= (ARRAY<T> &right);
    ARRAY<T> &operator+= (int right);
    template <typename U> friend ostream &operator<<(ostream &left, const ARRAY<U> &ob);
  private:
    T *p;
    int n;
};


/* SOS!!
   Είναι σημαντικό να γνωρίζουμε πως αν είχαμε στατικές μεθόδους και μεταβλητές στην template κλάση,
   (όπως ξέρουμε οι στατικές μέθοδοι και μεταβλητές είναι γνωστές σε όλα τα ατνικείμενα τις κλάσης και όλα βλέπουν 
   την ίδια πχ. αν ένα αντικείμενο αλλάξει μία στατική μεταβλητή, τότε κάθε αντικείμενο θα τη βλέπει αλλαγμένη),
   τότε θα υπήρχε ξεχωριστή στατική μέθοδος και μεταβλητή για κάθε τύπο δεδομένων που θα χρησιμοποιούσαμε. */

int main()
{
    int n=10;
    ARRAY<double> pin(n); /* Δημιουργία αντικειμένου της κλάσης ARRAY με τύπο δεδομένων double
                             Αντί για double θα μπορούσε να είναι int, char, float κλπ
    ARRAY<int> pin(n); //Δημιουργία αντικειμένου της κλάσης ARRAY με τύπο δεδομένων int
    ARRAY<char> pin(n); // Δημιουργία αντικειμένου της κλάσης ARRAY με τύπο δεδομένων char
    
    ΔΕΝ μπορούμε πλέον να αρχικοποιήσουμε αντικείμενο ως ARRAY pin(n), 
    πρέπει πάντα να δηλώνουμε τον τύπο δεδομένων */

    for (int i=0; i<n; i++)
        pin[i]=i*0.1;
    
    cout<<pin; 

    return 0;
}

/* Αφού η κλάση μας είναι template, θα πρέπει για όλες τις μεθόδους να χρησιμοποιούμε το 
   template <typename T> και να γράφουμε τις μεθόδους μας χρησιμοποιώντας τον τύπο δεδομένων Τ 
   
   Επιπλέον αντί για το όνομα της κλάσης και το δείκτη εμβέλειας :: 
   θα χρησιμοποιούμε πλέον όνομα κλάσης και <Τ> */
template <typename T>
ARRAY<T>::ARRAY(int in_n)
{
    n = in_n; 
    
    p = new T [n]; // Δέσμευση μνήμης για n στοιχεία τύπου Τ
    if (!p)
        cout<<"Error allocating memory!";
}

template <typename T>
ARRAY<T>::ARRAY(const ARRAY<T> &ob)
{
    n = ob.get_n(); 
    
    p = new T [n];
    if (!p) cout<<"Memory Allocation Error!";
    
}

template <typename T>
ARRAY<T>::~ARRAY()
{
    delete [] p;
}

template <typename T>
int ARRAY<T>::get_n() const
{
    return n;
}

template <typename T>
T &ARRAY<T>::operator[] (int i)
{
    if (i>=0 && i<n) 
        return p[i]; 
    else
        cout<<"Index Error";
    
}

template <typename T>
ARRAY<T> &ARRAY<T>::operator= (ARRAY<T> &right)
{
    if (this==&right) return *this; 
    
    n=right.n; 
    delete [] p;
    p=new T [n];
    if(!p) cout<<"Error Allcoating Memory";
    
    for (int i=0; i<n; i++)
        p[i]=right[i];
        
    return *this; 
}

template <typename T>
ARRAY<T> &ARRAY<T>::operator+= (int right)
{
    int newn=n+right;
    int *newp;
    int i; 
    
    if (right>0)
    {
        newp = new T [newn];
        if (!newp) cout<<"Error Allocating Memory";
        
        for (i=0; i<n; i++)
            newp[i]=p[i];
        for (i=n; i<newn; i++)
            newp[i]=0;
            
        delete [] p;
        n=newn;
        p=newp; 
    }
    else 
        cout<<"Wrong index!";
        
}

template <typename T>
ostream &operator<<(ostream &left, const ARRAY<T> &ob)
{
    int i; 
    
    left<<"[";
    for (i=0; i<ob.n-1; i++)
        cout<<ob.p[i]<<" ";
    left<<ob.p[ob.n-1];
    left<<"]";
    
    return left; 
}