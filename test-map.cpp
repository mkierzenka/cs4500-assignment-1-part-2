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
    MapStrObj * mss = new MapStrObj();
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
    delete c;

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
    t_false(keys->equals(values));
    t_true(keys != nullptr);
    t_true(values != nullptr);

    delete a;
    delete b;
    delete mss;
    delete keys;
    delete values;

    OK("test_get_0");
  }

  void test_get_1() {
    MapStrStr * mss = new MapStrStr();
    mss->put(s, t);

    Array* keys = mss->get_keys();
    Array* values = mss->get_values();
    // Because of the different Array implementations, this is the most thorough test we can do
    t_true(keys != nullptr);
    t_true(values != nullptr);

    delete mss;
    delete keys;
    delete values;

    OK("test_get_1");
  }

  void test_get_2() {
    MapStrObj * mss = new MapStrObj();
    Array* keys = mss->get_keys();
    Array* values = mss->get_values();
    t_true(keys != nullptr);
    t_true(values != nullptr);

    mss->put(s, t);
    // Because of the different Array implementations, this is the most thorough test we can do
    t_true(keys != nullptr);
    t_true(values != nullptr);

    mss->remove(s);
    t_true(keys != nullptr);
    t_true(values != nullptr);

    delete mss;
    delete keys;
    delete values;
    OK("test_get_2");
  }

  void test_equals_0() {    
    Object * u = new String("hi");
    String * w = new String("w");
    Map* map1 = new Map();
    Map* map2 = new Map(97);
    t_true(map1->equals(map2));
    t_false(map1->equals(w));

    map1->put(s, u);
    map1->put(t, w);
    map2->put(t, w);
    t_false(map1->equals(map2));
    map2->put(s, s);
    t_false(map1->equals(map2));
    map2->put(s, u);
    t_true(map1->equals(map2));
    delete u;
    delete w;
    delete map1;
    delete map2;
    OK("test_equals_0");
  }

  void test_contain_keys_0() {
    Object * u = new String("hi");
    String * w = new String("w");
    Map* map = new Map();
    MapStrStr* str_map = new MapStrStr();
    MapStrObj* str_obj_map = new MapStrObj();
    map->put(s, t);
    map->put(t, s);
    t_true(map->contains_key(t));
    t_true(map->contains_key(s));
    t_false(map->contains_key(u));
    map->put(u, s);
    t_true(map->contains_key(u));

    t_false(str_map->contains_key(w));
    str_map->put(w, s);
    t_true(str_map->contains_key(w));

    t_false(str_obj_map->contains_key(s));
    str_obj_map->put(s, t);
    t_true(str_obj_map->contains_key(s));

    delete u;
    delete w;
    delete map;
    delete str_map;
    delete str_obj_map;
    OK("test_contains_keys_0");
  }

  void test_hash_0() {
    Map* map = new Map();
    MapStrStr* string_map = new MapStrStr();
    map->put(s, t);
    string_map->put(s, t);
    t_true(map->hash() == string_map->hash());
    map->put(t, s);
    t_true(map->hash() != string_map->hash());
    delete map;
    delete string_map;
    OK("test_hash_0");
  }

  void test_hash_1() {
    MapStrObj* m1 = new MapStrObj();
    MapStrObj* m2 = new MapStrObj();
    Object * a = new Object();
    String * s = new String("s");

    t_true(m1->hash() == m2->hash());
    m1->put(s, a);
    t_false(m1->hash() == m2->hash());
    m2->put(s, a);
    t_true(m1->hash() == m2->hash());

    delete m1;
    delete m2;
    delete a;
    delete s;

    OK("test_hash_1");
  }

};

int main(int argc, char** argv) {
  Test* test = new Test();
  test->test_put_0();
  test->test_put_1();
  test->test_put_2();
  test->test_remove_0();
  test->test_remove_1();
  test->test_remove_2();
  test->test_get_0();
  test->test_get_1();
  test->test_get_2();
  test->test_equals_0();
  test->test_contain_keys_0();
  test->test_hash_0();
  test->test_hash_1();
  delete test;
  return 0;
}

