// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: aspnetcore.proto

#include "aspnetcore.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_aspnetcore_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_aspnetcore_2eproto ::google::protobuf::internal::SCCInfo<1> scc_info_MvcRoute;
}  // namespace protobuf_aspnetcore_2eproto
namespace protobuf_google_2fprotobuf_2fwrappers_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_google_2fprotobuf_2fwrappers_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_StringValue;
}  // namespace protobuf_google_2fprotobuf_2fwrappers_2eproto
namespace aspnet {
namespace core {
class MvcRouteDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MvcRoute>
      _instance;
} _MvcRoute_default_instance_;
}  // namespace core
}  // namespace aspnet
namespace protobuf_aspnetcore_2eproto {
static void InitDefaultsMvcRoute() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::aspnet::core::_MvcRoute_default_instance_;
    new (ptr) ::aspnet::core::MvcRoute();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::aspnet::core::MvcRoute::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_MvcRoute =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsMvcRoute}, {
      &protobuf_google_2fprotobuf_2fwrappers_2eproto::scc_info_StringValue.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_MvcRoute.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, method_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, source_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, route_pattern_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, custom_method_attributes_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, custom_return_type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, custom_method_body_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, is_empty_request_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::aspnet::core::MvcRoute, custom_exception_handling_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::aspnet::core::MvcRoute)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::aspnet::core::_MvcRoute_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "aspnetcore.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\020aspnetcore.proto\022\013aspnet.core\032\036google/"
      "protobuf/wrappers.proto\032 google/protobuf"
      "/descriptor.proto\"\313\002\n\010MvcRoute\022\'\n\006method"
      "\030\001 \001(\0162\027.aspnet.core.HttpMethod\022,\n\006sourc"
      "e\030\002 \001(\0162\034.aspnet.core.HttpInputSource\0223\n"
      "\rroute_pattern\030\003 \001(\0132\034.google.protobuf.S"
      "tringValue\022 \n\030custom_method_attributes\030\004"
      " \003(\t\0228\n\022custom_return_type\030\005 \001(\0132\034.googl"
      "e.protobuf.StringValue\022\032\n\022custom_method_"
      "body\030\006 \003(\t\022\030\n\020is_empty_request\030\007 \001(\010\022!\n\031"
      "custom_exception_handling\030\010 \003(\t*`\n\nHttpM"
      "ethod\022\022\n\016HttpMethod_Get\020\000\022\023\n\017HttpMethod_"
      "Post\020\001\022\022\n\016HttpMethod_Put\020\002\022\025\n\021HttpMethod"
      "_Delete\020\003*\235\001\n\017HttpInputSource\022\037\n\033HttpInp"
      "utSource_Unspecified\020\000\022\030\n\024HttpInputSourc"
      "e_Body\020\001\022\030\n\024HttpInputSource_Form\020\002\022\031\n\025Ht"
      "tpInputSource_Query\020\003\022\032\n\026HttpInputSource"
      "_Header\020\004:E\n\003api\022\036.google.protobuf.Metho"
      "dOptions\030\347\332\254\014 \001(\0132\025.aspnet.core.MvcRoute"
      "b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 768);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "aspnetcore.proto", &protobuf_RegisterTypes);
  ::protobuf_google_2fprotobuf_2fwrappers_2eproto::AddDescriptors();
  ::protobuf_google_2fprotobuf_2fdescriptor_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_aspnetcore_2eproto
