# 🎮 Mini-Project: Character Guessing Game

This C project creates a small game where the player must guess the letters of a hidden word.  

---

## 📝 Description

- The secret word is stored in a character array.  
- The player inputs letters one by one, and the program reveals them if they are present in the word.  
- The game continues until the player finds all letters.  

**Bonus challenge:** Add a limited number of attempts. If the player makes too many mistakes, the game ends with a "Game Over" message.  

---

## 🛠️ Features to Implement

1. **Secret Word Storage**  
   - Store a fixed word in a character array, e.g., `"hello"`.  
   - Create another array (same size) filled with `_` to represent the hidden word.

2. **Display Hidden Word**  
   - At the beginning, display the hidden word as underscores: `_ _ _ _ _`.

3. **Letter Input**  
   - Prompt the user to input a letter.

4. **Letter Verification**  
   - If the guessed letter is in the word, reveal it in the hidden word.  
   - Otherwise, display a message indicating a wrong guess.

5. **Victory Condition**  
   - If the player guesses all letters, display a victory message.

6. **Bonus: Limited Attempts**  
   - Set a maximum number of incorrect attempts.  
   - Decrease the counter after each wrong guess.  
   - If the counter reaches 0, end the game with `"Game Over"`.
