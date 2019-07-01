#ifndef SUBJECT_H
#define SUBJECT_H

#include "iobserver.h"
#include <vector>
#include <functional>

template<typename T>
class Subject {
  public:
    void Register(IObserver<T>& observer) {
      observers.emplace_back(observer);
    }
    void NotifyAll() {
      for(auto& observer : observers) {
        observer.get().Notify(data);
      }
    }

	  void SetData(const T& data) {
		  this->data = data;
	  }

	  T GetData() const {
		  return data;
	  }

  protected:
    T data;
  private:
    std::vector<std::reference_wrapper<IObserver<T>>> observers;
};

#endif  // SUBJECT_H