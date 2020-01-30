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

  void test_replace_1() {
    String * u = new String("HelloWorld");
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
    String * u = new String("HelloWorld");
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

  void test_get_1() {
    String * u = new String("HelloWorld");
    String * w = new String("w");
    MapStrStr * mss = new MapStrStr();
    mss->put(s, t);

    String** keys = mss->get_keys();
    String** values = mss->get_values();
    t_true(t->equals(values[0]));
    t_true(s->equals(keys[0]));

    delete u;
    delete w;
    delete mss;
    delete[] keys;
    delete[] values;

    OK("test_get_1");
  }

  void test_get_2() {
    Object * u = new String("hi");
    String * w = new String("w");
    MapStrObj * mss = new MapStrObj();
    mss->put(s, t);

    String** keys = mss->get_keys();
    Object** values = mss->get_values();
    t_true(t->equals(values[0]));
    t_true(s->equals(keys[0]));

    delete u;
    delete w;
    delete mss;
    delete keys;
    delete values;
    OK("test_get_2");
  }
};

int main(int argc, char** argv) {
  Test* test = new Test();
  test->test_replace_1();
  test->test_replace_2();
  test->test_remove_1();
  test->test_remove_2();
  test->test_get_1();
  test->test_get_2();
  delete test;
  return 0;
}

