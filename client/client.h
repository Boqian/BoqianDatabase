#pragma once
#include <string>
#include <functional>
#include <vector>
using namespace std;
class ResponseType;
class RequestType;

class Client {
public:
  bool connect(string serverIP, string userName, string password);
  bool regist(string serverIP, string userName, string password);

  //blocking synchronous function
  template <typename K, typename V> void insert(K key, V value);
  template <typename K, typename V> void update(K key, V value);
  template <typename K, typename V> void erase(K key);
  template <typename K, typename V> V get(K key);

  //non-blocking asynchronous function
  using Callback = function<ResponseType>;
  template <typename K, typename V> void asyncInsert(K key, V value, Callback cb);
  template <typename K, typename V> void asyncUpdate(K key, V value, Callback cb);
  template <typename K, typename V> void asyncErase(K key, Callback cb);
  template <typename K, typename V> void asyncGet(K key, Callback cb);

  // general request function
  ResponseType send(RequestType request); // blocking synchronous
  void send(RequestType request, function<ResponseType> callback); //non-blocking asynchronous

  bool subscribe(function<ResponseType> callback);
  void unsubscibe();
};