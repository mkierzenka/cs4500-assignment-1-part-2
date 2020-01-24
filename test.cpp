#include <iostream>

#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"  // Your file with the String class
#include "map.h"
 
// This test class was added to allow for easier testing
class Test {
public:
  String* s;
  String* t;
  Test() {
    s = new String("Hello");
    t = new String("World");
  }

  ~Test() {
    delete s;
    delete t;
  }

  void FAIL() {   exit(1);    }
  void OK(const char* m) { std::cout << "OK: " << m << '\n'; }
  void t_true(bool p) { if (!p) FAIL(); }
  void t_false(bool p) { if (p) FAIL(); }

  void test_string() {
    String * w = new String("Hello");
    String * u = s->concat(t);
    t_true(s->equals(s));
    t_false(s->equals(t));
    t_false(s->equals(u));
    t_true(s->equals(w));
    t_true(u->equals(new String("HelloWorld")));
    w->concat_char('o');
    t_true(w->equals(new String("Helloo")));
    t_true(w->length == 6);
    delete w;
    delete u;
    OK("test_string");
  }

  void test_replace_1() {
    String * u = s->concat(t);
    MapStrStr * mss = new MapStrStr();
    mss->put(s, t);
    t_true(t->equals(mss->get(s)));
    mss->put(s, u);
    t_true(u->equals(mss->get(s)));
    t_true(mss->size() == 1);
    delete u;
    delete mss;
    OK("test_replace_1");
  }

  void test_replace_2() {
    Object * u = new String("hi");
    MapStrObj * mss = new MapStrObj();
    mss->put(s, t);
    t_true(t->equals(mss->get(s)));
    mss->put(s, u);
    t_true(u->equals(mss->get(s)));
    t_true(mss->size() == 1);
    delete u;
    delete mss;
    OK("test_replace_2");
  }

  void test_remove_1() {
    Object * u = new String("hi");
    String * w = new String("w");
    MapStrObj * mss = new MapStrObj();
    mss->put(s, t);
    mss->put(w, u);
    t_true(mss->size() == 2);
    t_true(mss->contains_key(s));
    t_true(mss->contains_key(w));
    Object * q = mss->remove(s);
    t_true(t->equals(q));
    t_false(mss->contains_key(s));
    t_true(mss->size() == 1);
    delete u;
    delete w;
    delete mss;
    OK("test_remove_1");
  }

  void test_remove_2() {
    String * u = s->concat(t);
    String * w = new String("w");
    MapStrStr * mss = new MapStrStr();
    mss->put(s, t);
    mss->put(w, u);
    t_true(mss->size() == 2);
    t_true(mss->contains_key(s));
    t_true(mss->contains_key(w));
    t_false(mss->contains_key(t));
    String * q = mss->remove(s);
    t_true(t->equals(q));
    t_false(mss->contains_key(s));
    t_true(mss->size() == 1);
    delete u;
    delete w;
    OK("test_remove_2");
  }
};

int main(int argc, char** argv) {
  Test* test = new Test();
  test->test_string();
  test->test_replace_1();
  test->test_replace_2();
  test->test_remove_1();
  test->test_remove_2();
  delete test;
  return 0;
}

