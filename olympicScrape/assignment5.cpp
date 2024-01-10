// Benjamin R Spitzauer
// assignment5.cpp
// 3/13/2023

/*

  Purpose: Assignment tests knowledge of hash tables and its functions.
  It also tests on file parsing. Each country will have its own DataEntry
  stored in a container which will be our hash table using seperate
  chaining as our collision resolution. We have a hash function which will
  count the ASCII value of each character in the country's name and 
  multiply it by its position in the string and modulus it by 17
  (or this->olympicTally.size() should always be 17 in this assignment).
  We will have 4 main functions in the MedalsDB class which will be our
  hash table class: add, remove, parseDoc, and search. The DataEntry will
  hold: country name, year counted up to, gold medals, silver medals,
  and bronze medals. This assignment will work to introduce a rehashing
  function which will double the tables size, and find the next prime number
  after this resizing and will insert the given elements.

*/

#include <vector> 
#include <string> 
#include <fstream>
#include <sstream>
#include <iostream> 

using namespace std; 


// ~~~~~~~~~~~~~~~~~~~~~Prototypes~~~~~~~~~~~~~~~~~~~~~
  
  /*

    Pre-Condition: Implicit Constructor; needs no arguments.

    Post-Condition: Will create a data type to contain the state of a olympic
    team and their total medal count for each genre; followed by the year this
    is up to.

  */
  class DataEntry;

  /*

    Pre-Condition: None; constructor will initialize vector<vector<DataEntry*>>
    of size 17.

    Post-Condition: Calls main functions of ShelterBST in order to make sure
    it behaves correctly when empty, or only with one element. Shouldn't
    throw any errors from accession of memory not given to itself.

  */
  class MedalsDB;

// ~~~~~~~~~~~~~~~~~END Prototypes~~~~~~~~~~~~~~~~~~~~~



class DataEntry
{
 private:
  int year; // up to this year
  string country;
  int gold; //total gold medal count for country
  int silver; //total silver medal count for country
  int bronze; //total bronze medal count for country

 public:

    /*

      Pre-Condition: Needs references to two DataEntry's. The first one will
      be the DataEntry to have the other's data added into.

      Post-Condition: Will return a reference to the first DataEntry in order
      to update first's members.

    */
    DataEntry* operator+(DataEntry& other)
    {

      this->gold += other.gold;
      this->silver += other.silver;
      this->bronze += other.bronze;
      this->year = other.year;

      return this;

    };


    /*

      Pre-Condition: A string called newName to set to this->country.
      Post-Condition: Will set this->country as newName.

    */
    void setCountry(string newName)
    {
      this->country = newName;
    };


    /*

      Pre-Condition: A int called newYear to set to this->year.
      Post-Condition: Will set this->year as newYear.

    */
    void setYear(int newYear)
    {
      this->year = newYear;
    };


