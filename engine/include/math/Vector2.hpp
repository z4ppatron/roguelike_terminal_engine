// 2D vector class with integer entries.
#include <cmath>
#include <iostream>

class Vector2 {
  private:
    int x;
    int y;

  public:
    Vector2();
    Vector2(int x, int y);
    
    static Vector2 ZERO;
    static Vector2 E1;
    static Vector2 E2;
    
    int get_x() const;
    int get_y() const;

    Vector2 operator+ (Vector2 const& v);
    Vector2 operator- (Vector2 const& v);

    constexpr float angle() const;
    constexpr float length() const;
    constexpr float dot(const Vector2& v) const;
    constexpr Vector2 cross(const Vector2& v) const;
    constexpr float angle_between(const Vector2& v) const;
    
    friend std::ostream& operator<<(std::ostream& out, const Vector2& v); 

};


std::ostream& operator<<(std::ostream& out, const Vector2& v); 
