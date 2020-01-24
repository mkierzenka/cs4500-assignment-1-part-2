#include <iostream>

#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"  // Your file with the String class
#include "map.h"
 
void FAIL() {   exit(1);    }
void OK(const char* m) { std::cout << "OK: " << m << '\n'; }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

void test_string() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * w = new String("Hello");
  String * u = s->concat(t);
  t_true(s->equals(s));
  t_false(s->equals(t));
  t_false(s->equals(u));
  t_true(s->equals(w));
  t_true(u->equals(new String("HelloWorld")));
  s->concat_char('o');
  t_true(s->equals(new String("Helloo")));
  t_true(s->length == 6);

  OK("test_string");
}

void test_replace_1() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  MapStrStr * mss = new MapStrStr();
  mss->put(s, t);
  t_true(t->equals(mss->get(s)));
  mss->replace(s, u);
  t_true(u->equals(mss->get(s)));
  t_true(mss->size() == 1);

  OK("test_replace_1");
}

void test_replace_2() {
  String * s = new String("Hello");
  Object * t = new String("World");
  Object * u = new String("hi");
  MapStrObj * mss = new MapStrObj();
  mss->put(s, t);
  t_true(t->equals(mss->get(s)));
  mss->replace(s, u);
  t_true(u->equals(mss->get(s)));
  t_true(mss->size() == 1);

  OK("test_replace_2");
}

void test_remove_1() {
  String * s = new String("Hello");
  Object * t = new String("World");
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

  OK("test_remove_1");
}

void test_remove_2() {
  String * s = new String("Hello");
  String * t = new String("World");
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

  OK("test_remove_2");
}

int main(int argc, char** argv) {
  test_string();
  test_replace_1();
  test_replace_2();
  test_remove_1();
  test_remove_2();
  
  return 0;
}

