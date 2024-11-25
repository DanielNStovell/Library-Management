#include <iostream>

class BOOK {
  public:
    char id[10];
    char title[10];
    char author[10];
    bool isAvaliable;

    void DisplayDetails() {
      std::cout << "id: " << id << std::endl;
      std::cout << "title: " << title << std::endl;
      std::cout << "author: " << author << std::endl;
      std::cout << "isAvaliable: " << (isAvaliable ? "yes":"no") << std::endl;
    }

    void BorrowBook() {
      isAvaliable = false;
    }
    void ReturnBook() {
      isAvaliable = true;
    }
};

class LIBRARY {
  public:
    BOOK collection[100];
    int bookCount;
    
    LIBRARY() : bookCount(0) {} // Constructor

    void AddBook(BOOK book) {
      if (bookCount < 100) {
        collection[bookCount] = book;
        bookCount++;
      } else {
        std::cout << "Library is full" << std::endl;
      }
      
    }

    void SearchBook(char searchTitle[10]) {
      bool found = false;
      for (int i = 0; i < bookCount; i++) {
        if (std::strcmp(collection[i].title, searchTitle) == 0) {
          std::cout << "Book found" << std::endl;
          collection[i].DisplayDetails();
          found = true;
          break;
        }
      }
      if (!found) {
        std::cout << "Book not found" << std::endl;
      }
    }

    void BorrowBook(char searchTitle[10]) {
      for (int i = 0; i < bookCount; i++) {
        if (std::strcmp(collection[i].title, searchTitle) == 0) {
          if (collection[i].isAvaliable) {
            collection[i].BorrowBook();
            std::cout << "Book borrowed" << std::endl;
          } else {
            std::cout << "Book not avaliable" << std::endl;
          }
          return;
        }
      }
      std::cout << "Book not found" << std::endl;
    }

    void ReturnBook(char searchTitle[10]) {
      for (int i = 0; i < bookCount; i++) {
        if (std::strcmp(collection[i].title, searchTitle) == 0) {
          if (!collection[i].isAvaliable) {
            collection[i].ReturnBook();
            std::cout << "Book returned" << std::endl;
          } else {
            std::cout << "Book was never borrowed" << std::endl;
          }
          return;
        }
        std::cout << "Book not found" << std::endl;
      }
    }

    void ListBook() {
      if (bookCount == 0) {
        std::cout << "Library is empty" << std::endl;
      } else {
        std::cout << "Books in library" << std::endl;
        std::cout << "-------------------" << std::endl;
        for (int i = 0; i < bookCount; i++) {
          collection[i].DisplayDetails();
          std::cout << "-------------------" << std::endl;
        }
      }
    }
};

int main() {
  // So many errors when I run but I dont know why :<

  LIBRARY library;

  BOOK book1 = {"001", "Title1", "Author1", true};
  BOOK book2 = {"002", "Title2", "Author2", true};

  library.AddBook(book1);
  library.AddBook(book2);

  library.ListBook();

  library.SearchBook("Title1");

  library.BorrowBook("Title1");
  library.BorrowBook("Title1");

  library.ReturnBook("Title1");
  library.ReturnBook("Title1");

  return 0;
}