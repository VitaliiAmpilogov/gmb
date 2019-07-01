#ifndef IOBSERVER_H
#define IOBSERVER_H

template<typename T>
class IObserver {
  public:
    virtual void Notify(const T&) = 0;
    virtual ~IObserver() = default;
};

#endif  // IOBSERVER_H