namespace aspnet {
namespace core {
const ::google::protobuf::EnumDescriptor* HttpMethod_descriptor() {
  protobuf_aspnetcore_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_aspnetcore_2eproto::file_level_enum_descriptors[0];
}
bool HttpMethod_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* HttpInputSource_descriptor() {
  protobuf_aspnetcore_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_aspnetcore_2eproto::file_level_enum_descriptors[1];
}
bool HttpInputSource_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void MvcRoute::InitAsDefaultInstance() {
  ::aspnet::core::_MvcRoute_default_instance_._instance.get_mutable()->route_pattern_ = const_cast< ::google::protobuf::StringValue*>(
      ::google::protobuf::StringValue::internal_default_instance());
  ::aspnet::core::_MvcRoute_default_instance_._instance.get_mutable()->custom_return_type_ = const_cast< ::google::protobuf::StringValue*>(
      ::google::protobuf::StringValue::internal_default_instance());
}
void MvcRoute::clear_route_pattern() {
  if (GetArenaNoVirtual() == NULL && route_pattern_ != NULL) {
    delete route_pattern_;
  }
  route_pattern_ = NULL;
}
void MvcRoute::clear_custom_return_type() {
  if (GetArenaNoVirtual() == NULL && custom_return_type_ != NULL) {
    delete custom_return_type_;
  }
  custom_return_type_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MvcRoute::kMethodFieldNumber;
const int MvcRoute::kSourceFieldNumber;
const int MvcRoute::kRoutePatternFieldNumber;
const int MvcRoute::kCustomMethodAttributesFieldNumber;
const int MvcRoute::kCustomReturnTypeFieldNumber;
const int MvcRoute::kCustomMethodBodyFieldNumber;
const int MvcRoute::kIsEmptyRequestFieldNumber;
const int MvcRoute::kCustomExceptionHandlingFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MvcRoute::MvcRoute()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_aspnetcore_2eproto::scc_info_MvcRoute.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:aspnet.core.MvcRoute)
}
MvcRoute::MvcRoute(const MvcRoute& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      custom_method_attributes_(from.custom_method_attributes_),
      custom_method_body_(from.custom_method_body_),
      custom_exception_handling_(from.custom_exception_handling_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_route_pattern()) {
    route_pattern_ = new ::google::protobuf::StringValue(*from.route_pattern_);
  } else {
    route_pattern_ = NULL;
  }
  if (from.has_custom_return_type()) {
    custom_return_type_ = new ::google::protobuf::StringValue(*from.custom_return_type_);
  } else {
    custom_return_type_ = NULL;
  }
  ::memcpy(&method_, &from.method_,
    static_cast<size_t>(reinterpret_cast<char*>(&is_empty_request_) -
    reinterpret_cast<char*>(&method_)) + sizeof(is_empty_request_));
  // @@protoc_insertion_point(copy_constructor:aspnet.core.MvcRoute)
}

void MvcRoute::SharedCtor() {
  ::memset(&route_pattern_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&is_empty_request_) -
      reinterpret_cast<char*>(&route_pattern_)) + sizeof(is_empty_request_));
}

MvcRoute::~MvcRoute() {
  // @@protoc_insertion_point(destructor:aspnet.core.MvcRoute)
  SharedDtor();
}

void MvcRoute::SharedDtor() {
  if (this != internal_default_instance()) delete route_pattern_;
  if (this != internal_default_instance()) delete custom_return_type_;
}

void MvcRoute::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* MvcRoute::descriptor() {
  ::protobuf_aspnetcore_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_aspnetcore_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MvcRoute& MvcRoute::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_aspnetcore_2eproto::scc_info_MvcRoute.base);
  return *internal_default_instance();
}


void MvcRoute::Clear() {
// @@protoc_insertion_point(message_clear_start:aspnet.core.MvcRoute)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  custom_method_attributes_.Clear();
  custom_method_body_.Clear();
  custom_exception_handling_.Clear();
  if (GetArenaNoVirtual() == NULL && route_pattern_ != NULL) {
    delete route_pattern_;
  }
  route_pattern_ = NULL;
  if (GetArenaNoVirtual() == NULL && custom_return_type_ != NULL) {
    delete custom_return_type_;
  }
  custom_return_type_ = NULL;
  ::memset(&method_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&is_empty_request_) -
      reinterpret_cast<char*>(&method_)) + sizeof(is_empty_request_));
  _internal_metadata_.Clear();
}

