// -*- C++ -*-
// Automatically generated from protocol-curr/xdr/Stellar-ledger-entries.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_PROTOCOL_CURR_XDR_STELLAR_LEDGER_ENTRIES_H_INCLUDED__
#define __XDR_PROTOCOL_CURR_XDR_STELLAR_LEDGER_ENTRIES_H_INCLUDED__ 1

#include "types.h"

#include "Stellar-types.h"

namespace stellar {

using AccountID = PublicKey;
using Thresholds = xdr::opaque_array<4>;
using string32 = xdr::xstring<32>;
using string64 = xdr::xstring<64>;
using SequenceNumber = int64;
using TimePoint = uint64;
using Duration = uint64;
using DataValue = xdr::opaque_vec<64>;
using PoolID = Hash;
using AssetCode4 = xdr::opaque_array<4>;
using AssetCode12 = xdr::opaque_array<12>;

enum AssetType : std::int32_t {
  ASSET_TYPE_NATIVE = 0,
  ASSET_TYPE_CREDIT_ALPHANUM4 = 1,
  ASSET_TYPE_CREDIT_ALPHANUM12 = 2,
  ASSET_TYPE_POOL_SHARE = 3,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AssetType>
  : xdr_integral_base<::stellar::AssetType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::AssetType val) {
    switch (val) {
    case ::stellar::ASSET_TYPE_NATIVE:
      return "ASSET_TYPE_NATIVE";
    case ::stellar::ASSET_TYPE_CREDIT_ALPHANUM4:
      return "ASSET_TYPE_CREDIT_ALPHANUM4";
    case ::stellar::ASSET_TYPE_CREDIT_ALPHANUM12:
      return "ASSET_TYPE_CREDIT_ALPHANUM12";
    case ::stellar::ASSET_TYPE_POOL_SHARE:
      return "ASSET_TYPE_POOL_SHARE";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ASSET_TYPE_NATIVE,
      ::stellar::ASSET_TYPE_CREDIT_ALPHANUM4,
      ::stellar::ASSET_TYPE_CREDIT_ALPHANUM12,
      ::stellar::ASSET_TYPE_POOL_SHARE
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct AssetCode {
  using _xdr_case_type = xdr::xdr_traits<AssetType>::case_type;
private:
  _xdr_case_type type_;
  union {
    AssetCode4 assetCode4_;
    AssetCode12 assetCode12_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<AssetType> &_xdr_case_values() {
    static const std::vector<AssetType> _xdr_disc_vec {
      ASSET_TYPE_CREDIT_ALPHANUM4,
      ASSET_TYPE_CREDIT_ALPHANUM12
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ASSET_TYPE_CREDIT_ALPHANUM4 ? 1
      : which == ASSET_TYPE_CREDIT_ALPHANUM12 ? 2
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ASSET_TYPE_CREDIT_ALPHANUM4:
      _f(&AssetCode::assetCode4_, std::forward<_A>(_a)...);
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM12:
      _f(&AssetCode::assetCode12_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in AssetCode");
    if (fnum != _xdr_field_number(type_)) {
      this->~AssetCode();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit AssetCode(AssetType which = AssetType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  AssetCode(const AssetCode &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  AssetCode(AssetCode &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~AssetCode() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  AssetCode &operator=(const AssetCode &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~AssetCode();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  AssetCode &operator=(AssetCode &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~AssetCode();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  AssetType type() const { return AssetType(type_); }
  AssetCode &type(AssetType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  AssetCode4 &assetCode4() {
    if (_xdr_field_number(type_) == 1)
      return assetCode4_;
    throw xdr::xdr_wrong_union("AssetCode: assetCode4 accessed when not selected");
  }
  const AssetCode4 &assetCode4() const {
    if (_xdr_field_number(type_) == 1)
      return assetCode4_;
    throw xdr::xdr_wrong_union("AssetCode: assetCode4 accessed when not selected");
  }
  AssetCode12 &assetCode12() {
    if (_xdr_field_number(type_) == 2)
      return assetCode12_;
    throw xdr::xdr_wrong_union("AssetCode: assetCode12 accessed when not selected");
  }
  const AssetCode12 &assetCode12() const {
    if (_xdr_field_number(type_) == 2)
      return assetCode12_;
    throw xdr::xdr_wrong_union("AssetCode: assetCode12 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AssetCode> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AssetCode;
  using case_type = ::stellar::AssetCode::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "assetCode4";
    case 2:
      return "assetCode12";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AssetCode &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in AssetCode");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AssetCode &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in AssetCode");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AssetCode &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AlphaNum4 {
  AssetCode4 assetCode{};
  AccountID issuer{};

  AlphaNum4() = default;
  template<typename _assetCode_T,
           typename _issuer_T,
           typename = typename
           std::enable_if<std::is_constructible<AssetCode4, _assetCode_T>::value
                          && std::is_constructible<AccountID, _issuer_T>::value
                         >::type>
  explicit AlphaNum4(_assetCode_T &&_assetCode,
                     _issuer_T &&_issuer)
    : assetCode(std::forward<_assetCode_T>(_assetCode)),
      issuer(std::forward<_issuer_T>(_issuer)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AlphaNum4>
  : xdr_struct_base<field_ptr<::stellar::AlphaNum4,
                              decltype(::stellar::AlphaNum4::assetCode),
                              &::stellar::AlphaNum4::assetCode>,
                    field_ptr<::stellar::AlphaNum4,
                              decltype(::stellar::AlphaNum4::issuer),
                              &::stellar::AlphaNum4::issuer>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AlphaNum4 &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AlphaNum4 &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AlphaNum12 {
  AssetCode12 assetCode{};
  AccountID issuer{};

  AlphaNum12() = default;
  template<typename _assetCode_T,
           typename _issuer_T,
           typename = typename
           std::enable_if<std::is_constructible<AssetCode12, _assetCode_T>::value
                          && std::is_constructible<AccountID, _issuer_T>::value
                         >::type>
  explicit AlphaNum12(_assetCode_T &&_assetCode,
                      _issuer_T &&_issuer)
    : assetCode(std::forward<_assetCode_T>(_assetCode)),
      issuer(std::forward<_issuer_T>(_issuer)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AlphaNum12>
  : xdr_struct_base<field_ptr<::stellar::AlphaNum12,
                              decltype(::stellar::AlphaNum12::assetCode),
                              &::stellar::AlphaNum12::assetCode>,
                    field_ptr<::stellar::AlphaNum12,
                              decltype(::stellar::AlphaNum12::issuer),
                              &::stellar::AlphaNum12::issuer>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AlphaNum12 &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AlphaNum12 &obj) {
    archive(ar, obj.assetCode, "assetCode");
    archive(ar, obj.issuer, "issuer");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Asset {
  using _xdr_case_type = xdr::xdr_traits<AssetType>::case_type;
private:
  _xdr_case_type type_;
  union {
    AlphaNum4 alphaNum4_;
    AlphaNum12 alphaNum12_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<AssetType> &_xdr_case_values() {
    static const std::vector<AssetType> _xdr_disc_vec {
      ASSET_TYPE_NATIVE,
      ASSET_TYPE_CREDIT_ALPHANUM4,
      ASSET_TYPE_CREDIT_ALPHANUM12
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ASSET_TYPE_NATIVE ? 0
      : which == ASSET_TYPE_CREDIT_ALPHANUM4 ? 1
      : which == ASSET_TYPE_CREDIT_ALPHANUM12 ? 2
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ASSET_TYPE_NATIVE:
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM4:
      _f(&Asset::alphaNum4_, std::forward<_A>(_a)...);
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM12:
      _f(&Asset::alphaNum12_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in Asset");
    if (fnum != _xdr_field_number(type_)) {
      this->~Asset();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit Asset(AssetType which = AssetType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  Asset(const Asset &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  Asset(Asset &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~Asset() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  Asset &operator=(const Asset &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~Asset();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  Asset &operator=(Asset &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~Asset();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  AssetType type() const { return AssetType(type_); }
  Asset &type(AssetType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  AlphaNum4 &alphaNum4() {
    if (_xdr_field_number(type_) == 1)
      return alphaNum4_;
    throw xdr::xdr_wrong_union("Asset: alphaNum4 accessed when not selected");
  }
  const AlphaNum4 &alphaNum4() const {
    if (_xdr_field_number(type_) == 1)
      return alphaNum4_;
    throw xdr::xdr_wrong_union("Asset: alphaNum4 accessed when not selected");
  }
  AlphaNum12 &alphaNum12() {
    if (_xdr_field_number(type_) == 2)
      return alphaNum12_;
    throw xdr::xdr_wrong_union("Asset: alphaNum12 accessed when not selected");
  }
  const AlphaNum12 &alphaNum12() const {
    if (_xdr_field_number(type_) == 2)
      return alphaNum12_;
    throw xdr::xdr_wrong_union("Asset: alphaNum12 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Asset> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::Asset;
  using case_type = ::stellar::Asset::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "alphaNum4";
    case 2:
      return "alphaNum12";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::Asset &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in Asset");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Asset &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in Asset");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Asset &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Price {
  int32 n{};
  int32 d{};

  Price() = default;
  template<typename _n_T,
           typename _d_T,
           typename = typename
           std::enable_if<std::is_constructible<int32, _n_T>::value
                          && std::is_constructible<int32, _d_T>::value
                         >::type>
  explicit Price(_n_T &&_n,
                 _d_T &&_d)
    : n(std::forward<_n_T>(_n)),
      d(std::forward<_d_T>(_d)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Price>
  : xdr_struct_base<field_ptr<::stellar::Price,
                              decltype(::stellar::Price::n),
                              &::stellar::Price::n>,
                    field_ptr<::stellar::Price,
                              decltype(::stellar::Price::d),
                              &::stellar::Price::d>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Price &obj) {
    archive(ar, obj.n, "n");
    archive(ar, obj.d, "d");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Price &obj) {
    archive(ar, obj.n, "n");
    archive(ar, obj.d, "d");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct Liabilities {
  int64 buying{};
  int64 selling{};

  Liabilities() = default;
  template<typename _buying_T,
           typename _selling_T,
           typename = typename
           std::enable_if<std::is_constructible<int64, _buying_T>::value
                          && std::is_constructible<int64, _selling_T>::value
                         >::type>
  explicit Liabilities(_buying_T &&_buying,
                       _selling_T &&_selling)
    : buying(std::forward<_buying_T>(_buying)),
      selling(std::forward<_selling_T>(_selling)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Liabilities>
  : xdr_struct_base<field_ptr<::stellar::Liabilities,
                              decltype(::stellar::Liabilities::buying),
                              &::stellar::Liabilities::buying>,
                    field_ptr<::stellar::Liabilities,
                              decltype(::stellar::Liabilities::selling),
                              &::stellar::Liabilities::selling>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Liabilities &obj) {
    archive(ar, obj.buying, "buying");
    archive(ar, obj.selling, "selling");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Liabilities &obj) {
    archive(ar, obj.buying, "buying");
    archive(ar, obj.selling, "selling");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ThresholdIndexes : std::int32_t {
  THRESHOLD_MASTER_WEIGHT = 0,
  THRESHOLD_LOW = 1,
  THRESHOLD_MED = 2,
  THRESHOLD_HIGH = 3,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ThresholdIndexes>
  : xdr_integral_base<::stellar::ThresholdIndexes, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ThresholdIndexes val) {
    switch (val) {
    case ::stellar::THRESHOLD_MASTER_WEIGHT:
      return "THRESHOLD_MASTER_WEIGHT";
    case ::stellar::THRESHOLD_LOW:
      return "THRESHOLD_LOW";
    case ::stellar::THRESHOLD_MED:
      return "THRESHOLD_MED";
    case ::stellar::THRESHOLD_HIGH:
      return "THRESHOLD_HIGH";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::THRESHOLD_MASTER_WEIGHT,
      ::stellar::THRESHOLD_LOW,
      ::stellar::THRESHOLD_MED,
      ::stellar::THRESHOLD_HIGH
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

enum LedgerEntryType : std::int32_t {
  ACCOUNT = 0,
  TRUSTLINE = 1,
  OFFER = 2,
  DATA = 3,
  CLAIMABLE_BALANCE = 4,
  LIQUIDITY_POOL = 5,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LedgerEntryType>
  : xdr_integral_base<::stellar::LedgerEntryType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::LedgerEntryType val) {
    switch (val) {
    case ::stellar::ACCOUNT:
      return "ACCOUNT";
    case ::stellar::TRUSTLINE:
      return "TRUSTLINE";
    case ::stellar::OFFER:
      return "OFFER";
    case ::stellar::DATA:
      return "DATA";
    case ::stellar::CLAIMABLE_BALANCE:
      return "CLAIMABLE_BALANCE";
    case ::stellar::LIQUIDITY_POOL:
      return "LIQUIDITY_POOL";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ACCOUNT,
      ::stellar::TRUSTLINE,
      ::stellar::OFFER,
      ::stellar::DATA,
      ::stellar::CLAIMABLE_BALANCE,
      ::stellar::LIQUIDITY_POOL
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct Signer {
  SignerKey key{};
  uint32 weight{};

  Signer() = default;
  template<typename _key_T,
           typename _weight_T,
           typename = typename
           std::enable_if<std::is_constructible<SignerKey, _key_T>::value
                          && std::is_constructible<uint32, _weight_T>::value
                         >::type>
  explicit Signer(_key_T &&_key,
                  _weight_T &&_weight)
    : key(std::forward<_key_T>(_key)),
      weight(std::forward<_weight_T>(_weight)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Signer>
  : xdr_struct_base<field_ptr<::stellar::Signer,
                              decltype(::stellar::Signer::key),
                              &::stellar::Signer::key>,
                    field_ptr<::stellar::Signer,
                              decltype(::stellar::Signer::weight),
                              &::stellar::Signer::weight>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Signer &obj) {
    archive(ar, obj.key, "key");
    archive(ar, obj.weight, "weight");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Signer &obj) {
    archive(ar, obj.key, "key");
    archive(ar, obj.weight, "weight");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum AccountFlags : std::int32_t {
  AUTH_REQUIRED_FLAG = 0x1,
  AUTH_REVOCABLE_FLAG = 0x2,
  AUTH_IMMUTABLE_FLAG = 0x4,
  AUTH_CLAWBACK_ENABLED_FLAG = 0x8,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountFlags>
  : xdr_integral_base<::stellar::AccountFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::AccountFlags val) {
    switch (val) {
    case ::stellar::AUTH_REQUIRED_FLAG:
      return "AUTH_REQUIRED_FLAG";
    case ::stellar::AUTH_REVOCABLE_FLAG:
      return "AUTH_REVOCABLE_FLAG";
    case ::stellar::AUTH_IMMUTABLE_FLAG:
      return "AUTH_IMMUTABLE_FLAG";
    case ::stellar::AUTH_CLAWBACK_ENABLED_FLAG:
      return "AUTH_CLAWBACK_ENABLED_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::AUTH_REQUIRED_FLAG,
      ::stellar::AUTH_REVOCABLE_FLAG,
      ::stellar::AUTH_IMMUTABLE_FLAG,
      ::stellar::AUTH_CLAWBACK_ENABLED_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_ACCOUNT_FLAGS = 0x7;
Constexpr const std::uint32_t MASK_ACCOUNT_FLAGS_V17 = 0xF;
Constexpr const std::uint32_t MAX_SIGNERS = 20;

using SponsorshipDescriptor = xdr::pointer<AccountID>;

struct AccountEntryExtensionV3 {
  ExtensionPoint ext{};
  uint32 seqLedger{};
  TimePoint seqTime{};

  AccountEntryExtensionV3() = default;
  template<typename _ext_T,
           typename _seqLedger_T,
           typename _seqTime_T,
           typename = typename
           std::enable_if<std::is_constructible<ExtensionPoint, _ext_T>::value
                          && std::is_constructible<uint32, _seqLedger_T>::value
                          && std::is_constructible<TimePoint, _seqTime_T>::value
                         >::type>
  explicit AccountEntryExtensionV3(_ext_T &&_ext,
                                   _seqLedger_T &&_seqLedger,
                                   _seqTime_T &&_seqTime)
    : ext(std::forward<_ext_T>(_ext)),
      seqLedger(std::forward<_seqLedger_T>(_seqLedger)),
      seqTime(std::forward<_seqTime_T>(_seqTime)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountEntryExtensionV3>
  : xdr_struct_base<field_ptr<::stellar::AccountEntryExtensionV3,
                              decltype(::stellar::AccountEntryExtensionV3::ext),
                              &::stellar::AccountEntryExtensionV3::ext>,
                    field_ptr<::stellar::AccountEntryExtensionV3,
                              decltype(::stellar::AccountEntryExtensionV3::seqLedger),
                              &::stellar::AccountEntryExtensionV3::seqLedger>,
                    field_ptr<::stellar::AccountEntryExtensionV3,
                              decltype(::stellar::AccountEntryExtensionV3::seqTime),
                              &::stellar::AccountEntryExtensionV3::seqTime>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntryExtensionV3 &obj) {
    archive(ar, obj.ext, "ext");
    archive(ar, obj.seqLedger, "seqLedger");
    archive(ar, obj.seqTime, "seqTime");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntryExtensionV3 &obj) {
    archive(ar, obj.ext, "ext");
    archive(ar, obj.seqLedger, "seqLedger");
    archive(ar, obj.seqTime, "seqTime");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AccountEntryExtensionV2 {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      AccountEntryExtensionV3 v3_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        3
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 3 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 3:
        _f(&_ext_t::v3_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    AccountEntryExtensionV3 &v3() {
      if (_xdr_field_number(v_) == 1)
        return v3_;
      throw xdr::xdr_wrong_union("_ext_t: v3 accessed when not selected");
    }
    const AccountEntryExtensionV3 &v3() const {
      if (_xdr_field_number(v_) == 1)
        return v3_;
      throw xdr::xdr_wrong_union("_ext_t: v3 accessed when not selected");
    }
  };

  uint32 numSponsored{};
  uint32 numSponsoring{};
  xdr::xvector<SponsorshipDescriptor,MAX_SIGNERS> signerSponsoringIDs{};
  _ext_t ext{};

  AccountEntryExtensionV2() = default;
  template<typename _numSponsored_T,
           typename _numSponsoring_T,
           typename _signerSponsoringIDs_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<uint32, _numSponsored_T>::value
                          && std::is_constructible<uint32, _numSponsoring_T>::value
                          && std::is_constructible<xdr::xvector<SponsorshipDescriptor,MAX_SIGNERS>, _signerSponsoringIDs_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit AccountEntryExtensionV2(_numSponsored_T &&_numSponsored,
                                   _numSponsoring_T &&_numSponsoring,
                                   _signerSponsoringIDs_T &&_signerSponsoringIDs,
                                   _ext_T &&_ext)
    : numSponsored(std::forward<_numSponsored_T>(_numSponsored)),
      numSponsoring(std::forward<_numSponsoring_T>(_numSponsoring)),
      signerSponsoringIDs(std::forward<_signerSponsoringIDs_T>(_signerSponsoringIDs)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountEntryExtensionV2::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AccountEntryExtensionV2::_ext_t;
  using case_type = ::stellar::AccountEntryExtensionV2::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v3";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AccountEntryExtensionV2::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntryExtensionV2::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntryExtensionV2::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AccountEntryExtensionV2>
  : xdr_struct_base<field_ptr<::stellar::AccountEntryExtensionV2,
                              decltype(::stellar::AccountEntryExtensionV2::numSponsored),
                              &::stellar::AccountEntryExtensionV2::numSponsored>,
                    field_ptr<::stellar::AccountEntryExtensionV2,
                              decltype(::stellar::AccountEntryExtensionV2::numSponsoring),
                              &::stellar::AccountEntryExtensionV2::numSponsoring>,
                    field_ptr<::stellar::AccountEntryExtensionV2,
                              decltype(::stellar::AccountEntryExtensionV2::signerSponsoringIDs),
                              &::stellar::AccountEntryExtensionV2::signerSponsoringIDs>,
                    field_ptr<::stellar::AccountEntryExtensionV2,
                              decltype(::stellar::AccountEntryExtensionV2::ext),
                              &::stellar::AccountEntryExtensionV2::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntryExtensionV2 &obj) {
    archive(ar, obj.numSponsored, "numSponsored");
    archive(ar, obj.numSponsoring, "numSponsoring");
    archive(ar, obj.signerSponsoringIDs, "signerSponsoringIDs");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntryExtensionV2 &obj) {
    archive(ar, obj.numSponsored, "numSponsored");
    archive(ar, obj.numSponsoring, "numSponsoring");
    archive(ar, obj.signerSponsoringIDs, "signerSponsoringIDs");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AccountEntryExtensionV1 {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      AccountEntryExtensionV2 v2_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        2
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 2 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 2:
        _f(&_ext_t::v2_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    AccountEntryExtensionV2 &v2() {
      if (_xdr_field_number(v_) == 1)
        return v2_;
      throw xdr::xdr_wrong_union("_ext_t: v2 accessed when not selected");
    }
    const AccountEntryExtensionV2 &v2() const {
      if (_xdr_field_number(v_) == 1)
        return v2_;
      throw xdr::xdr_wrong_union("_ext_t: v2 accessed when not selected");
    }
  };

  Liabilities liabilities{};
  _ext_t ext{};

  AccountEntryExtensionV1() = default;
  template<typename _liabilities_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<Liabilities, _liabilities_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit AccountEntryExtensionV1(_liabilities_T &&_liabilities,
                                   _ext_T &&_ext)
    : liabilities(std::forward<_liabilities_T>(_liabilities)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountEntryExtensionV1::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AccountEntryExtensionV1::_ext_t;
  using case_type = ::stellar::AccountEntryExtensionV1::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v2";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AccountEntryExtensionV1::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntryExtensionV1::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntryExtensionV1::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AccountEntryExtensionV1>
  : xdr_struct_base<field_ptr<::stellar::AccountEntryExtensionV1,
                              decltype(::stellar::AccountEntryExtensionV1::liabilities),
                              &::stellar::AccountEntryExtensionV1::liabilities>,
                    field_ptr<::stellar::AccountEntryExtensionV1,
                              decltype(::stellar::AccountEntryExtensionV1::ext),
                              &::stellar::AccountEntryExtensionV1::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntryExtensionV1 &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntryExtensionV1 &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct AccountEntry {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      AccountEntryExtensionV1 v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        1
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 1 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 1:
        _f(&_ext_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    AccountEntryExtensionV1 &v1() {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
    const AccountEntryExtensionV1 &v1() const {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
  };

  AccountID accountID{};
  int64 balance{};
  SequenceNumber seqNum{};
  uint32 numSubEntries{};
  xdr::pointer<AccountID> inflationDest{};
  uint32 flags{};
  string32 homeDomain{};
  Thresholds thresholds{};
  xdr::xvector<Signer,MAX_SIGNERS> signers{};
  _ext_t ext{};

  AccountEntry() = default;
  template<typename _accountID_T,
           typename _balance_T,
           typename _seqNum_T,
           typename _numSubEntries_T,
           typename _inflationDest_T,
           typename _flags_T,
           typename _homeDomain_T,
           typename _thresholds_T,
           typename _signers_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                          && std::is_constructible<int64, _balance_T>::value
                          && std::is_constructible<SequenceNumber, _seqNum_T>::value
                          && std::is_constructible<uint32, _numSubEntries_T>::value
                          && std::is_constructible<xdr::pointer<AccountID>, _inflationDest_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                          && std::is_constructible<string32, _homeDomain_T>::value
                          && std::is_constructible<Thresholds, _thresholds_T>::value
                          && std::is_constructible<xdr::xvector<Signer,MAX_SIGNERS>, _signers_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit AccountEntry(_accountID_T &&_accountID,
                        _balance_T &&_balance,
                        _seqNum_T &&_seqNum,
                        _numSubEntries_T &&_numSubEntries,
                        _inflationDest_T &&_inflationDest,
                        _flags_T &&_flags,
                        _homeDomain_T &&_homeDomain,
                        _thresholds_T &&_thresholds,
                        _signers_T &&_signers,
                        _ext_T &&_ext)
    : accountID(std::forward<_accountID_T>(_accountID)),
      balance(std::forward<_balance_T>(_balance)),
      seqNum(std::forward<_seqNum_T>(_seqNum)),
      numSubEntries(std::forward<_numSubEntries_T>(_numSubEntries)),
      inflationDest(std::forward<_inflationDest_T>(_inflationDest)),
      flags(std::forward<_flags_T>(_flags)),
      homeDomain(std::forward<_homeDomain_T>(_homeDomain)),
      thresholds(std::forward<_thresholds_T>(_thresholds)),
      signers(std::forward<_signers_T>(_signers)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::AccountEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::AccountEntry::_ext_t;
  using case_type = ::stellar::AccountEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v1";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::AccountEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::AccountEntry>
  : xdr_struct_base<field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::accountID),
                              &::stellar::AccountEntry::accountID>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::balance),
                              &::stellar::AccountEntry::balance>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::seqNum),
                              &::stellar::AccountEntry::seqNum>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::numSubEntries),
                              &::stellar::AccountEntry::numSubEntries>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::inflationDest),
                              &::stellar::AccountEntry::inflationDest>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::flags),
                              &::stellar::AccountEntry::flags>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::homeDomain),
                              &::stellar::AccountEntry::homeDomain>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::thresholds),
                              &::stellar::AccountEntry::thresholds>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::signers),
                              &::stellar::AccountEntry::signers>,
                    field_ptr<::stellar::AccountEntry,
                              decltype(::stellar::AccountEntry::ext),
                              &::stellar::AccountEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::AccountEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.numSubEntries, "numSubEntries");
    archive(ar, obj.inflationDest, "inflationDest");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.homeDomain, "homeDomain");
    archive(ar, obj.thresholds, "thresholds");
    archive(ar, obj.signers, "signers");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::AccountEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.seqNum, "seqNum");
    archive(ar, obj.numSubEntries, "numSubEntries");
    archive(ar, obj.inflationDest, "inflationDest");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.homeDomain, "homeDomain");
    archive(ar, obj.thresholds, "thresholds");
    archive(ar, obj.signers, "signers");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum TrustLineFlags : std::int32_t {
  AUTHORIZED_FLAG = 1,
  AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG = 2,
  TRUSTLINE_CLAWBACK_ENABLED_FLAG = 4,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TrustLineFlags>
  : xdr_integral_base<::stellar::TrustLineFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::TrustLineFlags val) {
    switch (val) {
    case ::stellar::AUTHORIZED_FLAG:
      return "AUTHORIZED_FLAG";
    case ::stellar::AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG:
      return "AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG";
    case ::stellar::TRUSTLINE_CLAWBACK_ENABLED_FLAG:
      return "TRUSTLINE_CLAWBACK_ENABLED_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::AUTHORIZED_FLAG,
      ::stellar::AUTHORIZED_TO_MAINTAIN_LIABILITIES_FLAG,
      ::stellar::TRUSTLINE_CLAWBACK_ENABLED_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_TRUSTLINE_FLAGS = 1;
Constexpr const std::uint32_t MASK_TRUSTLINE_FLAGS_V13 = 3;
Constexpr const std::uint32_t MASK_TRUSTLINE_FLAGS_V17 = 7;

enum LiquidityPoolType : std::int32_t {
  LIQUIDITY_POOL_CONSTANT_PRODUCT = 0,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LiquidityPoolType>
  : xdr_integral_base<::stellar::LiquidityPoolType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::LiquidityPoolType val) {
    switch (val) {
    case ::stellar::LIQUIDITY_POOL_CONSTANT_PRODUCT:
      return "LIQUIDITY_POOL_CONSTANT_PRODUCT";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::LIQUIDITY_POOL_CONSTANT_PRODUCT
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct TrustLineAsset {
  using _xdr_case_type = xdr::xdr_traits<AssetType>::case_type;
private:
  _xdr_case_type type_;
  union {
    AlphaNum4 alphaNum4_;
    AlphaNum12 alphaNum12_;
    PoolID liquidityPoolID_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<AssetType> &_xdr_case_values() {
    static const std::vector<AssetType> _xdr_disc_vec {
      ASSET_TYPE_NATIVE,
      ASSET_TYPE_CREDIT_ALPHANUM4,
      ASSET_TYPE_CREDIT_ALPHANUM12,
      ASSET_TYPE_POOL_SHARE
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ASSET_TYPE_NATIVE ? 0
      : which == ASSET_TYPE_CREDIT_ALPHANUM4 ? 1
      : which == ASSET_TYPE_CREDIT_ALPHANUM12 ? 2
      : which == ASSET_TYPE_POOL_SHARE ? 3
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ASSET_TYPE_NATIVE:
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM4:
      _f(&TrustLineAsset::alphaNum4_, std::forward<_A>(_a)...);
      return true;
    case ASSET_TYPE_CREDIT_ALPHANUM12:
      _f(&TrustLineAsset::alphaNum12_, std::forward<_A>(_a)...);
      return true;
    case ASSET_TYPE_POOL_SHARE:
      _f(&TrustLineAsset::liquidityPoolID_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in TrustLineAsset");
    if (fnum != _xdr_field_number(type_)) {
      this->~TrustLineAsset();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit TrustLineAsset(AssetType which = AssetType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  TrustLineAsset(const TrustLineAsset &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  TrustLineAsset(TrustLineAsset &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~TrustLineAsset() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  TrustLineAsset &operator=(const TrustLineAsset &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~TrustLineAsset();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  TrustLineAsset &operator=(TrustLineAsset &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~TrustLineAsset();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  AssetType type() const { return AssetType(type_); }
  TrustLineAsset &type(AssetType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  AlphaNum4 &alphaNum4() {
    if (_xdr_field_number(type_) == 1)
      return alphaNum4_;
    throw xdr::xdr_wrong_union("TrustLineAsset: alphaNum4 accessed when not selected");
  }
  const AlphaNum4 &alphaNum4() const {
    if (_xdr_field_number(type_) == 1)
      return alphaNum4_;
    throw xdr::xdr_wrong_union("TrustLineAsset: alphaNum4 accessed when not selected");
  }
  AlphaNum12 &alphaNum12() {
    if (_xdr_field_number(type_) == 2)
      return alphaNum12_;
    throw xdr::xdr_wrong_union("TrustLineAsset: alphaNum12 accessed when not selected");
  }
  const AlphaNum12 &alphaNum12() const {
    if (_xdr_field_number(type_) == 2)
      return alphaNum12_;
    throw xdr::xdr_wrong_union("TrustLineAsset: alphaNum12 accessed when not selected");
  }
  PoolID &liquidityPoolID() {
    if (_xdr_field_number(type_) == 3)
      return liquidityPoolID_;
    throw xdr::xdr_wrong_union("TrustLineAsset: liquidityPoolID accessed when not selected");
  }
  const PoolID &liquidityPoolID() const {
    if (_xdr_field_number(type_) == 3)
      return liquidityPoolID_;
    throw xdr::xdr_wrong_union("TrustLineAsset: liquidityPoolID accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TrustLineAsset> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TrustLineAsset;
  using case_type = ::stellar::TrustLineAsset::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "alphaNum4";
    case 2:
      return "alphaNum12";
    case 3:
      return "liquidityPoolID";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TrustLineAsset &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in TrustLineAsset");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineAsset &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in TrustLineAsset");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineAsset &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TrustLineEntryExtensionV2 {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  int32 liquidityPoolUseCount{};
  _ext_t ext{};

  TrustLineEntryExtensionV2() = default;
  template<typename _liquidityPoolUseCount_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<int32, _liquidityPoolUseCount_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit TrustLineEntryExtensionV2(_liquidityPoolUseCount_T &&_liquidityPoolUseCount,
                                     _ext_T &&_ext)
    : liquidityPoolUseCount(std::forward<_liquidityPoolUseCount_T>(_liquidityPoolUseCount)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TrustLineEntryExtensionV2::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TrustLineEntryExtensionV2::_ext_t;
  using case_type = ::stellar::TrustLineEntryExtensionV2::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TrustLineEntryExtensionV2::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntryExtensionV2::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntryExtensionV2::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntryExtensionV2>
  : xdr_struct_base<field_ptr<::stellar::TrustLineEntryExtensionV2,
                              decltype(::stellar::TrustLineEntryExtensionV2::liquidityPoolUseCount),
                              &::stellar::TrustLineEntryExtensionV2::liquidityPoolUseCount>,
                    field_ptr<::stellar::TrustLineEntryExtensionV2,
                              decltype(::stellar::TrustLineEntryExtensionV2::ext),
                              &::stellar::TrustLineEntryExtensionV2::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntryExtensionV2 &obj) {
    archive(ar, obj.liquidityPoolUseCount, "liquidityPoolUseCount");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntryExtensionV2 &obj) {
    archive(ar, obj.liquidityPoolUseCount, "liquidityPoolUseCount");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct TrustLineEntry {
  struct _ext_t {
    struct _v1_t {
      struct _ext_t {
        using _xdr_case_type = xdr::xdr_traits<int>::case_type;
      private:
        _xdr_case_type v_;
        union {
          TrustLineEntryExtensionV2 v2_;
        };

      public:
        static Constexpr const bool _xdr_has_default_case = false;
        static const std::vector<int> &_xdr_case_values() {
          static const std::vector<int> _xdr_disc_vec {
            0,
            2
          };
          return _xdr_disc_vec;
        }
        static Constexpr int _xdr_field_number(_xdr_case_type which) {
          return which == 0 ? 0
            : which == 2 ? 1
            : -1;
        }
        template<typename _F, typename..._A> static bool
        _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
          switch (_which) {
          case 0:
            return true;
          case 2:
            _f(&_ext_t::v2_, std::forward<_A>(_a)...);
            return true;
          }
          return false;
        }

        _xdr_case_type _xdr_discriminant() const { return v_; }
        void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
          int fnum = _xdr_field_number(which);
          if (fnum < 0 && validate)
            throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
          if (fnum != _xdr_field_number(v_)) {
            this->~_ext_t();
            v_ = which;
            _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
          }
          else
            v_ = which;
        }
        explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
        }
        _ext_t(const _ext_t &source) : v_(source.v_) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
        }
        _ext_t(_ext_t &&source) : v_(source.v_) {
          _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                            std::move(source));
        }
        ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
        _ext_t &operator=(const _ext_t &source) {
          if (_xdr_field_number(v_)
              == _xdr_field_number(source.v_))
            _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
          else {
            this->~_ext_t();
            v_ = std::numeric_limits<_xdr_case_type>::max();
            _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
          }
          v_ = source.v_;
          return *this;
        }
        _ext_t &operator=(_ext_t &&source) {
          if (_xdr_field_number(v_)
               == _xdr_field_number(source.v_))
            _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                              std::move(source));
          else {
            this->~_ext_t();
            v_ = std::numeric_limits<_xdr_case_type>::max();
            _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                              std::move(source));
          }
          v_ = source.v_;
          return *this;
        }

        std::int32_t v() const { return std::int32_t(v_); }
        _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
          _xdr_discriminant(_xdr_d, _xdr_validate);
          return *this;
        }

        TrustLineEntryExtensionV2 &v2() {
          if (_xdr_field_number(v_) == 1)
            return v2_;
          throw xdr::xdr_wrong_union("_ext_t: v2 accessed when not selected");
        }
        const TrustLineEntryExtensionV2 &v2() const {
          if (_xdr_field_number(v_) == 1)
            return v2_;
          throw xdr::xdr_wrong_union("_ext_t: v2 accessed when not selected");
        }
      };

      Liabilities liabilities{};
      _ext_t ext{};

      _v1_t() = default;
      template<typename _liabilities_T,
               typename _ext_T,
               typename = typename
               std::enable_if<std::is_constructible<Liabilities, _liabilities_T>::value
                              && std::is_constructible<_ext_t, _ext_T>::value
                             >::type>
      explicit _v1_t(_liabilities_T &&_liabilities,
                     _ext_T &&_ext)
        : liabilities(std::forward<_liabilities_T>(_liabilities)),
          ext(std::forward<_ext_T>(_ext)) {}
    };

    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      _v1_t v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        1
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 1 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 1:
        _f(&_ext_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    _v1_t &v1() {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
    const _v1_t &v1() const {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
  };

  AccountID accountID{};
  TrustLineAsset asset{};
  int64 balance{};
  int64 limit{};
  uint32 flags{};
  _ext_t ext{};

  TrustLineEntry() = default;
  template<typename _accountID_T,
           typename _asset_T,
           typename _balance_T,
           typename _limit_T,
           typename _flags_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                          && std::is_constructible<TrustLineAsset, _asset_T>::value
                          && std::is_constructible<int64, _balance_T>::value
                          && std::is_constructible<int64, _limit_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit TrustLineEntry(_accountID_T &&_accountID,
                          _asset_T &&_asset,
                          _balance_T &&_balance,
                          _limit_T &&_limit,
                          _flags_T &&_flags,
                          _ext_T &&_ext)
    : accountID(std::forward<_accountID_T>(_accountID)),
      asset(std::forward<_asset_T>(_asset)),
      balance(std::forward<_balance_T>(_balance)),
      limit(std::forward<_limit_T>(_limit)),
      flags(std::forward<_flags_T>(_flags)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t;
  using case_type = ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v2";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry::_ext_t::_v1_t::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntry::_ext_t::_v1_t>
  : xdr_struct_base<field_ptr<::stellar::TrustLineEntry::_ext_t::_v1_t,
                              decltype(::stellar::TrustLineEntry::_ext_t::_v1_t::liabilities),
                              &::stellar::TrustLineEntry::_ext_t::_v1_t::liabilities>,
                    field_ptr<::stellar::TrustLineEntry::_ext_t::_v1_t,
                              decltype(::stellar::TrustLineEntry::_ext_t::_v1_t::ext),
                              &::stellar::TrustLineEntry::_ext_t::_v1_t::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry::_ext_t::_v1_t &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry::_ext_t::_v1_t &obj) {
    archive(ar, obj.liabilities, "liabilities");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::TrustLineEntry::_ext_t;
  using case_type = ::stellar::TrustLineEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v1";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::TrustLineEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::TrustLineEntry>
  : xdr_struct_base<field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::accountID),
                              &::stellar::TrustLineEntry::accountID>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::asset),
                              &::stellar::TrustLineEntry::asset>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::balance),
                              &::stellar::TrustLineEntry::balance>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::limit),
                              &::stellar::TrustLineEntry::limit>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::flags),
                              &::stellar::TrustLineEntry::flags>,
                    field_ptr<::stellar::TrustLineEntry,
                              decltype(::stellar::TrustLineEntry::ext),
                              &::stellar::TrustLineEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::TrustLineEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.limit, "limit");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::TrustLineEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.balance, "balance");
    archive(ar, obj.limit, "limit");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum OfferEntryFlags : std::int32_t {
  PASSIVE_FLAG = 1,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OfferEntryFlags>
  : xdr_integral_base<::stellar::OfferEntryFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::OfferEntryFlags val) {
    switch (val) {
    case ::stellar::PASSIVE_FLAG:
      return "PASSIVE_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::PASSIVE_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_OFFERENTRY_FLAGS = 1;

struct OfferEntry {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  AccountID sellerID{};
  int64 offerID{};
  Asset selling{};
  Asset buying{};
  int64 amount{};
  Price price{};
  uint32 flags{};
  _ext_t ext{};

  OfferEntry() = default;
  template<typename _sellerID_T,
           typename _offerID_T,
           typename _selling_T,
           typename _buying_T,
           typename _amount_T,
           typename _price_T,
           typename _flags_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _sellerID_T>::value
                          && std::is_constructible<int64, _offerID_T>::value
                          && std::is_constructible<Asset, _selling_T>::value
                          && std::is_constructible<Asset, _buying_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                          && std::is_constructible<Price, _price_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit OfferEntry(_sellerID_T &&_sellerID,
                      _offerID_T &&_offerID,
                      _selling_T &&_selling,
                      _buying_T &&_buying,
                      _amount_T &&_amount,
                      _price_T &&_price,
                      _flags_T &&_flags,
                      _ext_T &&_ext)
    : sellerID(std::forward<_sellerID_T>(_sellerID)),
      offerID(std::forward<_offerID_T>(_offerID)),
      selling(std::forward<_selling_T>(_selling)),
      buying(std::forward<_buying_T>(_buying)),
      amount(std::forward<_amount_T>(_amount)),
      price(std::forward<_price_T>(_price)),
      flags(std::forward<_flags_T>(_flags)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::OfferEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::OfferEntry::_ext_t;
  using case_type = ::stellar::OfferEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::OfferEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::OfferEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::OfferEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::OfferEntry>
  : xdr_struct_base<field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::sellerID),
                              &::stellar::OfferEntry::sellerID>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::offerID),
                              &::stellar::OfferEntry::offerID>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::selling),
                              &::stellar::OfferEntry::selling>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::buying),
                              &::stellar::OfferEntry::buying>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::amount),
                              &::stellar::OfferEntry::amount>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::price),
                              &::stellar::OfferEntry::price>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::flags),
                              &::stellar::OfferEntry::flags>,
                    field_ptr<::stellar::OfferEntry,
                              decltype(::stellar::OfferEntry::ext),
                              &::stellar::OfferEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::OfferEntry &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::OfferEntry &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    archive(ar, obj.selling, "selling");
    archive(ar, obj.buying, "buying");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.price, "price");
    archive(ar, obj.flags, "flags");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct DataEntry {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  AccountID accountID{};
  string64 dataName{};
  DataValue dataValue{};
  _ext_t ext{};

  DataEntry() = default;
  template<typename _accountID_T,
           typename _dataName_T,
           typename _dataValue_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                          && std::is_constructible<string64, _dataName_T>::value
                          && std::is_constructible<DataValue, _dataValue_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit DataEntry(_accountID_T &&_accountID,
                     _dataName_T &&_dataName,
                     _dataValue_T &&_dataValue,
                     _ext_T &&_ext)
    : accountID(std::forward<_accountID_T>(_accountID)),
      dataName(std::forward<_dataName_T>(_dataName)),
      dataValue(std::forward<_dataValue_T>(_dataValue)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::DataEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::DataEntry::_ext_t;
  using case_type = ::stellar::DataEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::DataEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::DataEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::DataEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::DataEntry>
  : xdr_struct_base<field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::accountID),
                              &::stellar::DataEntry::accountID>,
                    field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::dataName),
                              &::stellar::DataEntry::dataName>,
                    field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::dataValue),
                              &::stellar::DataEntry::dataValue>,
                    field_ptr<::stellar::DataEntry,
                              decltype(::stellar::DataEntry::ext),
                              &::stellar::DataEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::DataEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.dataName, "dataName");
    archive(ar, obj.dataValue, "dataValue");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::DataEntry &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.dataName, "dataName");
    archive(ar, obj.dataValue, "dataValue");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ClaimPredicateType : std::int32_t {
  CLAIM_PREDICATE_UNCONDITIONAL = 0,
  CLAIM_PREDICATE_AND = 1,
  CLAIM_PREDICATE_OR = 2,
  CLAIM_PREDICATE_NOT = 3,
  CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME = 4,
  CLAIM_PREDICATE_BEFORE_RELATIVE_TIME = 5,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimPredicateType>
  : xdr_integral_base<::stellar::ClaimPredicateType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ClaimPredicateType val) {
    switch (val) {
    case ::stellar::CLAIM_PREDICATE_UNCONDITIONAL:
      return "CLAIM_PREDICATE_UNCONDITIONAL";
    case ::stellar::CLAIM_PREDICATE_AND:
      return "CLAIM_PREDICATE_AND";
    case ::stellar::CLAIM_PREDICATE_OR:
      return "CLAIM_PREDICATE_OR";
    case ::stellar::CLAIM_PREDICATE_NOT:
      return "CLAIM_PREDICATE_NOT";
    case ::stellar::CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME:
      return "CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME";
    case ::stellar::CLAIM_PREDICATE_BEFORE_RELATIVE_TIME:
      return "CLAIM_PREDICATE_BEFORE_RELATIVE_TIME";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CLAIM_PREDICATE_UNCONDITIONAL,
      ::stellar::CLAIM_PREDICATE_AND,
      ::stellar::CLAIM_PREDICATE_OR,
      ::stellar::CLAIM_PREDICATE_NOT,
      ::stellar::CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME,
      ::stellar::CLAIM_PREDICATE_BEFORE_RELATIVE_TIME
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct ClaimPredicate {
  using _xdr_case_type = xdr::xdr_traits<ClaimPredicateType>::case_type;
private:
  _xdr_case_type type_;
  union {
    xdr::xvector<ClaimPredicate,2> andPredicates_;
    xdr::xvector<ClaimPredicate,2> orPredicates_;
    xdr::pointer<ClaimPredicate> notPredicate_;
    int64 absBefore_;
    int64 relBefore_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<ClaimPredicateType> &_xdr_case_values() {
    static const std::vector<ClaimPredicateType> _xdr_disc_vec {
      CLAIM_PREDICATE_UNCONDITIONAL,
      CLAIM_PREDICATE_AND,
      CLAIM_PREDICATE_OR,
      CLAIM_PREDICATE_NOT,
      CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME,
      CLAIM_PREDICATE_BEFORE_RELATIVE_TIME
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == CLAIM_PREDICATE_UNCONDITIONAL ? 0
      : which == CLAIM_PREDICATE_AND ? 1
      : which == CLAIM_PREDICATE_OR ? 2
      : which == CLAIM_PREDICATE_NOT ? 3
      : which == CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME ? 4
      : which == CLAIM_PREDICATE_BEFORE_RELATIVE_TIME ? 5
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case CLAIM_PREDICATE_UNCONDITIONAL:
      return true;
    case CLAIM_PREDICATE_AND:
      _f(&ClaimPredicate::andPredicates_, std::forward<_A>(_a)...);
      return true;
    case CLAIM_PREDICATE_OR:
      _f(&ClaimPredicate::orPredicates_, std::forward<_A>(_a)...);
      return true;
    case CLAIM_PREDICATE_NOT:
      _f(&ClaimPredicate::notPredicate_, std::forward<_A>(_a)...);
      return true;
    case CLAIM_PREDICATE_BEFORE_ABSOLUTE_TIME:
      _f(&ClaimPredicate::absBefore_, std::forward<_A>(_a)...);
      return true;
    case CLAIM_PREDICATE_BEFORE_RELATIVE_TIME:
      _f(&ClaimPredicate::relBefore_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in ClaimPredicate");
    if (fnum != _xdr_field_number(type_)) {
      this->~ClaimPredicate();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit ClaimPredicate(ClaimPredicateType which = ClaimPredicateType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  ClaimPredicate(const ClaimPredicate &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  ClaimPredicate(ClaimPredicate &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~ClaimPredicate() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  ClaimPredicate &operator=(const ClaimPredicate &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~ClaimPredicate();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  ClaimPredicate &operator=(ClaimPredicate &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~ClaimPredicate();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ClaimPredicateType type() const { return ClaimPredicateType(type_); }
  ClaimPredicate &type(ClaimPredicateType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  xdr::xvector<ClaimPredicate,2> &andPredicates() {
    if (_xdr_field_number(type_) == 1)
      return andPredicates_;
    throw xdr::xdr_wrong_union("ClaimPredicate: andPredicates accessed when not selected");
  }
  const xdr::xvector<ClaimPredicate,2> &andPredicates() const {
    if (_xdr_field_number(type_) == 1)
      return andPredicates_;
    throw xdr::xdr_wrong_union("ClaimPredicate: andPredicates accessed when not selected");
  }
  xdr::xvector<ClaimPredicate,2> &orPredicates() {
    if (_xdr_field_number(type_) == 2)
      return orPredicates_;
    throw xdr::xdr_wrong_union("ClaimPredicate: orPredicates accessed when not selected");
  }
  const xdr::xvector<ClaimPredicate,2> &orPredicates() const {
    if (_xdr_field_number(type_) == 2)
      return orPredicates_;
    throw xdr::xdr_wrong_union("ClaimPredicate: orPredicates accessed when not selected");
  }
  xdr::pointer<ClaimPredicate> &notPredicate() {
    if (_xdr_field_number(type_) == 3)
      return notPredicate_;
    throw xdr::xdr_wrong_union("ClaimPredicate: notPredicate accessed when not selected");
  }
  const xdr::pointer<ClaimPredicate> &notPredicate() const {
    if (_xdr_field_number(type_) == 3)
      return notPredicate_;
    throw xdr::xdr_wrong_union("ClaimPredicate: notPredicate accessed when not selected");
  }
  int64 &absBefore() {
    if (_xdr_field_number(type_) == 4)
      return absBefore_;
    throw xdr::xdr_wrong_union("ClaimPredicate: absBefore accessed when not selected");
  }
  const int64 &absBefore() const {
    if (_xdr_field_number(type_) == 4)
      return absBefore_;
    throw xdr::xdr_wrong_union("ClaimPredicate: absBefore accessed when not selected");
  }
  int64 &relBefore() {
    if (_xdr_field_number(type_) == 5)
      return relBefore_;
    throw xdr::xdr_wrong_union("ClaimPredicate: relBefore accessed when not selected");
  }
  const int64 &relBefore() const {
    if (_xdr_field_number(type_) == 5)
      return relBefore_;
    throw xdr::xdr_wrong_union("ClaimPredicate: relBefore accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimPredicate> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ClaimPredicate;
  using case_type = ::stellar::ClaimPredicate::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "andPredicates";
    case 2:
      return "orPredicates";
    case 3:
      return "notPredicate";
    case 4:
      return "absBefore";
    case 5:
      return "relBefore";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ClaimPredicate &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in ClaimPredicate");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimPredicate &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in ClaimPredicate");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimPredicate &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ClaimantType : std::int32_t {
  CLAIMANT_TYPE_V0 = 0,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimantType>
  : xdr_integral_base<::stellar::ClaimantType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ClaimantType val) {
    switch (val) {
    case ::stellar::CLAIMANT_TYPE_V0:
      return "CLAIMANT_TYPE_V0";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CLAIMANT_TYPE_V0
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct Claimant {
  struct _v0_t {
    AccountID destination{};
    ClaimPredicate predicate{};

    _v0_t() = default;
    template<typename _destination_T,
             typename _predicate_T,
             typename = typename
             std::enable_if<std::is_constructible<AccountID, _destination_T>::value
                            && std::is_constructible<ClaimPredicate, _predicate_T>::value
                           >::type>
    explicit _v0_t(_destination_T &&_destination,
                   _predicate_T &&_predicate)
      : destination(std::forward<_destination_T>(_destination)),
        predicate(std::forward<_predicate_T>(_predicate)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<ClaimantType>::case_type;
private:
  _xdr_case_type type_;
  union {
    _v0_t v0_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<ClaimantType> &_xdr_case_values() {
    static const std::vector<ClaimantType> _xdr_disc_vec {
      CLAIMANT_TYPE_V0
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == CLAIMANT_TYPE_V0 ? 1
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case CLAIMANT_TYPE_V0:
      _f(&Claimant::v0_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in Claimant");
    if (fnum != _xdr_field_number(type_)) {
      this->~Claimant();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit Claimant(ClaimantType which = ClaimantType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  Claimant(const Claimant &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  Claimant(Claimant &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~Claimant() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  Claimant &operator=(const Claimant &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~Claimant();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  Claimant &operator=(Claimant &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~Claimant();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ClaimantType type() const { return ClaimantType(type_); }
  Claimant &type(ClaimantType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _v0_t &v0() {
    if (_xdr_field_number(type_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("Claimant: v0 accessed when not selected");
  }
  const _v0_t &v0() const {
    if (_xdr_field_number(type_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("Claimant: v0 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::Claimant::_v0_t>
  : xdr_struct_base<field_ptr<::stellar::Claimant::_v0_t,
                              decltype(::stellar::Claimant::_v0_t::destination),
                              &::stellar::Claimant::_v0_t::destination>,
                    field_ptr<::stellar::Claimant::_v0_t,
                              decltype(::stellar::Claimant::_v0_t::predicate),
                              &::stellar::Claimant::_v0_t::predicate>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Claimant::_v0_t &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.predicate, "predicate");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Claimant::_v0_t &obj) {
    archive(ar, obj.destination, "destination");
    archive(ar, obj.predicate, "predicate");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::Claimant> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::Claimant;
  using case_type = ::stellar::Claimant::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v0";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::Claimant &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in Claimant");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::Claimant &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in Claimant");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::Claimant &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ClaimableBalanceIDType : std::int32_t {
  CLAIMABLE_BALANCE_ID_TYPE_V0 = 0,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimableBalanceIDType>
  : xdr_integral_base<::stellar::ClaimableBalanceIDType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ClaimableBalanceIDType val) {
    switch (val) {
    case ::stellar::CLAIMABLE_BALANCE_ID_TYPE_V0:
      return "CLAIMABLE_BALANCE_ID_TYPE_V0";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CLAIMABLE_BALANCE_ID_TYPE_V0
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

struct ClaimableBalanceID {
  using _xdr_case_type = xdr::xdr_traits<ClaimableBalanceIDType>::case_type;
private:
  _xdr_case_type type_;
  union {
    Hash v0_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<ClaimableBalanceIDType> &_xdr_case_values() {
    static const std::vector<ClaimableBalanceIDType> _xdr_disc_vec {
      CLAIMABLE_BALANCE_ID_TYPE_V0
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == CLAIMABLE_BALANCE_ID_TYPE_V0 ? 1
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case CLAIMABLE_BALANCE_ID_TYPE_V0:
      _f(&ClaimableBalanceID::v0_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in ClaimableBalanceID");
    if (fnum != _xdr_field_number(type_)) {
      this->~ClaimableBalanceID();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit ClaimableBalanceID(ClaimableBalanceIDType which = ClaimableBalanceIDType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  ClaimableBalanceID(const ClaimableBalanceID &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  ClaimableBalanceID(ClaimableBalanceID &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~ClaimableBalanceID() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  ClaimableBalanceID &operator=(const ClaimableBalanceID &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~ClaimableBalanceID();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  ClaimableBalanceID &operator=(ClaimableBalanceID &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~ClaimableBalanceID();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ClaimableBalanceIDType type() const { return ClaimableBalanceIDType(type_); }
  ClaimableBalanceID &type(ClaimableBalanceIDType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  Hash &v0() {
    if (_xdr_field_number(type_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("ClaimableBalanceID: v0 accessed when not selected");
  }
  const Hash &v0() const {
    if (_xdr_field_number(type_) == 1)
      return v0_;
    throw xdr::xdr_wrong_union("ClaimableBalanceID: v0 accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimableBalanceID> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ClaimableBalanceID;
  using case_type = ::stellar::ClaimableBalanceID::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v0";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ClaimableBalanceID &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in ClaimableBalanceID");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimableBalanceID &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in ClaimableBalanceID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimableBalanceID &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum ClaimableBalanceFlags : std::int32_t {
  CLAIMABLE_BALANCE_CLAWBACK_ENABLED_FLAG = 0x1,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimableBalanceFlags>
  : xdr_integral_base<::stellar::ClaimableBalanceFlags, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::ClaimableBalanceFlags val) {
    switch (val) {
    case ::stellar::CLAIMABLE_BALANCE_CLAWBACK_ENABLED_FLAG:
      return "CLAIMABLE_BALANCE_CLAWBACK_ENABLED_FLAG";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::CLAIMABLE_BALANCE_CLAWBACK_ENABLED_FLAG
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

Constexpr const std::uint32_t MASK_CLAIMABLE_BALANCE_FLAGS = 0x1;

struct ClaimableBalanceEntryExtensionV1 {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  _ext_t ext{};
  uint32 flags{};

  ClaimableBalanceEntryExtensionV1() = default;
  template<typename _ext_T,
           typename _flags_T,
           typename = typename
           std::enable_if<std::is_constructible<_ext_t, _ext_T>::value
                          && std::is_constructible<uint32, _flags_T>::value
                         >::type>
  explicit ClaimableBalanceEntryExtensionV1(_ext_T &&_ext,
                                            _flags_T &&_flags)
    : ext(std::forward<_ext_T>(_ext)),
      flags(std::forward<_flags_T>(_flags)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimableBalanceEntryExtensionV1::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ClaimableBalanceEntryExtensionV1::_ext_t;
  using case_type = ::stellar::ClaimableBalanceEntryExtensionV1::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ClaimableBalanceEntryExtensionV1::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimableBalanceEntryExtensionV1::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimableBalanceEntryExtensionV1::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::ClaimableBalanceEntryExtensionV1>
  : xdr_struct_base<field_ptr<::stellar::ClaimableBalanceEntryExtensionV1,
                              decltype(::stellar::ClaimableBalanceEntryExtensionV1::ext),
                              &::stellar::ClaimableBalanceEntryExtensionV1::ext>,
                    field_ptr<::stellar::ClaimableBalanceEntryExtensionV1,
                              decltype(::stellar::ClaimableBalanceEntryExtensionV1::flags),
                              &::stellar::ClaimableBalanceEntryExtensionV1::flags>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimableBalanceEntryExtensionV1 &obj) {
    archive(ar, obj.ext, "ext");
    archive(ar, obj.flags, "flags");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimableBalanceEntryExtensionV1 &obj) {
    archive(ar, obj.ext, "ext");
    archive(ar, obj.flags, "flags");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct ClaimableBalanceEntry {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      ClaimableBalanceEntryExtensionV1 v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        1
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 1 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 1:
        _f(&_ext_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    ClaimableBalanceEntryExtensionV1 &v1() {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
    const ClaimableBalanceEntryExtensionV1 &v1() const {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
  };

  ClaimableBalanceID balanceID{};
  xdr::xvector<Claimant,10> claimants{};
  Asset asset{};
  int64 amount{};
  _ext_t ext{};

  ClaimableBalanceEntry() = default;
  template<typename _balanceID_T,
           typename _claimants_T,
           typename _asset_T,
           typename _amount_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<ClaimableBalanceID, _balanceID_T>::value
                          && std::is_constructible<xdr::xvector<Claimant,10>, _claimants_T>::value
                          && std::is_constructible<Asset, _asset_T>::value
                          && std::is_constructible<int64, _amount_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit ClaimableBalanceEntry(_balanceID_T &&_balanceID,
                                 _claimants_T &&_claimants,
                                 _asset_T &&_asset,
                                 _amount_T &&_amount,
                                 _ext_T &&_ext)
    : balanceID(std::forward<_balanceID_T>(_balanceID)),
      claimants(std::forward<_claimants_T>(_claimants)),
      asset(std::forward<_asset_T>(_asset)),
      amount(std::forward<_amount_T>(_amount)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::ClaimableBalanceEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::ClaimableBalanceEntry::_ext_t;
  using case_type = ::stellar::ClaimableBalanceEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v1";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::ClaimableBalanceEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimableBalanceEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimableBalanceEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::ClaimableBalanceEntry>
  : xdr_struct_base<field_ptr<::stellar::ClaimableBalanceEntry,
                              decltype(::stellar::ClaimableBalanceEntry::balanceID),
                              &::stellar::ClaimableBalanceEntry::balanceID>,
                    field_ptr<::stellar::ClaimableBalanceEntry,
                              decltype(::stellar::ClaimableBalanceEntry::claimants),
                              &::stellar::ClaimableBalanceEntry::claimants>,
                    field_ptr<::stellar::ClaimableBalanceEntry,
                              decltype(::stellar::ClaimableBalanceEntry::asset),
                              &::stellar::ClaimableBalanceEntry::asset>,
                    field_ptr<::stellar::ClaimableBalanceEntry,
                              decltype(::stellar::ClaimableBalanceEntry::amount),
                              &::stellar::ClaimableBalanceEntry::amount>,
                    field_ptr<::stellar::ClaimableBalanceEntry,
                              decltype(::stellar::ClaimableBalanceEntry::ext),
                              &::stellar::ClaimableBalanceEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::ClaimableBalanceEntry &obj) {
    archive(ar, obj.balanceID, "balanceID");
    archive(ar, obj.claimants, "claimants");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::ClaimableBalanceEntry &obj) {
    archive(ar, obj.balanceID, "balanceID");
    archive(ar, obj.claimants, "claimants");
    archive(ar, obj.asset, "asset");
    archive(ar, obj.amount, "amount");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct LiquidityPoolConstantProductParameters {
  Asset assetA{};
  Asset assetB{};
  int32 fee{};

  LiquidityPoolConstantProductParameters() = default;
  template<typename _assetA_T,
           typename _assetB_T,
           typename _fee_T,
           typename = typename
           std::enable_if<std::is_constructible<Asset, _assetA_T>::value
                          && std::is_constructible<Asset, _assetB_T>::value
                          && std::is_constructible<int32, _fee_T>::value
                         >::type>
  explicit LiquidityPoolConstantProductParameters(_assetA_T &&_assetA,
                                                  _assetB_T &&_assetB,
                                                  _fee_T &&_fee)
    : assetA(std::forward<_assetA_T>(_assetA)),
      assetB(std::forward<_assetB_T>(_assetB)),
      fee(std::forward<_fee_T>(_fee)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LiquidityPoolConstantProductParameters>
  : xdr_struct_base<field_ptr<::stellar::LiquidityPoolConstantProductParameters,
                              decltype(::stellar::LiquidityPoolConstantProductParameters::assetA),
                              &::stellar::LiquidityPoolConstantProductParameters::assetA>,
                    field_ptr<::stellar::LiquidityPoolConstantProductParameters,
                              decltype(::stellar::LiquidityPoolConstantProductParameters::assetB),
                              &::stellar::LiquidityPoolConstantProductParameters::assetB>,
                    field_ptr<::stellar::LiquidityPoolConstantProductParameters,
                              decltype(::stellar::LiquidityPoolConstantProductParameters::fee),
                              &::stellar::LiquidityPoolConstantProductParameters::fee>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LiquidityPoolConstantProductParameters &obj) {
    archive(ar, obj.assetA, "assetA");
    archive(ar, obj.assetB, "assetB");
    archive(ar, obj.fee, "fee");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LiquidityPoolConstantProductParameters &obj) {
    archive(ar, obj.assetA, "assetA");
    archive(ar, obj.assetB, "assetB");
    archive(ar, obj.fee, "fee");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct LiquidityPoolEntry {
  struct _body_t {
    struct _constantProduct_t {
      LiquidityPoolConstantProductParameters params{};
      int64 reserveA{};
      int64 reserveB{};
      int64 totalPoolShares{};
      int64 poolSharesTrustLineCount{};

      _constantProduct_t() = default;
      template<typename _params_T,
               typename _reserveA_T,
               typename _reserveB_T,
               typename _totalPoolShares_T,
               typename _poolSharesTrustLineCount_T,
               typename = typename
               std::enable_if<std::is_constructible<LiquidityPoolConstantProductParameters, _params_T>::value
                              && std::is_constructible<int64, _reserveA_T>::value
                              && std::is_constructible<int64, _reserveB_T>::value
                              && std::is_constructible<int64, _totalPoolShares_T>::value
                              && std::is_constructible<int64, _poolSharesTrustLineCount_T>::value
                             >::type>
      explicit _constantProduct_t(_params_T &&_params,
                                  _reserveA_T &&_reserveA,
                                  _reserveB_T &&_reserveB,
                                  _totalPoolShares_T &&_totalPoolShares,
                                  _poolSharesTrustLineCount_T &&_poolSharesTrustLineCount)
        : params(std::forward<_params_T>(_params)),
          reserveA(std::forward<_reserveA_T>(_reserveA)),
          reserveB(std::forward<_reserveB_T>(_reserveB)),
          totalPoolShares(std::forward<_totalPoolShares_T>(_totalPoolShares)),
          poolSharesTrustLineCount(std::forward<_poolSharesTrustLineCount_T>(_poolSharesTrustLineCount)) {}
    };

    using _xdr_case_type = xdr::xdr_traits<LiquidityPoolType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      _constantProduct_t constantProduct_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<LiquidityPoolType> &_xdr_case_values() {
      static const std::vector<LiquidityPoolType> _xdr_disc_vec {
        LIQUIDITY_POOL_CONSTANT_PRODUCT
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == LIQUIDITY_POOL_CONSTANT_PRODUCT ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case LIQUIDITY_POOL_CONSTANT_PRODUCT:
        _f(&_body_t::constantProduct_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _body_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_body_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _body_t(LiquidityPoolType which = LiquidityPoolType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _body_t(const _body_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _body_t(_body_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_body_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _body_t &operator=(const _body_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_body_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _body_t &operator=(_body_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_body_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    LiquidityPoolType type() const { return LiquidityPoolType(type_); }
    _body_t &type(LiquidityPoolType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    _constantProduct_t &constantProduct() {
      if (_xdr_field_number(type_) == 1)
        return constantProduct_;
      throw xdr::xdr_wrong_union("_body_t: constantProduct accessed when not selected");
    }
    const _constantProduct_t &constantProduct() const {
      if (_xdr_field_number(type_) == 1)
        return constantProduct_;
      throw xdr::xdr_wrong_union("_body_t: constantProduct accessed when not selected");
    }
  };

  PoolID liquidityPoolID{};
  _body_t body{};

  LiquidityPoolEntry() = default;
  template<typename _liquidityPoolID_T,
           typename _body_T,
           typename = typename
           std::enable_if<std::is_constructible<PoolID, _liquidityPoolID_T>::value
                          && std::is_constructible<_body_t, _body_T>::value
                         >::type>
  explicit LiquidityPoolEntry(_liquidityPoolID_T &&_liquidityPoolID,
                              _body_T &&_body)
    : liquidityPoolID(std::forward<_liquidityPoolID_T>(_liquidityPoolID)),
      body(std::forward<_body_T>(_body)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t>
  : xdr_struct_base<field_ptr<::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t,
                              decltype(::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::params),
                              &::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::params>,
                    field_ptr<::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t,
                              decltype(::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::reserveA),
                              &::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::reserveA>,
                    field_ptr<::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t,
                              decltype(::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::reserveB),
                              &::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::reserveB>,
                    field_ptr<::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t,
                              decltype(::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::totalPoolShares),
                              &::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::totalPoolShares>,
                    field_ptr<::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t,
                              decltype(::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::poolSharesTrustLineCount),
                              &::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t::poolSharesTrustLineCount>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t &obj) {
    archive(ar, obj.params, "params");
    archive(ar, obj.reserveA, "reserveA");
    archive(ar, obj.reserveB, "reserveB");
    archive(ar, obj.totalPoolShares, "totalPoolShares");
    archive(ar, obj.poolSharesTrustLineCount, "poolSharesTrustLineCount");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LiquidityPoolEntry::_body_t::_constantProduct_t &obj) {
    archive(ar, obj.params, "params");
    archive(ar, obj.reserveA, "reserveA");
    archive(ar, obj.reserveB, "reserveB");
    archive(ar, obj.totalPoolShares, "totalPoolShares");
    archive(ar, obj.poolSharesTrustLineCount, "poolSharesTrustLineCount");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LiquidityPoolEntry::_body_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LiquidityPoolEntry::_body_t;
  using case_type = ::stellar::LiquidityPoolEntry::_body_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "constantProduct";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LiquidityPoolEntry::_body_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _body_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LiquidityPoolEntry::_body_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _body_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LiquidityPoolEntry::_body_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LiquidityPoolEntry>
  : xdr_struct_base<field_ptr<::stellar::LiquidityPoolEntry,
                              decltype(::stellar::LiquidityPoolEntry::liquidityPoolID),
                              &::stellar::LiquidityPoolEntry::liquidityPoolID>,
                    field_ptr<::stellar::LiquidityPoolEntry,
                              decltype(::stellar::LiquidityPoolEntry::body),
                              &::stellar::LiquidityPoolEntry::body>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LiquidityPoolEntry &obj) {
    archive(ar, obj.liquidityPoolID, "liquidityPoolID");
    archive(ar, obj.body, "body");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LiquidityPoolEntry &obj) {
    archive(ar, obj.liquidityPoolID, "liquidityPoolID");
    archive(ar, obj.body, "body");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct LedgerEntryExtensionV1 {
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

  };

  SponsorshipDescriptor sponsoringID{};
  _ext_t ext{};

  LedgerEntryExtensionV1() = default;
  template<typename _sponsoringID_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<SponsorshipDescriptor, _sponsoringID_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit LedgerEntryExtensionV1(_sponsoringID_T &&_sponsoringID,
                                  _ext_T &&_ext)
    : sponsoringID(std::forward<_sponsoringID_T>(_sponsoringID)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LedgerEntryExtensionV1::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LedgerEntryExtensionV1::_ext_t;
  using case_type = ::stellar::LedgerEntryExtensionV1::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LedgerEntryExtensionV1::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntryExtensionV1::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntryExtensionV1::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerEntryExtensionV1>
  : xdr_struct_base<field_ptr<::stellar::LedgerEntryExtensionV1,
                              decltype(::stellar::LedgerEntryExtensionV1::sponsoringID),
                              &::stellar::LedgerEntryExtensionV1::sponsoringID>,
                    field_ptr<::stellar::LedgerEntryExtensionV1,
                              decltype(::stellar::LedgerEntryExtensionV1::ext),
                              &::stellar::LedgerEntryExtensionV1::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntryExtensionV1 &obj) {
    archive(ar, obj.sponsoringID, "sponsoringID");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntryExtensionV1 &obj) {
    archive(ar, obj.sponsoringID, "sponsoringID");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct LedgerEntry {
  struct _data_t {
    using _xdr_case_type = xdr::xdr_traits<LedgerEntryType>::case_type;
  private:
    _xdr_case_type type_;
    union {
      AccountEntry account_;
      TrustLineEntry trustLine_;
      OfferEntry offer_;
      DataEntry data_;
      ClaimableBalanceEntry claimableBalance_;
      LiquidityPoolEntry liquidityPool_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<LedgerEntryType> &_xdr_case_values() {
      static const std::vector<LedgerEntryType> _xdr_disc_vec {
        ACCOUNT,
        TRUSTLINE,
        OFFER,
        DATA,
        CLAIMABLE_BALANCE,
        LIQUIDITY_POOL
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == ACCOUNT ? 1
        : which == TRUSTLINE ? 2
        : which == OFFER ? 3
        : which == DATA ? 4
        : which == CLAIMABLE_BALANCE ? 5
        : which == LIQUIDITY_POOL ? 6
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case ACCOUNT:
        _f(&_data_t::account_, std::forward<_A>(_a)...);
        return true;
      case TRUSTLINE:
        _f(&_data_t::trustLine_, std::forward<_A>(_a)...);
        return true;
      case OFFER:
        _f(&_data_t::offer_, std::forward<_A>(_a)...);
        return true;
      case DATA:
        _f(&_data_t::data_, std::forward<_A>(_a)...);
        return true;
      case CLAIMABLE_BALANCE:
        _f(&_data_t::claimableBalance_, std::forward<_A>(_a)...);
        return true;
      case LIQUIDITY_POOL:
        _f(&_data_t::liquidityPool_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return type_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of type in _data_t");
      if (fnum != _xdr_field_number(type_)) {
        this->~_data_t();
        type_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
      }
      else
        type_ = which;
    }
    explicit _data_t(LedgerEntryType which = LedgerEntryType{}) : type_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    _data_t(const _data_t &source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    _data_t(_data_t &&source) : type_(source.type_) {
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    ~_data_t() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
    _data_t &operator=(const _data_t &source) {
      if (_xdr_field_number(type_)
          == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
      else {
        this->~_data_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
      }
      type_ = source.type_;
      return *this;
    }
    _data_t &operator=(_data_t &&source) {
      if (_xdr_field_number(type_)
           == _xdr_field_number(source.type_))
        _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                          std::move(source));
      else {
        this->~_data_t();
        type_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                          std::move(source));
      }
      type_ = source.type_;
      return *this;
    }

    LedgerEntryType type() const { return LedgerEntryType(type_); }
    _data_t &type(LedgerEntryType _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    AccountEntry &account() {
      if (_xdr_field_number(type_) == 1)
        return account_;
      throw xdr::xdr_wrong_union("_data_t: account accessed when not selected");
    }
    const AccountEntry &account() const {
      if (_xdr_field_number(type_) == 1)
        return account_;
      throw xdr::xdr_wrong_union("_data_t: account accessed when not selected");
    }
    TrustLineEntry &trustLine() {
      if (_xdr_field_number(type_) == 2)
        return trustLine_;
      throw xdr::xdr_wrong_union("_data_t: trustLine accessed when not selected");
    }
    const TrustLineEntry &trustLine() const {
      if (_xdr_field_number(type_) == 2)
        return trustLine_;
      throw xdr::xdr_wrong_union("_data_t: trustLine accessed when not selected");
    }
    OfferEntry &offer() {
      if (_xdr_field_number(type_) == 3)
        return offer_;
      throw xdr::xdr_wrong_union("_data_t: offer accessed when not selected");
    }
    const OfferEntry &offer() const {
      if (_xdr_field_number(type_) == 3)
        return offer_;
      throw xdr::xdr_wrong_union("_data_t: offer accessed when not selected");
    }
    DataEntry &data() {
      if (_xdr_field_number(type_) == 4)
        return data_;
      throw xdr::xdr_wrong_union("_data_t: data accessed when not selected");
    }
    const DataEntry &data() const {
      if (_xdr_field_number(type_) == 4)
        return data_;
      throw xdr::xdr_wrong_union("_data_t: data accessed when not selected");
    }
    ClaimableBalanceEntry &claimableBalance() {
      if (_xdr_field_number(type_) == 5)
        return claimableBalance_;
      throw xdr::xdr_wrong_union("_data_t: claimableBalance accessed when not selected");
    }
    const ClaimableBalanceEntry &claimableBalance() const {
      if (_xdr_field_number(type_) == 5)
        return claimableBalance_;
      throw xdr::xdr_wrong_union("_data_t: claimableBalance accessed when not selected");
    }
    LiquidityPoolEntry &liquidityPool() {
      if (_xdr_field_number(type_) == 6)
        return liquidityPool_;
      throw xdr::xdr_wrong_union("_data_t: liquidityPool accessed when not selected");
    }
    const LiquidityPoolEntry &liquidityPool() const {
      if (_xdr_field_number(type_) == 6)
        return liquidityPool_;
      throw xdr::xdr_wrong_union("_data_t: liquidityPool accessed when not selected");
    }
  };
  struct _ext_t {
    using _xdr_case_type = xdr::xdr_traits<int>::case_type;
  private:
    _xdr_case_type v_;
    union {
      LedgerEntryExtensionV1 v1_;
    };

  public:
    static Constexpr const bool _xdr_has_default_case = false;
    static const std::vector<int> &_xdr_case_values() {
      static const std::vector<int> _xdr_disc_vec {
        0,
        1
      };
      return _xdr_disc_vec;
    }
    static Constexpr int _xdr_field_number(_xdr_case_type which) {
      return which == 0 ? 0
        : which == 1 ? 1
        : -1;
    }
    template<typename _F, typename..._A> static bool
    _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
      switch (_which) {
      case 0:
        return true;
      case 1:
        _f(&_ext_t::v1_, std::forward<_A>(_a)...);
        return true;
      }
      return false;
    }

    _xdr_case_type _xdr_discriminant() const { return v_; }
    void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
      int fnum = _xdr_field_number(which);
      if (fnum < 0 && validate)
        throw xdr::xdr_bad_discriminant("bad value of v in _ext_t");
      if (fnum != _xdr_field_number(v_)) {
        this->~_ext_t();
        v_ = which;
        _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
      }
      else
        v_ = which;
    }
    explicit _ext_t(std::int32_t which = std::int32_t{}) : v_(which) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this);
    }
    _ext_t(const _ext_t &source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this, source);
    }
    _ext_t(_ext_t &&source) : v_(source.v_) {
      _xdr_with_mem_ptr(xdr::field_constructor, v_, *this,
                        std::move(source));
    }
    ~_ext_t() { _xdr_with_mem_ptr(xdr::field_destructor, v_, *this); }
    _ext_t &operator=(const _ext_t &source) {
      if (_xdr_field_number(v_)
          == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this, source);
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this, source);
      }
      v_ = source.v_;
      return *this;
    }
    _ext_t &operator=(_ext_t &&source) {
      if (_xdr_field_number(v_)
           == _xdr_field_number(source.v_))
        _xdr_with_mem_ptr(xdr::field_assigner, v_, *this,
                          std::move(source));
      else {
        this->~_ext_t();
        v_ = std::numeric_limits<_xdr_case_type>::max();
        _xdr_with_mem_ptr(xdr::field_constructor, source.v_, *this,
                          std::move(source));
      }
      v_ = source.v_;
      return *this;
    }

    std::int32_t v() const { return std::int32_t(v_); }
    _ext_t &v(int _xdr_d, bool _xdr_validate = true) {
      _xdr_discriminant(_xdr_d, _xdr_validate);
      return *this;
    }

    LedgerEntryExtensionV1 &v1() {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
    const LedgerEntryExtensionV1 &v1() const {
      if (_xdr_field_number(v_) == 1)
        return v1_;
      throw xdr::xdr_wrong_union("_ext_t: v1 accessed when not selected");
    }
  };

  uint32 lastModifiedLedgerSeq{};
  _data_t data{};
  _ext_t ext{};

  LedgerEntry() = default;
  template<typename _lastModifiedLedgerSeq_T,
           typename _data_T,
           typename _ext_T,
           typename = typename
           std::enable_if<std::is_constructible<uint32, _lastModifiedLedgerSeq_T>::value
                          && std::is_constructible<_data_t, _data_T>::value
                          && std::is_constructible<_ext_t, _ext_T>::value
                         >::type>
  explicit LedgerEntry(_lastModifiedLedgerSeq_T &&_lastModifiedLedgerSeq,
                       _data_T &&_data,
                       _ext_T &&_ext)
    : lastModifiedLedgerSeq(std::forward<_lastModifiedLedgerSeq_T>(_lastModifiedLedgerSeq)),
      data(std::forward<_data_T>(_data)),
      ext(std::forward<_ext_T>(_ext)) {}
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LedgerEntry::_data_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LedgerEntry::_data_t;
  using case_type = ::stellar::LedgerEntry::_data_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "account";
    case 2:
      return "trustLine";
    case 3:
      return "offer";
    case 4:
      return "data";
    case 5:
      return "claimableBalance";
    case 6:
      return "liquidityPool";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LedgerEntry::_data_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in _data_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntry::_data_t &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in _data_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntry::_data_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerEntry::_ext_t> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LedgerEntry::_ext_t;
  using case_type = ::stellar::LedgerEntry::_ext_t::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().v());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "v1";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LedgerEntry::_ext_t &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntry::_ext_t &obj) {
    xdr::archive(ar, obj.v(), "v");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of v in _ext_t");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntry::_ext_t &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "v");
    obj.v(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.v(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerEntry>
  : xdr_struct_base<field_ptr<::stellar::LedgerEntry,
                              decltype(::stellar::LedgerEntry::lastModifiedLedgerSeq),
                              &::stellar::LedgerEntry::lastModifiedLedgerSeq>,
                    field_ptr<::stellar::LedgerEntry,
                              decltype(::stellar::LedgerEntry::data),
                              &::stellar::LedgerEntry::data>,
                    field_ptr<::stellar::LedgerEntry,
                              decltype(::stellar::LedgerEntry::ext),
                              &::stellar::LedgerEntry::ext>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerEntry &obj) {
    archive(ar, obj.lastModifiedLedgerSeq, "lastModifiedLedgerSeq");
    archive(ar, obj.data, "data");
    archive(ar, obj.ext, "ext");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerEntry &obj) {
    archive(ar, obj.lastModifiedLedgerSeq, "lastModifiedLedgerSeq");
    archive(ar, obj.data, "data");
    archive(ar, obj.ext, "ext");
    xdr::validate(obj);
  }
};
} namespace stellar {

struct LedgerKey {
  struct _account_t {
    AccountID accountID{};

    _account_t() = default;
    template<typename _accountID_T,
             typename = typename
             std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                           >::type>
    explicit _account_t(_accountID_T &&_accountID)
      : accountID(std::forward<_accountID_T>(_accountID)) {}
  };
  struct _trustLine_t {
    AccountID accountID{};
    TrustLineAsset asset{};

    _trustLine_t() = default;
    template<typename _accountID_T,
             typename _asset_T,
             typename = typename
             std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                            && std::is_constructible<TrustLineAsset, _asset_T>::value
                           >::type>
    explicit _trustLine_t(_accountID_T &&_accountID,
                          _asset_T &&_asset)
      : accountID(std::forward<_accountID_T>(_accountID)),
        asset(std::forward<_asset_T>(_asset)) {}
  };
  struct _offer_t {
    AccountID sellerID{};
    int64 offerID{};

    _offer_t() = default;
    template<typename _sellerID_T,
             typename _offerID_T,
             typename = typename
             std::enable_if<std::is_constructible<AccountID, _sellerID_T>::value
                            && std::is_constructible<int64, _offerID_T>::value
                           >::type>
    explicit _offer_t(_sellerID_T &&_sellerID,
                      _offerID_T &&_offerID)
      : sellerID(std::forward<_sellerID_T>(_sellerID)),
        offerID(std::forward<_offerID_T>(_offerID)) {}
  };
  struct _data_t {
    AccountID accountID{};
    string64 dataName{};

    _data_t() = default;
    template<typename _accountID_T,
             typename _dataName_T,
             typename = typename
             std::enable_if<std::is_constructible<AccountID, _accountID_T>::value
                            && std::is_constructible<string64, _dataName_T>::value
                           >::type>
    explicit _data_t(_accountID_T &&_accountID,
                     _dataName_T &&_dataName)
      : accountID(std::forward<_accountID_T>(_accountID)),
        dataName(std::forward<_dataName_T>(_dataName)) {}
  };
  struct _claimableBalance_t {
    ClaimableBalanceID balanceID{};

    _claimableBalance_t() = default;
    template<typename _balanceID_T,
             typename = typename
             std::enable_if<std::is_constructible<ClaimableBalanceID, _balanceID_T>::value
                           >::type>
    explicit _claimableBalance_t(_balanceID_T &&_balanceID)
      : balanceID(std::forward<_balanceID_T>(_balanceID)) {}
  };
  struct _liquidityPool_t {
    PoolID liquidityPoolID{};

    _liquidityPool_t() = default;
    template<typename _liquidityPoolID_T,
             typename = typename
             std::enable_if<std::is_constructible<PoolID, _liquidityPoolID_T>::value
                           >::type>
    explicit _liquidityPool_t(_liquidityPoolID_T &&_liquidityPoolID)
      : liquidityPoolID(std::forward<_liquidityPoolID_T>(_liquidityPoolID)) {}
  };

  using _xdr_case_type = xdr::xdr_traits<LedgerEntryType>::case_type;
private:
  _xdr_case_type type_;
  union {
    _account_t account_;
    _trustLine_t trustLine_;
    _offer_t offer_;
    _data_t data_;
    _claimableBalance_t claimableBalance_;
    _liquidityPool_t liquidityPool_;
  };

public:
  static Constexpr const bool _xdr_has_default_case = false;
  static const std::vector<LedgerEntryType> &_xdr_case_values() {
    static const std::vector<LedgerEntryType> _xdr_disc_vec {
      ACCOUNT,
      TRUSTLINE,
      OFFER,
      DATA,
      CLAIMABLE_BALANCE,
      LIQUIDITY_POOL
    };
    return _xdr_disc_vec;
  }
  static Constexpr int _xdr_field_number(_xdr_case_type which) {
    return which == ACCOUNT ? 1
      : which == TRUSTLINE ? 2
      : which == OFFER ? 3
      : which == DATA ? 4
      : which == CLAIMABLE_BALANCE ? 5
      : which == LIQUIDITY_POOL ? 6
      : -1;
  }
  template<typename _F, typename..._A> static bool
  _xdr_with_mem_ptr(_F &_f, _xdr_case_type _which, _A&&..._a) {
    switch (_which) {
    case ACCOUNT:
      _f(&LedgerKey::account_, std::forward<_A>(_a)...);
      return true;
    case TRUSTLINE:
      _f(&LedgerKey::trustLine_, std::forward<_A>(_a)...);
      return true;
    case OFFER:
      _f(&LedgerKey::offer_, std::forward<_A>(_a)...);
      return true;
    case DATA:
      _f(&LedgerKey::data_, std::forward<_A>(_a)...);
      return true;
    case CLAIMABLE_BALANCE:
      _f(&LedgerKey::claimableBalance_, std::forward<_A>(_a)...);
      return true;
    case LIQUIDITY_POOL:
      _f(&LedgerKey::liquidityPool_, std::forward<_A>(_a)...);
      return true;
    }
    return false;
  }

  _xdr_case_type _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(_xdr_case_type which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in LedgerKey");
    if (fnum != _xdr_field_number(type_)) {
      this->~LedgerKey();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
    else
      type_ = which;
  }
  explicit LedgerKey(LedgerEntryType which = LedgerEntryType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  LedgerKey(const LedgerKey &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  LedgerKey(LedgerKey &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~LedgerKey() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  LedgerKey &operator=(const LedgerKey &source) {
    if (_xdr_field_number(type_)
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~LedgerKey();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  LedgerKey &operator=(LedgerKey &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~LedgerKey();
      type_ = std::numeric_limits<_xdr_case_type>::max();
      _xdr_with_mem_ptr(xdr::field_constructor, source.type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  LedgerEntryType type() const { return LedgerEntryType(type_); }
  LedgerKey &type(LedgerEntryType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  _account_t &account() {
    if (_xdr_field_number(type_) == 1)
      return account_;
    throw xdr::xdr_wrong_union("LedgerKey: account accessed when not selected");
  }
  const _account_t &account() const {
    if (_xdr_field_number(type_) == 1)
      return account_;
    throw xdr::xdr_wrong_union("LedgerKey: account accessed when not selected");
  }
  _trustLine_t &trustLine() {
    if (_xdr_field_number(type_) == 2)
      return trustLine_;
    throw xdr::xdr_wrong_union("LedgerKey: trustLine accessed when not selected");
  }
  const _trustLine_t &trustLine() const {
    if (_xdr_field_number(type_) == 2)
      return trustLine_;
    throw xdr::xdr_wrong_union("LedgerKey: trustLine accessed when not selected");
  }
  _offer_t &offer() {
    if (_xdr_field_number(type_) == 3)
      return offer_;
    throw xdr::xdr_wrong_union("LedgerKey: offer accessed when not selected");
  }
  const _offer_t &offer() const {
    if (_xdr_field_number(type_) == 3)
      return offer_;
    throw xdr::xdr_wrong_union("LedgerKey: offer accessed when not selected");
  }
  _data_t &data() {
    if (_xdr_field_number(type_) == 4)
      return data_;
    throw xdr::xdr_wrong_union("LedgerKey: data accessed when not selected");
  }
  const _data_t &data() const {
    if (_xdr_field_number(type_) == 4)
      return data_;
    throw xdr::xdr_wrong_union("LedgerKey: data accessed when not selected");
  }
  _claimableBalance_t &claimableBalance() {
    if (_xdr_field_number(type_) == 5)
      return claimableBalance_;
    throw xdr::xdr_wrong_union("LedgerKey: claimableBalance accessed when not selected");
  }
  const _claimableBalance_t &claimableBalance() const {
    if (_xdr_field_number(type_) == 5)
      return claimableBalance_;
    throw xdr::xdr_wrong_union("LedgerKey: claimableBalance accessed when not selected");
  }
  _liquidityPool_t &liquidityPool() {
    if (_xdr_field_number(type_) == 6)
      return liquidityPool_;
    throw xdr::xdr_wrong_union("LedgerKey: liquidityPool accessed when not selected");
  }
  const _liquidityPool_t &liquidityPool() const {
    if (_xdr_field_number(type_) == 6)
      return liquidityPool_;
    throw xdr::xdr_wrong_union("LedgerKey: liquidityPool accessed when not selected");
  }
};
} namespace xdr {
template<> struct xdr_traits<::stellar::LedgerKey::_account_t>
  : xdr_struct_base<field_ptr<::stellar::LedgerKey::_account_t,
                              decltype(::stellar::LedgerKey::_account_t::accountID),
                              &::stellar::LedgerKey::_account_t::accountID>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey::_account_t &obj) {
    archive(ar, obj.accountID, "accountID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey::_account_t &obj) {
    archive(ar, obj.accountID, "accountID");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerKey::_trustLine_t>
  : xdr_struct_base<field_ptr<::stellar::LedgerKey::_trustLine_t,
                              decltype(::stellar::LedgerKey::_trustLine_t::accountID),
                              &::stellar::LedgerKey::_trustLine_t::accountID>,
                    field_ptr<::stellar::LedgerKey::_trustLine_t,
                              decltype(::stellar::LedgerKey::_trustLine_t::asset),
                              &::stellar::LedgerKey::_trustLine_t::asset>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey::_trustLine_t &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.asset, "asset");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey::_trustLine_t &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.asset, "asset");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerKey::_offer_t>
  : xdr_struct_base<field_ptr<::stellar::LedgerKey::_offer_t,
                              decltype(::stellar::LedgerKey::_offer_t::sellerID),
                              &::stellar::LedgerKey::_offer_t::sellerID>,
                    field_ptr<::stellar::LedgerKey::_offer_t,
                              decltype(::stellar::LedgerKey::_offer_t::offerID),
                              &::stellar::LedgerKey::_offer_t::offerID>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey::_offer_t &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey::_offer_t &obj) {
    archive(ar, obj.sellerID, "sellerID");
    archive(ar, obj.offerID, "offerID");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerKey::_data_t>
  : xdr_struct_base<field_ptr<::stellar::LedgerKey::_data_t,
                              decltype(::stellar::LedgerKey::_data_t::accountID),
                              &::stellar::LedgerKey::_data_t::accountID>,
                    field_ptr<::stellar::LedgerKey::_data_t,
                              decltype(::stellar::LedgerKey::_data_t::dataName),
                              &::stellar::LedgerKey::_data_t::dataName>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey::_data_t &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.dataName, "dataName");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey::_data_t &obj) {
    archive(ar, obj.accountID, "accountID");
    archive(ar, obj.dataName, "dataName");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerKey::_claimableBalance_t>
  : xdr_struct_base<field_ptr<::stellar::LedgerKey::_claimableBalance_t,
                              decltype(::stellar::LedgerKey::_claimableBalance_t::balanceID),
                              &::stellar::LedgerKey::_claimableBalance_t::balanceID>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey::_claimableBalance_t &obj) {
    archive(ar, obj.balanceID, "balanceID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey::_claimableBalance_t &obj) {
    archive(ar, obj.balanceID, "balanceID");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerKey::_liquidityPool_t>
  : xdr_struct_base<field_ptr<::stellar::LedgerKey::_liquidityPool_t,
                              decltype(::stellar::LedgerKey::_liquidityPool_t::liquidityPoolID),
                              &::stellar::LedgerKey::_liquidityPool_t::liquidityPoolID>> {
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey::_liquidityPool_t &obj) {
    archive(ar, obj.liquidityPoolID, "liquidityPoolID");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey::_liquidityPool_t &obj) {
    archive(ar, obj.liquidityPoolID, "liquidityPoolID");
    xdr::validate(obj);
  }
};
template<> struct xdr_traits<::stellar::LedgerKey> : xdr_traits_base {
  static Constexpr const bool is_class = true;
  static Constexpr const bool is_union = true;
  static Constexpr const bool has_fixed_size = false;

  using union_type = ::stellar::LedgerKey;
  using case_type = ::stellar::LedgerKey::_xdr_case_type;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static const char *union_field_name(case_type which) {
    switch (union_type::_xdr_field_number(which)) {
    case 1:
      return "account";
    case 2:
      return "trustLine";
    case 3:
      return "offer";
    case 4:
      return "data";
    case 5:
      return "claimableBalance";
    case 6:
      return "liquidityPool";
    }
    return nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stellar::LedgerKey &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in LedgerKey");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stellar::LedgerKey &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in LedgerKey");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stellar::LedgerKey &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
    xdr::validate(obj);
  }
};
} namespace stellar {

enum EnvelopeType : std::int32_t {
  ENVELOPE_TYPE_TX_V0 = 0,
  ENVELOPE_TYPE_SCP = 1,
  ENVELOPE_TYPE_TX = 2,
  ENVELOPE_TYPE_AUTH = 3,
  ENVELOPE_TYPE_SCPVALUE = 4,
  ENVELOPE_TYPE_TX_FEE_BUMP = 5,
  ENVELOPE_TYPE_OP_ID = 6,
  ENVELOPE_TYPE_POOL_REVOKE_OP_ID = 7,
};
} namespace xdr {
template<> struct xdr_traits<::stellar::EnvelopeType>
  : xdr_integral_base<::stellar::EnvelopeType, std::uint32_t> {
  using case_type = std::int32_t;
  static Constexpr const bool is_enum = true;
  static Constexpr const bool is_numeric = false;
  static const char *enum_name(::stellar::EnvelopeType val) {
    switch (val) {
    case ::stellar::ENVELOPE_TYPE_TX_V0:
      return "ENVELOPE_TYPE_TX_V0";
    case ::stellar::ENVELOPE_TYPE_SCP:
      return "ENVELOPE_TYPE_SCP";
    case ::stellar::ENVELOPE_TYPE_TX:
      return "ENVELOPE_TYPE_TX";
    case ::stellar::ENVELOPE_TYPE_AUTH:
      return "ENVELOPE_TYPE_AUTH";
    case ::stellar::ENVELOPE_TYPE_SCPVALUE:
      return "ENVELOPE_TYPE_SCPVALUE";
    case ::stellar::ENVELOPE_TYPE_TX_FEE_BUMP:
      return "ENVELOPE_TYPE_TX_FEE_BUMP";
    case ::stellar::ENVELOPE_TYPE_OP_ID:
      return "ENVELOPE_TYPE_OP_ID";
    case ::stellar::ENVELOPE_TYPE_POOL_REVOKE_OP_ID:
      return "ENVELOPE_TYPE_POOL_REVOKE_OP_ID";
    default:
      return nullptr;
    }
  }
  static const std::vector<int32_t> &enum_values() {
    static const std::vector<int32_t> _xdr_enum_vec = {
      ::stellar::ENVELOPE_TYPE_TX_V0,
      ::stellar::ENVELOPE_TYPE_SCP,
      ::stellar::ENVELOPE_TYPE_TX,
      ::stellar::ENVELOPE_TYPE_AUTH,
      ::stellar::ENVELOPE_TYPE_SCPVALUE,
      ::stellar::ENVELOPE_TYPE_TX_FEE_BUMP,
      ::stellar::ENVELOPE_TYPE_OP_ID,
      ::stellar::ENVELOPE_TYPE_POOL_REVOKE_OP_ID
    };
    return _xdr_enum_vec;
  }
};
} namespace stellar {

}

#endif // !__XDR_PROTOCOL_CURR_XDR_STELLAR_LEDGER_ENTRIES_H_INCLUDED__
