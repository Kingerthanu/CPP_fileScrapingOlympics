# CPP_fileScrapingOlympics
  Assignment tests knowledge of hash tables and its functions. It also tests on file parsing. Each country will have its own DataEntry stored in a container which will be our hash table using seperate chaining as our collision resolution. We have a hash function which will count the ASCII value of each character in the country's name and multiply it by its position in the string and modulus it by 17 (or this->olympicTally.size() should always be 17 in this assignment). We will have 4 main functions in the MedalsDB class which will be our hash table class: add, remove, parseDoc, and search. The DataEntry will hold: country name, year counted up to, gold medals, silver medals, and bronze medals. 
  
  <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/8d7df191-b013-4161-8131-b440c37c3ee4" alt="Cornstarch <3" width="105" height="159">


  This assignment will work to introduce a rehashing function which will double the tables size, and find the next prime number after this resizing and will insert the given elements.


----------------------------------------------
<img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/062cd5ad-92eb-482e-947d-d6592a77f0a3" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/062cd5ad-92eb-482e-947d-d6592a77f0a3" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/062cd5ad-92eb-482e-947d-d6592a77f0a3" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/062cd5ad-92eb-482e-947d-d6592a77f0a3" alt="Cornstarch <3" width="55" height="49">





**The Breakdown:**

  This Program Takes In A .txt File Including Olympic Winning Information And Uses It To Parse And Count Up The Amount Of Medals From Each Line.

  The Program Utilizes A Defined DataEntry Class In Which Will Represent A Countires Current Year Total For Its Gold, Silver, And Bronze Count. 

  When The Program Starts, We Will Initialize A Instance Of Our DataBase Class In Which Will Call Its Request Function In Which Will Ask The User For Continual Input Until They Say To Leave.

  The User Can Read In From Our .txt Filr And From The Parsed Document We Will Interpret New Country Names In A Given Mapped Data Structure To Include Only Unique Countries.

  We Can Also Add Ontop Of This New Entries Through The request Function With Our Add Function. This Allows Us To Have A Interface Where We Can Add Even More Entries, Or Even Update New Entries On The Fly During Runtime.

This Program Was Very Interesting And Allowed Me To See New Ways Of Parsing Documents In C++. Also Through This Project I Learned Proper Encapsulation By Making Sure The Main Function Is Calling A Method Of The Class Instead Of Doing It Itself In Main Which Can Ensure Modularity As Well As Just Being Easier To Follow Along With. Also Using External Flags Was Interesting As Also Showed Me Ways Of Using Classes To Change External States Like Our loopFlag.
  






<img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/40008094-f365-4afe-838c-7415fd8f07d8" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/40008094-f365-4afe-838c-7415fd8f07d8" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/40008094-f365-4afe-838c-7415fd8f07d8" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/40008094-f365-4afe-838c-7415fd8f07d8" alt="Cornstarch <3" width="55" height="49">


----------------------------------------------

<img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/b96ebf69-25be-4490-8619-bff54c50abda" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/b96ebf69-25be-4490-8619-bff54c50abda" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/b96ebf69-25be-4490-8619-bff54c50abda" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/b96ebf69-25be-4490-8619-bff54c50abda" alt="Cornstarch <3" width="55" height="49">



**Features:**
  
![giph](https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/f5aedb7b-a9a7-4e18-913d-6d759b566280)

<img width="779" alt="image" src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/1f953ee5-86fc-4b18-bd53-e7a9edeb41e2">



<img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/f9aceb34-6e6b-43e9-a6ca-28233b3a0d05" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/f9aceb34-6e6b-43e9-a6ca-28233b3a0d05" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/f9aceb34-6e6b-43e9-a6ca-28233b3a0d05" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_fileScrapingOlympics/assets/76754592/f9aceb34-6e6b-43e9-a6ca-28233b3a0d05" alt="Cornstarch <3" width="55" height="49">

