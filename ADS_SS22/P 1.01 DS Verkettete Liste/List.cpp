#include "List.h"

List::List()
{
/* 
    Konstruktor für eine leere Liste 
*/
    head_tail       = new Node;
    list_size       = 0;
    temp            = false;
    head_tail->next = head_tail;
    head_tail->prev = head_tail;
}

List::List(const List& _List)
{
/*  
    Konstruktor mit Übergabe einer Liste, die dann kopiert wird. 
    in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    sollen.
*/
    list_form       = _List.list_form;
    head_tail       = new Node;
    list_size       = 0;
    temp            = _List.temp;
    head_tail->next = head_tail;        
    head_tail->prev = head_tail;
    Node* tmp_node;
    tmp_node = _List.head_tail->next;
    while (tmp_node != _List.head_tail)
    {
        head_tail->prev =
            new Node(tmp_node->value, head_tail->prev->next, head_tail->prev);
        head_tail->prev->prev->next = head_tail->prev;
        list_size++;
        tmp_node = tmp_node->next;
    }
/*  
    Ist die übergebene Liste eine temporäre Liste? -> aus Operator +
*/
    if (_List.temp)
        delete &_List; 
}

List::~List()
{
    //TODD: Dekonstruktor Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.

    /*
    * Wir erzeigen einen Temporärern Knoten "current", Zeigt auf das erste Element. 
    * Biegen dann die Zeiger von Head_tail auf das zweite Element um , löschen current -> somit löschen wir immer den Ersten Knoten bis die Liste leer ist
    * Liste Leer head_tail->next = head_tail
    */

    
    while (head_tail->next != head_tail && list_size > 0)
    {
        Node* current = head_tail->next;
        head_tail->next = current->next;
        current->next->prev = head_tail;

        delete current;

        //Listengröße Veringern
        list_size--;
    }

    // Laufzeitkomplexität O(n)

}

void List::insertFront(int value)
{
    /* TODO: Einfuegen eines neuen Knotens am Anfang der Liste.
       Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einfügen
    */

    /*
    * Erstellein einen neuen Knoten und initialisieren ihn mit value
    * Fügen ihn dann der Liste hinzu
    */
    Node* NewNode = new Node(value);

    NewNode->next = head_tail->next;
    head_tail->next->prev = NewNode;
    NewNode->prev = head_tail;
    head_tail->next = NewNode;

    //Listen größe um 1 erhöhen noch einfügen eines Knotens
    list_size++;

    // Laufzeitkomplexität O(1), da wir Konstante aufrufe haben.
 
}

void List::insertFront(List& _List)
{
    
/*	
    TODO: Einfuegen der Liste _List am Anfang an einer vorhandenen Liste
	Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
	Die einzufuegende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden. 
*/

/*
    gleiches Objekt -> keine Aktion
*/ 
	if (head_tail == _List.head_tail) return;	

/*
	Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
	Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	Die Liste _List ist danach leer, aber vorhanden.
*/
    //Summe der beiden Liste = Gesamtgröße
    this->list_size = this->list_size + _List.list_size;

  
    // Zusammenführen der Liste
    _List.head_tail->prev->next = this->head_tail->next;
    this->head_tail->next->prev = _List.head_tail->prev;

    // Neuen Ersten Knoten festlegen, zweite Liste
    this->head_tail->next = _List.head_tail->next;
    _List.head_tail->next->prev = this->head_tail;

    // Zweite Liste soll Leer aber vorhanden sein, somit soll sie auf sich selber Zeigen.
    _List.head_tail->next = head_tail;
    _List.head_tail->prev = head_tail;

    _List.list_size = 0;

    //Laufzeitkomplexität 0(1)
}

void List::insertBack(int value)
{
    
/*
	TODO: Einfuegen eines neuen Knotens am Ende der Liste
    Einen neuen Knoten mit dem Wert value wird am Ende der Liste einfügen
*/

/*
* Erstellein einen neuen Knoten und initialisieren ihn mit value
* Fügen ihn dann der Liste hinzu
*/
    Node* NewNode = new Node(value);
    
    NewNode->next = head_tail;
    NewNode->prev = head_tail->prev;
    head_tail->prev->next = NewNode;
    head_tail->prev = NewNode;

    //Listen größe um 1 erhöhen noch einfügen eines Knotens
    list_size++;

    // Laufzeitkomplexität O(1), da wir Konstante aufrufe haben.
}

void List::insertBack(List& _List)
{
    
/*
    TODO: Einfuegen der Liste _List am Ende einer vorhandenen Liste
        - Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
	    - Die einzufuegende Liste _List ist anschließend leer.
	    - Es darf keine Schleife und kein new benutzt werden. 
        - Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.Diese Knoten (koplette Kette) werden an den Ende der Liste (this) übertragen,
        ohne sie zu kopieren! Die Liste _List ist danach leer, aber vorhanden.
*/

/*
    gleiches Objekt -> keine Aktion
*/
	if (head_tail == _List.head_tail) return;

    //Summe der beiden Liste = Gesamtgröße
    this->list_size = this->list_size + _List.list_size;

    // Zusammenführen der Liste
    this->head_tail->prev->next = _List.head_tail->next;
    _List.head_tail->next->prev = this->head_tail->prev;

    this->head_tail->prev = _List.head_tail->prev;
    _List.head_tail->prev->next = this->head_tail;

    _List.head_tail->next = _List.head_tail;
    _List.head_tail->prev = _List.head_tail;

    _List.list_size = 0;



}

