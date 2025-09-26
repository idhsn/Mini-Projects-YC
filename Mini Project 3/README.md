# 🤖 Mini-Project 3: Chatbot with Sentiment Analysis and Multiple Responses

This C project creates an intelligent chatbot capable of recognizing keywords, detecting sentiment, and providing multiple responses.  

---

## 📌 Description

The chatbot can:  

1. Recognize multiple keywords in the same sentence.  
2. Give different responses based on detected tone (positive / negative / neutral).  
3. Provide a random response among multiple options for the same keyword.  
4. Store the history of questions and answers (array of strings).  

---

## 🔧 Features to Implement

1. Store positive, negative, and neutral keywords.  
2. Store multiple possible responses for each keyword.  
3. Prompt the user to enter a sentence.  
4. Analyze the sentence to detect keywords and select an appropriate response.  
5. Display a random response among possible responses for the detected keyword.  
6. Keep a history of questions and answers and display it if the user requests.  
7. Exit the chatbot if the user types `"exit"`.

---

## 🔹 Example Interaction

You: Hello, I am feeling happy

Bot: Hi! Great to hear that! 😊

You: I am sad today

Bot: Oh no! Hope things get better soon.

You: Can you help me?

Bot: Sure! What do you want to talk about?

You: show history

Bot:
1) You: Hello, I am feeling happy -> Bot: Hi! Great to hear that! 😊
2) You: I am sad today -> Bot: Oh no! Hope things get better soon.

You: exit

Bot: Goodbye!

---

## 💡 Tips & Notes  
- Run **Borland C** in compatibility mode if needed.  
- Keep file paths simple to avoid compile errors.  
- **trig(.h):** This project include a header file (`.h`). Make sure to include it in your editor or IDE so the compiler can locate it correctly.

