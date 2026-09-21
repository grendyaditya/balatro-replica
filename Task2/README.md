# Task 2 — Develop Your Own Core Loop

## A. Game Concept

Game yang digunakan dalam tugas ini adalah **Type 'n Smash**, yaitu game typing combat dengan tema belajar syntax Python. Pemain harus menyelesaikan snippet Python untuk menyerang musuh. Implementasi pada tugas ini dibuat dalam bentuk simulasi sederhana menggunakan C++.

Game menggunakan sistem **Best of 3**, sehingga pemain yang memenangkan 2 ronde terlebih dahulu akan memenangkan pertandingan.

Struktur file program:

```text
Task 2/
├── SnippetGenerator/
│   ├── SnippetGenerator.h
│   └── SnippetGenerator.cpp
├── TypingSystem/
│   ├── TypingSystem.h
│   └── TypingSystem.cpp
├── DamageRule/
│   ├── DamageRule.h
│   └── DamageRule.cpp
├── GameSession/
│   ├── GameSession.h
│   └── GameSession.cpp
├── main.cpp
└── README.md
```

## B. Core Loop

Core loop yang digunakan dalam Type 'n Smash adalah:

```text
Generate Snippet
      ↓
Simulate Typing
      ↓
Check Result
      ↓
Calculate Damage
      ↓
Update HP
      ↓
Check Round
      ↓
Next Turn
```

Core loop tersebut berjalan berulang selama HP pemain atau musuh masih tersedia. Setelah satu ronde selesai, sistem mengecek hasil ronde dan melanjutkan ke ronde berikutnya sampai salah satu pemain mendapatkan 2 kemenangan.

## C. Invariant Structure

Invariant utama dalam program adalah **urutan core loop** di dalam `GameSession`.

`GameSession` bertugas mengatur jalannya permainan, tetapi tidak menentukan bagaimana snippet dibuat, bagaimana typing diproses, atau berapa damage yang diberikan.

Urutan utama tetap:

1. Generate Snippet
2. Simulate Typing
3. Check Result
4. Calculate Damage
5. Update HP
6. Check Round
7. Advance

Struktur ini tetap digunakan meskipun behavior dari bagian tertentu diubah.

## D. Mutable Parts

Beberapa bagian yang dapat diubah tanpa mengubah struktur utama adalah:

* **SnippetGenerator** — menentukan snippet yang muncul.
* **TypingSystem** — menentukan bagaimana hasil typing diperoleh.
* **DamageRule** — menentukan jumlah damage yang diberikan.
* **GameSession** — tetap menjadi pengatur alur, sedangkan detail behavior berada di class lain.

Contohnya, `SimpleDamageRule` dapat diganti dengan rule yang memiliki combo atau damage yang berbeda tanpa harus mengubah urutan core loop.

## E. Implementation

Program menggunakan beberapa interface agar behavior dapat dipisahkan dari core loop:

```text
ISnippetGenerator
        ↓
SimpleSnippetGenerator

ITypingSystem
        ↓
AutomaticTypingSystem

IDamageRule
        ↓
SimpleDamageRule
```

`GameSession` menggunakan interface tersebut sehingga tidak bergantung langsung pada implementasi tertentu.

Program juga menggunakan simulasi otomatis agar fokus tugas tetap pada core loop, bukan pada pembuatan gameplay secara lengkap.

## F. Reflection

Dalam tugas ini, saya belajar bahwa core loop tidak harus berisi semua logic dari sebuah game. Pada Type 'n Smash, `GameSession` hanya bertanggung jawab mengatur urutan proses permainan. Detail seperti membuat snippet, menentukan hasil typing, dan menghitung damage dipisahkan ke class masing-masing.

Bagian yang paling penting sebagai invariant adalah urutan core loop. Snippet harus dibuat terlebih dahulu, kemudian typing diproses, hasilnya diperiksa, damage dihitung, HP diperbarui, dan setelah itu sistem mengecek apakah ronde sudah selesai. Urutan tersebut menjadi struktur utama permainan.

Sementara itu, behavior seperti generator snippet, sistem typing, dan damage rule merupakan bagian yang mutable. Behavior tersebut dapat diganti tanpa harus mengubah struktur utama `GameSession`. Misalnya, sistem damage dapat dikembangkan menjadi sistem combo atau memberikan damage yang berbeda berdasarkan hasil typing.

Menurut saya, pemisahan ini membuat program lebih mudah dikembangkan. Jika semua logic dimasukkan langsung ke `GameSession`, perubahan kecil pada satu behavior dapat membuat class tersebut ikut banyak berubah. Dengan memisahkan behavior ke class masing-masing, `GameSession` tetap fokus pada tugasnya sebagai pengatur core loop.
