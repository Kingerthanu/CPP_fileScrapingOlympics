# CPP_fileScrapingOlympics
  Assignment tests knowledge of hash tables and its functions. It also tests on file parsing. Each country will have its own DataEntry stored in a container which will be our hash table using seperate chaining as our collision resolution. We have a hash function which will count the ASCII value of each character in the country's name and multiply it by its position in the string and modulus it by 17 (or this->olympicTally.size() should always be 17 in this assignment). We will have 4 main functions in the MedalsDB class which will be our hash table class: add, remove, parseDoc, and search. The DataEntry will hold: country name, year counted up to, gold medals, silver medals, and bronze medals. This assignment will work to introduce a rehashing function which will double the tables size, and find the next prime number after this resizing and will insert the given elements.
  
![giph](https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/f5aedb7b-a9a7-4e18-913d-6d759b566280)

<img width="779" alt="image" src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/1f953ee5-86fc-4b18-bd53-e7a9edeb41e2">
