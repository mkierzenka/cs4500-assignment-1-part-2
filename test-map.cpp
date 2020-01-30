#include <iostream>

#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"  // Your file with the String class
#include "map.h"
#include "array.h"
#include <assert.h>
 
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

  void test_put_0() {
    Object * a = new Object();
    Object * b = new Object();
    Map * mss = new Map();
    mss->put(s, t);
    Object * e = mss->put(a, b);
    t_true(mss->size() == 2);
    t_true(mss->contains_key(s));
    t_true(mss->contains_key(a));
    t_true(mss->get(a)->equals(b));
    t_true(e == nullptr);

    Object * c = new Object();
    Object * d = mss->put(a, c);
    t_true(mss->get(a)->equals(c));
    t_true(d->equals(b));

    delete a;
    delete b;
    delete mss;
    delete c;

    OK("test_put_0");
  }

  void test_put_1() {
    Object * a = new Object();
    Object * b = new Object();
    MapStrObj * mss = new Map();
    mss->put(s, a);
    Object * e = mss->put(t, b);
    t_true(mss->size() == 2);
    t_true(mss->contains_key(s));
    t_true(mss->contains_key(t));
    t_true(mss->get(t)->equals(b));
    t_true(e == nullptr);

    Object * c = new Object();
    Object * d = mss->put(s, c);
    t_true(mss->get(s)->equals(c));
    t_true(d->equals(a));

    delete a;
    delete b;
    delete mss;
    delete b;

    OK("test_put_1");
  }

  void test_put_2() {
    String * a = new String("a");
    String * b = new String("b");
    MapStrStr * mss = new MapStrStr();
    mss->put(s, t);
    String * e = mss->put(a, b);
    t_true(mss->size() == 2);
    t_true(mss->contains_key(s));
    t_true(mss->contains_key(a));
    t_true(mss->get(a)->equals(b));
    t_true(e == nullptr);

    String * c = new String("c");
    String * d = mss->put(a, c);
    t_true(mss->get(a)->equals(c));
    t_true(d->equals(b));

    delete a;
    delete b;
    delete mss;
    delete c;

    OK("test_put_2");
  }

  void test_remove_0() {
    Object * a = new Object();
    Object * b = new Object();
    Map * mss = new Map();
    mss->put(s, t);
    mss->put(a, b);
    t_true(mss->size() == 2);
    t_true(mss->contains_key(s));
    t_true(mss->contains_key(a));
    Object * q = mss->remove(s);
    t_true(t->equals(q));
    t_false(mss->contains_key(s));
    t_true(mss->size() == 1);
    delete a;
    delete b;
    delete mss;
    OK("test_remove_0");
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

  void test_get_0() {
    Object * a = new Object();
    Object * b = new Object();
    Map * mss = new Map();
    mss->put(a, b);

    Array* keys = mss->get_keys();
    Array* values = mss->get_values();
    t_true(b->equals(values->get(0)));
    t_true(a->equals(keys->get(0)));

    delete a;
    delete b;
    delete mss;
    delete keys;
    delete values;

    OK("test_get_0");
  }

  void test_get_1() {
    String * u = new String("HelloWorld");
    String * w = new String("w");
    MapStrStr * mss = new MapStrStr();
    mss->put(s, t);

    Array* keys = mss->get_keys();
    Array* values = mss->get_values();
    t_true(t->equals(values->get(0)));
    t_true(s->equals(keys->get(0)));

    delete u;
    delete w;
    delete mss;
    delete keys;
    delete values;

    OK("test_get_1");
  }

  void test_get_2() {
    Object * u = new String("hi");
    String * w = new String("w");
    MapStrObj * mss = new MapStrObj();
    mss->put(s, t);

    Array* keys = mss->get_keys();
    Array* values = mss->get_values();
    t_true(t->equals(values->get(0)));
    t_true(s->equals(keys->get(0)));

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
  test->test_remove_0();
  test->test_remove_1();
  test->test_remove_2();
  test->test_get_0();
  test->test_get_1();
  test->test_get_2();
  delete test;
  return 0;
}

