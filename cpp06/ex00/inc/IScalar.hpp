#ifndef CPP06_EX00_IScalar_H_
#define CPP06_EX00_IScalar_H_

class IScalar {
public:
  virtual ~IScalar(void);
  virtual int castToInt(void) = 0;
  virtual char castToChar(void) = 0;
  virtual float castToFloat(void) = 0;
  virtual double castToDouble(void) = 0;

private:
  IScalar(void);
  IScalar(const IScalar &other);
  IScalar &operator=(const IScalar &other);
};

#endif
