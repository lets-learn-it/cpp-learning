# Visibility

## Access Specifiers

- `private`: member can't be accessed from outside of class. only member functions/friend functions can access private data members.
- `protected`: members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
- `public`: members are accessible from outside the class

### Friend class & function

```cpp
class ABC {
private:
  int x;
public:
  ABC() {
    x = 10;
  }

  // tell about your friend
  friend class XYZ;
  friend int FriendOfABC(ABC& abc);
  friend int NotFriendOfABC getX(ABC& abc);
}

class XYZ {
public:
  int getX(ABC& abc) {
    return abc.x;
  }
}

class NotFriendOfABC {
public:
  int getX(ABC& abc) {
    return abc.x;
  }
}

int FriendOfABC(ABC& abc) {
  return abc.x;
}
```