bool MvcRoute::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:aspnet.core.MvcRoute)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .aspnet.core.HttpMethod method = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_method(static_cast< ::aspnet::core::HttpMethod >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aspnet.core.HttpInputSource source = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_source(static_cast< ::aspnet::core::HttpInputSource >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .google.protobuf.StringValue route_pattern = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_route_pattern()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string custom_method_attributes = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_custom_method_attributes()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->custom_method_attributes(this->custom_method_attributes_size() - 1).data(),
            static_cast<int>(this->custom_method_attributes(this->custom_method_attributes_size() - 1).length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aspnet.core.MvcRoute.custom_method_attributes"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .google.protobuf.StringValue custom_return_type = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_custom_return_type()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string custom_method_body = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_custom_method_body()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->custom_method_body(this->custom_method_body_size() - 1).data(),
            static_cast<int>(this->custom_method_body(this->custom_method_body_size() - 1).length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aspnet.core.MvcRoute.custom_method_body"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool is_empty_request = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &is_empty_request_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string custom_exception_handling = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(66u /* 66 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_custom_exception_handling()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->custom_exception_handling(this->custom_exception_handling_size() - 1).data(),
            static_cast<int>(this->custom_exception_handling(this->custom_exception_handling_size() - 1).length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aspnet.core.MvcRoute.custom_exception_handling"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:aspnet.core.MvcRoute)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:aspnet.core.MvcRoute)
  return false;
#undef DO_
}

void MvcRoute::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:aspnet.core.MvcRoute)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .aspnet.core.HttpMethod method = 1;
  if (this->method() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->method(), output);
  }

  // .aspnet.core.HttpInputSource source = 2;
  if (this->source() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->source(), output);
  }

  // .google.protobuf.StringValue route_pattern = 3;
  if (this->has_route_pattern()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->_internal_route_pattern(), output);
  }

  // repeated string custom_method_attributes = 4;
  for (int i = 0, n = this->custom_method_attributes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->custom_method_attributes(i).data(), static_cast<int>(this->custom_method_attributes(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspnet.core.MvcRoute.custom_method_attributes");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->custom_method_attributes(i), output);
  }

  // .google.protobuf.StringValue custom_return_type = 5;
  if (this->has_custom_return_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->_internal_custom_return_type(), output);
  }

  // repeated string custom_method_body = 6;
  for (int i = 0, n = this->custom_method_body_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->custom_method_body(i).data(), static_cast<int>(this->custom_method_body(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspnet.core.MvcRoute.custom_method_body");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      6, this->custom_method_body(i), output);
  }

  // bool is_empty_request = 7;
  if (this->is_empty_request() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->is_empty_request(), output);
  }

  // repeated string custom_exception_handling = 8;
  for (int i = 0, n = this->custom_exception_handling_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->custom_exception_handling(i).data(), static_cast<int>(this->custom_exception_handling(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspnet.core.MvcRoute.custom_exception_handling");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      8, this->custom_exception_handling(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:aspnet.core.MvcRoute)
}

::google::protobuf::uint8* MvcRoute::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:aspnet.core.MvcRoute)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .aspnet.core.HttpMethod method = 1;
  if (this->method() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->method(), target);
  }

  // .aspnet.core.HttpInputSource source = 2;
  if (this->source() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->source(), target);
  }

  // .google.protobuf.StringValue route_pattern = 3;
  if (this->has_route_pattern()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, this->_internal_route_pattern(), deterministic, target);
  }

  // repeated string custom_method_attributes = 4;
  for (int i = 0, n = this->custom_method_attributes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->custom_method_attributes(i).data(), static_cast<int>(this->custom_method_attributes(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspnet.core.MvcRoute.custom_method_attributes");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->custom_method_attributes(i), target);
  }

  // .google.protobuf.StringValue custom_return_type = 5;
  if (this->has_custom_return_type()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        5, this->_internal_custom_return_type(), deterministic, target);
  }

  // repeated string custom_method_body = 6;
  for (int i = 0, n = this->custom_method_body_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->custom_method_body(i).data(), static_cast<int>(this->custom_method_body(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspnet.core.MvcRoute.custom_method_body");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(6, this->custom_method_body(i), target);
  }

  // bool is_empty_request = 7;
  if (this->is_empty_request() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->is_empty_request(), target);
  }

  // repeated string custom_exception_handling = 8;
  for (int i = 0, n = this->custom_exception_handling_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->custom_exception_handling(i).data(), static_cast<int>(this->custom_exception_handling(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aspnet.core.MvcRoute.custom_exception_handling");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(8, this->custom_exception_handling(i), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:aspnet.core.MvcRoute)
  return target;
}

size_t MvcRoute::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:aspnet.core.MvcRoute)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated string custom_method_attributes = 4;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->custom_method_attributes_size());
  for (int i = 0, n = this->custom_method_attributes_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->custom_method_attributes(i));
  }

  // repeated string custom_method_body = 6;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->custom_method_body_size());
  for (int i = 0, n = this->custom_method_body_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->custom_method_body(i));
  }

  // repeated string custom_exception_handling = 8;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->custom_exception_handling_size());
  for (int i = 0, n = this->custom_exception_handling_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->custom_exception_handling(i));
  }

  // .google.protobuf.StringValue route_pattern = 3;
  if (this->has_route_pattern()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *route_pattern_);
  }

  // .google.protobuf.StringValue custom_return_type = 5;
  if (this->has_custom_return_type()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *custom_return_type_);
  }

  // .aspnet.core.HttpMethod method = 1;
  if (this->method() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->method());
  }

  // .aspnet.core.HttpInputSource source = 2;
  if (this->source() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->source());
  }

  // bool is_empty_request = 7;
  if (this->is_empty_request() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MvcRoute::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:aspnet.core.MvcRoute)
  GOOGLE_DCHECK_NE(&from, this);
  const MvcRoute* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MvcRoute>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:aspnet.core.MvcRoute)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:aspnet.core.MvcRoute)
    MergeFrom(*source);
  }
}

