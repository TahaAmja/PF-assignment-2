# PF-assignment-2
# BAI-1A
# 24K-0007
# Taha Amjad
# Q1: for this problem i consider another min2 and aplly condition (if(arr[m]<min2 && arr[m]!=min)
min2=arr[m];) to find second largest 
# ![Screenshot (1)](https://github.com/user-attachments/assets/ed678c04-2fb6-4d6b-8278-ba59bf0f3523)

# Q2:Explanation:
analyzeCharacterFrequency takes an array of slogans and counts the frequency of each character for each slogan.
We use an array freq to store character counts, where each index corresponds to an ASCII character.
The first loop iterates over each slogan, and the second loop counts characters for that slogan.
# ![Screenshot (2)](https://github.com/user-attachments/assets/f4a50602-dd5b-4af8-8421-0e1d95522b8a)
# Q3:Explanation
compressWord: This function compresses a single word by removing consecutive duplicate characters. It builds the compressed version of the word in compressedWord and returns the number of removed characters.compressWords: This function processes an array of words by calling compressWord for each word, storing each compressed word in compressedWords and keeping track of the total number of removed characters.Sets up an array of words, calls compressWords, and prints the compressed words and the total number of characters removed.
# ![Screenshot (3)](https://github.com/user-attachments/assets/10bdac8b-3ea3-4170-96f7-fc92e0757690)
# Q4:![Screenshot (4)](https://github.com/user-attachments/assets/cbc725df-164e-4823-9ddd-20d28b590167)
#Explanation
sortString: Sorts characters within a string, which helps us recognize anagrams by producing the same sorted result for each set of anagrams.
areAnagrams: Checks if two strings are anagrams by sorting and comparing them.
groupScrambledTransactions: Groups transactions by iterating through the list and finding all anagrams for each ungrouped transaction. It marks transactions as grouped to avoid reprocessing.
# Q5:![Screenshot (5)](https://github.com/user-attachments/assets/c79a5efc-6ea7-4706-8296-542713fb3919)
# Input Handling: The input_handling function simply prints the input values for demonstration purposes.
Horizontal Histogram: The horizontal_histogram function iterates through the values and prints a corresponding number of asterisks for each value.Vertical Histogram: The vertical_histogram function first determines the maximum value and then prints asterisks in a vertical format. It includes a base that shows the values.
# Q6:![Screenshot (6)](https://github.com/user-attachments/assets/2266b292-cf78-4a2b-ae87-d752720d9cdc)
#Explanation:
Game Logic: The game has a periodic structure, where every group of 5 matchsticks is a losing position for the player who has to play. If the total number of matchsticks is a multiple of 5, then the player cannot guarantee a win if both play optimally.Functionality:The matchsticks_to_pick function checks the number of matchsticks 𝑁 If N is a multiple of 5, it returns -1, indicating that A cannot guarantee a win.If not, it calculates N%5, which gives the optimal number of matchsticks A should pick to force the opponent into a losing position.User Input: The main function prompts the user to enter the number of matchsticks, then calls the matchsticks_to_pick function and outputs the result.
# Q7:
