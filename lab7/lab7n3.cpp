#include <iostream>
#include <vector>
#include <string>
#include <cctype> // Для tolower()

using namespace std;

int main() {
    string message;
    char targetLetter;
    
    // Ввод сообщения
    cout << "Введите сообщение (заканчивается точкой): ";
    getline(cin, message, '.'); // Читаем до точки
    
    // Ввод искомой буквы
    cout << "Введите букву для поиска: ";
    cin >> targetLetter;
    targetLetter = tolower(targetLetter); // Приводим к нижнему регистру
    
    vector<string> matchingWords; //подходящие слова
    string currentWord; // Текущее обрабатываемое слово
    bool inWord = false;
    
    // Проходим по всем символам сообщения
    for (char ch : message) {
        if (isalpha(ch)) { // Если символ - буква
            if (!inWord) { // Если до этого не были в слове
                inWord = true;
                currentWord.clear(); // Начинаем новое слово
            }
            currentWord += tolower(ch); // Добавляем букву в слово
        } else { 
            if (inWord) { 
                // Проверяем, начинается и заканчивается ли слово на нужную букву
                if (currentWord.size() >= 1 && 
                    currentWord[0] == targetLetter && 
                    currentWord.back() == targetLetter) {
                    matchingWords.push_back(currentWord); // Добавляем подходящее слово
                }
                inWord = false;
            }
        }
    }
    
    // Проверяем последнее слово
    if (inWord && currentWord.size() >= 1 && 
        currentWord[0] == targetLetter && 
        currentWord.back() == targetLetter) {
        matchingWords.push_back(currentWord);
    }
    
    // Вывод результатов
    cout << "\nСлова, начинающиеся и заканчивающиеся на '" << targetLetter << "':" << endl;
    for (const string& word : matchingWords) {
        cout << word << endl;
    }
    
    return 0;
}