bool List::getFront(int& value)
{
    
/*  
    TODO: Entnehmen des Knotens am Anfang der Liste der Wert wird als Parameter zurueckgegeben der Knoten wird entnommen.im Fehlerfall wird false zurückgegeben
        - Der Wert des vorderen Knotens wird rückgegeben und der Knoten gelöscht.
        - Die Methode del(value) darf nicht zum löschen benutzt werden.
	
*/

/*
    gleiches Objekt -> keine Aktion
*/
	if (!list_size) return false;	


        value = head_tail->next->value;

        Node* tmp = head_tail->next;

        head_tail->next = tmp->next;
        tmp->next->prev = head_tail;
        list_size--;
        delete tmp;
        return true;

    //Komplexität 0(1)
}

bool List::getBack(int& value)
{ 
  
/*  
    TODO: Entnehmen des Knotens am Ende der Liste
	der Wert wird als Parameter zurueckgegeben
	der Knoten wird entnommen
	im Fehlerfall wird false zurückgegeben
*/

/*
    gleiches Objekt -> keine Aktion
*/
	if (!list_size) return false;

/*
	Der Wert des letzten Knotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(value) darf nicht zum löschen benutzt werden.
*/
   
        value = head_tail->prev->value;

        Node *tmp = head_tail->prev;
        tmp->prev->next = head_tail;
        head_tail->prev = tmp->prev;

        delete tmp;

        list_size--;
        return true;
}

bool List::del(int value)
{
 
//  TODO :Loeschen eines gegebenen Knotens mit dem Wert = Value.Im Fehlerfall wird false zurückgegeben


/*
    gleiches Objekt -> keine Aktion
*/
	if (!list_size) return false;


    Node* current = head_tail->next;

    while (current != head_tail)
    {
        if (current->value == value) 
        {
            
            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;

            list_size--;
            return true;
        }
        current = current->next;
    }
    return false;

}

