#pragma once

/// @file storages/mongo_ng/exception.hpp
/// @brief MongoDB-specific exceptions

#include <utils/traceful_exception.hpp>

namespace storages::mongo_ng {

/// Generic mongo-related exception
class MongoException : public utils::TracefulException {
 public:
  using utils::TracefulException::TracefulException;
};

/// Config validation error
class InvalidConfigException : public MongoException {
  using MongoException::MongoException;
};

/// Network (connectivity) error
class NetworkException : public MongoException {
 public:
  using MongoException::MongoException;
};

/// No server available to satisfy request constraints
class ClusterUnavailableException : public MongoException {
 public:
  using MongoException::MongoException;
};

/// Incompatible server version
class IncompatibleServerException : public MongoException {
 public:
  using MongoException::MongoException;
};

/// Authentication error
class AuthenticationException : public MongoException {
 public:
  using MongoException::MongoException;
};

/// Generic query error
class QueryException : public MongoException {
 public:
  using MongoException::MongoException;
};

/// Query argument validation error
class InvalidQueryArgumentException : public QueryException {
 public:
  using QueryException::QueryException;
};

/// Server-side error
class ServerException : public QueryException {
 public:
  explicit ServerException(int code) : code_(code) {}

  ServerException(int code, std::string message)
      : QueryException(std::move(message)), code_(code) {}

  int Code() const { return code_; }

 private:
  int code_;
};

/// Write concern error
class WriteConcernException : public ServerException {
 public:
  using ServerException::ServerException;
};

/// Duplicate key error
class DuplicateKeyException : public ServerException {
 public:
  using ServerException::ServerException;
};

}  // namespace storages::mongo_ng