    /*

      Pre-Condition: A int called newGold to set to this->gold.
      Post-Condition: Will set this->gold as newGold.

    */
    void setGold(int newGold)
    {
      this->gold = newGold;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will increment this->gold by 1.

    */
    void addGold()
    {
      this->gold++;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will increment this->silver by 1.

    */
    void addSilver()
    {
      this->silver++;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will increment this->bronze by 1.

    */
    void addBronze()
    {
      this->bronze++;
    };


    /*

      Pre-Condition: A int called newSilver to set to this->silver.
      Post-Condition: Will set this->silver as newSilver.

    */
    void setSilver(int newSilver)
    {
      this->silver = newSilver;
    };


    /*

      Pre-Condition: A int called newBronze to set to this->bronze.
      Post-Condition: Will set this->bronze as newBronze.

    */
    void setBronze(int newBronze)
    {
      this->bronze = newBronze;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will return this->year.

    */
    int getYear()
    {
      return this->year;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will return this->gold.

    */
    int getGold()
    {
      return this->gold;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will return this->silver.

    */
    int getSilver()
    {
      return this->silver;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will return this->bronze.

    */
    int getBronze()
    {
      return this->bronze;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will return this->country.

    */
    string getCountry()
    {
      return this->country;
    };


    /*

      Pre-Condition: None.
      Post-Condition: Will print members of DataEntry.

    */
    void displayContent()
    {
      cout << this->year << ", "
      << this->country << ", "
      << this->gold << ", "
      << this->silver << ", "
      << this->bronze << '\n';
    }

};


class MedalsDB
{

  private:

    // Hash Table
    vector<vector<DataEntry*>> olympicTally;


    /*

      Pre-Condition: None.

      Post-Condition: Will access SummerOlympics1896-2012.csv and read its
      contents. Each country entry will be then read, and sifted for the main
      descriptors of it's entry year, the country, and which medal they won
      (gold, silver, bronze). These are then hashed into olympicTally through
      this->add(DataEntry*).

    */
    void parseDoc()
    {

      ifstream olympicChart("SummerOlympics1896-2012.csv"); // Doc to parse

      string line;
      DataEntry* tmp = nullptr; // Holds current olympic candidate

      // Skip first
      getline(olympicChart, line, '\n');            


      // Get country entry until no more
      while(getline(olympicChart, line, '\n')){

        istringstream lineContent(line);

        int counter = 0; // What part of entry we're looking at

        tmp = new DataEntry();

        for(string i; getline(lineContent, i, ','); ){
          switch(counter){
            case 0: // Year
              tmp->setYear(stoi(i));
              break;
            case 6: // Location 
              tmp->setCountry(i);
              break;
            case 9: // Medal; silver, gold, bronze
              
              if(i[0] == 'B'){
                tmp->addBronze();
              }
              else if(i[0] == 'S'){
                tmp->addSilver();
              }
              else if(i[0] == 'G'){
                tmp->addGold();
              }

              counter = 0;
              continue;

          }

          counter++;

        }
        
        // Add to vector
        add(tmp);

      }

    };
  

    /*

      Pre-Condition: Name of country to look for in olympicTally.

      Post-Condition: Will return a pointer to the address of the stored
      country in this->olympicTally. If it's not inside the vector(s),
      return nullptr.

    */
    DataEntry* search(string countryName)
    {

      int index = hash(countryName);

      for(int i = 0; i < (int)this->olympicTally[index].size(); i++){

        if(this->olympicTally[index][i]->getCountry() == countryName){
          return this->olympicTally[index][i];

        }

      }

      return nullptr;

    };


    /*

      Pre-Condition: DataEntry* olympicCandidate to be added to olympicTally.

      Post-Condition: Will add olympicCandidate if it's country name is not
      already in the hash table. If it is, then if olympicCandidate's year
      is < current stored year for that country return false. Else, add 
      together the medal count of olympicCandidate to the current stored
      DataEntry and update the year of current stored to olympicCandidate's.
      Return true if added.

    */
    bool add(DataEntry* olympicCandidate)
    {

      DataEntry* query = this->search(olympicCandidate->getCountry());

      if(!query){ // Not inside hash table

        this->olympicTally[hash(olympicCandidate->getCountry())].push_back
        (olympicCandidate);

      }
      else{

        // New entry older than current
        if(olympicCandidate->getYear() < query->getYear()){ 

          delete olympicCandidate;
          return false;

        }

        (*query) + (*olympicCandidate); // Add together values into query

        delete olympicCandidate; // Free as values are now in query

      }

      return true;

    };


    /*

      Pre-Condition: Country name to remove from olympicTally.
      Post-Condition: If not inside tally, return false. Else,
      remove it and return true.

    */
    bool remove(string countryName)
    {
    
      DataEntry* entry = this->search(countryName);
      
      
      if(!entry){ // If not in hash table
        
        return false;

      }

      int hashIndex = hash(countryName);

      for(int i = 0; i < (int)this->olympicTally[hashIndex].size(); i++){

        if(this->olympicTally[hashIndex][i]->getCountry() == countryName){

          this->olympicTally[hashIndex].erase
          (this->olympicTally[hashIndex].begin()+i);

          delete entry; // erase won't dealloc.

          return true;

        }

      }

      return false;

    };


    /*

      Pre-Condition: Name of country to hash index from.

      Post-Condition: Will add ASCII code of all chararcters in country
      multiplied by their occuring index (1-based). This sum will then
      be bounded by modulo olympicTally.size() (should be 17) and
      returned.

    */
    int hash(string country)
    {

        int sum = 0;
        int step = 1;

        for(char let : country){
          sum += (step * (int)let);
          step++;

        }

        // Now Set in bound of array and return
        return sum % (olympicTally.size());
    
    };


    /*

      Pre-Condition: Number to check if prime.

      Post-Condition: Returns true if this number is prime else false.

    */
    bool checkPrime(int num)
    {

      // Case is 1 or 0 we don't look for
      if(num <= 1) return false;

      for(int j = 2; j <= num/2; j++){ // n / 2 is only possible cases needed
        if(num % j == 0) return false; // Is not prime
      }
    
      return true; // If no modulo is found, then it's prime

    }


    /*

      Pre-Condition: Number to find next prime for.

      Post-Condition: Will return next prime number greater than i.

    */
    int getNextPrime(int i)
    {
      // Increment up one to make sure we get next prime if is already prime
      i++; 
      
      while(!checkPrime(i)){
        i++; // keep counting till find next prime
      }

      return i;

    }


    /*

      Pre-Condition: None.

      Post-Condition: Will double and find next prime number for hash table size
      and add each element from the original hash table in this new one with the
      new size.

    */
    void rehash()
    {

      // Contains old vector to copy data of
      vector<vector<DataEntry*>> newVector = this->olympicTally;

      // Grab next prime
      olympicTally = vector<vector<DataEntry*>>(getNextPrime(olympicTally.size()*2));

      // Grab each element and add its value to new vector size
      for(int i = 0; i < (int)newVector.size(); i++){
      
        for(int j = 0; j < (int)newVector[i].size(); j++){

          this->add(newVector[i][j]); // Insert current
          
        }

      }

    }

  public:

    /*

      Pre-Condition: None.
      Post-Condition: Initilizes olympicTally's outside container to size 17.

    */
    MedalsDB()
    {

      olympicTally = vector<vector<DataEntry*>>(17);

    };


    /*

      Pre-Condition: None.
      Post-Condition: Allows user to call rehash on this->olympicTally.

    */
    void callRehash()
    {
    
      this->rehash();
    
    }


    /*

      Pre-Condition: None.
      Post-Condition: Calls private function this->parseDoc() for user.

    */
    void runParse()
    {

      this->parseDoc();

    };


    /*

      Pre-Condition: None.

      Post-Condition: Asks user 6 options either to initialize the olympicTally
      hash table with values stored in SummerOlympics1896-2012.csv. Or add a
      new DataEntry* with user given data; get a DataEntry* stored in 
      olympicTally using a country name; remove a DataEntry* from olympicTally
      using country name; display contents of olympicTally; and finally a exit.
      The function will always return true if the user doesn't specifically
      tell it to stop, then it will return false.

    */
    bool request()
    {

      int userResponse;

      std::cout << "\nWelcome to the Olympic Counter Hash Table,"
      << " What would you like to do?\n"
      << "1. Create the initial hash table\n"
      << "2. Add a new data entry\n"
      << "3. Get a data entry\n"
      << "4. Remove a data entry\n"
      << "5. Display hash table\n"
      << "6. Rehash Table\n"
      << "7. Exit\n"
      << "Reponse (1-6): ";

      std::cin >> userResponse;

      switch(userResponse){

        /*
        
          Must have case in its own scope with variable declarations
          as switch is compiled as single scope and will jump
          declarations which are considered local.

        */
        case 1:
          this->parseDoc();
          break;

        case 2:
        { 
          DataEntry* tmp = new DataEntry();
          int b, g, s;

          std::string countryName;
          std::cout << "Whats the Country? ";
          std::cin >> countryName;
          tmp->setCountry(countryName);

          std::cout << "Whats the Year of the Olympic medal? ";
          std::cin >> userResponse;
          tmp->setYear(userResponse);

          std::cout << "Whats the Medal count (Gold, Silver, Bronze)? ";
          std::cin >> g >> s >> b;

          tmp->setGold(g);
          tmp->setSilver(s);
          tmp->setBronze(b);
        

          this->add(tmp);
          break;

        }

        case 3:
        {
        
          std::string countryName;

          std::cout << "Whats the Country? ";
          std::cin >> countryName;
          
          // Pointer to country in table
          DataEntry* countryEntry = this->search(countryName);

          if(countryEntry){
            countryEntry->displayContent();
          }
          else{
            cout << "Sorry there's no country with that name in the table.\n";
          }

          break;
        
        }  

        case 4:
        {
        
          std::string countryName;
          std::cout << "Whats the Country? ";
          std::cin >> countryName;

          cout << (this->remove(countryName) == 1 ? "Removed!" :
          (countryName + " is not in hash table.")) << endl;

          break;

        }   

        case 5:
          this->display();
          break;

        case 6:
          this->rehash();
          break;

        case 7:
          cout << "\n\n"; // Clear from sys prompts
          return false; // Exit
      }


      return true;

    };    


    /*

      Pre-Condition: None.
      Post-Condition: Will print the contents of olympicTally to user, showing
      what corresponds to each chain.

    */
    void display()
    {
    
      cout << "\nDisplaying Countries in Hash Table: \n";

      for(int i = 0; i < (int)this->olympicTally.size(); i++){
        
        cout << "\nDisplaying Chained Link in Index " << i << ":\n";

        for(DataEntry* entry : this->olympicTally[i]){
          entry->displayContent();
        }

        cout << "\nDone with row " << i << ".\n";

      }      

      

    };

    /*

      Pre-Condition: Deconstructor called.
      Post-Condition: Will deallocate any remaining DataEntry*(s) from
      olympicTally.

    */
    ~MedalsDB()
    {

      DataEntry* tmp = nullptr;    

      for(int i = 0; i < (int)this->olympicTally.size(); i++){
      
        while(this->olympicTally[i].size() != 0){

          tmp = this->olympicTally[i][this->olympicTally[i].size()-1];
          this->olympicTally[i].pop_back();
          delete tmp;

        }

      }
    
    };

};



int main()
{

  MedalsDB chart;

  bool loopFlag = true;

  while(loopFlag){

    loopFlag = chart.request();

  }

}