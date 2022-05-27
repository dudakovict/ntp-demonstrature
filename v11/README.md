# Predlošci funkcija i klasa

Napravite generičku strukturu ili klasu **stack** koja će se moći upotrebljavati kako je prikazano u kodu ispod.

```c++
stack<int> stogIntova;
stack<string> stogStringova;

stogIntova.push(3);
stogStringova.push("abc");

int a = stogIntova.top();
string b = stogStringova.top();

stogIntova.pop();

cout << "broj clanova: " << stogIntova.size() << endl;
```