void MvcRoute::MergeFrom(const MvcRoute& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:aspnet.core.MvcRoute)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  custom_method_attributes_.MergeFrom(from.custom_method_attributes_);
  custom_method_body_.MergeFrom(from.custom_method_body_);
  custom_exception_handling_.MergeFrom(from.custom_exception_handling_);
  if (from.has_route_pattern()) {
    mutable_route_pattern()->::google::protobuf::StringValue::MergeFrom(from.route_pattern());
  }
  if (from.has_custom_return_type()) {
    mutable_custom_return_type()->::google::protobuf::StringValue::MergeFrom(from.custom_return_type());
  }
  if (from.method() != 0) {
    set_method(from.method());
  }
  if (from.source() != 0) {
    set_source(from.source());
  }
  if (from.is_empty_request() != 0) {
    set_is_empty_request(from.is_empty_request());
  }
}

void MvcRoute::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:aspnet.core.MvcRoute)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MvcRoute::CopyFrom(const MvcRoute& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:aspnet.core.MvcRoute)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MvcRoute::IsInitialized() const {
  return true;
}

void MvcRoute::Swap(MvcRoute* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MvcRoute::InternalSwap(MvcRoute* other) {
  using std::swap;
  custom_method_attributes_.InternalSwap(CastToBase(&other->custom_method_attributes_));
  custom_method_body_.InternalSwap(CastToBase(&other->custom_method_body_));
  custom_exception_handling_.InternalSwap(CastToBase(&other->custom_exception_handling_));
  swap(route_pattern_, other->route_pattern_);
  swap(custom_return_type_, other->custom_return_type_);
  swap(method_, other->method_);
  swap(source_, other->source_);
  swap(is_empty_request_, other->is_empty_request_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata MvcRoute::GetMetadata() const {
  protobuf_aspnetcore_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_aspnetcore_2eproto::file_level_metadata[kIndexInFileMessages];
}

::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::aspnet::core::MvcRoute >, 11, false >
  api(kApiFieldNumber, *::aspnet::core::MvcRoute::internal_default_instance());

// @@protoc_insertion_point(namespace_scope)
}  // namespace core
}  // namespace aspnet
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::aspnet::core::MvcRoute* Arena::CreateMaybeMessage< ::aspnet::core::MvcRoute >(Arena* arena) {
  return Arena::CreateInternal< ::aspnet::core::MvcRoute >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
