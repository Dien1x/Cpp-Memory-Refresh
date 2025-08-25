/* Κατα την κληρονομικότητα μπορούμε να κάνεουμε μεθόδους της βασικής κλάσης override με μεθόδους
που θέλουμε να βάλουμε στις παραγόμενες κλάσεις και έχουν ίδιο όνομα και παρόμοια λειτουργικότητα. */

/* Η κληρονομικότητα μας επιτρπεπει τη χρήση ενός πολύ σημαντικού πίνακα του
Πολυμορφικού πίνακα δεικτών
ο οπο΄΄ιος μας επιτρέπει να έχουμε σε ένα πίνακα αντικείμενα διαφορετικού τύπου αλλα μόνο να αυτά
παράγοντια απο την ίδια βασική κλάση.
Παρακάτω έχουμε:
1) μία βασική κλάση
2) δύο παραγόμενες κλάσεις
3) μία κλάση που έχει ως μέλος τις δύο παραγόμενες κλάσεις. */

/* Αυτό που θέλουμε βασικά να καταφέρουμε είναι να διμηουργήσουμε ένα πίνακα απο δείκτες τις βασικής κλάσης
και οι δείκτες αυτοί να δείχνουν σε αντικείμενα παραγόμενων κλάσεων.
Επιτρέπεται να έχουμε αντικείμενα παραγόμενων κλάσεων μόνο σε: 
δείκτες ή αναφορές της βασικής κλάσης.
Όταν αναθέτουμε αντικείμενα παραγόμενης κλάσης σε δείκτες βασικής κλάσης, δεν μπορούμε να καλέσουμε τις μεθόδους
που έχουν γίνει override παρα μόνο:

Αν έχουμε ορίσει τις μεθόδους τις βασικής κλάσης virtual
και τις μεθόδους της παραγόμενης κλάσης override. */


class card{
    protected:
        string name;
        string color;
        string rarity;
    
    public:
        card(string in_name, string in_color, string in_rarity);
        friend ostream &operator<<(ostream &left, const card &obj);
        
        /* Χρησιμοποιώντας virtual μεθόδο = 0 σημαίνει πως η μέθοδο δεν έχει κάποιο λειτουργικότητα
        για την κλάση αλλά απαιτείται να υπάρχει στις παραγομενες κλα΄σεις. */
        virtual card *clone() const = 0; // Πολύ σημαντική, Δες παρακάτω.
        virtual ostream &print(ostream &out) const = 0;
};

class creature: public card{
    int attack;
    int defence;
    string type;
    
    public:
        creature(string in_name, string in_color, string in_rarity, int in_attack, int in_defence, string in_type);
        friend ostream &operator<<(ostream &left, const creature &obj);
        
        /* Η μέθοδος clone είναι πολύ σημαντική, διότι επιτρέπει την αντιγραφή ενός αντικειμένου τύπου pointer βασικής κλάσης 
        να αντιγραφεί σωστά ως pointer παραγόμενης κλάσης.
        Ουσιαστικά δημιουργείται ένας δείκτης ενός αντίγραφου του αντικειμένου μέσο copy constructor και πειστρέφεται αυτός ο δείκτης
        ο οποίος είναι τύπου παραγόμενης κλάσης αλλά μπορεί να ανατεθεί σε δείκτη βασικής κλάσης. */
        creature *clone() const override {return new creature(*this);};
        ostream &print(ostream &left) const override; /* Χρησιμοποιείται για να εκτυπώσουμε σωστά αντικείμενα παραγόμενης κάσης 
                                                      που έχουν αντιστοιχιστεί σε δείκτες βασικής κλάσης. Σε περ΄΄ιπτωση που δεν υπάρχει
                                                      virtual print μέθοδος, θα χρησιμοποιείται η μέθοδος της βασικής κλάσης. */
};

class land: public card{
    int mana;
    string description;
    bool tap;
    public:
        land(string in_name, string in_color, string in_rarity, int in_mana, string in_description, bool in_tap);
        friend ostream &operator<<(ostream &left, const land &obj);
        
        // Ομοίως με παραπάνω
        land *clone() const override {return new land(*this);}
        ostream &print(ostream &left) const override;
};

class pool{
    card **cardpool;
    int current;
    
    public:
        static const int max_cards; // Μέγιστος αριθμός καρτών.
        pool();
        pool(const pool &obj);
        ~pool();
        card &operator[](int i);
        friend ostream &operator<<(ostream &left, const pool &obj);
        void add_card(card &obj);
        card *pick_random();
};

class hand{
    card **cardhand;
    int current;
    
    public:
        static const int max_hand;
        hand(pool &p);
        ~hand();
        void pick_card(pool &p ,int i);
        void fill_hand(pool &p);
        friend ostream &operator<<(ostream &left, const hand &obj);
};