bool List::search(int value)
{
    

//  TODO: suchen eines Knotens nicht gefunden -> Rueckgabe: false


/*
    leere Liste -> keine Aktion
*/
	if (!list_size) return false; 


    Node* current = head_tail->next;
    while (current != head_tail) 
    {
        if (current->value == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool List::swap(int value1, int value2)
{
    
/*  
    TODO: Vertauschen von zwei Knoten Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.im Fehlerfall wird false zurueckgegeben  
    Vertauschen von zwei Knoten mit dem Wert value1 und dem Wert value2.Es duerfen nicht nur einfach die Werte in den Knoten getauscht werden!
    Die Knoten sind in der Kette umzuhaengen.
*/

/*
    Wenn Liste Leer oder weniger als 2 Knoten besitzt -> Keine Aktion
*/
	if (list_size < 2) return false; 


    if (list_size > 1) {
        Node* NodeV1 = head_tail->next;
        Node* NodeV2 = head_tail->next;

        // Traviersiert die Liste um Node mit Value1 und Node mit Value2 zu finden.
        while (NodeV1 != head_tail) 
        { 
            if (NodeV1->value == value1) break;
            NodeV1 = NodeV1->next;
        }
        while (NodeV2 != head_tail) 
        {  
            if (NodeV2->value == value2) break;
            NodeV2 = NodeV2->next;
        }

        /* 
        *  Liste im Start zustand:  4-9-7-5-3-2-4-1
        *  1. Swap: (7,2) -> Liste nach Swap : 4-9-2-5-3-7-4-1   
        *  2. Swap: (4,5) -> Liste nach Swap : 5-9-2-4-3-7-4-1   -> 1. Parameter 4 ist head->next , 2.Parameter Mitte
        *  3. Swap: (1,3) -> Liste nach Swap : 5-9-2-4-1-7-4-3   -> 1. Parameter 1 ist head->prev , 2.Parameter 3 Mitte
        *  4. Swap: (4,2) -> Liste nach Swap : 5-9-4-2-1-7-4-3
        */

        // Fall 1: Zwei Knoten aus der Mitte, nicht nebeneinander
        if ((NodeV1->prev != head_tail && NodeV1->next != head_tail) && (NodeV2->prev != head_tail && NodeV2->next != head_tail) && (NodeV1->next != NodeV2 && NodeV2->prev != NodeV1)) 
        {
            Node* save_connection_prev = NodeV1->prev;
            Node* save_connection_next = NodeV1->next;

            NodeV1->prev->next = NodeV2;
            NodeV1->next->prev = NodeV2;

            NodeV2->prev->next = NodeV1;
            NodeV2->next->prev = NodeV1;

            NodeV1->next = NodeV2->next;
            NodeV1->prev = NodeV2->prev;

            NodeV2->next = save_connection_next;
            NodeV2->prev = save_connection_prev;
            return true;
        }
        //Fall 2: Erster Knoten mit einem aus der Mitte, nicht nebeneinander
        else if (NodeV1->prev == head_tail && NodeV2->next != head_tail)
        {

            Node* save_connection_prev = NodeV2->prev;
            Node* save_connection_next = NodeV2->next;

            NodeV2->next->prev = NodeV1;
            NodeV2->prev->next = NodeV1;

            NodeV1->next->prev = NodeV2;
            NodeV2->next = NodeV1->next;

            NodeV1->next = save_connection_next;
            NodeV1->prev = save_connection_prev;

            head_tail->next = NodeV2;
            NodeV2->prev = head_tail;
            return true;
        }
        // Fall 3: Letzter Knoten mit einem aus der Mitte, nicht nebeneinander
        else if (NodeV1->next == head_tail && NodeV2->prev != head_tail)
        {
            Node* save_connection_prev = NodeV2->prev;
            Node* save_connection_next = NodeV2->next;

            NodeV2->next->prev = NodeV1;
            NodeV2->prev->next = NodeV1;

            NodeV1->prev->next = NodeV2;
            NodeV2->prev = NodeV1->prev;

            NodeV1->next = save_connection_next;
            NodeV1->prev = save_connection_prev;

            head_tail->prev = NodeV2;
            NodeV2->next = head_tail;
            return true;
        }
        //Fall 4: Zwei Knoten aus der Mitte, nebeneinander
        else if (NodeV1->next == NodeV2 && NodeV2->prev == NodeV1)
        {
           
            NodeV2->next = NodeV1->next;
            NodeV1->prev = NodeV2->prev;
            NodeV2->prev->next = NodeV1;
            NodeV1->next->prev = NodeV2;

            NodeV2->prev = NodeV1;
            NodeV1->next = NodeV2;
            return true;
        }
        
    }
    return false;
}

int List::size(void)
{
    //ToDo
/*  
    Rueckgabe der Anzahl der Knoten in der Liste mit O(1)
    d.h. die Liste darf NICHT traversiert werden um die Größe zu bestimmen.

	Anzahl der Knoten in der Liste zurückgeben.
    Hier richtiges Ergebnis zurückgeben
*/
    if (list_size > 0)return list_size;
	return 0;	
}

bool List::test(void)
{
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und
    // zurück Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
    // der Knoten überein liefert die Methode true
    Node* tmp    = head_tail->next;
    int   i_next = 0, i_prev = 0;
    while (tmp != head_tail)
    {
        tmp = tmp->next;
        if (i_next > list_size)
            return false;
        i_next++;
    }
    if (i_next != list_size)
        return false;
    tmp = head_tail->prev;
    while (tmp != head_tail)
    {
        tmp = tmp->prev;
        if (i_prev > list_size)
            return false;
        i_prev++;
    }
    return i_prev == i_next;
}

List& List::operator=(const List& _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen. Kopiert wird in das Objekt "this"
    if (this == &_List)
        return *this; //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node* tmp_node;
    if (list_size)
    {
        Node* tmp_del;
        tmp_node = head_tail->next;
        while (tmp_node !=
               head_tail) // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del  = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        list_size       = 0;
        head_tail->next = head_tail;
        head_tail->prev = head_tail;
    }
    tmp_node = _List.head_tail->next; // Die Listen-Knotenwerte werden kopiert
    while (tmp_node != _List.head_tail)
    {
        insertBack(tmp_node->value);
        tmp_node = tmp_node->next;
    }
    if (_List.temp)
        delete &_List; // ist die übergebene Liste eine temporäre Liste? -> aus
                       // Operator +
    return *this;
}

List& List::operator+(const List& List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue
    // Ergebnisliste.
    Node* tmp_node;
    List* tmp;
    if (temp)
    { // this ist eine temporäre Liste und kann verändert werden
        tmp = this;
    }
    else
    {
        tmp =
            new List(*this); // this ist keine temporäre Liste -> Kopie erzeugen
        tmp->temp = true;    // Merker setzten, dass es sich um eine temporäre
                             // Liste handelt
    }
    if (List_Append.list_size)
    { // anhängen der übergebenen Liste an tmp
        tmp_node = List_Append.head_tail->next;
        while (tmp_node != List_Append.head_tail)
        {
            tmp->insertBack(tmp_node->value);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append.temp)
        delete &List_Append; // wurde eine temporäre Liste übergeben, dann wird
                             // diese gelöscht
    return *tmp;
}

void List::format(const std::string& start,
                  const std::string& zwischen,
                  const std::string& ende)
{
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start    = start;
    list_form.zwischen = zwischen;
    list_form.ende     = ende;
}

std::ostream& operator<<(std::ostream& stream, List const& Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node* tmp = Liste.head_tail->next; tmp != Liste.head_tail;
         tmp       = tmp->next)
        stream << tmp->value
               << (tmp->next == Liste.head_tail ? Liste.list_form.ende :
                                                  Liste.list_form.zwischen);
    if (Liste.temp)
        delete &Liste; // wurde eine temporäre Liste übergeben, dann wird diese
                       // gelöscht
    return stream;
}
