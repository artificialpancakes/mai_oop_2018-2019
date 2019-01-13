#include "figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& obj) {
  return obj.Format(os);
}
