﻿// Created by Microsoft (R) C/C++ Compiler Version 14.00.50727.762 (812a966c).
//
// c:\dokumente und einstellungen\mike\eigene dateien\visual studio 2005\projects\nethost\nethost2\debug\mscorlib.tlh
//
// C++ source equivalent of Win32 type library C:\\WINDOWS\\Microsoft.NET\\Framework\\v2.0.50727\\Mscorlib.tlb
// compiler-generated file created 04/12/07 at 23:21:38 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

//#include <comdef.h>

namespace mscorlib {

//
// Forward references and typedefs
//

struct __declspec(uuid("bed7f4ea-1a96-11d2-8f08-00a0c9a6186d"))
/* LIBID */ __mscorlib;
struct /* coclass */ Object;
struct __declspec(uuid("0cb251a7-3ab3-3b5c-a0b8-9ddf88824b85"))
/* dual interface */ ICloneable;
struct __declspec(uuid("496b0abe-cdee-11d3-88e8-00902754c43a"))
/* dual interface */ IEnumerable;
struct __declspec(uuid("de8db6f8-d101-3a92-8d1c-e72e5f10e992"))
/* dual interface */ ICollection;
struct __declspec(uuid("7bcfa00f-f764-3113-9140-3bbd127a96bb"))
/* dual interface */ IList;
struct /* coclass */ Array;
struct /* coclass */ ValueType;
struct __declspec(uuid("496b0abf-cdee-11d3-88e8-00902754c43a"))
/* dual interface */ IEnumerator;
struct __declspec(uuid("805d7a98-d4af-3f0f-967f-e5cf45312d2c"))
/* dual interface */ IDisposable;
struct __declspec(uuid("deb0e770-91fd-3cf6-9a6c-e6a3656f3965"))
/* dual interface */ IComparable;
struct __declspec(uuid("9a604ee7-e630-3ded-9444-baae247075ab"))
/* dual interface */ IFormattable;
struct __declspec(uuid("805e3b62-b5e9-393d-8941-377d8bf4556b"))
/* dual interface */ IConvertible;
struct /* coclass */ Enum;
struct /* coclass */ String;
struct __declspec(uuid("c20fd3eb-7022-3d14-8477-760fab54e50d"))
/* dual interface */ IComparer;
struct __declspec(uuid("aab7c6ea-cab0-3adb-82aa-cf32e29af238"))
/* dual interface */ IEqualityComparer;
struct /* coclass */ StringComparer;
enum StringComparison;
struct __declspec(uuid("d0eeaa62-3d30-3ee2-b896-a2f34dda47d8"))
/* dual interface */ ISerializable;
struct /* coclass */ StringBuilder;
struct __declspec(uuid("b36b5c63-42ef-38bc-a07e-0b34c98f164a"))
/* dual interface */ _Exception;
struct /* coclass */ Exception;
enum DateTimeKind;
struct /* coclass */ SystemException;
struct /* coclass */ OutOfMemoryException;
struct /* coclass */ StackOverflowException;
struct /* coclass */ DataMisalignedException;
struct /* coclass */ ExecutionEngineException;
struct /* coclass */ Delegate;
struct /* coclass */ MulticastDelegate;
struct /* coclass */ MemberAccessException;
struct __declspec(uuid("03973551-57a1-3900-a2b5-9083e3ff2943"))
/* interface */ _Activator;
struct /* coclass */ Activator;
struct /* coclass */ AccessViolationException;
struct /* coclass */ ApplicationActivator;
struct /* coclass */ ApplicationException;
struct /* coclass */ EventArgs;
struct /* coclass */ ResolveEventArgs;
struct /* coclass */ AssemblyLoadEventArgs;
struct /* coclass */ ResolveEventHandler;
struct /* coclass */ AssemblyLoadEventHandler;
struct /* coclass */ AppDomainInitializer;
struct /* coclass */ MarshalByRefObject;
struct __declspec(uuid("05f696dc-2b29-3663-ad8b-c4389cf2a713"))
/* interface */ _AppDomain;
struct __declspec(uuid("35a8f3ac-fe28-360f-a0c0-9a4d50c4682a"))
/* dual interface */ IEvidenceFactory;
struct /* coclass */ AppDomain;
struct /* coclass */ CrossAppDomainDelegate;
enum AppDomainManagerInitializationOptions;
struct /* coclass */ AppDomainManager;
struct __declspec(uuid("27fff232-a7a8-40dd-8d4a-734ad59fcd41"))
/* interface */ IAppDomainSetup;
struct /* coclass */ AppDomainSetup;
enum LoaderOptimization;
struct __declspec(uuid("917b14d0-2d9e-38b8-92a9-381acf52f7c0"))
/* interface */ _Attribute;
struct /* coclass */ Attribute;
struct /* coclass */ LoaderOptimizationAttribute;
struct /* coclass */ AppDomainUnloadedException;
struct /* coclass */ ActivationArguments;
struct /* coclass */ ApplicationId;
struct /* coclass */ ArgumentException;
struct /* coclass */ ArgumentNullException;
struct /* coclass */ ArgumentOutOfRangeException;
struct /* coclass */ ArithmeticException;
struct /* coclass */ ArrayTypeMismatchException;
struct /* coclass */ AsyncCallback;
enum AttributeTargets;
struct /* coclass */ AttributeUsageAttribute;
struct /* coclass */ BadImageFormatException;
struct Boolean;
struct /* coclass */ Buffer;
struct Byte;
struct /* coclass */ CannotUnloadAppDomainException;
struct Char;
struct /* coclass */ CharEnumerator;
struct /* coclass */ CLSCompliantAttribute;
struct /* coclass */ TypeUnloadedException;
struct __declspec(uuid("c281c7f1-4aa9-3517-961a-463cfed57e75"))
/* interface */ _Thread;
struct /* coclass */ CriticalFinalizerObject;
struct /* coclass */ ContextMarshalException;
struct /* coclass */ ContextBoundObject;
struct /* coclass */ ContextStaticAttribute;
struct /* coclass */ TimeZone;
enum DayOfWeek;
struct /* coclass */ DBNull;
struct Decimal;
struct /* coclass */ Binder;
struct __declspec(uuid("6e70ed5f-0439-38ce-83bb-860f1421f29f"))
/* dual interface */ IObjectReference;
struct /* coclass */ DivideByZeroException;
struct Double;
struct /* coclass */ DuplicateWaitObjectException;
struct /* coclass */ TypeLoadException;
struct /* coclass */ EntryPointNotFoundException;
struct /* coclass */ DllNotFoundException;
enum EnvironmentVariableTarget;
struct /* coclass */ Environment;
enum SpecialFolder;
struct /* coclass */ EventHandler;
struct /* coclass */ FieldAccessException;
struct /* coclass */ FlagsAttribute;
struct /* coclass */ FormatException;
struct Guid;
struct __declspec(uuid("11ab34e7-0176-3c9e-9efe-197858400a3d"))
/* dual interface */ IAsyncResult;
struct __declspec(uuid("2b130940-ca5e-3406-8385-e259e68ab039"))
/* dual interface */ ICustomFormatter;
struct __declspec(uuid("c8cb1ded-2814-396a-9cc0-473ca49779cc"))
/* dual interface */ IFormatProvider;
struct /* coclass */ IndexOutOfRangeException;
struct Int16;
struct Int32;
struct Int64;
struct IntPtr;
struct /* coclass */ InvalidCastException;
struct /* coclass */ InvalidOperationException;
struct /* coclass */ InvalidProgramException;
struct /* coclass */ LocalDataStoreSlot;
struct /* coclass */ MethodAccessException;
enum MidpointRounding;
struct /* coclass */ MissingMemberException;
struct /* coclass */ MissingFieldException;
struct /* coclass */ MissingMethodException;
struct /* coclass */ MulticastNotSupportedException;
struct /* coclass */ NonSerializedAttribute;
struct /* coclass */ NotFiniteNumberException;
struct /* coclass */ NotImplementedException;
struct /* coclass */ NotSupportedException;
struct /* coclass */ NullReferenceException;
struct /* coclass */ ObjectDisposedException;
struct /* coclass */ ObsoleteAttribute;
struct /* coclass */ OperatingSystem;
struct /* coclass */ OperationCanceledException;
struct /* coclass */ OverflowException;
struct /* coclass */ ParamArrayAttribute;
enum PlatformID;
struct /* coclass */ PlatformNotSupportedException;
struct /* coclass */ Random;
struct /* coclass */ RankException;
struct __declspec(uuid("b9b91146-d6c2-3a62-8159-c2d1794cdeb0"))
/* dual interface */ ICustomAttributeProvider;
struct __declspec(uuid("f7102fa9-cabb-3a74-a6da-b4567ef1b079"))
/* interface */ _MemberInfo;
struct /* coclass */ MemberInfo;
struct __declspec(uuid("bca8b44d-aad6-3a86-8ab7-03349f4f2da2"))
/* interface */ _Type;
struct __declspec(uuid("afbf15e5-c37c-11d2-b88e-00a0c9b471b8"))
/* dual interface */ IReflect;
struct /* coclass */ Type;
struct RuntimeArgumentHandle;
struct RuntimeTypeHandle;
struct RuntimeMethodHandle;
struct RuntimeFieldHandle;
struct ModuleHandle;
struct SByte;
struct /* coclass */ SerializableAttribute;
struct Single;
struct /* coclass */ TimeoutException;
struct TimeSpan;
enum TypeCode;
struct TypedReference;
struct /* coclass */ TypeInitializationException;
struct UInt16;
struct UInt32;
struct UInt64;
struct UIntPtr;
struct /* coclass */ UnauthorizedAccessException;
struct /* coclass */ UnhandledExceptionEventArgs;
struct /* coclass */ UnhandledExceptionEventHandler;
struct /* coclass */ Version;
struct Void;
struct /* coclass */ WeakReference;
struct /* coclass */ WaitHandle;
struct /* coclass */ EventWaitHandle;
struct /* coclass */ AutoResetEvent;
struct /* coclass */ ContextCallback;
//struct __declspec(uuid("c460e2b4-e199-412a-8456-84dc3e4838c3"))
///* interface */ IObjectHandle;
struct LockCookie;
struct /* coclass */ ManualResetEvent;
struct /* coclass */ Monitor;
struct /* coclass */ Mutex;
struct NativeOverlapped;
struct /* coclass */ Overlapped;
struct /* coclass */ ReaderWriterLock;
struct /* coclass */ SynchronizationLockException;
struct /* coclass */ Thread;
struct /* coclass */ ThreadAbortException;
struct /* coclass */ ThreadInterruptedException;
struct /* coclass */ RegisteredWaitHandle;
struct /* coclass */ WaitCallback;
struct /* coclass */ WaitOrTimerCallback;
struct /* coclass */ IOCompletionCallback;
enum ThreadPriority;
struct /* coclass */ ThreadStart;
enum ThreadState;
struct /* coclass */ ThreadStateException;
struct /* coclass */ ThreadStaticAttribute;
struct /* coclass */ Timeout;
struct /* coclass */ TimerCallback;
struct /* coclass */ Timer;
enum ApartmentState;
struct /* coclass */ STAThreadAttribute;
struct /* coclass */ MTAThreadAttribute;
struct /* coclass */ ArrayList;
struct /* coclass */ BitArray;
struct /* coclass */ CaseInsensitiveComparer;
struct __declspec(uuid("5d573036-3435-3c5a-aeff-2b8191082c71"))
/* dual interface */ IHashCodeProvider;
struct /* coclass */ CaseInsensitiveHashCodeProvider;
struct /* coclass */ CollectionBase;
struct /* coclass */ Comparer;
struct __declspec(uuid("6a6841df-3287-3d87-8060-ce0b4c77d2a1"))
/* dual interface */ IDictionary;
struct /* coclass */ DictionaryBase;
struct DictionaryEntry;
struct __declspec(uuid("35d574bf-7a4f-3588-8c19-12212a0fe4dc"))
/* dual interface */ IDictionaryEnumerator;
struct __declspec(uuid("ab3f47e4-c227-3b05-bf9f-94649bef9888"))
/* dual interface */ IDeserializationCallback;
struct /* coclass */ Hashtable;
struct /* coclass */ Queue;
struct /* coclass */ ReadOnlyCollectionBase;
struct /* coclass */ SortedList;
struct /* coclass */ Stack;
struct /* coclass */ Nullable;
struct /* coclass */ KeyNotFoundException;
struct /* coclass */ ConditionalAttribute;
struct /* coclass */ Debugger;
struct /* coclass */ DebuggerStepThroughAttribute;
struct /* coclass */ DebuggerStepperBoundaryAttribute;
struct /* coclass */ DebuggerHiddenAttribute;
struct /* coclass */ DebuggerNonUserCodeAttribute;
struct /* coclass */ DebuggableAttribute;
enum DebuggingModes;
enum DebuggerBrowsableState;
struct /* coclass */ DebuggerBrowsableAttribute;
struct /* coclass */ DebuggerTypeProxyAttribute;
struct /* coclass */ DebuggerDisplayAttribute;
struct /* coclass */ DebuggerVisualizerAttribute;
struct /* coclass */ StackTrace;
struct /* coclass */ StackFrame;
struct __declspec(uuid("20808adc-cc01-3f3a-8f09-ed12940fc212"))
/* dual interface */ ISymbolBinder;
struct __declspec(uuid("027c036a-4052-3821-85de-b53319df1211"))
/* dual interface */ ISymbolBinder1;
struct __declspec(uuid("1c32f012-2684-3efe-8d50-9c2973acc00b"))
/* dual interface */ ISymbolDocument;
struct __declspec(uuid("fa682f24-3a3c-390d-b8a2-96f1106f4b37"))
/* dual interface */ ISymbolDocumentWriter;
struct __declspec(uuid("25c72eb0-e437-3f17-946d-3b72a3acff37"))
/* dual interface */ ISymbolMethod;
struct __declspec(uuid("23ed2454-6899-3c28-bab7-6ec86683964a"))
/* dual interface */ ISymbolNamespace;
struct __declspec(uuid("e809a5f1-d3d7-3144-9bef-fe8ac0364699"))
/* dual interface */ ISymbolReader;
struct __declspec(uuid("1cee3a11-01ae-3244-a939-4972fc9703ef"))
/* dual interface */ ISymbolScope;
struct __declspec(uuid("4042bd4d-b5ab-30e8-919b-14910687baae"))
/* dual interface */ ISymbolVariable;
struct __declspec(uuid("da295a1b-c5bd-3b34-8acd-1d7d334ffb7f"))
/* dual interface */ ISymbolWriter;
enum SymAddressKind;
struct /* coclass */ SymDocumentType;
struct /* coclass */ SymLanguageType;
struct /* coclass */ SymLanguageVendor;
struct SymbolToken;
struct /* coclass */ AmbiguousMatchException;
struct /* coclass */ ModuleResolveEventHandler;
struct __declspec(uuid("17156360-2f1a-384a-bc52-fde93c215c5b"))
/* dual interface */ _Assembly;
struct /* coclass */ Assembly;
struct /* coclass */ AssemblyCopyrightAttribute;
struct /* coclass */ AssemblyTrademarkAttribute;
struct /* coclass */ AssemblyProductAttribute;
struct /* coclass */ AssemblyCompanyAttribute;
struct /* coclass */ AssemblyDescriptionAttribute;
struct /* coclass */ AssemblyTitleAttribute;
struct /* coclass */ AssemblyConfigurationAttribute;
struct /* coclass */ AssemblyDefaultAliasAttribute;
struct /* coclass */ AssemblyInformationalVersionAttribute;
struct /* coclass */ AssemblyFileVersionAttribute;
struct /* coclass */ AssemblyCultureAttribute;
struct /* coclass */ AssemblyVersionAttribute;
struct /* coclass */ AssemblyKeyFileAttribute;
struct /* coclass */ AssemblyDelaySignAttribute;
struct /* coclass */ AssemblyAlgorithmIdAttribute;
struct /* coclass */ AssemblyFlagsAttribute;
struct /* coclass */ AssemblyKeyNameAttribute;
struct __declspec(uuid("b42b6aac-317e-34d5-9fa9-093bb4160c50"))
/* interface */ _AssemblyName;
struct /* coclass */ AssemblyName;
struct /* coclass */ AssemblyNameProxy;
enum AssemblyNameFlags;
enum ProcessorArchitecture;
struct /* coclass */ CustomAttributeFormatException;
enum BindingFlags;
enum CallingConventions;
struct __declspec(uuid("6240837a-707f-3181-8e98-a36ae086766b"))
/* interface */ _MethodBase;
struct __declspec(uuid("ffcc1b5d-ecb8-38dd-9b01-3dc8abc2aa5f"))
/* interface */ _MethodInfo;
struct __declspec(uuid("e9a19478-9646-3679-9b10-8411ae1fd57d"))
/* interface */ _ConstructorInfo;
struct __declspec(uuid("8a7c1442-a9fb-366b-80d8-4939ffa6dbe0"))
/* interface */ _FieldInfo;
struct __declspec(uuid("f59ed4e4-e68f-3218-bd77-061aa82824bf"))
/* interface */ _PropertyInfo;
struct __declspec(uuid("9de59c64-d889-35a1-b897-587d74469e5b"))
/* interface */ _EventInfo;
struct __declspec(uuid("993634c4-e47a-32cc-be08-85f567dc27d6"))
/* interface */ _ParameterInfo;
struct __declspec(uuid("d002e9ba-d9e3-3749-b1d3-d565a08b13e7"))
/* interface */ _Module;
struct /* coclass */ CustomAttributeData;
struct CustomAttributeNamedArgument;
struct CustomAttributeTypedArgument;
struct /* coclass */ DefaultMemberAttribute;
enum EventAttributes;
enum FieldAttributes;
struct InterfaceMapping;
struct /* coclass */ InvalidFilterCriteriaException;
struct /* coclass */ ManifestResourceInfo;
enum ResourceLocation;
struct /* coclass */ MemberFilter;
enum MemberTypes;
enum MethodAttributes;
enum MethodImplAttributes;
struct /* coclass */ Missing;
enum PortableExecutableKinds;
enum ImageFileMachine;
struct /* coclass */ Module;
struct /* coclass */ ObfuscateAssemblyAttribute;
struct /* coclass */ ObfuscationAttribute;
enum ExceptionHandlingClauseOptions;
struct /* coclass */ ExceptionHandlingClause;
struct /* coclass */ MethodBody;
struct /* coclass */ LocalVariableInfo;
enum ParameterAttributes;
struct ParameterModifier;
struct /* coclass */ Pointer;
enum PropertyAttributes;
struct /* coclass */ ReflectionTypeLoadException;
enum ResourceAttributes;
struct /* coclass */ StrongNameKeyPair;
struct /* coclass */ TargetException;
struct /* coclass */ TargetInvocationException;
struct /* coclass */ TargetParameterCountException;
enum TypeAttributes;
struct /* coclass */ TypeDelegator;
struct /* coclass */ TypeFilter;
struct /* coclass */ MethodBase;
struct /* coclass */ ConstructorInfo;
struct /* coclass */ MethodInfo;
struct /* coclass */ FieldInfo;
struct /* coclass */ EventInfo;
struct /* coclass */ PropertyInfo;
struct /* coclass */ ParameterInfo;
struct __declspec(uuid("93d7a8c5-d2eb-319b-a374-a65d321f2aa9"))
/* dual interface */ IFormatter;
struct /* coclass */ Formatter;
struct __declspec(uuid("f4f5c303-fad3-3d0c-a4df-bb82b5ee308f"))
/* dual interface */ IFormatterConverter;
struct /* coclass */ FormatterConverter;
struct /* coclass */ FormatterServices;
struct __declspec(uuid("62339172-dbfa-337b-8ac8-053b241e06ab"))
/* dual interface */ ISerializationSurrogate;
struct __declspec(uuid("7c66ff18-a1a5-3e19-857b-0e7b6a9e3f38"))
/* dual interface */ ISurrogateSelector;
struct /* coclass */ ObjectIDGenerator;
struct /* coclass */ ObjectManager;
struct /* coclass */ OptionalFieldAttribute;
struct /* coclass */ OnSerializingAttribute;
struct /* coclass */ OnSerializedAttribute;
struct /* coclass */ OnDeserializingAttribute;
struct /* coclass */ OnDeserializedAttribute;
struct /* coclass */ SerializationBinder;
struct /* coclass */ SerializationInfo;
struct SerializationEntry;
struct /* coclass */ SerializationInfoEnumerator;
struct /* coclass */ SerializationException;
struct StreamingContext;
enum StreamingContextStates;
struct /* coclass */ SurrogateSelector;
struct /* coclass */ Calendar;
enum CalendarAlgorithmType;
enum CalendarWeekRule;
struct /* coclass */ EastAsianLunisolarCalendar;
enum CompareOptions;
struct /* coclass */ CompareInfo;
struct /* coclass */ CultureInfo;
enum CultureTypes;
enum DateTimeStyles;
struct /* coclass */ DateTimeFormatInfo;
struct /* coclass */ DaylightTime;
enum DigitShapes;
struct /* coclass */ GregorianCalendar;
enum GregorianCalendarTypes;
struct /* coclass */ HebrewCalendar;
struct /* coclass */ HijriCalendar;
struct /* coclass */ JapaneseCalendar;
struct /* coclass */ JulianCalendar;
struct /* coclass */ KoreanCalendar;
struct /* coclass */ RegionInfo;
struct /* coclass */ SortKey;
struct /* coclass */ StringInfo;
struct /* coclass */ TaiwanCalendar;
struct /* coclass */ TextElementEnumerator;
struct /* coclass */ TextInfo;
struct /* coclass */ ThaiBuddhistCalendar;
struct /* coclass */ NumberFormatInfo;
enum NumberStyles;
enum UnicodeCategory;
struct /* coclass */ Encoding;
struct /* coclass */ Encoder;
struct /* coclass */ Decoder;
struct /* coclass */ ASCIIEncoding;
enum NormalizationForm;
struct /* coclass */ UnicodeEncoding;
struct /* coclass */ UTF7Encoding;
struct /* coclass */ UTF8Encoding;
struct __declspec(uuid("8965a22f-fba8-36ad-8132-70bbd0da457d"))
/* dual interface */ IResourceReader;
struct __declspec(uuid("e97aa6e5-595e-31c3-82f0-688fb91954c6"))
/* dual interface */ IResourceWriter;
struct /* coclass */ MissingManifestResourceException;
struct /* coclass */ MissingSatelliteAssemblyException;
struct /* coclass */ NeutralResourcesLanguageAttribute;
struct /* coclass */ ResourceManager;
struct /* coclass */ ResourceReader;
struct /* coclass */ ResourceSet;
struct /* coclass */ ResourceWriter;
struct /* coclass */ SatelliteContractVersionAttribute;
enum UltimateResourceFallbackLocation;
struct /* coclass */ Registry;
enum RegistryHive;
struct /* coclass */ RegistryKey;
enum RegistryValueKind;
struct __declspec(uuid("fd46bde5-acdf-3ca5-b189-f0678387077f"))
/* dual interface */ ISecurityEncodable;
struct __declspec(uuid("e6c21ba7-21bb-34e9-8e57-db66d8ce4a70"))
/* dual interface */ ISecurityPolicyEncodable;
struct __declspec(uuid("6844eff4-4f86-3ca1-a1ea-aaf583a6395e"))
/* dual interface */ IMembershipCondition;
struct /* coclass */ AllMembershipCondition;
struct /* coclass */ ApplicationDirectory;
struct /* coclass */ ApplicationDirectoryMembershipCondition;
struct /* coclass */ ApplicationSecurityInfo;
struct /* coclass */ ApplicationSecurityManager;
enum ApplicationVersionMatch;
struct /* coclass */ ApplicationTrust;
struct /* coclass */ ApplicationTrustCollection;
struct /* coclass */ ApplicationTrustEnumerator;
struct /* coclass */ CodeGroup;
struct /* coclass */ Evidence;
struct /* coclass */ FileCodeGroup;
struct /* coclass */ FirstMatchCodeGroup;
struct __declspec(uuid("4e95244e-c6fc-3a86-8db7-1712454de3b6"))
/* dual interface */ IIdentityPermissionFactory;
struct __declspec(uuid("427e255d-af02-3b0d-8ce3-a2bb94ba300f"))
/* dual interface */ IApplicationTrustManager;
enum TrustManagerUIContext;
struct /* coclass */ TrustManagerContext;
struct /* coclass */ CodeConnectAccess;
struct /* coclass */ NetCodeGroup;
struct /* coclass */ PermissionRequestEvidence;
struct /* coclass */ PolicyException;
struct /* coclass */ PolicyLevel;
enum PolicyStatementAttribute;
struct /* coclass */ PolicyStatement;
struct /* coclass */ Site;
struct /* coclass */ SiteMembershipCondition;
struct /* coclass */ StrongName;
struct /* coclass */ StrongNameMembershipCondition;
struct /* coclass */ UnionCodeGroup;
struct /* coclass */ Url;
struct /* coclass */ UrlMembershipCondition;
struct /* coclass */ Zone;
struct /* coclass */ ZoneMembershipCondition;
struct /* coclass */ GacInstalled;
struct /* coclass */ GacMembershipCondition;
struct /* coclass */ Hash;
struct /* coclass */ HashMembershipCondition;
struct /* coclass */ Publisher;
struct /* coclass */ PublisherMembershipCondition;
struct __declspec(uuid("f4205a87-4d46-303d-b1d9-5a99f7c90d30"))
/* dual interface */ IIdentity;
struct /* coclass */ GenericIdentity;
struct __declspec(uuid("4283ca6c-d291-3481-83c9-9554481fe888"))
/* dual interface */ IPrincipal;
struct /* coclass */ GenericPrincipal;
enum PrincipalPolicy;
enum WindowsAccountType;
enum TokenImpersonationLevel;
enum TokenAccessLevels;
struct /* coclass */ WindowsIdentity;
struct /* coclass */ WindowsImpersonationContext;
enum WindowsBuiltInRole;
struct /* coclass */ WindowsPrincipal;
struct ArrayWithOffset;
struct /* coclass */ UnmanagedFunctionPointerAttribute;
struct /* coclass */ DispIdAttribute;
enum ComInterfaceType;
struct /* coclass */ InterfaceTypeAttribute;
struct /* coclass */ ComDefaultInterfaceAttribute;
enum ClassInterfaceType;
struct /* coclass */ ClassInterfaceAttribute;
struct /* coclass */ ComVisibleAttribute;
struct /* coclass */ TypeLibImportClassAttribute;
struct /* coclass */ LCIDConversionAttribute;
struct /* coclass */ ComRegisterFunctionAttribute;
struct /* coclass */ ComUnregisterFunctionAttribute;
struct /* coclass */ ProgIdAttribute;
struct /* coclass */ ImportedFromTypeLibAttribute;
enum IDispatchImplType;
struct /* coclass */ IDispatchImplAttribute;
struct /* coclass */ ComSourceInterfacesAttribute;
struct /* coclass */ ComConversionLossAttribute;
enum TypeLibTypeFlags;
enum TypeLibFuncFlags;
enum TypeLibVarFlags;
struct /* coclass */ TypeLibTypeAttribute;
struct /* coclass */ TypeLibFuncAttribute;
struct /* coclass */ TypeLibVarAttribute;
enum VarEnum;
enum UnmanagedType;
struct /* coclass */ MarshalAsAttribute;
struct /* coclass */ ComImportAttribute;
struct /* coclass */ GuidAttribute;
struct /* coclass */ PreserveSigAttribute;
struct /* coclass */ InAttribute;
struct /* coclass */ OutAttribute;
struct /* coclass */ OptionalAttribute;
struct /* coclass */ DllImportAttribute;
struct /* coclass */ StructLayoutAttribute;
struct /* coclass */ FieldOffsetAttribute;
struct /* coclass */ ComAliasNameAttribute;
struct /* coclass */ AutomationProxyAttribute;
struct /* coclass */ PrimaryInteropAssemblyAttribute;
struct /* coclass */ CoClassAttribute;
struct /* coclass */ ComEventInterfaceAttribute;
struct /* coclass */ TypeLibVersionAttribute;
struct /* coclass */ ComCompatibleVersionAttribute;
struct /* coclass */ BestFitMappingAttribute;
struct /* coclass */ DefaultCharSetAttribute;
struct /* coclass */ SetWin32ContextInIDispatchAttribute;
enum CallingConvention;
enum CharSet;
struct /* coclass */ ExternalException;
struct /* coclass */ COMException;
enum GCHandleType;
struct GCHandle;
struct HandleRef;
struct __declspec(uuid("601cd486-04bf-3213-9ea9-06ebe4351d74"))
/* dual interface */ ICustomMarshaler;
struct /* coclass */ InvalidOleVariantTypeException;
enum LayoutKind;
struct __declspec(uuid("f1c3bf76-c3e4-11d3-88e7-00902754c43a"))
/* interface */ ITypeLibImporterNotifySink;
struct /* coclass */ MarshalDirectiveException;
struct /* coclass */ RuntimeEnvironment;
struct /* coclass */ SEHException;
struct /* coclass */ BStrWrapper;
enum ComMemberType;
struct /* coclass */ CurrencyWrapper;
struct /* coclass */ DispatchWrapper;
struct /* coclass */ ErrorWrapper;
struct /* coclass */ ExtensibleClassFactory;
struct __declspec(uuid("3cc86595-feb5-3ce9-ba14-d05c8dc3321c"))
/* dual interface */ ICustomAdapter;
struct __declspec(uuid("0ca9008e-ee90-356e-9f6d-b59e6006b9a4"))
/* dual interface */ ICustomFactory;
struct /* coclass */ InvalidComObjectException;
enum AssemblyRegistrationFlags;
struct __declspec(uuid("ccbd682c-73a5-4568-b8b0-c7007e11aba2"))
/* dual interface */ IRegistrationServices;
enum TypeLibImporterFlags;
enum TypeLibExporterFlags;
enum ImporterEventKind;
enum ExporterEventKind;
struct __declspec(uuid("f1c3bf77-c3e4-11d3-88e7-00902754c43a"))
/* interface */ ITypeLibExporterNotifySink;
struct __declspec(uuid("f1c3bf78-c3e4-11d3-88e7-00902754c43a"))
/* interface */ ITypeLibConverter;
struct __declspec(uuid("fa1f3615-acb9-486d-9eac-1bef87e36b09"))
/* interface */ ITypeLibExporterNameProvider;
struct /* coclass */ ObjectCreationDelegate;
struct /* coclass */ RegistrationServices;
struct /* coclass */ SafeArrayRankMismatchException;
struct /* coclass */ SafeArrayTypeMismatchException;
struct /* coclass */ TypeLibConverter;
struct /* coclass */ UnknownWrapper;
struct __declspec(uuid("afbf15e6-c37c-11d2-b88e-00a0c9b471b8"))
/* dual interface */ IExpando;
struct /* coclass */ Stream;
struct /* coclass */ BinaryReader;
struct /* coclass */ BinaryWriter;
struct /* coclass */ BufferedStream;
struct /* coclass */ Directory;
struct /* coclass */ FileSystemInfo;
struct /* coclass */ DirectoryInfo;
enum SearchOption;
struct /* coclass */ IOException;
struct /* coclass */ DirectoryNotFoundException;
enum DriveType;
struct /* coclass */ DriveInfo;
struct /* coclass */ DriveNotFoundException;
struct /* coclass */ EndOfStreamException;
struct /* coclass */ File;
enum FileAccess;
struct /* coclass */ FileInfo;
struct /* coclass */ FileLoadException;
enum FileMode;
struct /* coclass */ FileNotFoundException;
enum FileOptions;
enum FileShare;
struct /* coclass */ FileStream;
enum FileAttributes;
struct /* coclass */ MemoryStream;
struct /* coclass */ Path;
struct /* coclass */ PathTooLongException;
enum SeekOrigin;
struct /* coclass */ TextReader;
struct /* coclass */ StreamReader;
struct /* coclass */ TextWriter;
struct /* coclass */ StreamWriter;
struct /* coclass */ StringReader;
struct /* coclass */ StringWriter;
struct /* coclass */ AccessedThroughPropertyAttribute;
struct /* coclass */ CallConvCdecl;
struct /* coclass */ CallConvStdcall;
struct /* coclass */ CallConvThiscall;
struct /* coclass */ CallConvFastcall;
struct /* coclass */ CustomConstantAttribute;
struct /* coclass */ DateTimeConstantAttribute;
struct /* coclass */ DiscardableAttribute;
struct /* coclass */ DecimalConstantAttribute;
enum CompilationRelaxations;
struct /* coclass */ CompilationRelaxationsAttribute;
struct /* coclass */ CompilerGlobalScopeAttribute;
struct /* coclass */ IndexerNameAttribute;
struct /* coclass */ IsVolatile;
enum MethodImplOptions;
enum MethodCodeType;
struct /* coclass */ MethodImplAttribute;
struct /* coclass */ RequiredAttributeAttribute;
struct /* coclass */ IsCopyConstructed;
struct /* coclass */ NativeCppClassAttribute;
struct /* coclass */ IDispatchConstantAttribute;
struct /* coclass */ IUnknownConstantAttribute;
struct /* coclass */ SecurityElement;
struct /* coclass */ XmlSyntaxException;
enum EnvironmentPermissionAccess;
struct __declspec(uuid("a19b3fc6-d680-3dd4-a17a-f58a7d481494"))
/* dual interface */ IPermission;
struct __declspec(uuid("60fc57b0-4a46-32a0-a5b4-b05b0de8e781"))
/* dual interface */ IStackWalk;
struct /* coclass */ CodeAccessPermission;
struct __declspec(uuid("0f1284e6-4399-3963-8ddd-a6a4904f66c8"))
/* dual interface */ IUnrestrictedPermission;
struct /* coclass */ EnvironmentPermission;
enum FileDialogPermissionAccess;
struct /* coclass */ FileDialogPermission;
enum FileIOPermissionAccess;
struct /* coclass */ FileIOPermission;
enum HostProtectionResource;
struct /* coclass */ SecurityAttribute;
struct /* coclass */ CodeAccessSecurityAttribute;
struct /* coclass */ HostProtectionAttribute;
enum IsolatedStorageContainment;
struct /* coclass */ IsolatedStoragePermission;
struct /* coclass */ IsolatedStorageFilePermission;
enum PermissionState;
enum SecurityAction;
struct /* coclass */ EnvironmentPermissionAttribute;
struct /* coclass */ FileDialogPermissionAttribute;
struct /* coclass */ FileIOPermissionAttribute;
struct /* coclass */ KeyContainerPermissionAttribute;
struct /* coclass */ PrincipalPermissionAttribute;
struct /* coclass */ ReflectionPermissionAttribute;
struct /* coclass */ RegistryPermissionAttribute;
struct /* coclass */ SecurityPermissionAttribute;
struct /* coclass */ UIPermissionAttribute;
struct /* coclass */ ZoneIdentityPermissionAttribute;
struct /* coclass */ StrongNameIdentityPermissionAttribute;
struct /* coclass */ SiteIdentityPermissionAttribute;
struct /* coclass */ UrlIdentityPermissionAttribute;
struct /* coclass */ PublisherIdentityPermissionAttribute;
struct /* coclass */ IsolatedStoragePermissionAttribute;
struct /* coclass */ IsolatedStorageFilePermissionAttribute;
struct /* coclass */ PermissionSetAttribute;
enum ReflectionPermissionFlag;
struct /* coclass */ ReflectionPermission;
struct /* coclass */ PrincipalPermission;
enum SecurityPermissionFlag;
struct /* coclass */ SecurityPermission;
struct /* coclass */ SiteIdentityPermission;
struct /* coclass */ StrongNameIdentityPermission;
struct /* coclass */ StrongNamePublicKeyBlob;
enum UIPermissionWindow;
enum UIPermissionClipboard;
struct /* coclass */ UIPermission;
struct /* coclass */ UrlIdentityPermission;
struct /* coclass */ ZoneIdentityPermission;
struct /* coclass */ GacIdentityPermissionAttribute;
struct /* coclass */ GacIdentityPermission;
enum KeyContainerPermissionFlags;
struct /* coclass */ KeyContainerPermissionAccessEntry;
struct /* coclass */ KeyContainerPermissionAccessEntryCollection;
struct /* coclass */ KeyContainerPermissionAccessEntryEnumerator;
struct /* coclass */ KeyContainerPermission;
struct /* coclass */ PublisherIdentityPermission;
enum RegistryPermissionAccess;
struct /* coclass */ RegistryPermission;
struct /* coclass */ SuppressUnmanagedCodeSecurityAttribute;
struct /* coclass */ UnverifiableCodeAttribute;
struct /* coclass */ AllowPartiallyTrustedCallersAttribute;
enum HostSecurityManagerOptions;
struct /* coclass */ HostSecurityManager;
struct /* coclass */ PermissionSet;
struct /* coclass */ NamedPermissionSet;
struct /* coclass */ SecurityException;
struct /* coclass */ HostProtectionException;
enum PolicyLevelType;
struct /* coclass */ SecurityManager;
enum SecurityZone;
struct /* coclass */ VerificationException;
struct __declspec(uuid("4a68baa3-27aa-314a-bdbb-6ae9bdfc0420"))
/* dual interface */ IContextAttribute;
struct __declspec(uuid("f01d896d-8d5f-3235-be59-20e1e10dc22a"))
/* dual interface */ IContextProperty;
struct /* coclass */ ContextAttribute;
struct __declspec(uuid("c02bbb79-5aa8-390d-927f-717b7bff06a1"))
/* dual interface */ IActivator;
struct __declspec(uuid("941f8aaa-a353-3b1d-a019-12e44377f1cd"))
/* dual interface */ IMessageSink;
struct /* coclass */ AsyncResult;
struct /* coclass */ CallContext;
struct __declspec(uuid("4d125449-ba27-3927-8589-3e1b34b622e5"))
/* dual interface */ ILogicalThreadAffinative;
struct /* coclass */ LogicalCallContext;
struct /* coclass */ ChannelServices;
struct __declspec(uuid("3afab213-f5a2-3241-93ba-329ea4ba8016"))
/* dual interface */ IClientResponseChannelSinkStack;
struct __declspec(uuid("3a5fde6b-db46-34e8-bacd-16ea5a440540"))
/* dual interface */ IClientChannelSinkStack;
struct /* coclass */ ClientChannelSinkStack;
struct __declspec(uuid("9be679a6-61fd-38fc-a7b2-89982d33338b"))
/* dual interface */ IServerResponseChannelSinkStack;
struct __declspec(uuid("e694a733-768d-314d-b317-dcead136b11d"))
/* dual interface */ IServerChannelSinkStack;
struct /* coclass */ ServerChannelSinkStack;
struct __declspec(uuid("675591af-0508-3131-a7cc-287d265ca7d6"))
/* dual interface */ ISponsor;
struct /* coclass */ ClientSponsor;
enum WellKnownObjectMode;
struct /* coclass */ CrossContextDelegate;
struct /* coclass */ Context;
struct /* coclass */ ContextProperty;
struct __declspec(uuid("7197b56b-5fa1-31ef-b38b-62fee737277f"))
/* dual interface */ IContextPropertyActivator;
struct __declspec(uuid("563581e8-c86d-39e2-b2e8-6c23f7987a4b"))
/* dual interface */ IChannel;
struct __declspec(uuid("10f1d605-e201-3145-b7ae-3ad746701986"))
/* dual interface */ IChannelSender;
struct __declspec(uuid("48ad41da-0872-31da-9887-f81f213527e6"))
/* dual interface */ IChannelReceiver;
struct __declspec(uuid("7dd6e975-24ea-323c-a98c-0fde96f9c4e6"))
/* dual interface */ IServerChannelSinkProvider;
struct __declspec(uuid("308de042-acc8-32f8-b632-7cb9799d9aa6"))
/* dual interface */ IChannelSinkBase;
struct __declspec(uuid("21b5f37b-bef3-354c-8f84-0f9f0863f5c5"))
/* dual interface */ IServerChannelSink;
struct /* coclass */ EnterpriseServicesHelper;
struct /* coclass */ Header;
struct /* coclass */ HeaderHandler;
enum ActivatorLevel;
struct __declspec(uuid("1a8b0de6-b825-38c5-b744-8f93075fd6fa"))
/* dual interface */ IMessage;
struct __declspec(uuid("8e5e0b95-750e-310d-892c-8ca7231cf75b"))
/* dual interface */ IMethodMessage;
struct __declspec(uuid("b90efaa6-25e4-33d2-aca3-94bf74dc4ab9"))
/* dual interface */ IMethodCallMessage;
struct __declspec(uuid("fa28e3af-7d09-31d5-beeb-7f2626497cde"))
/* dual interface */ IConstructionCallMessage;
struct __declspec(uuid("f617690a-55f4-36af-9149-d199831f8594"))
/* dual interface */ IMethodReturnMessage;
struct __declspec(uuid("ca0ab564-f5e9-3a7f-a80b-eb0aeefa44e9"))
/* dual interface */ IConstructionReturnMessage;
struct __declspec(uuid("3a02d3f7-3f40-3022-853d-cfda765182fe"))
/* dual interface */ IChannelReceiverHook;
struct __declspec(uuid("3f8742c2-ac57-3440-a283-fe5ff4c75025"))
/* dual interface */ IClientChannelSinkProvider;
struct __declspec(uuid("6d94b6f3-da91-3c2f-b876-083769667468"))
/* dual interface */ IClientFormatterSinkProvider;
struct __declspec(uuid("042b5200-4317-3e4d-b653-7e9a08f1a5f2"))
/* dual interface */ IServerFormatterSinkProvider;
struct __declspec(uuid("ff726320-6b92-3e6c-aaac-f97063d0b142"))
/* dual interface */ IClientChannelSink;
enum ServerProcessing;
struct __declspec(uuid("46527c03-b144-3cf0-86b3-b8776148a6e9"))
/* dual interface */ IClientFormatterSink;
struct __declspec(uuid("1e250ccd-dc30-3217-a7e4-148f375a0088"))
/* dual interface */ IChannelDataStore;
struct /* coclass */ ChannelDataStore;
struct __declspec(uuid("1ac82fbe-4ff0-383c-bbfd-fe40ecb3628d"))
/* dual interface */ ITransportHeaders;
struct /* coclass */ TransportHeaders;
struct /* coclass */ SinkProviderData;
struct /* coclass */ BaseChannelObjectWithProperties;
struct /* coclass */ BaseChannelSinkWithProperties;
struct /* coclass */ BaseChannelWithProperties;
struct __declspec(uuid("4db956b7-69d0-312a-aa75-44fb55fd5d4b"))
/* dual interface */ IContributeClientContextSink;
struct __declspec(uuid("a0fe9b86-0c06-32ce-85fa-2ff1b58697fb"))
/* dual interface */ IContributeDynamicSink;
struct __declspec(uuid("124777b6-0308-3569-97e5-e6fe88eae4eb"))
/* dual interface */ IContributeEnvoySink;
struct __declspec(uuid("6a5d38bc-2789-3546-81a1-f10c0fb59366"))
/* dual interface */ IContributeObjectSink;
struct __declspec(uuid("0caa23ec-f78c-39c9-8d25-b7a9ce4097a7"))
/* dual interface */ IContributeServerContextSink;
struct __declspec(uuid("00a358d4-4d58-3b9d-8fb6-fb7f6bc1713b"))
/* dual interface */ IDynamicProperty;
struct __declspec(uuid("c74076bb-8a2d-3c20-a542-625329e9af04"))
/* dual interface */ IDynamicMessageSink;
struct __declspec(uuid("53a561f2-cbbf-3748-bffe-2180002db3df"))
/* dual interface */ ILease;
struct __declspec(uuid("3677cbb0-784d-3c15-bbc8-75cd7dc3901e"))
/* dual interface */ IMessageCtrl;
struct __declspec(uuid("ae1850fd-3596-3727-a242-2fc31c5a0312"))
/* dual interface */ IRemotingFormatter;
enum LeaseState;
struct /* coclass */ LifetimeServices;
struct /* coclass */ ReturnMessage;
struct /* coclass */ MethodCall;
struct /* coclass */ ConstructionCall;
struct /* coclass */ MethodResponse;
struct __declspec(uuid("cc18fd4d-aa2d-3ab4-9848-584bbae4ab44"))
/* dual interface */ IFieldInfo;
struct /* coclass */ ConstructionResponse;
struct /* coclass */ InternalMessageWrapper;
struct /* coclass */ MethodCallMessageWrapper;
struct /* coclass */ MethodReturnMessageWrapper;
struct /* coclass */ ObjectHandle;
struct __declspec(uuid("c09effa9-1ffe-3a52-a733-6236cbc45e7b"))
/* dual interface */ IRemotingTypeInfo;
struct __declspec(uuid("855e6566-014a-3fe8-aa70-1eac771e3a88"))
/* dual interface */ IChannelInfo;
struct __declspec(uuid("2a6e91b9-a874-38e4-99c2-c5d83d78140d"))
/* dual interface */ IEnvoyInfo;
struct /* coclass */ ObjRef;
struct /* coclass */ OneWayAttribute;
struct /* coclass */ ProxyAttribute;
struct /* coclass */ RealProxy;
enum SoapOption;
enum XmlFieldOrderOption;
struct /* coclass */ SoapAttribute;
struct /* coclass */ SoapTypeAttribute;
struct /* coclass */ SoapMethodAttribute;
struct /* coclass */ SoapFieldAttribute;
struct /* coclass */ SoapParameterAttribute;
struct /* coclass */ RemotingConfiguration;
struct /* coclass */ TypeEntry;
struct /* coclass */ ActivatedClientTypeEntry;
struct /* coclass */ ActivatedServiceTypeEntry;
struct /* coclass */ WellKnownClientTypeEntry;
struct /* coclass */ WellKnownServiceTypeEntry;
enum CustomErrorsModes;
struct /* coclass */ RemotingException;
struct /* coclass */ ServerException;
struct /* coclass */ RemotingTimeoutException;
struct /* coclass */ RemotingServices;
struct /* coclass */ InternalRemotingServices;
struct /* coclass */ MessageSurrogateFilter;
struct /* coclass */ RemotingSurrogateSelector;
struct /* coclass */ SoapServices;
struct __declspec(uuid("80031d2a-ad59-3fb4-97f3-b864d71da86b"))
/* dual interface */ ISoapXsd;
struct /* coclass */ SoapDateTime;
struct /* coclass */ SoapDuration;
struct /* coclass */ SoapTime;
struct /* coclass */ SoapDate;
struct /* coclass */ SoapYearMonth;
struct /* coclass */ SoapYear;
struct /* coclass */ SoapMonthDay;
struct /* coclass */ SoapDay;
struct /* coclass */ SoapMonth;
struct /* coclass */ SoapHexBinary;
struct /* coclass */ SoapBase64Binary;
struct /* coclass */ SoapInteger;
struct /* coclass */ SoapPositiveInteger;
struct /* coclass */ SoapNonPositiveInteger;
struct /* coclass */ SoapNonNegativeInteger;
struct /* coclass */ SoapNegativeInteger;
struct /* coclass */ SoapAnyUri;
struct /* coclass */ SoapQName;
struct /* coclass */ SoapNotation;
struct /* coclass */ SoapNormalizedString;
struct /* coclass */ SoapToken;
struct /* coclass */ SoapLanguage;
struct /* coclass */ SoapName;
struct /* coclass */ SoapIdrefs;
struct /* coclass */ SoapEntities;
struct /* coclass */ SoapNmtoken;
struct /* coclass */ SoapNmtokens;
struct /* coclass */ SoapNcName;
struct /* coclass */ SoapId;
struct /* coclass */ SoapIdref;
struct /* coclass */ SoapEntity;
struct /* coclass */ SynchronizationAttribute;
struct __declspec(uuid("03ec7d10-17a5-3585-9a2e-0596fcac3870"))
/* dual interface */ ITrackingHandler;
struct /* coclass */ TrackingServices;
struct /* coclass */ UrlAttribute;
enum IsolatedStorageScope;
struct /* coclass */ IsolatedStorage;
struct /* coclass */ IsolatedStorageFile;
struct /* coclass */ IsolatedStorageFileStream;
struct /* coclass */ IsolatedStorageException;
struct __declspec(uuid("f5006531-d4d7-319e-9eda-9b4b65ad8d4f"))
/* dual interface */ INormalizeForIsolatedStorage;
enum FormatterTypeStyle;
enum FormatterAssemblyStyle;
enum TypeFilterLevel;
struct __declspec(uuid("e699146c-7793-3455-9bef-964c90d8f995"))
/* dual interface */ ISoapMessage;
struct /* coclass */ InternalRM;
struct /* coclass */ InternalST;
struct /* coclass */ SoapMessage;
struct /* coclass */ SoapFault;
struct /* coclass */ ServerFault;
struct /* coclass */ BinaryFormatter;
struct __declspec(uuid("bebb2505-8b54-3443-aead-142a16dd9cc7"))
/* interface */ _AssemblyBuilder;
struct /* coclass */ AssemblyBuilder;
enum AssemblyBuilderAccess;
struct __declspec(uuid("ed3e4384-d7e2-3fa7-8ffd-8940d330519a"))
/* interface */ _ConstructorBuilder;
struct __declspec(uuid("be9acce8-aaff-3b91-81ae-8211663f5cad"))
/* interface */ _CustomAttributeBuilder;
struct __declspec(uuid("c7bd73de-9f85-3290-88ee-090b8bdfe2df"))
/* interface */ _EnumBuilder;
struct __declspec(uuid("aadaba99-895d-3d65-9760-b1f12621fae8"))
/* interface */ _EventBuilder;
struct __declspec(uuid("ce1a3bf5-975e-30cc-97c9-1ef70f8f3993"))
/* interface */ _FieldBuilder;
struct __declspec(uuid("a4924b27-6e3b-37f7-9b83-a4501955e6a7"))
/* interface */ _ILGenerator;
struct __declspec(uuid("4e6350d1-a08b-3dec-9a3e-c465f9aeec0c"))
/* interface */ _LocalBuilder;
struct __declspec(uuid("007d8a14-fdf3-363e-9a0b-fec0618260a2"))
/* interface */ _MethodBuilder;
struct __declspec(uuid("c2323c25-f57f-3880-8a4d-12ebea7a5852"))
/* interface */ _MethodRental;
struct __declspec(uuid("d05ffa9a-04af-3519-8ee1-8d93ad73430b"))
/* interface */ _ModuleBuilder;
struct __declspec(uuid("36329eba-f97a-3565-bc07-0ed5c6ef19fc"))
/* interface */ _ParameterBuilder;
struct __declspec(uuid("15f9a479-9397-3a63-acbd-f51977fb0f02"))
/* interface */ _PropertyBuilder;
struct __declspec(uuid("7d13dd37-5a04-393c-bbca-a5fea802893d"))
/* interface */ _SignatureHelper;
struct __declspec(uuid("7e5678ee-48b3-3f83-b076-c58543498a58"))
/* interface */ _TypeBuilder;
struct /* coclass */ ConstructorBuilder;
struct /* coclass */ ILGenerator;
struct /* coclass */ DynamicILInfo;
struct /* coclass */ DynamicMethod;
struct /* coclass */ EventBuilder;
struct EventToken;
struct /* coclass */ FieldBuilder;
struct FieldToken;
struct Label;
struct /* coclass */ LocalBuilder;
struct /* coclass */ MethodBuilder;
struct /* coclass */ CustomAttributeBuilder;
struct /* coclass */ MethodRental;
struct MethodToken;
struct /* coclass */ ModuleBuilder;
enum PEFileKinds;
struct /* coclass */ OpCodes;
struct OpCode;
enum OpCodeType;
enum StackBehaviour;
enum OperandType;
enum FlowControl;
struct /* coclass */ ParameterBuilder;
struct ParameterToken;
struct /* coclass */ PropertyBuilder;
struct PropertyToken;
struct /* coclass */ SignatureHelper;
struct SignatureToken;
struct StringToken;
enum PackingSize;
struct /* coclass */ TypeBuilder;
struct /* coclass */ GenericTypeParameterBuilder;
struct /* coclass */ EnumBuilder;
struct TypeToken;
struct /* coclass */ UnmanagedMarshal;
struct AssemblyHash;
enum AssemblyHashAlgorithm;
enum AssemblyVersionCompatibility;
enum CipherMode;
enum PaddingMode;
struct /* coclass */ KeySizes;
struct /* coclass */ CryptographicException;
struct /* coclass */ CryptographicUnexpectedOperationException;
struct __declspec(uuid("8abad867-f515-3cf6-bb62-5f0c88b3bb11"))
/* dual interface */ ICryptoTransform;
struct /* coclass */ RandomNumberGenerator;
struct /* coclass */ RNGCryptoServiceProvider;
struct /* coclass */ AsymmetricAlgorithm;
struct /* coclass */ AsymmetricKeyExchangeDeformatter;
struct /* coclass */ AsymmetricKeyExchangeFormatter;
struct /* coclass */ AsymmetricSignatureDeformatter;
struct /* coclass */ AsymmetricSignatureFormatter;
enum FromBase64TransformMode;
struct /* coclass */ ToBase64Transform;
struct /* coclass */ FromBase64Transform;
struct /* coclass */ CryptoAPITransform;
enum CspProviderFlags;
struct /* coclass */ CspParameters;
struct /* coclass */ CryptoConfig;
enum CryptoStreamMode;
struct /* coclass */ CryptoStream;
struct /* coclass */ SymmetricAlgorithm;
struct /* coclass */ DES;
struct /* coclass */ DESCryptoServiceProvider;
struct /* coclass */ DeriveBytes;
struct DSAParameters;
struct /* coclass */ DSA;
struct __declspec(uuid("494a7583-190e-3693-9ec4-de54dc6a84a2"))
/* dual interface */ ICspAsymmetricAlgorithm;
struct /* coclass */ DSACryptoServiceProvider;
struct /* coclass */ DSASignatureDeformatter;
struct /* coclass */ DSASignatureFormatter;
struct /* coclass */ HashAlgorithm;
struct /* coclass */ KeyedHashAlgorithm;
struct /* coclass */ HMAC;
struct /* coclass */ HMACMD5;
struct /* coclass */ HMACRIPEMD160;
struct /* coclass */ HMACSHA1;
struct /* coclass */ HMACSHA256;
struct /* coclass */ HMACSHA384;
struct /* coclass */ HMACSHA512;
enum KeyNumber;
struct /* coclass */ CspKeyContainerInfo;
struct /* coclass */ MACTripleDES;
struct /* coclass */ MD5;
struct /* coclass */ MD5CryptoServiceProvider;
struct /* coclass */ MaskGenerationMethod;
struct /* coclass */ PasswordDeriveBytes;
struct /* coclass */ PKCS1MaskGenerationMethod;
struct /* coclass */ RC2;
struct /* coclass */ RC2CryptoServiceProvider;
struct /* coclass */ Rfc2898DeriveBytes;
struct /* coclass */ RIPEMD160;
struct /* coclass */ RIPEMD160Managed;
struct RSAParameters;
struct /* coclass */ RSA;
struct /* coclass */ RSACryptoServiceProvider;
struct /* coclass */ RSAOAEPKeyExchangeDeformatter;
struct /* coclass */ RSAOAEPKeyExchangeFormatter;
struct /* coclass */ RSAPKCS1KeyExchangeDeformatter;
struct /* coclass */ RSAPKCS1KeyExchangeFormatter;
struct /* coclass */ RSAPKCS1SignatureDeformatter;
struct /* coclass */ RSAPKCS1SignatureFormatter;
struct /* coclass */ Rijndael;
struct /* coclass */ RijndaelManaged;
struct /* coclass */ RijndaelManagedTransform;
struct /* coclass */ SHA1;
struct /* coclass */ SHA1CryptoServiceProvider;
struct /* coclass */ SHA1Managed;
struct /* coclass */ SHA256;
struct /* coclass */ SHA256Managed;
struct /* coclass */ SHA384;
struct /* coclass */ SHA384Managed;
struct /* coclass */ SHA512;
struct /* coclass */ SHA512Managed;
struct /* coclass */ SignatureDescription;
struct /* coclass */ TripleDES;
struct /* coclass */ TripleDESCryptoServiceProvider;
enum X509ContentType;
enum X509KeyStorageFlags;
struct /* coclass */ X509Certificate;
struct __declspec(uuid("65074f7f-63c0-304e-af0a-d51741cb4a8d"))
/* dual interface */ _Object;
struct __declspec(uuid("2b67cece-71c3-36a9-a136-925ccc1935a8"))
/* dual interface */ _Array;
struct __declspec(uuid("139e041d-0e41-39f5-a302-c4387e9d0a6c"))
/* dual interface */ _ValueType;
struct __declspec(uuid("d09d1e04-d590-39a3-b517-b734a49a9277"))
/* dual interface */ _Enum;
struct __declspec(uuid("36936699-fc79-324d-ab43-e33c1f94e263"))
/* dual interface */ _String;
struct __declspec(uuid("7499e7e8-df01-3948-b8d4-fa4b9661d36b"))
/* dual interface */ _StringComparer;
struct __declspec(uuid("9fb09782-8d39-3b0c-b79e-f7a37a65b3da"))
/* dual interface */ _StringBuilder;
struct __declspec(uuid("4c482cc2-68e9-37c6-8353-9a94bd2d7f0b"))
/* dual interface */ _SystemException;
struct __declspec(uuid("cf3edb7e-0574-3383-a44f-292f7c145db4"))
/* dual interface */ _OutOfMemoryException;
struct __declspec(uuid("9cf4339a-2911-3b8a-8f30-e5c6b5be9a29"))
/* dual interface */ _StackOverflowException;
struct __declspec(uuid("152a6b4d-09af-3edf-8cba-11797eeeea4e"))
/* dual interface */ _DataMisalignedException;
struct __declspec(uuid("ccf0139c-79f7-3d0a-affe-2b0762c65b07"))
/* dual interface */ _ExecutionEngineException;
struct __declspec(uuid("fb6ab00f-5096-3af8-a33d-d7885a5fa829"))
/* dual interface */ _Delegate;
struct __declspec(uuid("16fe0885-9129-3884-a232-90b58c5b2aa9"))
/* dual interface */ _MulticastDelegate;
struct __declspec(uuid("7eaba4e2-1259-3cf2-b084-9854278e5897"))
/* dual interface */ _MemberAccessException;
struct __declspec(uuid("13ef674a-6327-3caf-8772-fa0395612669"))
/* dual interface */ _AccessViolationException;
struct __declspec(uuid("d1204423-01f0-336a-8911-a7e8fbe185a3"))
/* dual interface */ _ApplicationActivator;
struct __declspec(uuid("d81130bf-d627-3b91-a7c7-cea597093464"))
/* dual interface */ _ApplicationException;
struct __declspec(uuid("1f9ec719-343a-3cb3-8040-3927626777c1"))
/* dual interface */ _EventArgs;
struct __declspec(uuid("98947cf0-77e7-328e-b709-5dd1aa1c9c96"))
/* dual interface */ _ResolveEventArgs;
struct __declspec(uuid("7a0325f0-22c2-31f9-8823-9b8aee9456b1"))
/* dual interface */ _AssemblyLoadEventArgs;
struct __declspec(uuid("8e54a9cc-7aa4-34ca-985b-bd7d7527b110"))
/* dual interface */ _ResolveEventHandler;
struct __declspec(uuid("deece11f-a893-3e35-a4c3-dab7fa0911eb"))
/* dual interface */ _AssemblyLoadEventHandler;
struct __declspec(uuid("5e6f9edb-3ce1-3a56-86d9-cd2ddf7a6fff"))
/* dual interface */ _AppDomainInitializer;
struct __declspec(uuid("2c358e27-8c1a-3c03-b086-a40465625557"))
/* dual interface */ _MarshalByRefObject;
struct __declspec(uuid("af93163f-c2f4-3fab-9ff1-728a7aaad1cb"))
/* dual interface */ _CrossAppDomainDelegate;
struct __declspec(uuid("63e53e04-d31b-3099-9f0c-c7a1c883c1d9"))
/* dual interface */ _AppDomainManager;
struct __declspec(uuid("ce59d7ad-05ca-33b4-a1dd-06028d46e9d2"))
/* dual interface */ _LoaderOptimizationAttribute;
struct __declspec(uuid("6e96aa70-9ffb-399d-96bf-a68436095c54"))
/* dual interface */ _AppDomainUnloadedException;
struct __declspec(uuid("cfd9ca27-f0ba-388a-acde-b7e20fcad79c"))
/* dual interface */ _ActivationArguments;
struct __declspec(uuid("2f218f95-4215-3cc6-8a51-bd2770c090e4"))
/* dual interface */ _ApplicationId;
struct __declspec(uuid("4db2c2b7-cbc2-3185-b966-875d4625b1a8"))
/* dual interface */ _ArgumentException;
struct __declspec(uuid("c991949b-e623-3f24-885c-bbb01ff43564"))
/* dual interface */ _ArgumentNullException;
struct __declspec(uuid("77da3028-bc45-3e82-bf76-2c123ee2c021"))
/* dual interface */ _ArgumentOutOfRangeException;
struct __declspec(uuid("9b012cf1-acf6-3389-a336-c023040c62a2"))
/* dual interface */ _ArithmeticException;
struct __declspec(uuid("dd7488a6-1b3f-3823-9556-c2772b15150f"))
/* dual interface */ _ArrayTypeMismatchException;
struct __declspec(uuid("3612706e-0239-35fd-b900-0819d16d442d"))
/* dual interface */ _AsyncCallback;
struct __declspec(uuid("a902a192-49ba-3ec8-b444-af5f7743f61a"))
/* dual interface */ _AttributeUsageAttribute;
struct __declspec(uuid("f98bce04-4a4b-398c-a512-fd8348d51e3b"))
/* dual interface */ _BadImageFormatException;
struct __declspec(uuid("f036bca4-f8df-3682-8290-75285ce7456c"))
/* dual interface */ _Buffer;
struct __declspec(uuid("6d4b6adb-b9fa-3809-b5ea-fa57b56c546f"))
/* dual interface */ _CannotUnloadAppDomainException;
struct __declspec(uuid("1dd627fc-89e3-384f-bb9d-58cb4efb9456"))
/* dual interface */ _CharEnumerator;
struct __declspec(uuid("bf1af177-94ca-3e6d-9d91-55cf9e859d22"))
/* dual interface */ _CLSCompliantAttribute;
struct __declspec(uuid("c2a10f3a-356a-3c77-aab9-8991d73a2561"))
/* dual interface */ _TypeUnloadedException;
struct __declspec(uuid("6b3f9834-1725-38c5-955e-20f051d067bd"))
/* dual interface */ _CriticalFinalizerObject;
struct __declspec(uuid("7386f4d7-7c11-389f-bb75-895714b12bb5"))
/* dual interface */ _ContextMarshalException;
struct __declspec(uuid("3eb1d909-e8bf-3c6b-ada5-0e86e31e186e"))
/* dual interface */ _ContextBoundObject;
struct __declspec(uuid("160d517f-f175-3b61-8264-6d2305b8246c"))
/* dual interface */ _ContextStaticAttribute;
struct __declspec(uuid("3025f666-7891-33d7-aacd-23d169ef354e"))
/* dual interface */ _TimeZone;
struct __declspec(uuid("0d9f1b65-6d27-3e9f-baf3-0597837e0f33"))
/* dual interface */ _DBNull;
struct __declspec(uuid("3169ab11-7109-3808-9a61-ef4ba0534fd9"))
/* dual interface */ _Binder;
struct __declspec(uuid("bdeea460-8241-3b41-9ed3-6e3e9977ac7f"))
/* dual interface */ _DivideByZeroException;
struct __declspec(uuid("d345a42b-cfe0-3eee-861c-f3322812b388"))
/* dual interface */ _DuplicateWaitObjectException;
struct __declspec(uuid("82d6b3bf-a633-3b3b-a09e-2363e4b24a41"))
/* dual interface */ _TypeLoadException;
struct __declspec(uuid("67388f3f-b600-3bcf-84aa-bb2b88dd9ee2"))
/* dual interface */ _EntryPointNotFoundException;
struct __declspec(uuid("24ae6464-2834-32cd-83d6-fa06953de62a"))
/* dual interface */ _DllNotFoundException;
struct __declspec(uuid("29dc56cf-b981-3432-97c8-3680ab6d862d"))
/* dual interface */ _Environment;
struct __declspec(uuid("7cefc46e-16e0-3e65-9c38-55b4342ba7f0"))
/* dual interface */ _EventHandler;
struct __declspec(uuid("8d5f5811-ffa1-3306-93e3-8afc572b9b82"))
/* dual interface */ _FieldAccessException;
struct __declspec(uuid("ebe3746d-ddec-3d23-8e8d-9361ba87bac6"))
/* dual interface */ _FlagsAttribute;
struct __declspec(uuid("07f92156-398a-3548-90b7-2e58026353d0"))
/* dual interface */ _FormatException;
struct __declspec(uuid("e5a5f1e4-82c1-391f-a1c6-f39eae9dc72f"))
/* dual interface */ _IndexOutOfRangeException;
struct __declspec(uuid("fa047cbd-9ba5-3a13-9b1f-6694d622cd76"))
/* dual interface */ _InvalidCastException;
struct __declspec(uuid("8d520d10-0b8a-3553-8874-d30a4ad2ff4c"))
/* dual interface */ _InvalidOperationException;
struct __declspec(uuid("3410e0fb-636f-3cd1-8045-3993ca113f25"))
/* dual interface */ _InvalidProgramException;
struct __declspec(uuid("dc77f976-318d-3a1a-9b60-abb9dd9406d6"))
/* dual interface */ _LocalDataStoreSlot;
struct __declspec(uuid("ff0bf77d-8f81-3d31-a3bb-6f54440fa7e5"))
/* dual interface */ _MethodAccessException;
struct __declspec(uuid("8897d14b-7fb3-3d8b-9ee4-221c3dbad6fe"))
/* dual interface */ _MissingMemberException;
struct __declspec(uuid("9717176d-1179-3487-8849-cf5f63de356e"))
/* dual interface */ _MissingFieldException;
struct __declspec(uuid("e5c659f6-92c8-3887-a07e-74d0d9c6267a"))
/* dual interface */ _MissingMethodException;
struct __declspec(uuid("d2ba71cc-1b3d-3966-a0d7-c61e957ad325"))
/* dual interface */ _MulticastNotSupportedException;
struct __declspec(uuid("665c9669-b9c6-3add-9213-099f0127c893"))
/* dual interface */ _NonSerializedAttribute;
struct __declspec(uuid("8e21ce22-4f17-347b-b3b5-6a6df3e0e58a"))
/* dual interface */ _NotFiniteNumberException;
struct __declspec(uuid("1e4d31a2-63ea-397a-a77e-b20ad87a9614"))
/* dual interface */ _NotImplementedException;
struct __declspec(uuid("40e5451f-b237-33f8-945b-0230db700bbb"))
/* dual interface */ _NotSupportedException;
struct __declspec(uuid("ecbe2313-cf41-34b4-9fd0-b6cd602b023f"))
/* dual interface */ _NullReferenceException;
struct __declspec(uuid("17b730ba-45ef-3ddf-9f8d-a490bac731f4"))
/* dual interface */ _ObjectDisposedException;
struct __declspec(uuid("e84307be-3036-307a-acc2-5d5de8a006a8"))
/* dual interface */ _ObsoleteAttribute;
struct __declspec(uuid("9e230640-a5d0-30e1-b217-9d2b6cc0fc40"))
/* dual interface */ _OperatingSystem;
struct __declspec(uuid("9df9af5a-7853-3d55-9b48-bd1f5d8367ab"))
/* dual interface */ _OperationCanceledException;
struct __declspec(uuid("37c69a5d-7619-3a0f-a96b-9c9578ae00ef"))
/* dual interface */ _OverflowException;
struct __declspec(uuid("d54500ae-8cf4-3092-9054-90dc91ac65c9"))
/* dual interface */ _ParamArrayAttribute;
struct __declspec(uuid("1eb8340b-8190-3d9d-92f8-51244b9804c5"))
/* dual interface */ _PlatformNotSupportedException;
struct __declspec(uuid("0f240708-629a-31ab-94a5-2bb476fe1783"))
/* dual interface */ _Random;
struct __declspec(uuid("871ddc46-b68e-3fee-a09a-c808b0f827e6"))
/* dual interface */ _RankException;
struct __declspec(uuid("1b96e53c-4028-38bc-9dc3-8d7a9555c311"))
/* dual interface */ _SerializableAttribute;
struct __declspec(uuid("7ab88ca9-17f4-385e-ad41-4ee0aa316fa1"))
/* dual interface */ _TimeoutException;
struct __declspec(uuid("feb0323d-8ce4-36a4-a41e-0ba0c32e1a6a"))
/* dual interface */ _TypeInitializationException;
struct __declspec(uuid("6193c5f6-6807-3561-a7f3-b64c80b5f00f"))
/* dual interface */ _UnauthorizedAccessException;
struct __declspec(uuid("a218e20a-0905-3741-b0b3-9e3193162e50"))
/* dual interface */ _UnhandledExceptionEventArgs;
struct __declspec(uuid("84199e64-439c-3011-b249-3c9065735adb"))
/* dual interface */ _UnhandledExceptionEventHandler;
struct __declspec(uuid("011a90c5-4910-3c29-bbb7-50d05ccbaa4a"))
/* dual interface */ _Version;
struct __declspec(uuid("c5df3568-c251-3c58-afb4-32e79e8261f0"))
/* dual interface */ _WeakReference;
struct __declspec(uuid("40dfc50a-e93a-3c08-b9ef-e2b4f28b5676"))
/* dual interface */ _WaitHandle;
struct __declspec(uuid("e142db4a-1a52-34ce-965e-13affd5447d0"))
/* dual interface */ _EventWaitHandle;
struct __declspec(uuid("3f243ebd-612f-3db8-9e03-bd92343a8371"))
/* dual interface */ _AutoResetEvent;
struct __declspec(uuid("56d201f1-3e5d-39d9-b5de-064710818905"))
/* dual interface */ _ContextCallback;
struct __declspec(uuid("c0bb9361-268f-3e72-bf6f-4120175a1500"))
/* dual interface */ _ManualResetEvent;
struct __declspec(uuid("ee22485e-4c45-3c9d-9027-a8d61c5f53f2"))
/* dual interface */ _Monitor;
struct __declspec(uuid("36cb559b-87c6-3ad2-9225-62a7ed499b37"))
/* dual interface */ _Mutex;
struct __declspec(uuid("dd846fcc-8d04-3665-81b6-aacbe99c19c3"))
/* dual interface */ _Overlapped;
struct __declspec(uuid("ad89b568-4fd4-3f8d-8327-b396b20a460e"))
/* dual interface */ _ReaderWriterLock;
struct __declspec(uuid("87f55344-17e0-30fd-8eb9-38eaf6a19b3f"))
/* dual interface */ _SynchronizationLockException;
struct __declspec(uuid("95b525db-6b81-3cdc-8fe7-713f7fc793c0"))
/* dual interface */ _ThreadAbortException;
struct __declspec(uuid("b9e07599-7c44-33be-a70e-efa16f51f54a"))
/* dual interface */ _ThreadInterruptedException;
struct __declspec(uuid("64409425-f8c9-370e-809e-3241ce804541"))
/* dual interface */ _RegisteredWaitHandle;
struct __declspec(uuid("ce949142-4d4c-358d-89a9-e69a531aa363"))
/* dual interface */ _WaitCallback;
struct __declspec(uuid("f078f795-f452-3d2d-8cc8-16d66ae46c67"))
/* dual interface */ _WaitOrTimerCallback;
struct __declspec(uuid("bbae942d-bff4-36e2-a3bc-508bb3801f4f"))
/* dual interface */ _IOCompletionCallback;
struct __declspec(uuid("b45bbd7e-a977-3f56-a626-7a693e5dbbc5"))
/* dual interface */ _ThreadStart;
struct __declspec(uuid("a13a41cf-e066-3b90-82f4-73109104e348"))
/* dual interface */ _ThreadStateException;
struct __declspec(uuid("a6b94b6d-854e-3172-a4ec-a17edd16f85e"))
/* dual interface */ _ThreadStaticAttribute;
struct __declspec(uuid("81456e86-22af-31d1-a91a-9c370c0e2530"))
/* dual interface */ _Timeout;
struct __declspec(uuid("3741bc6f-101b-36d7-a9d5-03fcc0ecda35"))
/* dual interface */ _TimerCallback;
struct __declspec(uuid("b49a029b-406b-3b1e-88e4-f86690d20364"))
/* dual interface */ _Timer;
struct __declspec(uuid("85d72f83-be91-3cb1-b4f0-76b56ff04033"))
/* dual interface */ _STAThreadAttribute;
struct __declspec(uuid("c02468d1-8713-3225-bda3-49b2fe37ddbb"))
/* dual interface */ _MTAThreadAttribute;
struct __declspec(uuid("401f89cb-c127-3041-82fd-b67035395c56"))
/* dual interface */ _ArrayList;
struct __declspec(uuid("f145c46a-d170-3170-b52f-4678dfca0300"))
/* dual interface */ _BitArray;
struct __declspec(uuid("ea6795ac-97d6-3377-be64-829abd67607b"))
/* dual interface */ _CaseInsensitiveComparer;
struct __declspec(uuid("0422b845-b636-3688-8f61-9b6d93096336"))
/* dual interface */ _CaseInsensitiveHashCodeProvider;
struct __declspec(uuid("b7d29e26-7798-3fa4-90f4-e6a22d2099f9"))
/* dual interface */ _CollectionBase;
struct __declspec(uuid("8064a157-b5c8-3a4a-ad3d-02dc1a39c417"))
/* dual interface */ _Comparer;
struct __declspec(uuid("ddd44da2-bc6b-3620-9317-c0372968c741"))
/* dual interface */ _DictionaryBase;
struct __declspec(uuid("d25a197e-3e69-3271-a989-23d85e97f920"))
/* dual interface */ _Hashtable;
struct __declspec(uuid("3a7d3ca4-b7d1-3a2a-800c-8fc2acfcbda4"))
/* dual interface */ _Queue;
struct __declspec(uuid("bd32d878-a59b-3e5c-bfe0-a96b1a1e9d6f"))
/* dual interface */ _ReadOnlyCollectionBase;
struct __declspec(uuid("56421139-a143-3ae9-9852-1dbdfe3d6bfa"))
/* dual interface */ _SortedList;
struct __declspec(uuid("ab538809-3c2f-35d9-80e6-7bad540484a1"))
/* dual interface */ _Stack;
struct __declspec(uuid("84e7ac09-795a-3ea9-a36a-5b81ebab0558"))
/* dual interface */ _Nullable;
struct __declspec(uuid("8039c41f-4399-38a2-99b7-d234b5cf7a7b"))
/* dual interface */ _KeyNotFoundException;
struct __declspec(uuid("e40a025c-645b-3c8e-a1ac-9c5cca279625"))
/* dual interface */ _ConditionalAttribute;
struct __declspec(uuid("a9b4786c-08e3-344f-a651-2f9926deac5e"))
/* dual interface */ _Debugger;
struct __declspec(uuid("3344e8b4-a5c3-3882-8d30-63792485eccf"))
/* dual interface */ _DebuggerStepThroughAttribute;
struct __declspec(uuid("b3276180-b23e-3034-b18f-e0122ba4e4cf"))
/* dual interface */ _DebuggerStepperBoundaryAttribute;
struct __declspec(uuid("55b6903b-55fe-35e0-804f-e42a096d2eb0"))
/* dual interface */ _DebuggerHiddenAttribute;
struct __declspec(uuid("cc6dcafd-0185-308a-891c-83812fe574e7"))
/* dual interface */ _DebuggerNonUserCodeAttribute;
struct __declspec(uuid("428e3627-2b1f-302c-a7e6-6388cd535e75"))
/* dual interface */ _DebuggableAttribute;
struct __declspec(uuid("a3fc6319-7355-3d7d-8621-b598561152fc"))
/* dual interface */ _DebuggerBrowsableAttribute;
struct __declspec(uuid("404fafdd-1e3f-3602-bff6-755c00613ed8"))
/* dual interface */ _DebuggerTypeProxyAttribute;
struct __declspec(uuid("22fdabc0-eec7-33e0-b4f2-f3b739e19a5e"))
/* dual interface */ _DebuggerDisplayAttribute;
struct __declspec(uuid("e19ea1a2-67ff-31a5-b95c-e0b753403f6b"))
/* dual interface */ _DebuggerVisualizerAttribute;
struct __declspec(uuid("9a2669ec-ff84-3726-89a0-663a3ef3b5cd"))
/* dual interface */ _StackTrace;
struct __declspec(uuid("0e9b8e47-ca67-38b6-b9db-2c42ee757b08"))
/* dual interface */ _StackFrame;
struct __declspec(uuid("5141d79c-7b01-37da-b7e9-53e5a271baf8"))
/* dual interface */ _SymDocumentType;
struct __declspec(uuid("22bb8891-fd21-313d-92e4-8a892dc0b39c"))
/* dual interface */ _SymLanguageType;
struct __declspec(uuid("01364e7b-c983-3651-b7d8-fd1b64fc0e00"))
/* dual interface */ _SymLanguageVendor;
struct __declspec(uuid("81aa0d59-c3b1-36a3-b2e7-054928fbfc1a"))
/* dual interface */ _AmbiguousMatchException;
struct __declspec(uuid("05532e88-e0f2-3263-9b57-805ac6b6bb72"))
/* dual interface */ _ModuleResolveEventHandler;
struct __declspec(uuid("6163f792-3cd6-38f1-b5f7-000b96a5082b"))
/* dual interface */ _AssemblyCopyrightAttribute;
struct __declspec(uuid("64c26bf9-c9e5-3f66-ad74-bebaade36214"))
/* dual interface */ _AssemblyTrademarkAttribute;
struct __declspec(uuid("de10d587-a188-3dcb-8000-92dfdb9b8021"))
/* dual interface */ _AssemblyProductAttribute;
struct __declspec(uuid("c6802233-ef82-3c91-ad72-b3a5d7230ed5"))
/* dual interface */ _AssemblyCompanyAttribute;
struct __declspec(uuid("6b2c0bc4-ddb7-38ea-8a86-f0b59e192816"))
/* dual interface */ _AssemblyDescriptionAttribute;
struct __declspec(uuid("df44cad3-cef2-36a9-b013-383cc03177d7"))
/* dual interface */ _AssemblyTitleAttribute;
struct __declspec(uuid("746d1d1e-ee37-393b-b6fa-e387d37553aa"))
/* dual interface */ _AssemblyConfigurationAttribute;
struct __declspec(uuid("04311d35-75ec-347b-bedf-969487ce4014"))
/* dual interface */ _AssemblyDefaultAliasAttribute;
struct __declspec(uuid("c6f5946c-143a-3747-a7c0-abfada6bdeb7"))
/* dual interface */ _AssemblyInformationalVersionAttribute;
struct __declspec(uuid("b101fe3c-4479-311a-a945-1225ee1731e8"))
/* dual interface */ _AssemblyFileVersionAttribute;
struct __declspec(uuid("177c4e63-9e0b-354d-838b-b52aa8683ef6"))
/* dual interface */ _AssemblyCultureAttribute;
struct __declspec(uuid("a1693c5c-101f-3557-94db-c480ceb4c16b"))
/* dual interface */ _AssemblyVersionAttribute;
struct __declspec(uuid("a9fcda18-c237-3c6f-a6ef-749be22ba2bf"))
/* dual interface */ _AssemblyKeyFileAttribute;
struct __declspec(uuid("6cf1c077-c974-38e1-90a4-976e4835e165"))
/* dual interface */ _AssemblyDelaySignAttribute;
struct __declspec(uuid("57b849aa-d8ef-3ea6-9538-c5b4d498c2f7"))
/* dual interface */ _AssemblyAlgorithmIdAttribute;
struct __declspec(uuid("0ecd8635-f5eb-3e4a-8989-4d684d67c48a"))
/* dual interface */ _AssemblyFlagsAttribute;
struct __declspec(uuid("322a304d-11ac-3814-a905-a019f6e3dae9"))
/* dual interface */ _AssemblyKeyNameAttribute;
struct __declspec(uuid("fe52f19a-8aa8-309c-bf99-9d0a566fb76a"))
/* dual interface */ _AssemblyNameProxy;
struct __declspec(uuid("1660eb67-ee41-363e-beb0-c2de09214abf"))
/* dual interface */ _CustomAttributeFormatException;
struct __declspec(uuid("f4e5539d-0a65-3073-bf27-8dce8ef1def1"))
/* dual interface */ _CustomAttributeData;
struct __declspec(uuid("c462b072-fe6e-3bdc-9fab-4cdbfcbcd124"))
/* dual interface */ _DefaultMemberAttribute;
struct __declspec(uuid("e6df0ae7-ba15-3f80-8afa-27773ae414fc"))
/* dual interface */ _InvalidFilterCriteriaException;
struct __declspec(uuid("3188878c-deb3-3558-80e8-84e9ed95f92c"))
/* dual interface */ _ManifestResourceInfo;
struct __declspec(uuid("fae5d9b7-40c1-3de1-be06-a91c9da1ba9f"))
/* dual interface */ _MemberFilter;
struct __declspec(uuid("0c48f55d-5240-30c7-a8f1-af87a640cefe"))
/* dual interface */ _Missing;
struct __declspec(uuid("8a5f0da2-7b43-3767-b623-2424cf7cd268"))
/* dual interface */ _ObfuscateAssemblyAttribute;
struct __declspec(uuid("71fb8dcf-3fa7-3483-8464-9d8200e57c43"))
/* dual interface */ _ObfuscationAttribute;
struct __declspec(uuid("643a4016-1b16-3ccf-ae86-9c2d9135ecb0"))
/* dual interface */ _ExceptionHandlingClause;
struct __declspec(uuid("b072efe2-c943-3977-bfd9-91d5232b0d53"))
/* dual interface */ _MethodBody;
struct __declspec(uuid("f2ecd8ca-91a2-31e8-b808-e028b4f5ca67"))
/* dual interface */ _LocalVariableInfo;
struct __declspec(uuid("f0deafe9-5eba-3737-9950-c1795739cdcd"))
/* dual interface */ _Pointer;
struct __declspec(uuid("22c26a41-5fa3-34e3-a76f-ba480252d8ec"))
/* dual interface */ _ReflectionTypeLoadException;
struct __declspec(uuid("fc4963cb-e52b-32d8-a418-d058fa51a1fa"))
/* dual interface */ _StrongNameKeyPair;
struct __declspec(uuid("98b1524d-da12-3c4b-8a69-7539a6dec4fa"))
/* dual interface */ _TargetException;
struct __declspec(uuid("a90106ed-9099-3329-8a5a-2044b3d8552b"))
/* dual interface */ _TargetInvocationException;
struct __declspec(uuid("6032b3cd-9bed-351c-a145-9d500b0f636f"))
/* dual interface */ _TargetParameterCountException;
struct __declspec(uuid("34e00ef9-83e2-3bbc-b6af-4cae703838bd"))
/* dual interface */ _TypeDelegator;
struct __declspec(uuid("e1817846-3745-3c97-b4a6-ee20a1641b29"))
/* dual interface */ _TypeFilter;
struct __declspec(uuid("d9bd3c8d-9395-3657-b6ee-d1b509c38b70"))
/* dual interface */ _Formatter;
struct __declspec(uuid("3faa35ee-c867-3e2e-bf48-2da271f88303"))
/* dual interface */ _FormatterConverter;
struct __declspec(uuid("f859954a-78cf-3d00-86ab-ef661e6a4b8d"))
/* dual interface */ _FormatterServices;
struct __declspec(uuid("a30646cc-f710-3bfa-a356-b4c858d4ed8e"))
/* dual interface */ _ObjectIDGenerator;
struct __declspec(uuid("f28e7d04-3319-3968-8201-c6e55becd3d4"))
/* dual interface */ _ObjectManager;
struct __declspec(uuid("feca70d4-ae27-3d94-93dd-a90f02e299d5"))
/* dual interface */ _OptionalFieldAttribute;
struct __declspec(uuid("9ec28d2c-04c0-35f3-a7ee-0013271ff65e"))
/* dual interface */ _OnSerializingAttribute;
struct __declspec(uuid("547bf8cd-f2a8-3b41-966d-98db33ded06d"))
/* dual interface */ _OnSerializedAttribute;
struct __declspec(uuid("f5aef88f-9ac4-320c-95d2-88e863a35762"))
/* dual interface */ _OnDeserializingAttribute;
struct __declspec(uuid("dd36c803-73d1-338d-88ba-dc9eb7620ef7"))
/* dual interface */ _OnDeserializedAttribute;
struct __declspec(uuid("450222d0-87ca-3699-a7b4-d8a0fdb72357"))
/* dual interface */ _SerializationBinder;
struct __declspec(uuid("b58d62cf-b03a-3a14-b0b6-b1e5ad4e4ad5"))
/* dual interface */ _SerializationInfo;
struct __declspec(uuid("607056c6-1bca-36c8-ab87-33b202ebf0d8"))
/* dual interface */ _SerializationInfoEnumerator;
struct __declspec(uuid("245fe7fd-e020-3053-b5f6-7467fd2c6883"))
/* dual interface */ _SerializationException;
struct __declspec(uuid("6de1230e-1f52-3779-9619-f5184103466c"))
/* dual interface */ _SurrogateSelector;
struct __declspec(uuid("4cca29e4-584b-3cd0-ad25-855dc5799c16"))
/* dual interface */ _Calendar;
struct __declspec(uuid("89e148c4-2424-30ae-80f5-c5d21ea3366c"))
/* dual interface */ _EastAsianLunisolarCalendar;
struct __declspec(uuid("505defe5-aefa-3e23-82b0-d5eb085bb840"))
/* dual interface */ _CompareInfo;
struct __declspec(uuid("152722c2-f0b1-3d19-ada8-f40ca5caecb8"))
/* dual interface */ _CultureInfo;
struct __declspec(uuid("015e9f67-337c-398a-a0c1-da4af1905571"))
/* dual interface */ _DateTimeFormatInfo;
struct __declspec(uuid("efea8feb-ee7f-3e48-8a36-6206a6acbf73"))
/* dual interface */ _DaylightTime;
struct __declspec(uuid("677ad8b5-8a0e-3c39-92fb-72fb817cf694"))
/* dual interface */ _GregorianCalendar;
struct __declspec(uuid("96a62d6c-72a9-387a-81fa-e6dd5998caee"))
/* dual interface */ _HebrewCalendar;
struct __declspec(uuid("28ddc187-56b2-34cf-a078-48bd1e113d1e"))
/* dual interface */ _HijriCalendar;
struct __declspec(uuid("d662ae3f-cef9-38b4-bb8e-5d8dd1dbf806"))
/* dual interface */ _JapaneseCalendar;
struct __declspec(uuid("36e2de92-1fb3-3d7d-ba26-9cad5b98dd52"))
/* dual interface */ _JulianCalendar;
struct __declspec(uuid("48bea6c4-752e-3974-8ca8-cfb6274e2379"))
/* dual interface */ _KoreanCalendar;
struct __declspec(uuid("f9e97e04-4e1e-368f-b6c6-5e96ce4362d6"))
/* dual interface */ _RegionInfo;
struct __declspec(uuid("f4c70e15-2ca6-3e90-96ed-92e28491f538"))
/* dual interface */ _SortKey;
struct __declspec(uuid("0a25141f-51b3-3121-aa30-0af4556a52d9"))
/* dual interface */ _StringInfo;
struct __declspec(uuid("0c08ed74-0acf-32a9-99df-09a9dc4786dd"))
/* dual interface */ _TaiwanCalendar;
struct __declspec(uuid("8c248251-3e6c-3151-9f8e-a255fb8d2b12"))
/* dual interface */ _TextElementEnumerator;
struct __declspec(uuid("db8de23f-f264-39ac-b61c-cc1e7eb4a5e6"))
/* dual interface */ _TextInfo;
struct __declspec(uuid("c70c8ae8-925b-37ce-8944-34f15ff94307"))
/* dual interface */ _ThaiBuddhistCalendar;
struct __declspec(uuid("25e47d71-20dd-31be-b261-7ae76497d6b9"))
/* dual interface */ _NumberFormatInfo;
struct __declspec(uuid("ddedb94d-4f3f-35c1-97c9-3f1d87628d9e"))
/* dual interface */ _Encoding;
struct __declspec(uuid("8fd56502-8724-3df0-a1b5-9d0e8d4e4f78"))
/* dual interface */ _Encoder;
struct __declspec(uuid("2adb0d4a-5976-38e4-852b-c131797430f5"))
/* dual interface */ _Decoder;
struct __declspec(uuid("0cbe0204-12a1-3d40-9d9e-195de6aaa534"))
/* dual interface */ _ASCIIEncoding;
struct __declspec(uuid("f7dd3b7f-2b05-3894-8eda-59cdf9395b6a"))
/* dual interface */ _UnicodeEncoding;
struct __declspec(uuid("89b9f00b-aa2a-3a49-91b4-e8d1f1c00e58"))
/* dual interface */ _UTF7Encoding;
struct __declspec(uuid("010fc1d0-3ef9-3f3b-aa0a-b78a1ff83a37"))
/* dual interface */ _UTF8Encoding;
struct __declspec(uuid("1a4e1878-fe8c-3f59-b6a9-21ab82be57e9"))
/* dual interface */ _MissingManifestResourceException;
struct __declspec(uuid("5a8de087-d9d7-3bba-92b4-fe1034a1242f"))
/* dual interface */ _MissingSatelliteAssemblyException;
struct __declspec(uuid("f48df808-8b7d-3f4e-9159-1dfd60f298d6"))
/* dual interface */ _NeutralResourcesLanguageAttribute;
struct __declspec(uuid("4de671b7-7c85-37e9-aff8-1222abe4883e"))
/* dual interface */ _ResourceManager;
struct __declspec(uuid("7fbcfdc7-5cec-3945-8095-daed61be5fb1"))
/* dual interface */ _ResourceReader;
struct __declspec(uuid("44d5f81a-727c-35ae-8df8-9ff6722f1c6c"))
/* dual interface */ _ResourceSet;
struct __declspec(uuid("af170258-aac6-3a86-bd34-303e62ced10e"))
/* dual interface */ _ResourceWriter;
struct __declspec(uuid("5cbb1f47-fba5-33b9-9d4a-57d6e3d133d2"))
/* dual interface */ _SatelliteContractVersionAttribute;
struct __declspec(uuid("23bae0c0-3a36-32f0-9dad-0e95add67d23"))
/* dual interface */ _Registry;
struct __declspec(uuid("2eac6733-8d92-31d9-be04-dc467efc3eb1"))
/* dual interface */ _RegistryKey;
struct __declspec(uuid("99f01720-3cc2-366d-9ab9-50e36647617f"))
/* dual interface */ _AllMembershipCondition;
struct __declspec(uuid("9ccc831b-1ba7-34be-a966-56d5a6db5aad"))
/* dual interface */ _ApplicationDirectory;
struct __declspec(uuid("a02a2b22-1dba-3f92-9f84-5563182851bb"))
/* dual interface */ _ApplicationDirectoryMembershipCondition;
struct __declspec(uuid("18e473f6-637b-3c01-8d46-d011aad26c95"))
/* dual interface */ _ApplicationSecurityInfo;
struct __declspec(uuid("c664fe09-0a55-316d-b25b-6b3200ecaf70"))
/* dual interface */ _ApplicationSecurityManager;
struct __declspec(uuid("e66a9755-58e2-3fcb-a265-835851cbf063"))
/* dual interface */ _ApplicationTrust;
struct __declspec(uuid("bb03c920-1c05-3ecb-982d-53324d5ac9ff"))
/* dual interface */ _ApplicationTrustCollection;
struct __declspec(uuid("01afd447-60ca-3b67-803a-e57b727f3a5b"))
/* dual interface */ _ApplicationTrustEnumerator;
struct __declspec(uuid("d7093f61-ed6b-343f-b1e9-02472fcc710e"))
/* dual interface */ _CodeGroup;
struct __declspec(uuid("a505edbc-380e-3b23-9e1a-0974d4ef02ef"))
/* dual interface */ _Evidence;
struct __declspec(uuid("dfad74dc-8390-32f6-9612-1bd293b233f4"))
/* dual interface */ _FileCodeGroup;
struct __declspec(uuid("54b0afb1-e7d3-3770-bb0e-75a95e8d2656"))
/* dual interface */ _FirstMatchCodeGroup;
struct __declspec(uuid("d89eac5e-0331-3fcd-9c16-4f1ed3fe1be2"))
/* dual interface */ _TrustManagerContext;
struct __declspec(uuid("fe8a2546-3478-3fad-be1d-da7bc25c4e4e"))
/* dual interface */ _CodeConnectAccess;
struct __declspec(uuid("a8f69eca-8c48-3b5e-92a1-654925058059"))
/* dual interface */ _NetCodeGroup;
struct __declspec(uuid("34b0417e-e71d-304c-9fac-689350a1b41c"))
/* dual interface */ _PermissionRequestEvidence;
struct __declspec(uuid("a9c9f3d9-e153-39b8-a533-b8df4664407b"))
/* dual interface */ _PolicyException;
struct __declspec(uuid("44494e35-c370-3014-bc78-0f2ecbf83f53"))
/* dual interface */ _PolicyLevel;
struct __declspec(uuid("3eefd1fc-4d8d-3177-99f6-6c19d9e088d3"))
/* dual interface */ _PolicyStatement;
struct __declspec(uuid("90c40b4c-b0d0-30f5-b520-fdba97bc31a0"))
/* dual interface */ _Site;
struct __declspec(uuid("0a7c3542-8031-3593-872c-78d85d7cc273"))
/* dual interface */ _SiteMembershipCondition;
struct __declspec(uuid("2a75c1fd-06b0-3cbb-b467-2545d4d6c865"))
/* dual interface */ _StrongName;
struct __declspec(uuid("579e93bc-ffab-3b8d-9181-ce9c22b51915"))
/* dual interface */ _StrongNameMembershipCondition;
struct __declspec(uuid("d9d822de-44e5-33ce-a43f-173e475cecb1"))
/* dual interface */ _UnionCodeGroup;
struct __declspec(uuid("d94ed9bf-c065-3703-81a2-2f76ea8e312f"))
/* dual interface */ _Url;
struct __declspec(uuid("bb7a158d-dbd9-3e13-b137-8e61e87e1128"))
/* dual interface */ _UrlMembershipCondition;
struct __declspec(uuid("742e0c26-0e23-3d20-968c-d221094909aa"))
/* dual interface */ _Zone;
struct __declspec(uuid("adbc3463-0101-3429-a06c-db2f1dd6b724"))
/* dual interface */ _ZoneMembershipCondition;
struct __declspec(uuid("a7aef52c-b47b-3660-bb3e-34347d56db46"))
/* dual interface */ _GacInstalled;
struct __declspec(uuid("b2217ab5-6e55-3ff6-a1a9-1b0dc0585040"))
/* dual interface */ _GacMembershipCondition;
struct __declspec(uuid("7574e121-74a6-3626-b578-0783badb19d2"))
/* dual interface */ _Hash;
struct __declspec(uuid("6ba6ea7a-c9fc-3e73-82ec-18f29d83eefd"))
/* dual interface */ _HashMembershipCondition;
struct __declspec(uuid("77cca693-abf6-3773-bf58-c0b02701a744"))
/* dual interface */ _Publisher;
struct __declspec(uuid("3515cf63-9863-3044-b3e1-210e98efc702"))
/* dual interface */ _PublisherMembershipCondition;
struct __declspec(uuid("9a37d8b2-2256-3fe3-8bf0-4fc421a1244f"))
/* dual interface */ _GenericIdentity;
struct __declspec(uuid("b4701c26-1509-3726-b2e1-409a636c9b4f"))
/* dual interface */ _GenericPrincipal;
struct __declspec(uuid("d8cf3f23-1a66-3344-8230-07eb53970b85"))
/* dual interface */ _WindowsIdentity;
struct __declspec(uuid("60ecfdda-650a-324c-b4b3-f4d75b563bb1"))
/* dual interface */ _WindowsImpersonationContext;
struct __declspec(uuid("6c42baf9-1893-34fc-b3af-06931e9b34a3"))
/* dual interface */ _WindowsPrincipal;
struct __declspec(uuid("1b6ed26a-4b7f-34fc-b2c8-8109d684b3df"))
/* dual interface */ _UnmanagedFunctionPointerAttribute;
struct __declspec(uuid("bbe41ac5-8692-3427-9ae1-c1058a38d492"))
/* dual interface */ _DispIdAttribute;
struct __declspec(uuid("a2145f38-cac1-33dd-a318-21948af6825d"))
/* dual interface */ _InterfaceTypeAttribute;
struct __declspec(uuid("0c1e7b57-b9b1-36e4-8396-549c29062a81"))
/* dual interface */ _ComDefaultInterfaceAttribute;
struct __declspec(uuid("6b6391ee-842f-3e9a-8eee-f13325e10996"))
/* dual interface */ _ClassInterfaceAttribute;
struct __declspec(uuid("1e7fffe2-aad9-34ee-8a9f-3c016b880ff0"))
/* dual interface */ _ComVisibleAttribute;
struct __declspec(uuid("288a86d1-6f4f-39c9-9e42-162cf1c37226"))
/* dual interface */ _TypeLibImportClassAttribute;
struct __declspec(uuid("4ab67927-3c86-328a-8186-f85357dd5527"))
/* dual interface */ _LCIDConversionAttribute;
struct __declspec(uuid("51ba926f-aab5-3945-b8a6-c8f0f4a7d12b"))
/* dual interface */ _ComRegisterFunctionAttribute;
struct __declspec(uuid("9f164188-34eb-3f86-9f74-0bbe4155e65e"))
/* dual interface */ _ComUnregisterFunctionAttribute;
struct __declspec(uuid("2b9f01df-5a12-3688-98d6-c34bf5ed1865"))
/* dual interface */ _ProgIdAttribute;
struct __declspec(uuid("3f3311ce-6baf-3fb0-b855-489aff740b6e"))
/* dual interface */ _ImportedFromTypeLibAttribute;
struct __declspec(uuid("5778e7c7-2040-330e-b47a-92974dffcfd4"))
/* dual interface */ _IDispatchImplAttribute;
struct __declspec(uuid("e1984175-55f5-3065-82d8-a683fdfcf0ac"))
/* dual interface */ _ComSourceInterfacesAttribute;
struct __declspec(uuid("fd5b6aac-ff8c-3472-b894-cd6dfadb6939"))
/* dual interface */ _ComConversionLossAttribute;
struct __declspec(uuid("b5a1729e-b721-3121-a838-fde43af13468"))
/* dual interface */ _TypeLibTypeAttribute;
struct __declspec(uuid("3d18a8e2-eede-3139-b29d-8cac057955df"))
/* dual interface */ _TypeLibFuncAttribute;
struct __declspec(uuid("7b89862a-02a4-3279-8b42-4095fa3a778e"))
/* dual interface */ _TypeLibVarAttribute;
struct __declspec(uuid("d858399f-e19e-3423-a720-ac12abe2e5e8"))
/* dual interface */ _MarshalAsAttribute;
struct __declspec(uuid("1b093056-5454-386f-8971-bbcbc4e9a8f3"))
/* dual interface */ _ComImportAttribute;
struct __declspec(uuid("74435dad-ec55-354b-8f5b-fa70d13b6293"))
/* dual interface */ _GuidAttribute;
struct __declspec(uuid("fdf2a2ee-c882-3198-a48b-e37f0e574dfa"))
/* dual interface */ _PreserveSigAttribute;
struct __declspec(uuid("8474b65c-c39a-3d05-893d-577b9a314615"))
/* dual interface */ _InAttribute;
struct __declspec(uuid("0697fc8c-9b04-3783-95c7-45eccac1ca27"))
/* dual interface */ _OutAttribute;
struct __declspec(uuid("0d6bd9ad-198e-3904-ad99-f6f82a2787c4"))
/* dual interface */ _OptionalAttribute;
struct __declspec(uuid("a1a26181-d55e-3ee2-96e6-70b354ef9371"))
/* dual interface */ _DllImportAttribute;
struct __declspec(uuid("23753322-c7b3-3f9a-ac96-52672c1b1ca9"))
/* dual interface */ _StructLayoutAttribute;
struct __declspec(uuid("c14342b8-bafd-322a-bb71-62c672da284e"))
/* dual interface */ _FieldOffsetAttribute;
struct __declspec(uuid("e78785c4-3a73-3c15-9390-618bf3a14719"))
/* dual interface */ _ComAliasNameAttribute;
struct __declspec(uuid("57b908a8-c082-3581-8a47-6b41b86e8fdc"))
/* dual interface */ _AutomationProxyAttribute;
struct __declspec(uuid("c69e96b2-6161-3621-b165-5805198c6b8d"))
/* dual interface */ _PrimaryInteropAssemblyAttribute;
struct __declspec(uuid("15d54c00-7c95-38d7-b859-e19346677dcd"))
/* dual interface */ _CoClassAttribute;
struct __declspec(uuid("76cc0491-9a10-35c0-8a66-7931ec345b7f"))
/* dual interface */ _ComEventInterfaceAttribute;
struct __declspec(uuid("a03b61a4-ca61-3460-8232-2f4ec96aa88f"))
/* dual interface */ _TypeLibVersionAttribute;
struct __declspec(uuid("ad419379-2ac8-3588-ab1e-0115413277c4"))
/* dual interface */ _ComCompatibleVersionAttribute;
struct __declspec(uuid("ed47abe7-c84b-39f9-be1b-828cfb925afe"))
/* dual interface */ _BestFitMappingAttribute;
struct __declspec(uuid("b26b3465-28e4-33b5-b9bf-dd7c4f6461f5"))
/* dual interface */ _DefaultCharSetAttribute;
struct __declspec(uuid("a54ac093-bfce-37b0-a81f-148dfed0971f"))
/* dual interface */ _SetWin32ContextInIDispatchAttribute;
struct __declspec(uuid("a83f04e9-fd28-384a-9dff-410688ac23ab"))
/* dual interface */ _ExternalException;
struct __declspec(uuid("a28c19df-b488-34ae-becc-7de744d17f7b"))
/* dual interface */ _COMException;
struct __declspec(uuid("76e5dbd6-f960-3c65-8ea6-fc8ad6a67022"))
/* dual interface */ _InvalidOleVariantTypeException;
struct __declspec(uuid("523f42a5-1fd2-355d-82bf-0d67c4a0a0e7"))
/* dual interface */ _MarshalDirectiveException;
struct __declspec(uuid("edcee21a-3e3a-331e-a86d-274028be6716"))
/* dual interface */ _RuntimeEnvironment;
struct __declspec(uuid("3e72e067-4c5e-36c8-bbef-1e2978c7780d"))
/* dual interface */ _SEHException;
struct __declspec(uuid("80da5818-609f-32b8-a9f8-95fcfbdb9c8e"))
/* dual interface */ _BStrWrapper;
struct __declspec(uuid("7df6f279-da62-3c9f-8944-4dd3c0f08170"))
/* dual interface */ _CurrencyWrapper;
struct __declspec(uuid("72103c67-d511-329c-b19a-dd5ec3f1206c"))
/* dual interface */ _DispatchWrapper;
struct __declspec(uuid("f79db336-06be-3959-a5ab-58b2ab6c5fd1"))
/* dual interface */ _ErrorWrapper;
struct __declspec(uuid("519eb857-7a2d-3a95-a2a3-8bb8ed63d41b"))
/* dual interface */ _ExtensibleClassFactory;
struct __declspec(uuid("de9156b5-5e7a-3041-bf45-a29a6c2cf48a"))
/* dual interface */ _InvalidComObjectException;
struct __declspec(uuid("e4a369d3-6cf0-3b05-9c0c-1a91e331641a"))
/* dual interface */ _ObjectCreationDelegate;
struct __declspec(uuid("8608fe7b-2fdc-318a-b711-6f7b2feded06"))
/* dual interface */ _SafeArrayRankMismatchException;
struct __declspec(uuid("e093fb32-e43b-3b3f-a163-742c920c2af3"))
/* dual interface */ _SafeArrayTypeMismatchException;
struct __declspec(uuid("1c8d8b14-4589-3dca-8e0f-a30e80fbd1a8"))
/* dual interface */ _UnknownWrapper;
struct __declspec(uuid("2752364a-924f-3603-8f6f-6586df98b292"))
/* dual interface */ _Stream;
struct __declspec(uuid("442e3c03-a205-3f21-aa4d-31768bb8ea28"))
/* dual interface */ _BinaryReader;
struct __declspec(uuid("4ca8147e-baa3-3a7f-92ce-a4fd7f17d8da"))
/* dual interface */ _BinaryWriter;
struct __declspec(uuid("4b7571c3-1275-3457-8fee-9976fd3937e3"))
/* dual interface */ _BufferedStream;
struct __declspec(uuid("8ce58ff5-f26d-38a4-9195-0e2ecb3b56b9"))
/* dual interface */ _Directory;
struct __declspec(uuid("a5d29a57-36a8-3e36-a099-7458b1fabaa2"))
/* dual interface */ _FileSystemInfo;
struct __declspec(uuid("487e52f1-2bb9-3bd0-a0ca-6728b3a1d051"))
/* dual interface */ _DirectoryInfo;
struct __declspec(uuid("c5bfc9bf-27a7-3a59-a986-44c85f3521bf"))
/* dual interface */ _IOException;
struct __declspec(uuid("c8a200e4-9735-30e4-b168-ed861a3020f2"))
/* dual interface */ _DirectoryNotFoundException;
struct __declspec(uuid("ce83a763-940f-341f-b880-332325eb6f4b"))
/* dual interface */ _DriveInfo;
struct __declspec(uuid("b24e9559-a662-3762-ae33-bc7dfdd538f4"))
/* dual interface */ _DriveNotFoundException;
struct __declspec(uuid("d625afd0-8fd9-3113-a900-43912a54c421"))
/* dual interface */ _EndOfStreamException;
struct __declspec(uuid("5d59051f-e19d-329a-9962-fd00d552e13d"))
/* dual interface */ _File;
struct __declspec(uuid("c3c429f9-8590-3a01-b2b2-434837f3d16d"))
/* dual interface */ _FileInfo;
struct __declspec(uuid("51d2c393-9b70-3551-84b5-ff5409fb3ada"))
/* dual interface */ _FileLoadException;
struct __declspec(uuid("a15a976b-81e3-3ef4-8ff1-d75ddbe20aef"))
/* dual interface */ _FileNotFoundException;
struct __declspec(uuid("74265195-4a46-3d6f-a9dd-69c367ea39c8"))
/* dual interface */ _FileStream;
struct __declspec(uuid("2dbc46fe-b3dd-3858-afc2-d3a2d492a588"))
/* dual interface */ _MemoryStream;
struct __declspec(uuid("6df93530-d276-31d9-8573-346778c650af"))
/* dual interface */ _Path;
struct __declspec(uuid("468b8eb4-89ac-381b-8f86-5e47ec0648b4"))
/* dual interface */ _PathTooLongException;
struct __declspec(uuid("897471f2-9450-3f03-a41f-d2e1f1397854"))
/* dual interface */ _TextReader;
struct __declspec(uuid("e645b470-dc3f-3ce0-8104-5837feda04b3"))
/* dual interface */ _StreamReader;
struct __declspec(uuid("556137ea-8825-30bc-9d49-e47a9db034ee"))
/* dual interface */ _TextWriter;
struct __declspec(uuid("1f124e1c-d05d-3643-a59f-c3de6051994f"))
/* dual interface */ _StreamWriter;
struct __declspec(uuid("59733b03-0ea5-358c-95b5-659fcd9aa0b4"))
/* dual interface */ _StringReader;
struct __declspec(uuid("cb9f94c0-d691-3b62-b0b2-3ce5309cfa62"))
/* dual interface */ _StringWriter;
struct __declspec(uuid("998dcf16-f603-355d-8c89-3b675947997f"))
/* dual interface */ _AccessedThroughPropertyAttribute;
struct __declspec(uuid("a6c2239b-08e6-3822-9769-e3d4b0431b82"))
/* dual interface */ _CallConvCdecl;
struct __declspec(uuid("8e17a5cd-1160-32dc-8548-407e7c3827c9"))
/* dual interface */ _CallConvStdcall;
struct __declspec(uuid("fa73dd3d-a472-35ed-b8be-f99a13581f72"))
/* dual interface */ _CallConvThiscall;
struct __declspec(uuid("3b452d17-3c5e-36c4-a12d-5e9276036cf8"))
/* dual interface */ _CallConvFastcall;
struct __declspec(uuid("62caf4a2-6a78-3fc7-af81-a6bbf930761f"))
/* dual interface */ _CustomConstantAttribute;
struct __declspec(uuid("ef387020-b664-3acd-a1d2-806345845953"))
/* dual interface */ _DateTimeConstantAttribute;
struct __declspec(uuid("3c3a8c69-7417-32fa-aa20-762d85e1b594"))
/* dual interface */ _DiscardableAttribute;
struct __declspec(uuid("7e133967-ccec-3e89-8bd2-6cfca649ecbf"))
/* dual interface */ _DecimalConstantAttribute;
struct __declspec(uuid("c5c4f625-2329-3382-8994-aaf561e5dfe9"))
/* dual interface */ _CompilationRelaxationsAttribute;
struct __declspec(uuid("1eed213e-656a-3a73-a4b9-0d3b26fd942b"))
/* dual interface */ _CompilerGlobalScopeAttribute;
struct __declspec(uuid("243368f5-67c9-3510-9424-335a8a67772f"))
/* dual interface */ _IndexerNameAttribute;
struct __declspec(uuid("0278c819-0c06-3756-b053-601a3e566d9b"))
/* dual interface */ _IsVolatile;
struct __declspec(uuid("98966503-5d80-3242-83ef-79e136f6b954"))
/* dual interface */ _MethodImplAttribute;
struct __declspec(uuid("db2c11d9-3870-35e7-a10c-a3ddc3dc79b1"))
/* dual interface */ _RequiredAttributeAttribute;
struct __declspec(uuid("f68a4008-ab94-3370-a9ac-8cc99939f534"))
/* dual interface */ _IsCopyConstructed;
struct __declspec(uuid("40e8e914-dc23-38a6-936b-90e4e3ab01fa"))
/* dual interface */ _NativeCppClassAttribute;
struct __declspec(uuid("97d0b28a-6932-3d74-b67f-6bcd3c921e7d"))
/* dual interface */ _IDispatchConstantAttribute;
struct __declspec(uuid("54542649-ce64-3f96-bce5-fde3bb22f242"))
/* dual interface */ _IUnknownConstantAttribute;
struct __declspec(uuid("8d597c42-2cfd-32b6-b6d6-86c9e2cff00a"))
/* dual interface */ _SecurityElement;
struct __declspec(uuid("d9fcad88-d869-3788-a802-1b1e007c7a22"))
/* dual interface */ _XmlSyntaxException;
struct __declspec(uuid("4803ce39-2f30-31fc-b84b-5a0141385269"))
/* dual interface */ _CodeAccessPermission;
struct __declspec(uuid("0720590d-5218-352a-a337-5449e6bd19da"))
/* dual interface */ _EnvironmentPermission;
struct __declspec(uuid("a8b7138c-8932-3d78-a585-a91569c743ac"))
/* dual interface */ _FileDialogPermission;
struct __declspec(uuid("a2ed7efc-8e59-3ccc-ae92-ea2377f4d5ef"))
/* dual interface */ _FileIOPermission;
struct __declspec(uuid("48815668-6c27-3312-803e-2757f55ce96a"))
/* dual interface */ _SecurityAttribute;
struct __declspec(uuid("9c5149cb-d3c6-32fd-a0d5-95350de7b813"))
/* dual interface */ _CodeAccessSecurityAttribute;
struct __declspec(uuid("9f8f73a3-1e99-3e51-a41b-179a41dc747c"))
/* dual interface */ _HostProtectionAttribute;
struct __declspec(uuid("7fee7903-f97c-3350-ad42-196b00ad2564"))
/* dual interface */ _IsolatedStoragePermission;
struct __declspec(uuid("0d0c83e8-bde1-3ba5-b1ef-a8fc686d8bc9"))
/* dual interface */ _IsolatedStorageFilePermission;
struct __declspec(uuid("4164071a-ed12-3bdd-af40-fdabcaa77d5f"))
/* dual interface */ _EnvironmentPermissionAttribute;
struct __declspec(uuid("0ccca629-440f-313e-96cd-ba1b4b4997f7"))
/* dual interface */ _FileDialogPermissionAttribute;
struct __declspec(uuid("0dca817d-f21a-3943-b54c-5e800ce5bc50"))
/* dual interface */ _FileIOPermissionAttribute;
struct __declspec(uuid("edb51d1c-08ad-346a-be6f-d74fd6d6f965"))
/* dual interface */ _KeyContainerPermissionAttribute;
struct __declspec(uuid("68ab69e4-5d68-3b51-b74d-1beab9f37f2b"))
/* dual interface */ _PrincipalPermissionAttribute;
struct __declspec(uuid("d31eed10-a5f0-308f-a951-e557961ec568"))
/* dual interface */ _ReflectionPermissionAttribute;
struct __declspec(uuid("38b6068c-1e94-3119-8841-1eca35ed8578"))
/* dual interface */ _RegistryPermissionAttribute;
struct __declspec(uuid("3a5b876c-cde4-32d2-9c7e-020a14aca332"))
/* dual interface */ _SecurityPermissionAttribute;
struct __declspec(uuid("1d5c0f70-af29-38a3-9436-3070a310c73b"))
/* dual interface */ _UIPermissionAttribute;
struct __declspec(uuid("2e3be3ed-2f22-3b20-9f92-bd29b79d6f42"))
/* dual interface */ _ZoneIdentityPermissionAttribute;
struct __declspec(uuid("c9a740f4-26e9-39a8-8885-8ca26bd79b21"))
/* dual interface */ _StrongNameIdentityPermissionAttribute;
struct __declspec(uuid("6fe6894a-2a53-3fb6-a06e-348f9bdad23b"))
/* dual interface */ _SiteIdentityPermissionAttribute;
struct __declspec(uuid("ca4a2073-48c5-3e61-8349-11701a90dd9b"))
/* dual interface */ _UrlIdentityPermissionAttribute;
struct __declspec(uuid("6722c730-1239-3784-ac94-c285ae5b901a"))
/* dual interface */ _PublisherIdentityPermissionAttribute;
struct __declspec(uuid("5c4c522f-de4e-3595-9aa9-9319c86a5283"))
/* dual interface */ _IsolatedStoragePermissionAttribute;
struct __declspec(uuid("6f1f8aae-d667-39cc-98fa-722bebbbeac3"))
/* dual interface */ _IsolatedStorageFilePermissionAttribute;
struct __declspec(uuid("947a1995-bc16-3e7c-b65a-99e71f39c091"))
/* dual interface */ _PermissionSetAttribute;
struct __declspec(uuid("aeb3727f-5c3a-34c4-bf18-a38f088ac8c7"))
/* dual interface */ _ReflectionPermission;
struct __declspec(uuid("7c6b06d1-63ad-35ef-a938-149b4ad9a71f"))
/* dual interface */ _PrincipalPermission;
struct __declspec(uuid("33c54a2d-02bd-3848-80b6-742d537085e5"))
/* dual interface */ _SecurityPermission;
struct __declspec(uuid("790b3ee9-7e06-3cd0-8243-5848486d6a78"))
/* dual interface */ _SiteIdentityPermission;
struct __declspec(uuid("5f1562fb-0160-3655-baea-b15bef609161"))
/* dual interface */ _StrongNameIdentityPermission;
struct __declspec(uuid("af53d21a-d6af-3406-b399-7df9d2aad48a"))
/* dual interface */ _StrongNamePublicKeyBlob;
struct __declspec(uuid("47698389-f182-3a67-87df-aed490e14dc6"))
/* dual interface */ _UIPermission;
struct __declspec(uuid("ec7cac31-08a2-393b-bdf2-d052eb53af2c"))
/* dual interface */ _UrlIdentityPermission;
struct __declspec(uuid("38b2f8d7-8cf4-323b-9c17-9c55ee287a63"))
/* dual interface */ _ZoneIdentityPermission;
struct __declspec(uuid("5f19e082-26f8-3361-b338-9bacb98809a4"))
/* dual interface */ _GacIdentityPermissionAttribute;
struct __declspec(uuid("a9637792-5be8-3c93-a501-49f0e840de38"))
/* dual interface */ _GacIdentityPermission;
struct __declspec(uuid("094351ea-dbc1-327f-8a83-913b593a66be"))
/* dual interface */ _KeyContainerPermissionAccessEntry;
struct __declspec(uuid("28ecf94e-3510-3a3e-8bd1-f866f45f3b06"))
/* dual interface */ _KeyContainerPermissionAccessEntryCollection;
struct __declspec(uuid("293187ea-5f88-316f-86a5-533b0c7b353f"))
/* dual interface */ _KeyContainerPermissionAccessEntryEnumerator;
struct __declspec(uuid("107a3cf1-b35e-3a23-b660-60264b231225"))
/* dual interface */ _KeyContainerPermission;
struct __declspec(uuid("e86cc74a-1233-3df3-b13f-8b27eeaac1f6"))
/* dual interface */ _PublisherIdentityPermission;
struct __declspec(uuid("c3fb5510-3454-3b31-b64f-de6aad6be820"))
/* dual interface */ _RegistryPermission;
struct __declspec(uuid("8000e51a-541c-3b20-a8ec-c8a8b41116c4"))
/* dual interface */ _SuppressUnmanagedCodeSecurityAttribute;
struct __declspec(uuid("41f41c1b-7b8d-39a3-a28f-aae20787f469"))
/* dual interface */ _UnverifiableCodeAttribute;
struct __declspec(uuid("f1c930c4-2233-3924-9840-231d008259b4"))
/* dual interface */ _AllowPartiallyTrustedCallersAttribute;
struct __declspec(uuid("9deae196-48c1-3590-9d0a-33716a214acd"))
/* dual interface */ _HostSecurityManager;
struct __declspec(uuid("c2af4970-4fb6-319c-a8aa-0614d27f2b2c"))
/* dual interface */ _PermissionSet;
struct __declspec(uuid("ba3e053f-ade3-3233-874a-16e624c9a49b"))
/* dual interface */ _NamedPermissionSet;
struct __declspec(uuid("f174290f-e4cf-3976-88aa-4f8e32eb03db"))
/* dual interface */ _SecurityException;
struct __declspec(uuid("ed727a9b-6fc5-3fed-bedd-7b66c847f87a"))
/* dual interface */ _HostProtectionException;
struct __declspec(uuid("abc04b16-5539-3c7e-92ec-0905a4a24464"))
/* dual interface */ _SecurityManager;
struct __declspec(uuid("f65070df-57af-3ae3-b951-d2ad7d513347"))
/* dual interface */ _VerificationException;
struct __declspec(uuid("f042505b-7aac-313b-a8c7-3f1ac949c311"))
/* dual interface */ _ContextAttribute;
struct __declspec(uuid("3936abe1-b29e-3593-83f1-793d1a7f3898"))
/* dual interface */ _AsyncResult;
struct __declspec(uuid("53bce4d4-6209-396d-bd4a-0b0a0a177df9"))
/* dual interface */ _CallContext;
struct __declspec(uuid("9aff21f5-1c9c-35e7-aea4-c3aa0beb3b77"))
/* dual interface */ _LogicalCallContext;
struct __declspec(uuid("ffb2e16e-e5c7-367c-b326-965abf510f24"))
/* dual interface */ _ChannelServices;
struct __declspec(uuid("e1796120-c324-30d8-86f4-20086711463b"))
/* dual interface */ _ClientChannelSinkStack;
struct __declspec(uuid("52da9f90-89b3-35ab-907b-3562642967de"))
/* dual interface */ _ServerChannelSinkStack;
struct __declspec(uuid("ff19d114-3bda-30ac-8e89-36ca64a87120"))
/* dual interface */ _ClientSponsor;
struct __declspec(uuid("ee949b7b-439f-363e-b9fc-34db1fb781d7"))
/* dual interface */ _CrossContextDelegate;
struct __declspec(uuid("11a2ea7a-d600-307b-a606-511a6c7950d1"))
/* dual interface */ _Context;
struct __declspec(uuid("4acb3495-05db-381b-890a-d12f5340dca3"))
/* dual interface */ _ContextProperty;
struct __declspec(uuid("77c9bceb-9958-33c0-a858-599f66697da7"))
/* dual interface */ _EnterpriseServicesHelper;
struct __declspec(uuid("0d296515-ad19-3602-b415-d8ec77066081"))
/* dual interface */ _Header;
struct __declspec(uuid("5dbbaf39-a3df-30b7-aaea-9fd11394123f"))
/* dual interface */ _HeaderHandler;
struct __declspec(uuid("aa6da581-f972-36de-a53b-7585428a68ab"))
/* dual interface */ _ChannelDataStore;
struct __declspec(uuid("65887f70-c646-3a66-8697-8a3f7d8fe94d"))
/* dual interface */ _TransportHeaders;
struct __declspec(uuid("a18545b7-e5ee-31ee-9b9b-41199b11c995"))
/* dual interface */ _SinkProviderData;
struct __declspec(uuid("a1329ec9-e567-369f-8258-18366d89eaf8"))
/* dual interface */ _BaseChannelObjectWithProperties;
struct __declspec(uuid("8af3451e-154d-3d86-80d8-f8478b9733ed"))
/* dual interface */ _BaseChannelSinkWithProperties;
struct __declspec(uuid("94bb98ed-18bb-3843-a7fe-642824ab4e01"))
/* dual interface */ _BaseChannelWithProperties;
struct __declspec(uuid("b0ad9a21-5439-3d88-8975-4018b828d74c"))
/* dual interface */ _LifetimeServices;
struct __declspec(uuid("0eeff4c2-84bf-3e4e-bf22-b7bdbb5df899"))
/* dual interface */ _ReturnMessage;
struct __declspec(uuid("95e01216-5467-371b-8597-4074402ccb06"))
/* dual interface */ _MethodCall;
struct __declspec(uuid("a2246ae7-eb81-3a20-8e70-c9fa341c7e10"))
/* dual interface */ _ConstructionCall;
struct __declspec(uuid("9e9ea93a-d000-3ab9-bfca-ddeb398a55b9"))
/* dual interface */ _MethodResponse;
struct __declspec(uuid("be457280-6ffa-3e76-9822-83de63c0c4e0"))
/* dual interface */ _ConstructionResponse;
struct __declspec(uuid("ef926e1f-3ee7-32bc-8b01-c6e98c24bc19"))
/* dual interface */ _InternalMessageWrapper;
struct __declspec(uuid("c9614d78-10ea-3310-87ea-821b70632898"))
/* dual interface */ _MethodCallMessageWrapper;
struct __declspec(uuid("89304439-a24f-30f6-9a8f-89ce472d85da"))
/* dual interface */ _MethodReturnMessageWrapper;
struct __declspec(uuid("ea675b47-64e0-3b5f-9be7-f7dc2990730d"))
/* dual interface */ _ObjectHandle;
struct __declspec(uuid("1dd3cf3d-df8e-32ff-91ec-e19aa10b63fb"))
/* dual interface */ _ObjRef;
struct __declspec(uuid("8ffedc68-5233-3fa8-813d-405aabb33ecb"))
/* dual interface */ _OneWayAttribute;
struct __declspec(uuid("d80ff312-2930-3680-a5e9-b48296c7415f"))
/* dual interface */ _ProxyAttribute;
struct __declspec(uuid("e0cf3f77-c7c3-33da-beb4-46147fc905de"))
/* dual interface */ _RealProxy;
struct __declspec(uuid("725692a5-9e12-37f6-911c-e3da77e5faca"))
/* dual interface */ _SoapAttribute;
struct __declspec(uuid("ebcdcd84-8c74-39fd-821c-f5eb3a2704d7"))
/* dual interface */ _SoapTypeAttribute;
struct __declspec(uuid("c58145b5-bd5a-3896-95d9-b358f54fbc44"))
/* dual interface */ _SoapMethodAttribute;
struct __declspec(uuid("46a3f9ff-f73c-33c7-bcc3-1bef4b25e4ae"))
/* dual interface */ _SoapFieldAttribute;
struct __declspec(uuid("c32abfc9-3917-30bf-a7bc-44250bdfc5d8"))
/* dual interface */ _SoapParameterAttribute;
struct __declspec(uuid("4b10971e-d61d-373f-bc8d-2ccf31126215"))
/* dual interface */ _RemotingConfiguration;
struct __declspec(uuid("8359f3ab-643f-3bcf-91e8-16e779edebe1"))
/* dual interface */ _TypeEntry;
struct __declspec(uuid("bac12781-6865-3558-a8d1-f1cadd2806dd"))
/* dual interface */ _ActivatedClientTypeEntry;
struct __declspec(uuid("94855a3b-5ca2-32cf-b1ab-48fd3915822c"))
/* dual interface */ _ActivatedServiceTypeEntry;
struct __declspec(uuid("4d0bc339-e3f9-3e9e-8f68-92168e6f6981"))
/* dual interface */ _WellKnownClientTypeEntry;
struct __declspec(uuid("60b8b604-0aed-3093-ac05-eb98fb29fc47"))
/* dual interface */ _WellKnownServiceTypeEntry;
struct __declspec(uuid("7264843f-f60c-39a9-99e1-029126aa0815"))
/* dual interface */ _RemotingException;
struct __declspec(uuid("19373c44-55b4-3487-9ad8-4c621aae85ea"))
/* dual interface */ _ServerException;
struct __declspec(uuid("44db8e15-acb1-34ee-81f9-56ed7ae37a5c"))
/* dual interface */ _RemotingTimeoutException;
struct __declspec(uuid("7b91368d-a50a-3d36-be8e-5b8836a419ad"))
/* dual interface */ _RemotingServices;
struct __declspec(uuid("f4efb305-cdc4-31c5-8102-33c9b91774f3"))
/* dual interface */ _InternalRemotingServices;
struct __declspec(uuid("04a35d22-0b08-34e7-a573-88ef2374375e"))
/* dual interface */ _MessageSurrogateFilter;
struct __declspec(uuid("551f7a57-8651-37db-a94a-6a3ca09c0ed7"))
/* dual interface */ _RemotingSurrogateSelector;
struct __declspec(uuid("7416b6ee-82e8-3a16-966b-018a40e7b1aa"))
/* dual interface */ _SoapServices;
struct __declspec(uuid("1738adbc-156e-3897-844f-c3147c528dea"))
/* dual interface */ _SoapDateTime;
struct __declspec(uuid("7ef50ddb-32a5-30a1-b412-47fab911404a"))
/* dual interface */ _SoapDuration;
struct __declspec(uuid("a3bf0bcd-ec32-38e6-92f2-5f37bad8030d"))
/* dual interface */ _SoapTime;
struct __declspec(uuid("cfa6e9d2-b3de-39a6-94d1-cc691de193f8"))
/* dual interface */ _SoapDate;
struct __declspec(uuid("103c7ef9-a9ee-35fb-84c5-3086c9725a20"))
/* dual interface */ _SoapYearMonth;
struct __declspec(uuid("c20769f3-858d-316a-be6d-c347a47948ad"))
/* dual interface */ _SoapYear;
struct __declspec(uuid("f9ead0aa-4156-368f-ae05-fd59d70f758d"))
/* dual interface */ _SoapMonthDay;
struct __declspec(uuid("d9e8314d-5053-3497-8a33-97d3dcfe33e2"))
/* dual interface */ _SoapDay;
struct __declspec(uuid("b4e32423-e473-3562-aa12-62fde5a7d4a2"))
/* dual interface */ _SoapMonth;
struct __declspec(uuid("63b9da95-fb91-358a-b7b7-90c34aa34ab7"))
/* dual interface */ _SoapHexBinary;
struct __declspec(uuid("8ed115a1-5e7b-34dc-ab85-90316f28015d"))
/* dual interface */ _SoapBase64Binary;
struct __declspec(uuid("30c65c40-4e54-3051-9d8f-4709b6ab214c"))
/* dual interface */ _SoapInteger;
struct __declspec(uuid("4979ec29-c2b7-3ad6-986d-5aaf7344cc4e"))
/* dual interface */ _SoapPositiveInteger;
struct __declspec(uuid("aaf5401e-f71c-3fe3-8a73-a25074b20d3a"))
/* dual interface */ _SoapNonPositiveInteger;
struct __declspec(uuid("bc261fc6-7132-3fb5-9aac-224845d3aa99"))
/* dual interface */ _SoapNonNegativeInteger;
struct __declspec(uuid("e384aa10-a70c-3943-97cf-0f7c282c3bdc"))
/* dual interface */ _SoapNegativeInteger;
struct __declspec(uuid("818ec118-be7e-3cde-92c8-44b99160920e"))
/* dual interface */ _SoapAnyUri;
struct __declspec(uuid("3ac646b6-6b84-382f-9aed-22c2433244e6"))
/* dual interface */ _SoapQName;
struct __declspec(uuid("974f01f4-6086-3137-9448-6a31fc9bef08"))
/* dual interface */ _SoapNotation;
struct __declspec(uuid("f4926b50-3f23-37e0-9afa-aa91ff89a7bd"))
/* dual interface */ _SoapNormalizedString;
struct __declspec(uuid("ab4e97b9-651d-36f4-aaba-28acf5746624"))
/* dual interface */ _SoapToken;
struct __declspec(uuid("14aed851-a168-3462-b877-8f9a01126653"))
/* dual interface */ _SoapLanguage;
struct __declspec(uuid("5eb06bef-4adf-3cc1-a6f2-62f76886b13a"))
/* dual interface */ _SoapName;
struct __declspec(uuid("7947a829-adb5-34d0-9cc8-6c172742c803"))
/* dual interface */ _SoapIdrefs;
struct __declspec(uuid("aca96da3-96ed-397e-8a72-ee1be1025f5e"))
/* dual interface */ _SoapEntities;
struct __declspec(uuid("e941fa15-e6c8-3dd4-b060-c0ddfbc0240a"))
/* dual interface */ _SoapNmtoken;
struct __declspec(uuid("a5e385ae-27fb-3708-baf7-0bf1f3955747"))
/* dual interface */ _SoapNmtokens;
struct __declspec(uuid("725cdaf7-b739-35c1-8463-e2a923e1f618"))
/* dual interface */ _SoapNcName;
struct __declspec(uuid("6a46b6a2-2d2c-3c67-af67-aae0175f17ae"))
/* dual interface */ _SoapId;
struct __declspec(uuid("7db7fd83-de89-38e1-9645-d4cabde694c0"))
/* dual interface */ _SoapIdref;
struct __declspec(uuid("37171746-b784-3586-a7d5-692a7604a66b"))
/* dual interface */ _SoapEntity;
struct __declspec(uuid("2d985674-231c-33d4-b14d-f3a6bd2ebe19"))
/* dual interface */ _SynchronizationAttribute;
struct __declspec(uuid("f51728f2-2def-308c-874a-cbb1baa9cf9e"))
/* dual interface */ _TrackingServices;
struct __declspec(uuid("717105a3-739b-3bc3-a2b7-ad215903fad2"))
/* dual interface */ _UrlAttribute;
struct __declspec(uuid("34ec3bd7-f2f6-3c20-a639-804bff89df65"))
/* dual interface */ _IsolatedStorage;
struct __declspec(uuid("6bbb7dee-186f-3d51-9486-be0a71e915ce"))
/* dual interface */ _IsolatedStorageFile;
struct __declspec(uuid("68d5592b-47c8-381a-8d51-3925c16cf025"))
/* dual interface */ _IsolatedStorageFileStream;
struct __declspec(uuid("aec2b0de-9898-3607-b845-63e2e307cb5f"))
/* dual interface */ _IsolatedStorageException;
struct __declspec(uuid("361a5049-1bc8-35a9-946a-53a877902f25"))
/* dual interface */ _InternalRM;
struct __declspec(uuid("a864fb13-f945-3dc0-a01c-b903f944fc97"))
/* dual interface */ _InternalST;
struct __declspec(uuid("bc0847b2-bd5c-37b3-ba67-7d2d54b17238"))
/* dual interface */ _SoapMessage;
struct __declspec(uuid("a1c392fc-314c-39d5-8de6-1f8ebca0a1e2"))
/* dual interface */ _SoapFault;
struct __declspec(uuid("02d1bd78-3bb6-37ad-a9f8-f7d5da273e4e"))
/* dual interface */ _ServerFault;
struct __declspec(uuid("3bcf0cb2-a849-375e-8189-1ba5f1f4a9b0"))
/* dual interface */ _BinaryFormatter;
struct __declspec(uuid("0daeaee7-007b-3fca-8755-a5c6c3158955"))
/* dual interface */ _DynamicILInfo;
struct __declspec(uuid("eaaa2670-0fb1-33ea-852b-f1c97fed1797"))
/* dual interface */ _DynamicMethod;
struct __declspec(uuid("1db1cc2a-da73-389e-828b-5c616f4fac49"))
/* dual interface */ _OpCodes;
struct __declspec(uuid("b1a62835-fc19-35a4-b206-a452463d7ee7"))
/* dual interface */ _GenericTypeParameterBuilder;
struct __declspec(uuid("fd302d86-240a-3694-a31f-9ef59e6e41bc"))
/* dual interface */ _UnmanagedMarshal;
struct __declspec(uuid("8978b0be-a89e-3ff9-9834-77862cebff3d"))
/* dual interface */ _KeySizes;
struct __declspec(uuid("4311e8f5-b249-3f81-8ff4-cf853d85306d"))
/* dual interface */ _CryptographicException;
struct __declspec(uuid("7fb08423-038f-3acc-b600-e6d072bae160"))
/* dual interface */ _CryptographicUnexpectedOperationException;
struct __declspec(uuid("7ae4b03c-414a-36e0-ba68-f9603004c925"))
/* dual interface */ _RandomNumberGenerator;
struct __declspec(uuid("2c65d4c0-584c-3e4e-8e6d-1afb112bff69"))
/* dual interface */ _RNGCryptoServiceProvider;
struct __declspec(uuid("09343ac0-d19a-3e62-bc16-0f600f10180a"))
/* dual interface */ _AsymmetricAlgorithm;
struct __declspec(uuid("b6685cca-7a49-37d1-a805-3de829cb8deb"))
/* dual interface */ _AsymmetricKeyExchangeDeformatter;
struct __declspec(uuid("1365b84b-6477-3c40-be6a-089dc01eced9"))
/* dual interface */ _AsymmetricKeyExchangeFormatter;
struct __declspec(uuid("7ca5fe57-d1ac-3064-bb0b-f450be40f194"))
/* dual interface */ _AsymmetricSignatureDeformatter;
struct __declspec(uuid("5363d066-6295-3618-be33-3f0b070b7976"))
/* dual interface */ _AsymmetricSignatureFormatter;
struct __declspec(uuid("23ded1e1-7d5f-3936-aa4e-18bbcc39b155"))
/* dual interface */ _ToBase64Transform;
struct __declspec(uuid("fc0717a6-2e86-372f-81f4-b35ed4bdf0de"))
/* dual interface */ _FromBase64Transform;
struct __declspec(uuid("983b8639-2ed7-364c-9899-682abb2ce850"))
/* dual interface */ _CryptoAPITransform;
struct __declspec(uuid("d5331d95-fff2-358f-afd5-588f469ff2e4"))
/* dual interface */ _CspParameters;
struct __declspec(uuid("ab00f3f8-7dde-3ff5-b805-6c5dbb200549"))
/* dual interface */ _CryptoConfig;
struct __declspec(uuid("4134f762-d0ec-3210-93c0-de4f443d5669"))
/* dual interface */ _CryptoStream;
struct __declspec(uuid("05bc0e38-7136-3825-9e34-26c1cf2142c9"))
/* dual interface */ _SymmetricAlgorithm;
struct __declspec(uuid("c7ef0214-b91c-3799-98dd-c994aabfc741"))
/* dual interface */ _DES;
struct __declspec(uuid("65e8495e-5207-3248-9250-0fc849b4f096"))
/* dual interface */ _DESCryptoServiceProvider;
struct __declspec(uuid("140ee78f-067f-3765-9258-c3bc72fe976b"))
/* dual interface */ _DeriveBytes;
struct __declspec(uuid("0eb5b5e0-1be6-3a5f-87b3-e3323342f44e"))
/* dual interface */ _DSA;
struct __declspec(uuid("1f38aafe-7502-332f-971f-c2fc700a1d55"))
/* dual interface */ _DSACryptoServiceProvider;
struct __declspec(uuid("0e774498-ade6-3820-b1d5-426b06397be7"))
/* dual interface */ _DSASignatureDeformatter;
struct __declspec(uuid("4b5fc561-5983-31e4-903b-1404231b2c89"))
/* dual interface */ _DSASignatureFormatter;
struct __declspec(uuid("69d3baba-1c3d-354c-acfe-f19109ec3896"))
/* dual interface */ _HashAlgorithm;
struct __declspec(uuid("d182cf91-628c-3ff6-87f0-41ba51cc7433"))
/* dual interface */ _KeyedHashAlgorithm;
struct __declspec(uuid("e5456726-33f6-34e4-95c2-db2bfa581462"))
/* dual interface */ _HMAC;
struct __declspec(uuid("486360f5-6213-322b-befb-45221579d4af"))
/* dual interface */ _HMACMD5;
struct __declspec(uuid("9fd974a5-338c-37b9-a1b2-d45f0c2b25c2"))
/* dual interface */ _HMACRIPEMD160;
struct __declspec(uuid("63ac7c37-c51a-3d82-8fdd-2a567039e46d"))
/* dual interface */ _HMACSHA1;
struct __declspec(uuid("1377ce34-8921-3bd4-96e9-c8d5d5aa1adf"))
/* dual interface */ _HMACSHA256;
struct __declspec(uuid("786f8ac3-93e4-3b6f-9f62-1901b0e5f433"))
/* dual interface */ _HMACSHA384;
struct __declspec(uuid("eb081b9d-a766-3abe-b720-505c42162d83"))
/* dual interface */ _HMACSHA512;
struct __declspec(uuid("be8619cb-3731-3cb2-a3a8-cd0bfa5566ec"))
/* dual interface */ _CspKeyContainerInfo;
struct __declspec(uuid("1cac0bda-ac58-31bc-b624-63f77d0c3d2f"))
/* dual interface */ _MACTripleDES;
struct __declspec(uuid("9aa8765e-69a0-30e3-9cde-ebc70662ae37"))
/* dual interface */ _MD5;
struct __declspec(uuid("d3f5c812-5867-33c9-8cee-cb170e8d844a"))
/* dual interface */ _MD5CryptoServiceProvider;
struct __declspec(uuid("85601fee-a79d-3710-af21-099089edc0bf"))
/* dual interface */ _MaskGenerationMethod;
struct __declspec(uuid("3cd62d67-586f-309e-a6d8-1f4baac5ac28"))
/* dual interface */ _PasswordDeriveBytes;
struct __declspec(uuid("425bff0d-59e4-36a8-b1ff-1f5d39d698f4"))
/* dual interface */ _PKCS1MaskGenerationMethod;
struct __declspec(uuid("f7c0c4cc-0d49-31ee-a3d3-b8b551e4928c"))
/* dual interface */ _RC2;
struct __declspec(uuid("875715c5-cb64-3920-8156-0ee9cb0e07ea"))
/* dual interface */ _RC2CryptoServiceProvider;
struct __declspec(uuid("a6589897-5a67-305f-9497-72e5fe8bead5"))
/* dual interface */ _Rfc2898DeriveBytes;
struct __declspec(uuid("e5481be9-3422-3506-bc35-b96d4535014d"))
/* dual interface */ _RIPEMD160;
struct __declspec(uuid("814f9c35-b7f8-3ceb-8e43-e01f09157060"))
/* dual interface */ _RIPEMD160Managed;
struct __declspec(uuid("0b3fb710-a25c-3310-8774-1cf117f95bd4"))
/* dual interface */ _RSA;
struct __declspec(uuid("bd9df856-2300-3254-bcf0-679ba03c7a13"))
/* dual interface */ _RSACryptoServiceProvider;
struct __declspec(uuid("37625095-7baa-377d-a0dc-7f465c0167aa"))
/* dual interface */ _RSAOAEPKeyExchangeDeformatter;
struct __declspec(uuid("77a416e7-2ac6-3d0e-98ff-3ba0f586f56f"))
/* dual interface */ _RSAOAEPKeyExchangeFormatter;
struct __declspec(uuid("8034aaf4-3666-3b6f-85cf-463f9bfd31a9"))
/* dual interface */ _RSAPKCS1KeyExchangeDeformatter;
struct __declspec(uuid("9ff67f8e-a7aa-3ba6-90ee-9d44af6e2f8c"))
/* dual interface */ _RSAPKCS1KeyExchangeFormatter;
struct __declspec(uuid("fc38507e-06a4-3300-8652-8d7b54341f65"))
/* dual interface */ _RSAPKCS1SignatureDeformatter;
struct __declspec(uuid("fb7a5ff4-cfa8-3f24-ad5f-d5eb39359707"))
/* dual interface */ _RSAPKCS1SignatureFormatter;
struct __declspec(uuid("21b52a91-856f-373c-ad42-4cf3f1021f5a"))
/* dual interface */ _Rijndael;
struct __declspec(uuid("427ea9d3-11d8-3e38-9e05-a4f7fa684183"))
/* dual interface */ _RijndaelManaged;
struct __declspec(uuid("5767c78f-f344-35a5-84bc-53b9eaeb68cb"))
/* dual interface */ _RijndaelManagedTransform;
struct __declspec(uuid("48600dd2-0099-337f-92d6-961d1e5010d4"))
/* dual interface */ _SHA1;
struct __declspec(uuid("a16537bc-1edf-3516-b75e-cc65caf873ab"))
/* dual interface */ _SHA1CryptoServiceProvider;
struct __declspec(uuid("c27990bb-3cfd-3d29-8dc0-bbe5fbadeafd"))
/* dual interface */ _SHA1Managed;
struct __declspec(uuid("3b274703-dfae-3f9c-a1b5-9990df9d7fa3"))
/* dual interface */ _SHA256;
struct __declspec(uuid("3d077954-7bcc-325b-9dda-3b17a03378e0"))
/* dual interface */ _SHA256Managed;
struct __declspec(uuid("b60ad5d7-2c2e-35b7-8d77-7946156cfe8e"))
/* dual interface */ _SHA384;
struct __declspec(uuid("de541460-f838-3698-b2da-510b09070118"))
/* dual interface */ _SHA384Managed;
struct __declspec(uuid("49dd9e4b-84f3-3d6d-91fb-3fedcef634c7"))
/* dual interface */ _SHA512;
struct __declspec(uuid("dc8ce439-7954-36ed-803c-674f72f27249"))
/* dual interface */ _SHA512Managed;
struct __declspec(uuid("8017b414-4886-33da-80a3-7865c1350d43"))
/* dual interface */ _SignatureDescription;
struct __declspec(uuid("c040b889-5278-3132-aff9-afa61707a81d"))
/* dual interface */ _TripleDES;
struct __declspec(uuid("ec69d083-3cd0-3c0c-998c-3b738db535d5"))
/* dual interface */ _TripleDESCryptoServiceProvider;
struct __declspec(uuid("68fd6f14-a7b2-36c8-a724-d01f90d73477"))
/* dual interface */ _X509Certificate;

//
// Type library items
//

struct __declspec(uuid("81c5fe01-027c-3e1c-98d5-da9c9862aa21"))
Object;
    // [ default ] interface _Object

struct __declspec(uuid("0cb251a7-3ab3-3b5c-a0b8-9ddf88824b85"))
ICloneable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Clone (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("496b0abe-cdee-11d3-88e8-00902754c43a"))
IEnumerable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetEnumerator (
        /*[out,retval]*/ struct IEnumVARIANT * * pRetVal ) = 0;
};

struct __declspec(uuid("7bcfa00f-f764-3113-9140-3bbd127a96bb"))
IList : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long index,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Item (
        /*[in]*/ long index,
        /*[in]*/ VARIANT pRetVal ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall Contains (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall get_IsReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFixedSize (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall IndexOf (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall Insert (
        /*[in]*/ long index,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall RemoveAt (
        /*[in]*/ long index ) = 0;
};

struct __declspec(uuid("200fb91c-815d-39e0-9e07-0e1bdb2ed47b"))
Array;
    // [ default ] interface _Array
    // interface _Object
    // interface ICloneable
    // interface IList
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("ce8ad32f-b6db-31ea-9f1e-c2424e0f5eee"))
ValueType;
    // [ default ] interface _ValueType
    // interface _Object

struct __declspec(uuid("496b0abf-cdee-11d3-88e8-00902754c43a"))
IEnumerator : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall MoveNext (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Current (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
};

struct __declspec(uuid("805d7a98-d4af-3f0f-967f-e5cf45312d2c"))
IDisposable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Dispose ( ) = 0;
};

struct __declspec(uuid("deb0e770-91fd-3cf6-9a6c-e6a3656f3965"))
IComparable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CompareTo (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ long * pRetVal ) = 0;
};

struct __declspec(uuid("c43345b9-7fed-3fc7-8fc2-7b1b82bc109e"))
Enum;
    // [ default ] interface _Enum
    // interface _Object
    // interface IComparable
    // interface IFormattable
    // interface IConvertible

struct __declspec(uuid("296afbff-1b0b-3ff5-9d6c-4e7e599f8b57"))
String;
    // [ default ] interface _String
    // interface _Object
    // interface IComparable
    // interface ICloneable
    // interface IConvertible
    // interface IEnumerable

struct __declspec(uuid("c20fd3eb-7022-3d14-8477-760fab54e50d"))
IComparer : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Compare (
        /*[in]*/ VARIANT x,
        /*[in]*/ VARIANT y,
        /*[out,retval]*/ long * pRetVal ) = 0;
};

struct __declspec(uuid("aab7c6ea-cab0-3adb-82aa-cf32e29af238"))
IEqualityComparer : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT x,
        /*[in]*/ VARIANT y,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ long * pRetVal ) = 0;
};

struct __declspec(uuid("8ea98c90-180d-39ae-aa70-2aa3d5ebb7ae"))
StringComparer;
    // [ default ] interface _StringComparer
    // interface _Object
    // interface IComparer
    // interface IEqualityComparer

enum __declspec(uuid("d0431551-3853-37f8-b714-8a8986e1ea38"))
StringComparison
{
    StringComparison_CurrentCulture = 0,
    StringComparison_CurrentCultureIgnoreCase = 1,
    StringComparison_InvariantCulture = 2,
    StringComparison_InvariantCultureIgnoreCase = 3,
    StringComparison_Ordinal = 4,
    StringComparison_OrdinalIgnoreCase = 5
};

struct __declspec(uuid("e724b749-18d6-36ab-9f6d-09c36d9c6016"))
StringBuilder;
    // [ default ] interface _StringBuilder
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("a1c0a095-df97-3441-bfc1-c9f194e494db"))
Exception;
    // interface _Object
    // interface ISerializable
    // [ default ] interface _Exception

enum __declspec(uuid("69cedc24-bc35-3354-b324-6bd5f3ecb757"))
DateTimeKind
{
    DateTimeKind_Unspecified = 0,
    DateTimeKind_Utc = 1,
    DateTimeKind_Local = 2
};

struct __declspec(uuid("4224ac84-9b11-3561-8923-c893ca77acbe"))
SystemException;
    // [ default ] interface _SystemException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("ccf306ae-33bd-3003-9cce-daf5befef611"))
OutOfMemoryException;
    // [ default ] interface _OutOfMemoryException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("9c125a6f-eae2-3fc1-97a1-c0dceab0b5df"))
StackOverflowException;
    // [ default ] interface _StackOverflowException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("aad4bdd3-81aa-3abc-b53b-d904d25bc01e"))
DataMisalignedException;
    // [ default ] interface _DataMisalignedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("e786fb32-b659-3d96-94c4-e1a9fc037868"))
ExecutionEngineException;
    // [ default ] interface _ExecutionEngineException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("03ce85f6-37cb-3588-b3db-d5628bb1335b"))
Delegate;
    // [ default ] interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("198ffbde-a6db-3cc3-ab15-fbbb7250d624"))
MulticastDelegate;
    // [ default ] interface _MulticastDelegate
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("0ff66430-c796-3ee7-902b-166c402ca288"))
MemberAccessException;
    // [ default ] interface _MemberAccessException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("03973551-57a1-3900-a2b5-9083e3ff2943"))
_Activator : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("9ba4fd4e-2bc2-31a0-b721-d17aba5b12c3"))
Activator;
    // interface _Object
    // [ default ] interface _Activator

struct __declspec(uuid("4c3ebfd5-fc72-33dc-bc37-9953eb25b8d7"))
AccessViolationException;
    // [ default ] interface _AccessViolationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("1d09b407-a97f-378a-accb-82ca0082f9f3"))
ApplicationActivator;
    // [ default ] interface _ApplicationActivator
    // interface _Object

struct __declspec(uuid("682d63b8-1692-31be-88cd-5cb1f79edb7b"))
ApplicationException;
    // [ default ] interface _ApplicationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("3fb717af-9d21-3016-871a-df817abddd51"))
EventArgs;
    // [ default ] interface _EventArgs
    // interface _Object

struct __declspec(uuid("1c1d34a9-3f45-3b51-a9af-0354975bf8cc"))
ResolveEventArgs;
    // [ default ] interface _ResolveEventArgs
    // interface _Object

struct __declspec(uuid("81548590-3849-32a8-aa6f-f2b3137cf4a3"))
AssemblyLoadEventArgs;
    // [ default ] interface _AssemblyLoadEventArgs
    // interface _Object

struct __declspec(uuid("a4b8c851-941a-3dee-bd08-d9e2eed101c5"))
ResolveEventHandler;
    // [ default ] interface _ResolveEventHandler
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("2e130dc8-564e-397f-a628-397709da52e9"))
AssemblyLoadEventHandler;
    // [ default ] interface _AssemblyLoadEventHandler
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("fa525b27-3d69-3116-8d15-0064f6299548"))
AppDomainInitializer;
    // [ default ] interface _AppDomainInitializer
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("14b542c6-1c5a-3869-b8f8-feefd7b29d09"))
MarshalByRefObject;
    // [ default ] interface _MarshalByRefObject
    // interface _Object

struct __declspec(uuid("5fe0a145-a82b-3d96-94e3-fd214c9d6eb9"))
AppDomain;
    // interface _Object
    // [ default ] interface _AppDomain
    // interface IEvidenceFactory

struct __declspec(uuid("496219c1-3fb7-3dcf-8af7-d56032f7891f"))
CrossAppDomainDelegate;
    // [ default ] interface _CrossAppDomainDelegate
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

enum __declspec(uuid("148540d3-e67f-36dc-a55d-2c8dec53b9d3"))
AppDomainManagerInitializationOptions
{
    AppDomainManagerInitializationOptions_None = 0,
    AppDomainManagerInitializationOptions_RegisterWithHost = 1
};

struct __declspec(uuid("c03880a5-0b5e-39ad-954a-ce0dcbd5ef7d"))
AppDomainManager;
    // [ default ] interface _AppDomainManager
    // interface _Object

struct __declspec(uuid("27fff232-a7a8-40dd-8d4a-734ad59fcd41"))
IAppDomainSetup : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ApplicationBase (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ApplicationBase (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_ApplicationName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ApplicationName (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_CachePath (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_CachePath (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_ConfigurationFile (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ConfigurationFile (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_DynamicBase (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_DynamicBase (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_LicenseFile (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_LicenseFile (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_PrivateBinPath (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_PrivateBinPath (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_PrivateBinPathProbe (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_PrivateBinPathProbe (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_ShadowCopyDirectories (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ShadowCopyDirectories (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_ShadowCopyFiles (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ShadowCopyFiles (
        /*[in]*/ BSTR pRetVal ) = 0;
};

struct __declspec(uuid("3e8e0f03-d3fd-3a93-bae0-c74a6494dbca"))
AppDomainSetup;
    // interface _Object
    // [ default ] interface IAppDomainSetup

enum __declspec(uuid("8a6c24c5-1f87-37c2-bc4d-3421eb62d4c1"))
LoaderOptimization
{
    LoaderOptimization_NotSpecified = 0,
    LoaderOptimization_SingleDomain = 1,
    LoaderOptimization_MultiDomain = 2,
    LoaderOptimization_MultiDomainHost = 3,
    LoaderOptimization_DomainMask = 3,
    LoaderOptimization_DisallowBindings = 4
};

struct __declspec(uuid("917b14d0-2d9e-38b8-92a9-381acf52f7c0"))
_Attribute : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("1765714b-e628-34c3-b66f-7686faf462da"))
Attribute;
    // interface _Object
    // [ default ] interface _Attribute

struct __declspec(uuid("b39742fd-1a55-3810-9ea5-f6e86ebeb472"))
LoaderOptimizationAttribute;
    // [ default ] interface _LoaderOptimizationAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("61b3e12b-3586-3a58-a497-7ed7c4c794b9"))
AppDomainUnloadedException;
    // [ default ] interface _AppDomainUnloadedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("d12b05f9-0654-351a-92d1-8fdac1f243de"))
ActivationArguments;
    // [ default ] interface _ActivationArguments
    // interface _Object

struct __declspec(uuid("af3866ad-f70a-3cf8-984e-858c5a686d57"))
ApplicationId;
    // [ default ] interface _ApplicationId
    // interface _Object

struct __declspec(uuid("3fdceec6-b14b-37e2-bb69-abc7ca0da22f"))
ArgumentException;
    // [ default ] interface _ArgumentException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("3bd1f243-9bc4-305d-9b1c-0d10c80329fc"))
ArgumentNullException;
    // [ default ] interface _ArgumentNullException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("74bdd0b9-38d7-3fda-a67e-d404ee684f24"))
ArgumentOutOfRangeException;
    // [ default ] interface _ArgumentOutOfRangeException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("647053c3-1879-34d7-ae57-67015c91fc70"))
ArithmeticException;
    // [ default ] interface _ArithmeticException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("676e1164-752c-3a74-8d3f-bcd32a2026d6"))
ArrayTypeMismatchException;
    // [ default ] interface _ArrayTypeMismatchException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("b2a87ddb-5dab-395f-b7be-ad83058fb516"))
AsyncCallback;
    // [ default ] interface _AsyncCallback
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

enum __declspec(uuid("9bc2306f-4971-38f5-b861-f19c022274a0"))
AttributeTargets
{
    AttributeTargets_Assembly = 1,
    AttributeTargets_Module = 2,
    AttributeTargets_Class = 4,
    AttributeTargets_Struct = 8,
    AttributeTargets_Enum = 16,
    AttributeTargets_Constructor = 32,
    AttributeTargets_Method = 64,
    AttributeTargets_Property = 128,
    AttributeTargets_Field = 256,
    AttributeTargets_Event = 512,
    AttributeTargets_Interface = 1024,
    AttributeTargets_Parameter = 2048,
    AttributeTargets_Delegate = 4096,
    AttributeTargets_ReturnValue = 8192,
    AttributeTargets_GenericParameter = 16384,
    AttributeTargets_All = 32767
};

struct __declspec(uuid("53a62bb1-75b9-3b52-ae98-92afd573cdb1"))
AttributeUsageAttribute;
    // [ default ] interface _AttributeUsageAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("e9148312-a9bf-3a45-bbca-350967fd78f5"))
BadImageFormatException;
    // [ default ] interface _BadImageFormatException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 4)

struct __declspec(uuid("c3008e12-9b16-36ec-b731-73257f25be7a"))
Boolean
{
    long m_value;
};

#pragma pack(pop)

struct __declspec(uuid("830fe109-4566-3af2-9b57-5602724fcace"))
Buffer;
    // [ default ] interface _Buffer
    // interface _Object

#pragma pack(push, 1)

struct __declspec(uuid("9b957340-adba-3234-91ea-46a5c9bff530"))
Byte
{
    unsigned char m_value;
};

#pragma pack(pop)

struct __declspec(uuid("29c69707-875f-3678-8f01-283094a2dfb1"))
CannotUnloadAppDomainException;
    // [ default ] interface _CannotUnloadAppDomainException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 1)

struct __declspec(uuid("6ee96102-3657-3d66-867a-26b63aaaaf78"))
Char
{
    unsigned char m_value;
};

#pragma pack(pop)

struct __declspec(uuid("277eabd6-f03a-3c52-8b42-b8e326d9c0cc"))
CharEnumerator;
    // [ default ] interface _CharEnumerator
    // interface _Object
    // interface ICloneable
    // interface IDisposable
    // interface IEnumerator

struct __declspec(uuid("15dbec24-0e2d-3db2-af66-932203215895"))
CLSCompliantAttribute;
    // [ default ] interface _CLSCompliantAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("d6d2034d-5f67-30d7-9cc5-452f2c46694f"))
TypeUnloadedException;
    // [ default ] interface _TypeUnloadedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("c281c7f1-4aa9-3517-961a-463cfed57e75"))
_Thread : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("314bda5a-9292-3fc0-830d-7a4b0261fc88"))
CriticalFinalizerObject;
    // [ default ] interface _CriticalFinalizerObject
    // interface _Object

struct __declspec(uuid("cbeaa915-4d2c-3f77-98e8-a258b0fd3cef"))
ContextMarshalException;
    // [ default ] interface _ContextMarshalException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("7916cbef-050e-3e39-b83a-5ab9558e72f1"))
ContextBoundObject;
    // [ default ] interface _ContextBoundObject
    // interface _Object

struct __declspec(uuid("96705ee3-f7ab-3e9a-9fb2-ad1d536e901a"))
ContextStaticAttribute;
    // [ default ] interface _ContextStaticAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("543c0dd8-a713-3777-b01a-aeb801dac001"))
TimeZone;
    // [ default ] interface _TimeZone
    // interface _Object

enum __declspec(uuid("12d4d747-6b55-36f2-9108-3ee9bc0ffefd"))
DayOfWeek
{
    DayOfWeek_Sunday = 0,
    DayOfWeek_Monday = 1,
    DayOfWeek_Tuesday = 2,
    DayOfWeek_Wednesday = 3,
    DayOfWeek_Thursday = 4,
    DayOfWeek_Friday = 5,
    DayOfWeek_Saturday = 6
};

struct __declspec(uuid("8c1a4524-3ceb-3436-b449-cac456ecab09"))
DBNull;
    // [ default ] interface _DBNull
    // interface _Object
    // interface ISerializable
    // interface IConvertible

#pragma pack(push, 4)

struct __declspec(uuid("6fb370d8-4f72-3ac1-9a32-3875f336ecb5"))
Decimal
{
    long flags;
    long hi;
    long lo;
    long mid;
};

#pragma pack(pop)

struct __declspec(uuid("74a6b90c-8710-32da-bbf7-9d4445e071e9"))
Binder;
    // [ default ] interface _Binder
    // interface _Object

struct __declspec(uuid("f6914a11-d95d-324f-ba0f-39a374625290"))
DivideByZeroException;
    // [ default ] interface _DivideByZeroException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 8)

struct __declspec(uuid("0f4f147f-4369-3388-8e4b-71e20c96f9ad"))
Double
{
    double m_value;
};

#pragma pack(pop)

struct __declspec(uuid("cc20c6df-a054-3f09-a5f5-a3b5a25f4ce6"))
DuplicateWaitObjectException;
    // [ default ] interface _DuplicateWaitObjectException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("112bc2e7-9ef9-3648-af9e-45c0d4b89929"))
TypeLoadException;
    // [ default ] interface _TypeLoadException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("ad326409-bf80-3e0c-ba6f-ee2c33b675a5"))
EntryPointNotFoundException;
    // [ default ] interface _EntryPointNotFoundException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("46e97093-b2ec-3787-a9a5-470d1a27417c"))
DllNotFoundException;
    // [ default ] interface _DllNotFoundException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("3b1774cd-34e0-3c00-aabd-168b38c62fd9"))
EnvironmentVariableTarget
{
    EnvironmentVariableTarget_Process = 0,
    EnvironmentVariableTarget_User = 1,
    EnvironmentVariableTarget_Machine = 2
};

struct __declspec(uuid("df81b4ff-7226-30fa-84df-80795ba1a642"))
Environment;
    // [ default ] interface _Environment
    // interface _Object

enum __declspec(uuid("2e05a70a-1bbe-31df-b2a8-b8fa0f130915"))
SpecialFolder
{
    SpecialFolder_ApplicationData = 26,
    SpecialFolder_CommonApplicationData = 35,
    SpecialFolder_LocalApplicationData = 28,
    SpecialFolder_Cookies = 33,
    SpecialFolder_Desktop = 0,
    SpecialFolder_Favorites = 6,
    SpecialFolder_History = 34,
    SpecialFolder_InternetCache = 32,
    SpecialFolder_Programs = 2,
    SpecialFolder_MyComputer = 17,
    SpecialFolder_MyMusic = 13,
    SpecialFolder_MyPictures = 39,
    SpecialFolder_Recent = 8,
    SpecialFolder_SendTo = 9,
    SpecialFolder_StartMenu = 11,
    SpecialFolder_Startup = 7,
    SpecialFolder_System = 37,
    SpecialFolder_Templates = 21,
    SpecialFolder_DesktopDirectory = 16,
    SpecialFolder_Personal = 5,
    SpecialFolder_MyDocuments = 5,
    SpecialFolder_ProgramFiles = 38,
    SpecialFolder_CommonProgramFiles = 43
};

struct __declspec(uuid("dca836de-c23d-334c-86b7-8385be47030d"))
EventHandler;
    // [ default ] interface _EventHandler
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("bda7bee5-85f1-3b66-b610-ddf1d5898006"))
FieldAccessException;
    // [ default ] interface _FieldAccessException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("66ce75d4-0334-3ca6-bca8-ce9af28a4396"))
FlagsAttribute;
    // [ default ] interface _FlagsAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("964aa3bd-4b12-3e23-9d7f-99342afae812"))
FormatException;
    // [ default ] interface _FormatException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 4)

struct __declspec(uuid("9c5923e9-de52-33ea-88de-7ebc8633b9cc"))
Guid
{
    long _a;
    short _b;
    short _c;
    unsigned char _d;
    unsigned char _e;
    unsigned char _f;
    unsigned char _g;
    unsigned char _h;
    unsigned char _i;
    unsigned char _j;
    unsigned char _k;
};

#pragma pack(pop)

struct __declspec(uuid("5ca9971b-2dc3-3bc8-847a-5e6d15cbb16e"))
IndexOutOfRangeException;
    // [ default ] interface _IndexOutOfRangeException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 2)

struct __declspec(uuid("206daf34-5ba5-3504-8a19-d57699561886"))
Int16
{
    short m_value;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("a310fadd-7c33-377c-9d6b-599b0317d7f2"))
Int32
{
    long m_value;
};

#pragma pack(pop)

#pragma pack(push, 8)

struct __declspec(uuid("ad1cecf5-5fad-3ecf-ad89-2febd6521fa9"))
Int64
{
    __int64 m_value;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("a1cb710c-8d50-3181-bb38-65ce2e98f9a6"))
IntPtr
{
    void * m_value;
};

#pragma pack(pop)

struct __declspec(uuid("7f6bcbe5-eb30-370b-9f1b-92a6265afedd"))
InvalidCastException;
    // [ default ] interface _InvalidCastException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("9546306b-1b68-33af-80db-3a9206501515"))
InvalidOperationException;
    // [ default ] interface _InvalidOperationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("91591469-efef-3d63-90f9-88520f0aa1ef"))
InvalidProgramException;
    // [ default ] interface _InvalidProgramException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("e95e800a-cba4-3613-821d-6d6ef3bcbf6b"))
LocalDataStoreSlot;
    // [ default ] interface _LocalDataStoreSlot
    // interface _Object

struct __declspec(uuid("92e76a74-2622-3aa9-a3ca-1ae8bd7bc4a8"))
MethodAccessException;
    // [ default ] interface _MethodAccessException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("d12abe44-783e-328b-aad3-4ed726e903c7"))
MidpointRounding
{
    MidpointRounding_ToEven = 0,
    MidpointRounding_AwayFromZero = 1
};

struct __declspec(uuid("cdc70043-d56b-3799-b7bd-6113bbca160a"))
MissingMemberException;
    // [ default ] interface _MissingMemberException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("8d36569b-14d6-3c3d-b55c-9d02a45bfc3d"))
MissingFieldException;
    // [ default ] interface _MissingFieldException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("58897d76-ef6c-327a-93f7-6cd66c424e11"))
MissingMethodException;
    // [ default ] interface _MissingMethodException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("9da2f8b8-59f0-3852-b509-0663e3bf643b"))
MulticastNotSupportedException;
    // [ default ] interface _MulticastNotSupportedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("cc77f5f3-222d-3586-88c3-410477a3b65d"))
NonSerializedAttribute;
    // [ default ] interface _NonSerializedAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("7e34ab89-0684-3b86-8a0f-e638eb4e6252"))
NotFiniteNumberException;
    // [ default ] interface _NotFiniteNumberException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("f8be2ad5-4e99-3e00-b10e-7c54d31c1c1d"))
NotImplementedException;
    // [ default ] interface _NotImplementedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("dafb2462-2a5b-3818-b17e-602984fe1bb0"))
NotSupportedException;
    // [ default ] interface _NotSupportedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("7f71db2d-1ea0-3cae-8087-26095f5215e6"))
NullReferenceException;
    // [ default ] interface _NullReferenceException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("f17baaf6-d35c-3c6e-acd3-d0d49a5022c4"))
ObjectDisposedException;
    // [ default ] interface _ObjectDisposedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("08295c62-7462-3633-b35e-7ae68aca3948"))
ObsoleteAttribute;
    // [ default ] interface _ObsoleteAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("d7ca3b25-a57b-354c-8758-9fe3a905c1ac"))
OperatingSystem;
    // [ default ] interface _OperatingSystem
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("11581718-2434-32e3-b559-e86ce9923744"))
OperationCanceledException;
    // [ default ] interface _OperationCanceledException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("4286fa72-a2fa-3245-8751-d4206070a191"))
OverflowException;
    // [ default ] interface _OverflowException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("3495e5fa-2a90-3ca7-b3b5-58736c4441dd"))
ParamArrayAttribute;
    // [ default ] interface _ParamArrayAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("f9628962-01e2-32f6-a40c-08bd8adcff25"))
PlatformID
{
    PlatformID_Win32S = 0,
    PlatformID_Win32Windows = 1,
    PlatformID_Win32NT = 2,
    PlatformID_WinCE = 3,
    PlatformID_Unix = 4
};

struct __declspec(uuid("a36738b5-fa8f-3316-a929-68099a32b43b"))
PlatformNotSupportedException;
    // [ default ] interface _PlatformNotSupportedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("4e77ec8f-51d8-386c-85fe-7dc931b7a8e7"))
Random;
    // [ default ] interface _Random
    // interface _Object

struct __declspec(uuid("c9f61cbd-287f-3d24-9feb-2c3f347cf570"))
RankException;
    // [ default ] interface _RankException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("5ae028b5-9a3a-32a9-899c-1deefb85cc50"))
MemberInfo;
    // interface _Object
    // interface ICustomAttributeProvider
    // [ default ] interface _MemberInfo

struct __declspec(uuid("6c9863dc-7207-327f-a048-c3bb63474bfc"))
Type;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // [ default ] interface _Type
    // interface IReflect

#pragma pack(push, 4)

struct __declspec(uuid("3613a9b6-c23b-3b54-ae02-6ec764d69e70"))
RuntimeArgumentHandle
{
    long m_ptr;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("78c18a10-c00e-3c09-b000-411c38900c2c"))
RuntimeTypeHandle
{
    long m_ptr;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("f8fc5d7c-8215-3e65-befb-11e8172606fe"))
RuntimeMethodHandle
{
    long m_ptr;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("27b33bd9-e6f7-3148-911d-f67340a5353f"))
RuntimeFieldHandle
{
    long m_ptr;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("8531f85a-746b-3db5-a45f-9bac4bd02d8b"))
ModuleHandle
{
    long m_ptr;
};

#pragma pack(pop)

#pragma pack(push, 1)

struct __declspec(uuid("ca2bcdb4-3a7e-33e8-80ed-d32475adef33"))
SByte
{
    char m_value;
};

#pragma pack(pop)

struct __declspec(uuid("89bcc804-53a5-3eb2-a342-6282cc410260"))
SerializableAttribute;
    // [ default ] interface _SerializableAttribute
    // interface _Object
    // interface _Attribute

#pragma pack(push, 4)

struct __declspec(uuid("23d4a35b-c997-3401-8372-736025b17744"))
Single
{
    float m_value;
};

#pragma pack(pop)

struct __declspec(uuid("eaa78d4a-20a3-3fde-ab72-d3d55e3aefe6"))
TimeoutException;
    // [ default ] interface _TimeoutException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 8)

struct __declspec(uuid("94942670-4acf-3572-92d1-0916cd777e00"))
TimeSpan
{
    __int64 _ticks;
};

#pragma pack(pop)

enum __declspec(uuid("8e3cc6fb-a6ed-3f63-a7d1-d40d8c6666f6"))
TypeCode
{
    TypeCode_Empty = 0,
    TypeCode_Object = 1,
    TypeCode_DBNull = 2,
    TypeCode_Boolean = 3,
    TypeCode_Char = 4,
    TypeCode_SByte = 5,
    TypeCode_Byte = 6,
    TypeCode_Int16 = 7,
    TypeCode_UInt16 = 8,
    TypeCode_Int32 = 9,
    TypeCode_UInt32 = 10,
    TypeCode_Int64 = 11,
    TypeCode_UInt64 = 12,
    TypeCode_Single = 13,
    TypeCode_Double = 14,
    TypeCode_Decimal = 15,
    TypeCode_DateTime = 16,
    TypeCode_String = 18
};

#pragma pack(push, 4)

struct __declspec(uuid("06ad02b5-c5a4-3eec-b7ba-b0af7860d36a"))
TypedReference
{
    long value;
    long Type;
};

#pragma pack(pop)

struct __declspec(uuid("811fb5f2-9bfe-3557-83de-1279f0b3eb55"))
TypeInitializationException;
    // [ default ] interface _TypeInitializationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

#pragma pack(push, 2)

struct __declspec(uuid("0f0928b7-11dd-31dd-a0d5-bb008ae887bf"))
UInt16
{
    unsigned short m_value;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("4f854e40-af6d-3d30-860a-e9722c85e9a3"))
UInt32
{
    unsigned long m_value;
};

#pragma pack(pop)

#pragma pack(push, 8)

struct __declspec(uuid("62ad7d6b-52cc-3ed4-a20d-1a32ef6bf1da"))
UInt64
{
    unsigned __int64 m_value;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("4f93b8dd-5396-3b65-b16a-11fbc8812a71"))
UIntPtr
{
    void * m_value;
};

#pragma pack(pop)

struct __declspec(uuid("75215200-a2fe-30f6-a34b-8f1a1830358e"))
UnauthorizedAccessException;
    // [ default ] interface _UnauthorizedAccessException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("b55dae2e-c8e8-3c48-b404-d991979a9d9d"))
UnhandledExceptionEventArgs;
    // [ default ] interface _UnhandledExceptionEventArgs
    // interface _Object

struct __declspec(uuid("db4d2d94-3fa3-36f5-b22e-a00ff22f08bd"))
UnhandledExceptionEventHandler;
    // [ default ] interface _UnhandledExceptionEventHandler
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("43cd41ad-3b78-3531-9031-3059e0aa64eb"))
Version;
    // [ default ] interface _Version
    // interface _Object
    // interface ICloneable
    // interface IComparable

struct __declspec(uuid("d3f54e92-a0c7-3bf4-a114-f1f384ce3eff"))
WeakReference;
    // [ default ] interface _WeakReference
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("4d0e564a-78c8-31e0-ba03-73af7bdff5a9"))
WaitHandle;
    // [ default ] interface _WaitHandle
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("80226212-1832-310f-862c-a511e3534e62"))
EventWaitHandle;
    // [ default ] interface _EventWaitHandle
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("e35af4dd-eb37-39fc-9071-4ce39b1a54be"))
AutoResetEvent;
    // [ default ] interface _AutoResetEvent
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("5b193863-a73e-3ec3-80d0-35b36e3cf4ed"))
ContextCallback;
    // [ default ] interface _ContextCallback
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable
/*
struct __declspec(uuid("c460e2b4-e199-412a-8456-84dc3e4838c3"))
IObjectHandle : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Unwrap (
//        /*[out,retval]* / VARIANT * pRetVal ) = 0;
//};
*/

#pragma pack(push, 4)

struct __declspec(uuid("ba0e4cf7-a429-3fe8-abab-183387d05852"))
LockCookie
{
    long _dwFlags;
    long _dwWriterSeqNum;
    long _wReaderAndWriterLevel;
    long _dwThreadID;
};

#pragma pack(pop)

struct __declspec(uuid("17a355c3-c65e-3f26-8a80-236890ebc997"))
ManualResetEvent;
    // [ default ] interface _ManualResetEvent
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("9e97213a-0b49-3c05-a0bf-d203c4fc8487"))
Monitor;
    // [ default ] interface _Monitor
    // interface _Object

struct __declspec(uuid("d74d613d-f27f-311b-a9a3-27ebc63a1a5d"))
Mutex;
    // [ default ] interface _Mutex
    // interface _Object
    // interface IDisposable

#pragma pack(push, 4)

struct __declspec(uuid("a2959123-2f66-35b4-815d-37c83360809b"))
NativeOverlapped
{
    long InternalLow;
    long InternalHigh;
    long OffsetLow;
    long OffsetHigh;
    long EventHandle;
};

#pragma pack(pop)

struct __declspec(uuid("7fe87a55-1321-3d9f-8fef-cd2f5e8ab2e9"))
Overlapped;
    // [ default ] interface _Overlapped
    // interface _Object

struct __declspec(uuid("9173d971-b142-38a5-8488-d10a9dcf71b0"))
ReaderWriterLock;
    // [ default ] interface _ReaderWriterLock
    // interface _Object

struct __declspec(uuid("48a75519-cb7a-3d18-b91e-be62ee842a3e"))
SynchronizationLockException;
    // [ default ] interface _SynchronizationLockException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("a5889aad-36a6-3b3e-89f9-118ce3a77d7c"))
Thread;
    // interface _Object
    // [ default ] interface _Thread

struct __declspec(uuid("ea1cf67d-7904-36a3-bd5b-dd028985861c"))
ThreadAbortException;
    // [ default ] interface _ThreadAbortException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("27e986e1-baec-3d48-82e4-14169ca8cecf"))
ThreadInterruptedException;
    // [ default ] interface _ThreadInterruptedException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("50f8ae2b-69f0-37ef-954b-d2618e3e8267"))
RegisteredWaitHandle;
    // [ default ] interface _RegisteredWaitHandle
    // interface _Object

struct __declspec(uuid("d8e04cc2-f4f5-367d-a23f-f71aff4f14f3"))
WaitCallback;
    // [ default ] interface _WaitCallback
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("3c8c9f02-2c23-39ff-ac7b-cd0ee1d14a79"))
WaitOrTimerCallback;
    // [ default ] interface _WaitOrTimerCallback
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("8a937e3b-9c07-3d4d-b50a-4f4f3c85317c"))
IOCompletionCallback;
    // [ default ] interface _IOCompletionCallback
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

enum __declspec(uuid("d32b1206-1440-3664-9991-1ae109add173"))
ThreadPriority
{
    ThreadPriority_Lowest = 0,
    ThreadPriority_BelowNormal = 1,
    ThreadPriority_Normal = 2,
    ThreadPriority_AboveNormal = 3,
    ThreadPriority_Highest = 4
};

struct __declspec(uuid("e7ac1e4d-35db-3432-a032-e94c012b2d39"))
ThreadStart;
    // [ default ] interface _ThreadStart
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

enum __declspec(uuid("f768ec63-95ed-35fc-9876-7bcf01a14919"))
ThreadState
{
    ThreadState_Running = 0,
    ThreadState_StopRequested = 1,
    ThreadState_SuspendRequested = 2,
    ThreadState_Background = 4,
    ThreadState_Unstarted = 8,
    ThreadState_Stopped = 16,
    ThreadState_WaitSleepJoin = 32,
    ThreadState_Suspended = 64,
    ThreadState_AbortRequested = 128,
    ThreadState_Aborted = 256
};

struct __declspec(uuid("3e5509f0-1fb9-304d-8174-75d6c9afe5da"))
ThreadStateException;
    // [ default ] interface _ThreadStateException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("ffc9f9ae-e87a-3252-8e25-b22423a40065"))
ThreadStaticAttribute;
    // [ default ] interface _ThreadStaticAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("5a49b766-b474-3501-901e-5bdac8b48a3d"))
Timeout;
    // [ default ] interface _Timeout
    // interface _Object

struct __declspec(uuid("ddf7ba7f-4b7c-378d-a153-6285b84c6593"))
TimerCallback;
    // [ default ] interface _TimerCallback
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("490ca7a8-d03f-3459-8208-d428ea010da0"))
Timer;
    // [ default ] interface _Timer
    // interface _Object
    // interface IDisposable

enum __declspec(uuid("7055b1db-d445-31fc-bdec-a9fb3f6e6e58"))
ApartmentState
{
    ApartmentState_STA = 0,
    ApartmentState_MTA = 1,
    ApartmentState_Unknown = 2
};

struct __declspec(uuid("50aad4c2-61fa-3b1f-8157-5ba3b27aee61"))
STAThreadAttribute;
    // [ default ] interface _STAThreadAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("b406ac70-4d7e-3d24-b241-aeaeac343bd9"))
MTAThreadAttribute;
    // [ default ] interface _MTAThreadAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("6896b49d-7afb-34dc-934e-5add38eeee39"))
ArrayList;
    // [ default ] interface _ArrayList
    // interface _Object
    // interface IList
    // interface ICollection
    // interface IEnumerable
    // interface ICloneable

struct __declspec(uuid("5d2fb755-c658-3f51-86f2-881f4a1a2a55"))
BitArray;
    // [ default ] interface _BitArray
    // interface _Object
    // interface ICollection
    // interface IEnumerable
    // interface ICloneable

struct __declspec(uuid("35e946e4-7cda-3824-8b24-d799a96309ad"))
CaseInsensitiveComparer;
    // [ default ] interface _CaseInsensitiveComparer
    // interface _Object
    // interface IComparer

struct __declspec(uuid("5d573036-3435-3c5a-aeff-2b8191082c71"))
IHashCodeProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetHashCode (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ long * pRetVal ) = 0;
};

struct __declspec(uuid("47d3c68d-7d85-3227-a9e7-88451d6badfc"))
CaseInsensitiveHashCodeProvider;
    // [ default ] interface _CaseInsensitiveHashCodeProvider
    // interface _Object
    // interface IHashCodeProvider

struct __declspec(uuid("87259279-9f5d-3c0a-bb58-723a2a6e4dba"))
CollectionBase;
    // [ default ] interface _CollectionBase
    // interface _Object
    // interface IList
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("8a63140f-7eb8-3f4e-ba59-19b8c747843f"))
Comparer;
    // [ default ] interface _Comparer
    // interface _Object
    // interface IComparer
    // interface ISerializable

struct __declspec(uuid("9840c5c3-21d3-3b8a-94c1-3fc542b0227e"))
DictionaryBase;
    // [ default ] interface _DictionaryBase
    // interface _Object
    // interface IDictionary
    // interface ICollection
    // interface IEnumerable

#pragma pack(push, 4)

struct __declspec(uuid("a6cceb32-ec73-3e9b-8852-02783c97d3fa"))
DictionaryEntry
{
    IUnknown * _key;
    IUnknown * _value;
};

#pragma pack(pop)

struct __declspec(uuid("35d574bf-7a4f-3588-8c19-12212a0fe4dc"))
IDictionaryEnumerator : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_key (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_value (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Entry (
        /*[out,retval]*/ struct DictionaryEntry * pRetVal ) = 0;
};

struct __declspec(uuid("ab3f47e4-c227-3b05-bf9f-94649bef9888"))
IDeserializationCallback : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall OnDeserialization (
        /*[in]*/ VARIANT sender ) = 0;
};

struct __declspec(uuid("146855fa-309f-3d0e-bb3e-df525f30a715"))
Hashtable;
    // [ default ] interface _Hashtable
    // interface _Object
    // interface IDictionary
    // interface ICollection
    // interface IEnumerable
    // interface ISerializable
    // interface IDeserializationCallback
    // interface ICloneable

struct __declspec(uuid("7f976b72-4b71-3858-bee8-8e3a3189a651"))
Queue;
    // [ default ] interface _Queue
    // interface _Object
    // interface ICollection
    // interface IEnumerable
    // interface ICloneable

struct __declspec(uuid("b66406bd-746d-3d10-98a1-41d097cf42b7"))
ReadOnlyCollectionBase;
    // [ default ] interface _ReadOnlyCollectionBase
    // interface _Object
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("026cc6d7-34b2-33d5-b551-ca31eb6ce345"))
SortedList;
    // [ default ] interface _SortedList
    // interface _Object
    // interface IDictionary
    // interface ICollection
    // interface IEnumerable
    // interface ICloneable

struct __declspec(uuid("4599202d-460f-3fb7-8a1c-c2cc6ed6c7c8"))
Stack;
    // [ default ] interface _Stack
    // interface _Object
    // interface ICollection
    // interface IEnumerable
    // interface ICloneable

struct __declspec(uuid("f358ac62-4569-3705-be32-b07e799b4223"))
Nullable;
    // [ default ] interface _Nullable
    // interface _Object

struct __declspec(uuid("0d52abe3-3c93-3d94-a744-ac44850baccd"))
KeyNotFoundException;
    // [ default ] interface _KeyNotFoundException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("75b3810e-f2d5-36e2-8d27-514ebcad4511"))
ConditionalAttribute;
    // [ default ] interface _ConditionalAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("91f672a3-6b82-3e04-b2d7-bac5d6676609"))
Debugger;
    // [ default ] interface _Debugger
    // interface _Object

struct __declspec(uuid("93f551d6-2f9e-301b-be63-85aef508cae0"))
DebuggerStepThroughAttribute;
    // [ default ] interface _DebuggerStepThroughAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("1b979846-aaeb-314b-8e63-d44ef1cb9efc"))
DebuggerStepperBoundaryAttribute;
    // [ default ] interface _DebuggerStepperBoundaryAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("41970d73-92f6-36d9-874d-3bd0762a0d6f"))
DebuggerHiddenAttribute;
    // [ default ] interface _DebuggerHiddenAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("29625281-51ce-3f8a-ac4d-e360cacb92e2"))
DebuggerNonUserCodeAttribute;
    // [ default ] interface _DebuggerNonUserCodeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("df1f67b4-74f7-30af-922d-29f0b91abc25"))
DebuggableAttribute;
    // [ default ] interface _DebuggableAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("86343361-ce50-35ee-8bea-6f39ec8c8159"))
DebuggingModes
{
    DebuggingModes_None = 0,
    DebuggingModes_Default = 1,
    DebuggingModes_DisableOptimizations = 256,
    DebuggingModes_IgnoreSymbolStoreSequencePoints = 2,
    DebuggingModes_EnableEditAndContinue = 4
};

enum __declspec(uuid("5a235286-93f1-3c18-a3ae-16d345a87a24"))
DebuggerBrowsableState
{
    DebuggerBrowsableState_Never = 0,
    DebuggerBrowsableState_Collapsed = 2,
    DebuggerBrowsableState_RootHidden = 3
};

struct __declspec(uuid("a709ebbe-bdb2-30f4-959b-37b7a68e4299"))
DebuggerBrowsableAttribute;
    // [ default ] interface _DebuggerBrowsableAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("8366ee18-bbe6-3061-b99f-ba87e26919d1"))
DebuggerTypeProxyAttribute;
    // [ default ] interface _DebuggerTypeProxyAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("f640e47b-67d0-31a2-8621-02e2dd41b496"))
DebuggerDisplayAttribute;
    // [ default ] interface _DebuggerDisplayAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("29813e13-8772-3b1f-878d-26c33b045d5a"))
DebuggerVisualizerAttribute;
    // [ default ] interface _DebuggerVisualizerAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("405c2d81-315b-3cb0-8442-ef5a38d4c3b8"))
StackTrace;
    // [ default ] interface _StackTrace
    // interface _Object

struct __declspec(uuid("14910622-09d4-3b4a-8c1e-9991dbdcc553"))
StackFrame;
    // [ default ] interface _StackFrame
    // interface _Object

struct __declspec(uuid("1c32f012-2684-3efe-8d50-9c2973acc00b"))
ISymbolDocument : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Url (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DocumentType (
        /*[out,retval]*/ GUID * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Language (
        /*[out,retval]*/ GUID * pRetVal ) = 0;
      virtual HRESULT __stdcall get_LanguageVendor (
        /*[out,retval]*/ GUID * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CheckSumAlgorithmId (
        /*[out,retval]*/ GUID * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCheckSum (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall FindClosestLine (
        /*[in]*/ long line,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_HasEmbeddedSource (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_SourceLength (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSourceRange (
        /*[in]*/ long startLine,
        /*[in]*/ long startColumn,
        /*[in]*/ long endLine,
        /*[in]*/ long endColumn,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("fa682f24-3a3c-390d-b8a2-96f1106f4b37"))
ISymbolDocumentWriter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall SetSource (
        /*[in]*/ SAFEARRAY * Source ) = 0;
      virtual HRESULT __stdcall SetCheckSum (
        /*[in]*/ GUID algorithmId,
        /*[in]*/ SAFEARRAY * checkSum ) = 0;
};

struct __declspec(uuid("23ed2454-6899-3c28-bab7-6ec86683964a"))
ISymbolNamespace : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNamespaces (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetVariables (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

enum __declspec(uuid("b6b91160-2abf-352b-a74d-1174cc324e18"))
SymAddressKind
{
    SymAddressKind_ILOffset = 1,
    SymAddressKind_NativeRVA = 2,
    SymAddressKind_NativeRegister = 3,
    SymAddressKind_NativeRegisterRelative = 4,
    SymAddressKind_NativeOffset = 5,
    SymAddressKind_NativeRegisterRegister = 6,
    SymAddressKind_NativeRegisterStack = 7,
    SymAddressKind_NativeStackRegister = 8,
    SymAddressKind_BitField = 9,
    SymAddressKind_NativeSectionOffset = 10
};

struct __declspec(uuid("4042bd4d-b5ab-30e8-919b-14910687baae"))
ISymbolVariable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSignature (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AddressKind (
        /*[out,retval]*/ enum SymAddressKind * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AddressField1 (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AddressField2 (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AddressField3 (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_StartOffset (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_EndOffset (
        /*[out,retval]*/ long * pRetVal ) = 0;
};

struct __declspec(uuid("40ae2088-ce00-33ad-9320-5d201cb46fc9"))
SymDocumentType;
    // [ default ] interface _SymDocumentType
    // interface _Object

struct __declspec(uuid("5a18d43e-115b-3b8b-8245-9a06b204b717"))
SymLanguageType;
    // [ default ] interface _SymLanguageType
    // interface _Object

struct __declspec(uuid("dfd888a7-a6b0-3b1b-985e-4cdab0e4c17d"))
SymLanguageVendor;
    // [ default ] interface _SymLanguageVendor
    // interface _Object

#pragma pack(push, 4)

struct __declspec(uuid("709164df-d0e2-3813-a07d-f9f1e99f9a4b"))
SymbolToken
{
    long m_token;
};

#pragma pack(pop)

struct __declspec(uuid("2846ae5e-a9fa-36cf-b2d1-6e95596dbde7"))
AmbiguousMatchException;
    // [ default ] interface _AmbiguousMatchException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("aaaa10c6-9902-3dbb-b173-eba1eba2cd5e"))
ModuleResolveEventHandler;
    // [ default ] interface _ModuleResolveEventHandler
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("28e89a9f-e67d-3028-aa1b-e5ebcde6f3c8"))
Assembly;
    // interface _Object
    // [ default ] interface _Assembly
    // interface IEvidenceFactory
    // interface ICustomAttributeProvider
    // interface ISerializable

struct __declspec(uuid("8687959f-d86d-3217-8d58-be9a0427bb84"))
AssemblyCopyrightAttribute;
    // [ default ] interface _AssemblyCopyrightAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("e64c95df-eadc-3d08-9c6f-80f29d92cb4e"))
AssemblyTrademarkAttribute;
    // [ default ] interface _AssemblyTrademarkAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("cfe2bcf1-683c-39b5-83ce-4b186a521513"))
AssemblyProductAttribute;
    // [ default ] interface _AssemblyProductAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("62342fb2-16bf-30a9-88ad-6bc781eec94f"))
AssemblyCompanyAttribute;
    // [ default ] interface _AssemblyCompanyAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("432e5e9f-03ba-37b2-8edf-7fac14b03b4f"))
AssemblyDescriptionAttribute;
    // [ default ] interface _AssemblyDescriptionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("51b4f67c-2fcb-391d-a381-d040100d6717"))
AssemblyTitleAttribute;
    // [ default ] interface _AssemblyTitleAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("09dd9840-5e39-317a-aab3-0a467998de25"))
AssemblyConfigurationAttribute;
    // [ default ] interface _AssemblyConfigurationAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("8beb1256-5d9b-3262-bf85-beb6287e4eea"))
AssemblyDefaultAliasAttribute;
    // [ default ] interface _AssemblyDefaultAliasAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("894593b9-99e5-3b61-a592-ee44b9396277"))
AssemblyInformationalVersionAttribute;
    // [ default ] interface _AssemblyInformationalVersionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("14152cb5-dc51-3c42-8a43-09854dea1b8f"))
AssemblyFileVersionAttribute;
    // [ default ] interface _AssemblyFileVersionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("4265ab21-a68f-38a9-98d8-5d62b8035ea0"))
AssemblyCultureAttribute;
    // [ default ] interface _AssemblyCultureAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("2d0fa06f-88fd-3643-8dbc-1f428a2b1a3b"))
AssemblyVersionAttribute;
    // [ default ] interface _AssemblyVersionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("ff408450-1db9-3203-84ec-b70a01f48a06"))
AssemblyKeyFileAttribute;
    // [ default ] interface _AssemblyKeyFileAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("4804184f-4741-396b-af5b-71134937f21a"))
AssemblyDelaySignAttribute;
    // [ default ] interface _AssemblyDelaySignAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("0d052b0a-23d1-3bac-85ee-4e764b814cee"))
AssemblyAlgorithmIdAttribute;
    // [ default ] interface _AssemblyAlgorithmIdAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("4554ed74-4243-3e7c-9b33-e9a89379c4f1"))
AssemblyFlagsAttribute;
    // [ default ] interface _AssemblyFlagsAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("3dace301-6c51-3bf7-b975-e4a05f00fd4d"))
AssemblyKeyNameAttribute;
    // [ default ] interface _AssemblyKeyNameAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("b42b6aac-317e-34d5-9fa9-093bb4160c50"))
_AssemblyName : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("f12fde6a-9394-3c32-8e4d-f3d470947284"))
AssemblyName;
    // interface _Object
    // [ default ] interface _AssemblyName
    // interface ICloneable
    // interface ISerializable
    // interface IDeserializationCallback

struct __declspec(uuid("3f4a4283-6a08-3e90-a976-2c2d3be4eb0b"))
AssemblyNameProxy;
    // [ default ] interface _AssemblyNameProxy
    // interface _Object

enum __declspec(uuid("981dc77e-ce21-3753-92da-3c4a0cc7aa44"))
AssemblyNameFlags
{
    AssemblyNameFlags_None = 0,
    AssemblyNameFlags_PublicKey = 1,
    AssemblyNameFlags_EnableJITcompileOptimizer = 16384,
    AssemblyNameFlags_EnableJITcompileTracking = 32768,
    AssemblyNameFlags_Retargetable = 256
};

enum __declspec(uuid("56b1cccb-6490-396d-8c09-2257259f3caa"))
ProcessorArchitecture
{
    ProcessorArchitecture_None = 0,
    ProcessorArchitecture_MSIL = 1,
    ProcessorArchitecture_X86 = 2,
    ProcessorArchitecture_IA64 = 3,
    ProcessorArchitecture_Amd64 = 4
};

struct __declspec(uuid("d5cb383d-99f4-3c7e-a9c3-85b53661448f"))
CustomAttributeFormatException;
    // [ default ] interface _CustomAttributeFormatException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("3223e024-5d70-3236-a92a-6b4114b2632f"))
BindingFlags
{
    BindingFlags_Default = 0,
    BindingFlags_IgnoreCase = 1,
    BindingFlags_DeclaredOnly = 2,
    BindingFlags_Instance = 4,
    BindingFlags_Static = 8,
    BindingFlags_Public = 16,
    BindingFlags_NonPublic = 32,
    BindingFlags_FlattenHierarchy = 64,
    BindingFlags_InvokeMethod = 256,
    BindingFlags_CreateInstance = 512,
    BindingFlags_GetField = 1024,
    BindingFlags_SetField = 2048,
    BindingFlags_GetProperty = 4096,
    BindingFlags_SetProperty = 8192,
    BindingFlags_PutDispProperty = 16384,
    BindingFlags_PutRefDispProperty = 32768,
    BindingFlags_ExactBinding = 65536,
    BindingFlags_SuppressChangeType = 131072,
    BindingFlags_OptionalParamBinding = 262144,
    BindingFlags_IgnoreReturn = 16777216
};

enum __declspec(uuid("fd67ebe2-30de-3fbe-896b-81da2e455137"))
CallingConventions
{
    CallingConventions_Standard = 1,
    CallingConventions_VarArgs = 2,
    CallingConventions_Any = 3,
    CallingConventions_HasThis = 32,
    CallingConventions_ExplicitThis = 64
};

struct __declspec(uuid("993634c4-e47a-32cc-be08-85f567dc27d6"))
_ParameterInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("d002e9ba-d9e3-3749-b1d3-d565a08b13e7"))
_Module : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("c2655ae8-0193-35d4-855e-f64909065c1e"))
CustomAttributeData;
    // [ default ] interface _CustomAttributeData
    // interface _Object

struct __declspec(uuid("cf452b26-6040-3acb-9c72-ce5bb86e5046"))
DefaultMemberAttribute;
    // [ default ] interface _DefaultMemberAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("03c85cd9-d760-3aa8-94bd-f774407391cb"))
EventAttributes
{
    EventAttributes_None = 0,
    EventAttributes_SpecialName = 512,
    EventAttributes_ReservedMask = 1024,
    EventAttributes_RTSpecialName = 1024
};

enum __declspec(uuid("c8679e0a-1c67-3a20-8645-0d930f529031"))
FieldAttributes
{
    FieldAttributes_FieldAccessMask = 7,
    FieldAttributes_PrivateScope = 0,
    FieldAttributes_Private = 1,
    FieldAttributes_FamANDAssem = 2,
    FieldAttributes_Assembly = 3,
    FieldAttributes_Family = 4,
    FieldAttributes_FamORAssem = 5,
    FieldAttributes_Public = 6,
    FieldAttributes_Static = 16,
    FieldAttributes_InitOnly = 32,
    FieldAttributes_Literal = 64,
    FieldAttributes_NotSerialized = 128,
    FieldAttributes_SpecialName = 512,
    FieldAttributes_PinvokeImpl = 8192,
    FieldAttributes_ReservedMask = 38144,
    FieldAttributes_RTSpecialName = 1024,
    FieldAttributes_HasFieldMarshal = 4096,
    FieldAttributes_HasDefault = 32768,
    FieldAttributes_HasFieldRVA = 256
};

struct __declspec(uuid("7b938a6f-77bf-351c-a712-69483c91115d"))
InvalidFilterCriteriaException;
    // [ default ] interface _InvalidFilterCriteriaException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("f695c021-dcf5-397b-a300-edaa51da5a5b"))
ManifestResourceInfo;
    // [ default ] interface _ManifestResourceInfo
    // interface _Object

enum __declspec(uuid("e84fe360-54e3-3884-adee-7c6832dd354e"))
ResourceLocation
{
    ResourceLocation_Embedded = 1,
    ResourceLocation_ContainedInAnotherAssembly = 2,
    ResourceLocation_ContainedInManifestFile = 4
};

struct __declspec(uuid("f52fd74c-ada6-38cc-ae0f-693afb9b9a8f"))
MemberFilter;
    // [ default ] interface _MemberFilter
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

enum __declspec(uuid("513b8b77-4930-36ba-9a22-0daeb293e109"))
MemberTypes
{
    MemberTypes_Constructor = 1,
    MemberTypes_Event = 2,
    MemberTypes_Field = 4,
    MemberTypes_Method = 8,
    MemberTypes_Property = 16,
    MemberTypes_TypeInfo = 32,
    MemberTypes_Custom = 64,
    MemberTypes_NestedType = 128,
    MemberTypes_All = 191
};

enum __declspec(uuid("641ab47a-9351-3a37-81c1-647d31873f15"))
MethodAttributes
{
    MethodAttributes_MemberAccessMask = 7,
    MethodAttributes_PrivateScope = 0,
    MethodAttributes_Private = 1,
    MethodAttributes_FamANDAssem = 2,
    MethodAttributes_Assembly = 3,
    MethodAttributes_Family = 4,
    MethodAttributes_FamORAssem = 5,
    MethodAttributes_Public = 6,
    MethodAttributes_Static = 16,
    MethodAttributes_Final = 32,
    MethodAttributes_Virtual = 64,
    MethodAttributes_HideBySig = 128,
    MethodAttributes_CheckAccessOnOverride = 512,
    MethodAttributes_VtableLayoutMask = 256,
    MethodAttributes_ReuseSlot = 0,
    MethodAttributes_NewSlot = 256,
    MethodAttributes_Abstract = 1024,
    MethodAttributes_SpecialName = 2048,
    MethodAttributes_PinvokeImpl = 8192,
    MethodAttributes_UnmanagedExport = 8,
    MethodAttributes_RTSpecialName = 4096,
    MethodAttributes_ReservedMask = 53248,
    MethodAttributes_HasSecurity = 16384,
    MethodAttributes_RequireSecObject = 32768
};

enum __declspec(uuid("bcab3a5d-f2cd-3c69-841d-ad001969bf50"))
MethodImplAttributes
{
    MethodImplAttributes_CodeTypeMask = 3,
    MethodImplAttributes_IL = 0,
    MethodImplAttributes_Native = 1,
    MethodImplAttributes_OPTIL = 2,
    MethodImplAttributes_Runtime = 3,
    MethodImplAttributes_ManagedMask = 4,
    MethodImplAttributes_Unmanaged = 4,
    MethodImplAttributes_Managed = 0,
    MethodImplAttributes_ForwardRef = 16,
    MethodImplAttributes_PreserveSig = 128,
    MethodImplAttributes_InternalCall = 4096,
    MethodImplAttributes_Synchronized = 32,
    MethodImplAttributes_NoInlining = 8,
    MethodImplAttributes_MaxMethodImplVal = 65535
};

struct __declspec(uuid("d5faac26-db25-34e7-adbd-ad5ed51f9433"))
Missing;
    // [ default ] interface _Missing
    // interface _Object
    // interface ISerializable

enum __declspec(uuid("68da8301-be1b-3c22-b9f2-db8f48694ddd"))
PortableExecutableKinds
{
    PortableExecutableKinds_NotAPortableExecutableImage = 0,
    PortableExecutableKinds_ILOnly = 1,
    PortableExecutableKinds_Required32Bit = 2,
    PortableExecutableKinds_PE32Plus = 4,
    PortableExecutableKinds_Unmanaged32Bit = 8
};

enum __declspec(uuid("51191552-c65e-360d-ba21-9f0e454fd59f"))
ImageFileMachine
{
    ImageFileMachine_I386 = 332,
    ImageFileMachine_IA64 = 512,
    ImageFileMachine_AMD64 = 34404
};

struct __declspec(uuid("128191c5-b188-3054-81b7-e4f588eacf0e"))
Module;
    // interface _Object
    // [ default ] interface _Module
    // interface ISerializable
    // interface ICustomAttributeProvider

struct __declspec(uuid("d495920d-00a0-3d6f-920c-672df186cec8"))
ObfuscateAssemblyAttribute;
    // [ default ] interface _ObfuscateAssemblyAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("93d11de9-5f6c-354a-a7c5-16ccca64a9b8"))
ObfuscationAttribute;
    // [ default ] interface _ObfuscationAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("6bd98650-5ae6-3f03-b6cf-1463bbd45e6d"))
ExceptionHandlingClauseOptions
{
    ExceptionHandlingClauseOptions_Clause = 0,
    ExceptionHandlingClauseOptions_Filter = 1,
    ExceptionHandlingClauseOptions_Finally = 2,
    ExceptionHandlingClauseOptions_Fault = 4
};

struct __declspec(uuid("17ca8e14-f624-3879-94ca-6b9556a97d1f"))
ExceptionHandlingClause;
    // [ default ] interface _ExceptionHandlingClause
    // interface _Object

struct __declspec(uuid("8e2ea778-34a7-32a0-8cc2-0baa5aa2066a"))
MethodBody;
    // [ default ] interface _MethodBody
    // interface _Object

struct __declspec(uuid("14c0b634-a0e7-3e5d-be59-b2bf1a571ffc"))
LocalVariableInfo;
    // [ default ] interface _LocalVariableInfo
    // interface _Object

enum __declspec(uuid("688a6ff0-5727-32d2-8228-6e838a822616"))
ParameterAttributes
{
    ParameterAttributes_None = 0,
    ParameterAttributes_In = 1,
    ParameterAttributes_Out = 2,
    ParameterAttributes_Lcid = 4,
    ParameterAttributes_Retval = 8,
    ParameterAttributes_Optional = 16,
    ParameterAttributes_ReservedMask = 61440,
    ParameterAttributes_HasDefault = 4096,
    ParameterAttributes_HasFieldMarshal = 8192,
    ParameterAttributes_Reserved3 = 16384,
    ParameterAttributes_Reserved4 = 32768
};

struct __declspec(uuid("da295a1b-c5bd-3b34-8acd-1d7d334ffb7f"))
ISymbolWriter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Initialize (
        /*[in]*/ long emitter,
        /*[in]*/ BSTR filename,
        /*[in]*/ VARIANT_BOOL fFullBuild ) = 0;
      virtual HRESULT __stdcall DefineDocument (
        /*[in]*/ BSTR Url,
        /*[in]*/ GUID Language,
        /*[in]*/ GUID LanguageVendor,
        /*[in]*/ GUID DocumentType,
        /*[out,retval]*/ struct ISymbolDocumentWriter * * pRetVal ) = 0;
      virtual HRESULT __stdcall SetUserEntryPoint (
        /*[in]*/ struct SymbolToken entryMethod ) = 0;
      virtual HRESULT __stdcall OpenMethod (
        /*[in]*/ struct SymbolToken Method ) = 0;
      virtual HRESULT __stdcall CloseMethod ( ) = 0;
      virtual HRESULT __stdcall DefineSequencePoints (
        /*[in]*/ struct ISymbolDocumentWriter * document,
        /*[in]*/ SAFEARRAY * offsets,
        /*[in]*/ SAFEARRAY * lines,
        /*[in]*/ SAFEARRAY * columns,
        /*[in]*/ SAFEARRAY * endLines,
        /*[in]*/ SAFEARRAY * endColumns ) = 0;
      virtual HRESULT __stdcall OpenScope (
        /*[in]*/ long StartOffset,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall CloseScope (
        /*[in]*/ long EndOffset ) = 0;
      virtual HRESULT __stdcall SetScopeRange (
        /*[in]*/ long scopeID,
        /*[in]*/ long StartOffset,
        /*[in]*/ long EndOffset ) = 0;
      virtual HRESULT __stdcall DefineLocalVariable (
        /*[in]*/ BSTR name,
        /*[in]*/ enum FieldAttributes Attributes,
        /*[in]*/ SAFEARRAY * signature,
        /*[in]*/ enum SymAddressKind addrKind,
        /*[in]*/ long addr1,
        /*[in]*/ long addr2,
        /*[in]*/ long addr3,
        /*[in]*/ long StartOffset,
        /*[in]*/ long EndOffset ) = 0;
      virtual HRESULT __stdcall DefineParameter (
        /*[in]*/ BSTR name,
        /*[in]*/ enum ParameterAttributes Attributes,
        /*[in]*/ long sequence,
        /*[in]*/ enum SymAddressKind addrKind,
        /*[in]*/ long addr1,
        /*[in]*/ long addr2,
        /*[in]*/ long addr3 ) = 0;
      virtual HRESULT __stdcall DefineField (
        /*[in]*/ struct SymbolToken parent,
        /*[in]*/ BSTR name,
        /*[in]*/ enum FieldAttributes Attributes,
        /*[in]*/ SAFEARRAY * signature,
        /*[in]*/ enum SymAddressKind addrKind,
        /*[in]*/ long addr1,
        /*[in]*/ long addr2,
        /*[in]*/ long addr3 ) = 0;
      virtual HRESULT __stdcall DefineGlobalVariable (
        /*[in]*/ BSTR name,
        /*[in]*/ enum FieldAttributes Attributes,
        /*[in]*/ SAFEARRAY * signature,
        /*[in]*/ enum SymAddressKind addrKind,
        /*[in]*/ long addr1,
        /*[in]*/ long addr2,
        /*[in]*/ long addr3 ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall SetSymAttribute (
        /*[in]*/ struct SymbolToken parent,
        /*[in]*/ BSTR name,
        /*[in]*/ SAFEARRAY * data ) = 0;
      virtual HRESULT __stdcall OpenNamespace (
        /*[in]*/ BSTR name ) = 0;
      virtual HRESULT __stdcall CloseNamespace ( ) = 0;
      virtual HRESULT __stdcall UsingNamespace (
        /*[in]*/ BSTR FullName ) = 0;
      virtual HRESULT __stdcall SetMethodSourceRange (
        /*[in]*/ struct ISymbolDocumentWriter * startDoc,
        /*[in]*/ long startLine,
        /*[in]*/ long startColumn,
        /*[in]*/ struct ISymbolDocumentWriter * endDoc,
        /*[in]*/ long endLine,
        /*[in]*/ long endColumn ) = 0;
      virtual HRESULT __stdcall SetUnderlyingWriter (
        /*[in]*/ long underlyingWriter ) = 0;
};

#pragma pack(push, 4)

struct __declspec(uuid("11d31042-14c0-3b5c-87d0-a2cd40803cb5"))
ParameterModifier
{
    SAFEARRAY * _byRef;
};

#pragma pack(pop)

struct __declspec(uuid("0517463e-1139-3970-bfa9-dcc997b23e7c"))
Pointer;
    // [ default ] interface _Pointer
    // interface _Object
    // interface ISerializable

enum __declspec(uuid("816c979c-d3d2-3101-b5ca-e4a5c5e966fa"))
PropertyAttributes
{
    PropertyAttributes_None = 0,
    PropertyAttributes_SpecialName = 512,
    PropertyAttributes_ReservedMask = 62464,
    PropertyAttributes_RTSpecialName = 1024,
    PropertyAttributes_HasDefault = 4096,
    PropertyAttributes_Reserved2 = 8192,
    PropertyAttributes_Reserved3 = 16384,
    PropertyAttributes_Reserved4 = 32768
};

struct __declspec(uuid("843b19ad-a02b-3852-ac56-fdc798935630"))
ReflectionTypeLoadException;
    // [ default ] interface _ReflectionTypeLoadException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("d89e7f8e-9f99-3ee9-8fce-d97e64c8650e"))
ResourceAttributes
{
    ResourceAttributes_Public = 1,
    ResourceAttributes_Private = 2
};

struct __declspec(uuid("d633f013-0563-312a-b9d6-d067a7d59231"))
StrongNameKeyPair;
    // [ default ] interface _StrongNameKeyPair
    // interface _Object
    // interface IDeserializationCallback
    // interface ISerializable

struct __declspec(uuid("0d23f8b4-f2a6-3eff-9d37-bdf79ac6b440"))
TargetException;
    // [ default ] interface _TargetException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("03d016e3-cae1-3068-880e-af8d08d517f0"))
TargetInvocationException;
    // [ default ] interface _TargetInvocationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("da317be2-1a0d-37b3-83f2-a0f32787fc67"))
TargetParameterCountException;
    // [ default ] interface _TargetParameterCountException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("28ee6224-fd72-3bdf-b248-ba9102fceb14"))
TypeAttributes
{
    TypeAttributes_VisibilityMask = 7,
    TypeAttributes_NotPublic = 0,
    TypeAttributes_Public = 1,
    TypeAttributes_NestedPublic = 2,
    TypeAttributes_NestedPrivate = 3,
    TypeAttributes_NestedFamily = 4,
    TypeAttributes_NestedAssembly = 5,
    TypeAttributes_NestedFamANDAssem = 6,
    TypeAttributes_NestedFamORAssem = 7,
    TypeAttributes_LayoutMask = 24,
    TypeAttributes_AutoLayout = 0,
    TypeAttributes_SequentialLayout = 8,
    TypeAttributes_ExplicitLayout = 16,
    TypeAttributes_ClassSemanticsMask = 32,
    TypeAttributes_Class = 0,
    TypeAttributes_Interface = 32,
    TypeAttributes_Abstract = 128,
    TypeAttributes_Sealed = 256,
    TypeAttributes_SpecialName = 1024,
    TypeAttributes_Import = 4096,
    TypeAttributes_Serializable = 8192,
    TypeAttributes_StringFormatMask = 196608,
    TypeAttributes_AnsiClass = 0,
    TypeAttributes_UnicodeClass = 65536,
    TypeAttributes_AutoClass = 131072,
    TypeAttributes_CustomFormatClass = 196608,
    TypeAttributes_CustomFormatMask = 12582912,
    TypeAttributes_BeforeFieldInit = 1048576,
    TypeAttributes_ReservedMask = 264192,
    TypeAttributes_RTSpecialName = 2048,
    TypeAttributes_HasSecurity = 262144
};

struct __declspec(uuid("19e2e2f7-b53c-366b-8840-aba2f8cb98b5"))
TypeDelegator;
    // [ default ] interface _TypeDelegator
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _Type
    // interface IReflect

struct __declspec(uuid("37e24f25-5ef0-366f-9d0f-f7b9e3edffd9"))
TypeFilter;
    // [ default ] interface _TypeFilter
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("ca308c9f-3b97-3152-acfa-8ab23c17df73"))
MethodBase;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // [ default ] interface _MethodBase

struct __declspec(uuid("0a541f87-ebd7-36a0-9a7d-9bbf86188766"))
ConstructorInfo;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _MethodBase
    // [ default ] interface _ConstructorInfo

struct __declspec(uuid("0e22cc27-ca1e-3138-9640-be831f721659"))
MethodInfo;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _MethodBase
    // [ default ] interface _MethodInfo

struct __declspec(uuid("98ba57dc-4cf2-3ed1-b4a2-890c21bbbf4b"))
FieldInfo;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // [ default ] interface _FieldInfo

struct __declspec(uuid("15762ca5-bc5c-3b86-a450-acf32fc98aa5"))
EventInfo;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // [ default ] interface _EventInfo

struct __declspec(uuid("bfdf1f57-230d-394a-b773-d9ec58cbef9a"))
PropertyInfo;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // [ default ] interface _PropertyInfo

struct __declspec(uuid("e5ce8078-0ca7-3578-80db-f20fca8786a6"))
ParameterInfo;
    // interface _Object
    // [ default ] interface _ParameterInfo
    // interface ICustomAttributeProvider

struct __declspec(uuid("e6854c08-0666-3939-bdf1-e1555a2c49fa"))
Formatter;
    // [ default ] interface _Formatter
    // interface _Object
    // interface IFormatter

struct __declspec(uuid("d23d2f41-1d69-3e03-a275-32ae381223ac"))
FormatterConverter;
    // [ default ] interface _FormatterConverter
    // interface _Object
    // interface IFormatterConverter

struct __declspec(uuid("688c32ea-1e9c-3a4b-90e0-a4d2a1d73f3f"))
FormatterServices;
    // [ default ] interface _FormatterServices
    // interface _Object

struct __declspec(uuid("4f272c37-f0a8-350c-867b-2c03b2b16b80"))
ObjectIDGenerator;
    // [ default ] interface _ObjectIDGenerator
    // interface _Object

struct __declspec(uuid("c3a27c9a-5f79-3b7a-963d-39b1e5202b55"))
ObjectManager;
    // [ default ] interface _ObjectManager
    // interface _Object

struct __declspec(uuid("1c97ef1d-74ed-3d21-84a4-8631d959634a"))
OptionalFieldAttribute;
    // [ default ] interface _OptionalFieldAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("9bf86f6e-b0e1-348b-9627-6970672eb3d3"))
OnSerializingAttribute;
    // [ default ] interface _OnSerializingAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("6f8527bf-5aad-3236-b639-a05177332efe"))
OnSerializedAttribute;
    // [ default ] interface _OnSerializedAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("30ac0b94-3bdb-3199-8a5d-eca0c5458381"))
OnDeserializingAttribute;
    // [ default ] interface _OnDeserializingAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("18b1c7ee-68e3-35bb-9e40-469a223285f7"))
OnDeserializedAttribute;
    // [ default ] interface _OnDeserializedAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("25d97db7-bdc3-3205-b86b-956b852ece76"))
SerializationBinder;
    // [ default ] interface _SerializationBinder
    // interface _Object

struct __declspec(uuid("d69398c1-7541-33e7-b544-a803f380ffb6"))
SerializationInfo;
    // [ default ] interface _SerializationInfo
    // interface _Object

struct __declspec(uuid("341ba870-b7fe-3cbc-9a72-b7894c6ec171"))
SerializationInfoEnumerator;
    // [ default ] interface _SerializationInfoEnumerator
    // interface _Object
    // interface IEnumerator

struct __declspec(uuid("57154c7c-edb2-3bfd-a8ba-924c60913ebf"))
SerializationException;
    // [ default ] interface _SerializationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("78304e50-a1e6-3d84-a718-49020681e02e"))
StreamingContextStates
{
    StreamingContextStates_CrossProcess = 1,
    StreamingContextStates_CrossMachine = 2,
    StreamingContextStates_File = 4,
    StreamingContextStates_Persistence = 8,
    StreamingContextStates_Remoting = 16,
    StreamingContextStates_Other = 32,
    StreamingContextStates_Clone = 64,
    StreamingContextStates_CrossAppDomain = 128,
    StreamingContextStates_All = 255
};

#pragma pack(push, 4)

struct __declspec(uuid("79179aa0-e14c-35ea-a666-66be968af69f"))
StreamingContext
{
    IUnknown * m_additionalContext;
    enum StreamingContextStates m_state;
};

#pragma pack(pop)

struct __declspec(uuid("6e70ed5f-0439-38ce-83bb-860f1421f29f"))
IObjectReference : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetRealObject (
        /*[in]*/ struct StreamingContext Context,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("88c8a919-eb24-3cca-84f7-2ea82bb3f3ed"))
SurrogateSelector;
    // [ default ] interface _SurrogateSelector
    // interface _Object
    // interface ISurrogateSelector

struct __declspec(uuid("8a93390f-4331-317f-b450-1e0e4914e335"))
Calendar;
    // [ default ] interface _Calendar
    // interface _Object
    // interface ICloneable

enum __declspec(uuid("f680a48a-2d6c-33f1-aff7-6273b785b035"))
CalendarAlgorithmType
{
    CalendarAlgorithmType_Unknown = 0,
    CalendarAlgorithmType_SolarCalendar = 1,
    CalendarAlgorithmType_LunarCalendar = 2,
    CalendarAlgorithmType_LunisolarCalendar = 3
};

enum __declspec(uuid("117d12e1-4d32-3326-b23e-57d4fe34a527"))
CalendarWeekRule
{
    CalendarWeekRule_FirstDay = 0,
    CalendarWeekRule_FirstFullWeek = 1,
    CalendarWeekRule_FirstFourDayWeek = 2
};

struct __declspec(uuid("47ff8f5e-f989-39ff-a985-898bf36109bd"))
EastAsianLunisolarCalendar;
    // [ default ] interface _EastAsianLunisolarCalendar
    // interface _Object
    // interface ICloneable

enum __declspec(uuid("fdbf0369-d278-3320-b9ce-0e0719380c0f"))
CompareOptions
{
    CompareOptions_None = 0,
    CompareOptions_IgnoreCase = 1,
    CompareOptions_IgnoreNonSpace = 2,
    CompareOptions_IgnoreSymbols = 4,
    CompareOptions_IgnoreKanaType = 8,
    CompareOptions_IgnoreWidth = 16,
    CompareOptions_OrdinalIgnoreCase = 268435456,
    CompareOptions_StringSort = 536870912,
    CompareOptions_Ordinal = 1073741824
};

struct __declspec(uuid("6747ff61-f8da-3689-bb01-47f2266ae261"))
CompareInfo;
    // [ default ] interface _CompareInfo
    // interface _Object
    // interface IDeserializationCallback

struct __declspec(uuid("348a8c6d-464a-3f21-856b-061370d54599"))
CultureInfo;
    // [ default ] interface _CultureInfo
    // interface _Object
    // interface ICloneable
    // interface IFormatProvider

enum __declspec(uuid("ab8e1300-f46a-3ffd-bcef-a45de1c55458"))
CultureTypes
{
    CultureTypes_NeutralCultures = 1,
    CultureTypes_SpecificCultures = 2,
    CultureTypes_InstalledWin32Cultures = 4,
    CultureTypes_AllCultures = 7,
    CultureTypes_UserCustomCulture = 8,
    CultureTypes_ReplacementCultures = 16,
    CultureTypes_WindowsOnlyCultures = 32,
    CultureTypes_FrameworkCultures = 64
};

enum __declspec(uuid("f62ff05f-99ce-30db-8344-2b2c26f5765c"))
DateTimeStyles
{
    DateTimeStyles_None = 0,
    DateTimeStyles_AllowLeadingWhite = 1,
    DateTimeStyles_AllowTrailingWhite = 2,
    DateTimeStyles_AllowInnerWhite = 4,
    DateTimeStyles_AllowWhiteSpaces = 7,
    DateTimeStyles_NoCurrentDateDefault = 8,
    DateTimeStyles_AdjustToUniversal = 16,
    DateTimeStyles_AssumeLocal = 32,
    DateTimeStyles_AssumeUniversal = 64,
    DateTimeStyles_RoundTripKind = 128
};

struct __declspec(uuid("70a738d1-1bc5-3175-bd42-603e2b82c08b"))
DateTimeFormatInfo;
    // [ default ] interface _DateTimeFormatInfo
    // interface _Object
    // interface ICloneable
    // interface IFormatProvider

struct __declspec(uuid("5050fe97-72a6-3bc6-92f2-9dd0413041e3"))
DaylightTime;
    // [ default ] interface _DaylightTime
    // interface _Object

enum __declspec(uuid("a2d18600-d187-399c-b2ed-6fa8ed5d2a59"))
DigitShapes
{
    DigitShapes_Context = 0,
    DigitShapes_None = 1,
    DigitShapes_NativeNational = 2
};

struct __declspec(uuid("68f8aea9-1968-35b9-8a0e-6fdc637a4f8e"))
GregorianCalendar;
    // [ default ] interface _GregorianCalendar
    // interface _Object
    // interface ICloneable

enum __declspec(uuid("d535a40b-83c0-36fc-82d1-7ef2de252ecc"))
GregorianCalendarTypes
{
    GregorianCalendarTypes_Localized = 1,
    GregorianCalendarTypes_USEnglish = 2,
    GregorianCalendarTypes_MiddleEastFrench = 9,
    GregorianCalendarTypes_Arabic = 10,
    GregorianCalendarTypes_TransliteratedEnglish = 11,
    GregorianCalendarTypes_TransliteratedFrench = 12
};

struct __declspec(uuid("2206d773-ca1c-3258-9456-ceb7706c3710"))
HebrewCalendar;
    // [ default ] interface _HebrewCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("ee832ce3-06ca-33ef-8f01-61c7c218bd7e"))
HijriCalendar;
    // [ default ] interface _HijriCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("374050dd-6190-3257-8812-8230bf095147"))
JapaneseCalendar;
    // [ default ] interface _JapaneseCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("5c3e6ce8-b218-3762-883c-91bc987cdc2d"))
JulianCalendar;
    // [ default ] interface _JulianCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("1a06a4dc-e239-3717-89e1-d0683f3a5320"))
KoreanCalendar;
    // [ default ] interface _KoreanCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("0c630393-7583-333c-ab5d-cb10b910f69b"))
RegionInfo;
    // [ default ] interface _RegionInfo
    // interface _Object

struct __declspec(uuid("f34b5293-82d0-32a5-9165-ae789fd3cf15"))
SortKey;
    // [ default ] interface _SortKey
    // interface _Object

struct __declspec(uuid("31c967b5-2f8a-3957-9c6d-34a0731db36c"))
StringInfo;
    // [ default ] interface _StringInfo
    // interface _Object

struct __declspec(uuid("769b8b68-64f7-3b61-b744-160a9fcc3216"))
TaiwanCalendar;
    // [ default ] interface _TaiwanCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("4c96da7c-8858-3c24-a973-cb50f2860a91"))
TextElementEnumerator;
    // [ default ] interface _TextElementEnumerator
    // interface _Object
    // interface IEnumerator

struct __declspec(uuid("bca1528c-6369-37ad-8cc1-db24a92cc6b1"))
TextInfo;
    // [ default ] interface _TextInfo
    // interface _Object
    // interface ICloneable
    // interface IDeserializationCallback

struct __declspec(uuid("ec3dac94-df80-3017-b381-b13dced6c4d8"))
ThaiBuddhistCalendar;
    // [ default ] interface _ThaiBuddhistCalendar
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("146a47ab-a2cf-3587-bb25-2b286d7566b4"))
NumberFormatInfo;
    // [ default ] interface _NumberFormatInfo
    // interface _Object
    // interface ICloneable
    // interface IFormatProvider

enum __declspec(uuid("00d1aca9-41f2-3340-816e-330175414a56"))
NumberStyles
{
    NumberStyles_None = 0,
    NumberStyles_AllowLeadingWhite = 1,
    NumberStyles_AllowTrailingWhite = 2,
    NumberStyles_AllowLeadingSign = 4,
    NumberStyles_AllowTrailingSign = 8,
    NumberStyles_AllowParentheses = 16,
    NumberStyles_AllowDecimalPoint = 32,
    NumberStyles_AllowThousands = 64,
    NumberStyles_AllowExponent = 128,
    NumberStyles_AllowCurrencySymbol = 256,
    NumberStyles_AllowHexSpecifier = 512,
    NumberStyles_Integer = 7,
    NumberStyles_HexNumber = 515,
    NumberStyles_Number = 111,
    NumberStyles_Float = 167,
    NumberStyles_Currency = 383,
    NumberStyles_Any = 511
};

enum __declspec(uuid("299e2a7d-6551-3ed1-b4a0-a51cb56eefe7"))
UnicodeCategory
{
    UnicodeCategory_UppercaseLetter = 0,
    UnicodeCategory_LowercaseLetter = 1,
    UnicodeCategory_TitlecaseLetter = 2,
    UnicodeCategory_ModifierLetter = 3,
    UnicodeCategory_OtherLetter = 4,
    UnicodeCategory_NonSpacingMark = 5,
    UnicodeCategory_SpacingCombiningMark = 6,
    UnicodeCategory_EnclosingMark = 7,
    UnicodeCategory_DecimalDigitNumber = 8,
    UnicodeCategory_LetterNumber = 9,
    UnicodeCategory_OtherNumber = 10,
    UnicodeCategory_SpaceSeparator = 11,
    UnicodeCategory_LineSeparator = 12,
    UnicodeCategory_ParagraphSeparator = 13,
    UnicodeCategory_Control = 14,
    UnicodeCategory_Format = 15,
    UnicodeCategory_Surrogate = 16,
    UnicodeCategory_PrivateUse = 17,
    UnicodeCategory_ConnectorPunctuation = 18,
    UnicodeCategory_DashPunctuation = 19,
    UnicodeCategory_OpenPunctuation = 20,
    UnicodeCategory_ClosePunctuation = 21,
    UnicodeCategory_InitialQuotePunctuation = 22,
    UnicodeCategory_FinalQuotePunctuation = 23,
    UnicodeCategory_OtherPunctuation = 24,
    UnicodeCategory_MathSymbol = 25,
    UnicodeCategory_CurrencySymbol = 26,
    UnicodeCategory_ModifierSymbol = 27,
    UnicodeCategory_OtherSymbol = 28,
    UnicodeCategory_OtherNotAssigned = 29
};

struct __declspec(uuid("eaecc459-5ce4-35a2-a085-5afc0451c03a"))
Encoding;
    // [ default ] interface _Encoding
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("cc9d4538-57e8-3a82-886a-5fe65a127a5a"))
Encoder;
    // [ default ] interface _Encoder
    // interface _Object

struct __declspec(uuid("a924269d-5df2-33af-b72a-3250c4105ebe"))
Decoder;
    // [ default ] interface _Decoder
    // interface _Object

struct __declspec(uuid("9e28ef95-9c6f-3a00-b525-36a76178cc9c"))
ASCIIEncoding;
    // [ default ] interface _ASCIIEncoding
    // interface _Object
    // interface ICloneable

enum __declspec(uuid("b38da717-d61b-3c13-93ce-2b9370d0ae43"))
NormalizationForm
{
    NormalizationForm_FormC = 1,
    NormalizationForm_FormD = 2,
    NormalizationForm_FormKC = 5,
    NormalizationForm_FormKD = 6
};

struct __declspec(uuid("a0f5f5dc-337b-38d7-b1a3-fb1b95666bbf"))
UnicodeEncoding;
    // [ default ] interface _UnicodeEncoding
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("3c9dca8b-4410-3143-b801-559553eb6725"))
UTF7Encoding;
    // [ default ] interface _UTF7Encoding
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("8c40d44a-4ede-3760-9b61-50255056d3c7"))
UTF8Encoding;
    // [ default ] interface _UTF8Encoding
    // interface _Object
    // interface ICloneable

struct __declspec(uuid("8965a22f-fba8-36ad-8132-70bbd0da457d"))
IResourceReader : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall GetEnumerator (
        /*[out,retval]*/ struct IDictionaryEnumerator * * pRetVal ) = 0;
};

struct __declspec(uuid("e97aa6e5-595e-31c3-82f0-688fb91954c6"))
IResourceWriter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddResource (
        /*[in]*/ BSTR name,
        /*[in]*/ BSTR value ) = 0;
      virtual HRESULT __stdcall AddResource_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall AddResource_3 (
        /*[in]*/ BSTR name,
        /*[in]*/ SAFEARRAY * value ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall Generate ( ) = 0;
};

struct __declspec(uuid("726bbdf4-6c6d-30f4-b3a0-f14d6aec08c7"))
MissingManifestResourceException;
    // [ default ] interface _MissingManifestResourceException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("d41969a6-c394-34b9-bd24-dd408f39f261"))
MissingSatelliteAssemblyException;
    // [ default ] interface _MissingSatelliteAssemblyException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("87797538-6bae-366a-a9bc-012c8f62ea44"))
NeutralResourcesLanguageAttribute;
    // [ default ] interface _NeutralResourcesLanguageAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("9afb3b93-e6da-35d6-b9fe-44815e2bfd45"))
ResourceManager;
    // [ default ] interface _ResourceManager
    // interface _Object

struct __declspec(uuid("dd78b5ed-aa52-3b2b-a1b4-6ce3ce3155ea"))
ResourceReader;
    // [ default ] interface _ResourceReader
    // interface _Object
    // interface IResourceReader
    // interface IEnumerable
    // interface IDisposable

struct __declspec(uuid("a907f7cd-8c99-31ea-ac00-80fa4d94780a"))
ResourceSet;
    // [ default ] interface _ResourceSet
    // interface _Object
    // interface IDisposable
    // interface IEnumerable

struct __declspec(uuid("9187a0d6-508c-36cc-a79f-f90b89a0e154"))
ResourceWriter;
    // [ default ] interface _ResourceWriter
    // interface _Object
    // interface IResourceWriter
    // interface IDisposable

struct __declspec(uuid("f4ae34f8-6ce4-32dc-96ba-9c7a0a9c6d06"))
SatelliteContractVersionAttribute;
    // [ default ] interface _SatelliteContractVersionAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("2173568c-6edc-392b-880a-cc158d7e2bda"))
UltimateResourceFallbackLocation
{
    UltimateResourceFallbackLocation_MainAssembly = 0,
    UltimateResourceFallbackLocation_Satellite = 1
};

struct __declspec(uuid("9b4ef4fa-742e-3878-953a-474999711087"))
Registry;
    // [ default ] interface _Registry
    // interface _Object

enum __declspec(uuid("b3b46869-c190-3199-96da-4006e2ac6e72"))
RegistryHive
{
    RegistryHive_ClassesRoot = 0x80000000,
    RegistryHive_CurrentUser = -2147483647,
    RegistryHive_LocalMachine = -2147483646,
    RegistryHive_Users = -2147483645,
    RegistryHive_PerformanceData = -2147483644,
    RegistryHive_CurrentConfig = -2147483643,
    RegistryHive_DynData = -2147483642
};

struct __declspec(uuid("2c8fa9bd-cbe4-3223-b592-41b5a22fb820"))
RegistryKey;
    // [ default ] interface _RegistryKey
    // interface _Object
    // interface IDisposable

enum __declspec(uuid("62ecb562-b92a-37e7-8d5b-84036a1a4348"))
RegistryValueKind
{
    RegistryValueKind_String = 1,
    RegistryValueKind_ExpandString = 2,
    RegistryValueKind_Binary = 3,
    RegistryValueKind_DWord = 4,
    RegistryValueKind_MultiString = 7,
    RegistryValueKind_QWord = 11,
    RegistryValueKind_Unknown = 0
};

struct __declspec(uuid("06b81c12-a5da-340d-aff7-fa1453fbc29a"))
AllMembershipCondition;
    // [ default ] interface _AllMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("720bf501-75aa-39f3-b6c2-eabe2f47cee5"))
ApplicationDirectory;
    // [ default ] interface _ApplicationDirectory
    // interface _Object

struct __declspec(uuid("3ddb2114-9285-30a6-906d-b117640ca927"))
ApplicationDirectoryMembershipCondition;
    // [ default ] interface _ApplicationDirectoryMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("80472d32-ef68-3988-be44-bd9e336d4df8"))
ApplicationSecurityInfo;
    // [ default ] interface _ApplicationSecurityInfo
    // interface _Object

struct __declspec(uuid("2fb9ac2a-8724-32d0-98fa-218c1b2b3e1d"))
ApplicationSecurityManager;
    // [ default ] interface _ApplicationSecurityManager
    // interface _Object

enum __declspec(uuid("d93eaca8-8176-387b-9667-6d32b504047b"))
ApplicationVersionMatch
{
    ApplicationVersionMatch_MatchExactVersion = 0,
    ApplicationVersionMatch_MatchAllVersions = 1
};

struct __declspec(uuid("a5448b7a-aa07-3c56-b42b-7d881fa10934"))
ApplicationTrust;
    // [ default ] interface _ApplicationTrust
    // interface _Object
    // interface ISecurityEncodable

struct __declspec(uuid("45cd6d50-a8b4-3783-9759-445fc3d4731c"))
ApplicationTrustCollection;
    // [ default ] interface _ApplicationTrustCollection
    // interface _Object
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("128ba7d4-e68f-3223-85be-7372d0fb5423"))
ApplicationTrustEnumerator;
    // [ default ] interface _ApplicationTrustEnumerator
    // interface _Object
    // interface IEnumerator

struct __declspec(uuid("05c4d71e-fb7d-30be-b6b4-1df8999ceee1"))
CodeGroup;
    // [ default ] interface _CodeGroup
    // interface _Object

struct __declspec(uuid("62545937-20a9-3d0f-b04b-322e854eacb0"))
Evidence;
    // [ default ] interface _Evidence
    // interface _Object
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("3f8d7e3a-24e7-3f7c-9dc5-4ca22ee7c782"))
FileCodeGroup;
    // [ default ] interface _FileCodeGroup
    // interface _Object

struct __declspec(uuid("28635cc7-4c39-3779-8c31-839101001f78"))
FirstMatchCodeGroup;
    // [ default ] interface _FirstMatchCodeGroup
    // interface _Object

enum __declspec(uuid("940b1725-f706-3cef-9586-0f189b117c20"))
TrustManagerUIContext
{
    TrustManagerUIContext_Install = 0,
    TrustManagerUIContext_Upgrade = 1,
    TrustManagerUIContext_Run = 2
};

struct __declspec(uuid("afaef10f-1bc4-351f-886a-878a265c1862"))
TrustManagerContext;
    // [ default ] interface _TrustManagerContext
    // interface _Object

struct __declspec(uuid("e7473f93-eccf-38ed-9285-e93cd2d27608"))
CodeConnectAccess;
    // [ default ] interface _CodeConnectAccess
    // interface _Object

struct __declspec(uuid("a601b6b7-422d-3b21-a61c-a77c5512f36a"))
NetCodeGroup;
    // [ default ] interface _NetCodeGroup
    // interface _Object

struct __declspec(uuid("e1c3e338-b088-3c69-9989-a0e59e96fea8"))
PermissionRequestEvidence;
    // [ default ] interface _PermissionRequestEvidence
    // interface _Object

struct __declspec(uuid("89d26277-8408-3fc8-bd44-cf5f0e614c82"))
PolicyException;
    // [ default ] interface _PolicyException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("64e304c1-d80d-3388-94ef-002f45d5ac05"))
PolicyLevel;
    // [ default ] interface _PolicyLevel
    // interface _Object

enum __declspec(uuid("338d2529-b3d6-37f1-bb01-404698dc537b"))
PolicyStatementAttribute
{
    PolicyStatementAttribute_Nothing = 0,
    PolicyStatementAttribute_Exclusive = 1,
    PolicyStatementAttribute_LevelFinal = 2,
    PolicyStatementAttribute_All = 3
};

struct __declspec(uuid("abcc3df5-7e59-3780-a3cc-4f412008a5ea"))
PolicyStatement;
    // [ default ] interface _PolicyStatement
    // interface _Object
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("0f71b36d-4006-35b5-9f42-4c468514af70"))
Site;
    // [ default ] interface _Site
    // interface _Object
    // interface IIdentityPermissionFactory

struct __declspec(uuid("7f5e4fd8-9575-3691-bf0c-2d30a21e4376"))
SiteMembershipCondition;
    // [ default ] interface _SiteMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("f1566aaf-63fe-3f4b-b121-dcd17999119b"))
StrongName;
    // [ default ] interface _StrongName
    // interface _Object
    // interface IIdentityPermissionFactory

struct __declspec(uuid("7cffac1c-7370-30f9-aa72-e30fe39257d9"))
StrongNameMembershipCondition;
    // [ default ] interface _StrongNameMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("f424d0be-f3cb-3d09-9b18-c523a739ebfe"))
UnionCodeGroup;
    // [ default ] interface _UnionCodeGroup
    // interface _Object

struct __declspec(uuid("7a2ae0c8-ef79-334e-bacf-d7ba452caf7c"))
Url;
    // [ default ] interface _Url
    // interface _Object
    // interface IIdentityPermissionFactory

struct __declspec(uuid("93e33d56-812d-3112-beeb-276a67d1172e"))
UrlMembershipCondition;
    // [ default ] interface _UrlMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("6fcf98ff-b4d6-37a4-9dab-4de11a5fe5f2"))
Zone;
    // [ default ] interface _Zone
    // interface _Object
    // interface IIdentityPermissionFactory

struct __declspec(uuid("d72f9aeb-23f8-3b88-b6fd-8a143e3245a1"))
ZoneMembershipCondition;
    // [ default ] interface _ZoneMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("ee24a2c3-3aa2-33da-8731-a4fcc1105813"))
GacInstalled;
    // [ default ] interface _GacInstalled
    // interface _Object
    // interface IIdentityPermissionFactory

struct __declspec(uuid("390e92c9-fa66-3357-bef2-45a1f34186b9"))
GacMembershipCondition;
    // [ default ] interface _GacMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("260356e2-bafa-3349-8bf7-86eeb460a2c7"))
Hash;
    // [ default ] interface _Hash
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("769edead-e3b2-3c89-b9a6-948cd7288587"))
HashMembershipCondition;
    // [ default ] interface _HashMembershipCondition
    // interface _Object
    // interface ISerializable
    // interface IDeserializationCallback
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("649546a7-965f-366f-a735-0fb522917b5a"))
Publisher;
    // [ default ] interface _Publisher
    // interface _Object
    // interface IIdentityPermissionFactory

struct __declspec(uuid("05bf00f9-44b8-39a7-af36-7e11c9b502dd"))
PublisherMembershipCondition;
    // [ default ] interface _PublisherMembershipCondition
    // interface _Object
    // interface IMembershipCondition
    // interface ISecurityEncodable
    // interface ISecurityPolicyEncodable

struct __declspec(uuid("f4205a87-4d46-303d-b1d9-5a99f7c90d30"))
IIdentity : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AuthenticationType (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAuthenticated (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("4c534a8e-3c46-3745-bdae-5119c40f98e7"))
GenericIdentity;
    // [ default ] interface _GenericIdentity
    // interface _Object
    // interface IIdentity

struct __declspec(uuid("4283ca6c-d291-3481-83c9-9554481fe888"))
IPrincipal : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Identity (
        /*[out,retval]*/ struct IIdentity * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsInRole (
        /*[in]*/ BSTR role,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("2eacb710-fe48-3c13-8145-e810792c58a2"))
GenericPrincipal;
    // [ default ] interface _GenericPrincipal
    // interface _Object
    // interface IPrincipal

enum __declspec(uuid("7d29bc4b-8fbc-38aa-8b35-ed4539a1cf8e"))
PrincipalPolicy
{
    PrincipalPolicy_UnauthenticatedPrincipal = 0,
    PrincipalPolicy_NoPrincipal = 1,
    PrincipalPolicy_WindowsPrincipal = 2
};

enum __declspec(uuid("8830f669-e622-3da0-bc37-4a02a151e142"))
WindowsAccountType
{
    WindowsAccountType_Normal = 0,
    WindowsAccountType_Guest = 1,
    WindowsAccountType_System = 2,
    WindowsAccountType_Anonymous = 3
};

enum __declspec(uuid("3e82fb4a-7f30-35b7-b8b1-6d717b3b5db0"))
TokenImpersonationLevel
{
    TokenImpersonationLevel_None = 0,
    TokenImpersonationLevel_Anonymous = 1,
    TokenImpersonationLevel_Identification = 2,
    TokenImpersonationLevel_Impersonation = 3,
    TokenImpersonationLevel_Delegation = 4
};

enum __declspec(uuid("10a8b906-2f7a-327c-87ab-1a95a9b5e23e"))
TokenAccessLevels
{
    TokenAccessLevels_AssignPrimary = 1,
    TokenAccessLevels_Duplicate = 2,
    TokenAccessLevels_Impersonate = 4,
    TokenAccessLevels_Query = 8,
    TokenAccessLevels_QuerySource = 16,
    TokenAccessLevels_AdjustPrivileges = 32,
    TokenAccessLevels_AdjustGroups = 64,
    TokenAccessLevels_AdjustDefault = 128,
    TokenAccessLevels_AdjustSessionId = 256,
    TokenAccessLevels_Read = 131080,
    TokenAccessLevels_Write = 131296,
    TokenAccessLevels_AllAccess = 983551,
    TokenAccessLevels_MaximumAllowed = 33554432
};

struct __declspec(uuid("70c7cec2-5bb2-3770-a26e-fc180c81f4fe"))
WindowsIdentity;
    // [ default ] interface _WindowsIdentity
    // interface _Object
    // interface IIdentity
    // interface ISerializable
    // interface IDeserializationCallback
    // interface IDisposable

struct __declspec(uuid("fc1abb5c-d107-3145-908a-3ea107d53748"))
WindowsImpersonationContext;
    // [ default ] interface _WindowsImpersonationContext
    // interface _Object
    // interface IDisposable

enum __declspec(uuid("8b7e18b8-3e96-3a4c-82cb-3d13fa15a32f"))
WindowsBuiltInRole
{
    WindowsBuiltInRole_Administrator = 544,
    WindowsBuiltInRole_User = 545,
    WindowsBuiltInRole_Guest = 546,
    WindowsBuiltInRole_PowerUser = 547,
    WindowsBuiltInRole_AccountOperator = 548,
    WindowsBuiltInRole_SystemOperator = 549,
    WindowsBuiltInRole_PrintOperator = 550,
    WindowsBuiltInRole_BackupOperator = 551,
    WindowsBuiltInRole_Replicator = 552
};

struct __declspec(uuid("138887db-c015-3254-b05a-d15616bf9aee"))
WindowsPrincipal;
    // [ default ] interface _WindowsPrincipal
    // interface _Object
    // interface IPrincipal

#pragma pack(push, 4)

struct __declspec(uuid("8351108f-34e3-3cc9-bf5a-c76c48060835"))
ArrayWithOffset
{
    IUnknown * m_array;
    long m_offset;
    long m_count;
};

#pragma pack(pop)

struct __declspec(uuid("1a8e1b1f-ef9e-33e6-950e-4d9435f1335b"))
UnmanagedFunctionPointerAttribute;
    // [ default ] interface _UnmanagedFunctionPointerAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("b36860b2-bac3-3c25-81ee-1f62cb91fc76"))
DispIdAttribute;
    // [ default ] interface _DispIdAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("18c327e4-e4ba-3c3c-9942-274272626278"))
ComInterfaceType
{
    ComInterfaceType_InterfaceIsDual = 0,
    ComInterfaceType_InterfaceIsIUnknown = 1,
    ComInterfaceType_InterfaceIsIDispatch = 2
};

struct __declspec(uuid("c8a36b3c-bc72-31e7-8ba2-ef949a54bd0c"))
InterfaceTypeAttribute;
    // [ default ] interface _InterfaceTypeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("43c2214a-95fc-362d-a792-7316c65b49aa"))
ComDefaultInterfaceAttribute;
    // [ default ] interface _ComDefaultInterfaceAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("d58dc4bb-3a4c-3b0c-b75f-9d0876694f3d"))
ClassInterfaceType
{
    ClassInterfaceType_None = 0,
    ClassInterfaceType_AutoDispatch = 1,
    ClassInterfaceType_AutoDual = 2
};

struct __declspec(uuid("5819db84-163f-3fa2-853b-43a0269626b1"))
ClassInterfaceAttribute;
    // [ default ] interface _ClassInterfaceAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("1f4bcc99-e9d8-3aab-99af-4d1ec26e3376"))
ComVisibleAttribute;
    // [ default ] interface _ComVisibleAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("a09b7b15-dfa5-3e98-9c26-865ad9079e42"))
TypeLibImportClassAttribute;
    // [ default ] interface _TypeLibImportClassAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("f912451b-8766-32cd-917f-3b9fee4421a8"))
LCIDConversionAttribute;
    // [ default ] interface _LCIDConversionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("630a3ef1-23c6-31fe-9d25-294e3b3e7486"))
ComRegisterFunctionAttribute;
    // [ default ] interface _ComRegisterFunctionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("8f45c7ff-1e6e-34c1-a7cc-260985392a05"))
ComUnregisterFunctionAttribute;
    // [ default ] interface _ComUnregisterFunctionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("47854ae8-f71c-3459-a943-1e91edc951a7"))
ProgIdAttribute;
    // [ default ] interface _ProgIdAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("8afeaa55-757f-3ddb-a750-b2caa6a0b80b"))
ImportedFromTypeLibAttribute;
    // [ default ] interface _ImportedFromTypeLibAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("8a958a5b-626c-3d22-ab56-3ec30c9b7ee2"))
IDispatchImplType
{
    IDispatchImplType_SystemDefinedImpl = 0,
    IDispatchImplType_InternalImpl = 1,
    IDispatchImplType_CompatibleImpl = 2
};

struct __declspec(uuid("3ab97590-3a62-36fb-903f-bb70b015f156"))
IDispatchImplAttribute;
    // [ default ] interface _IDispatchImplAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("ac0c43b1-6ca0-3e6c-b088-b11e96fa0ce3"))
ComSourceInterfacesAttribute;
    // [ default ] interface _ComSourceInterfacesAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("8a3fd229-b2a9-347f-93d2-87f3b7f92753"))
ComConversionLossAttribute;
    // [ default ] interface _ComConversionLossAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("97aa3979-1066-3969-b278-e064bdb97dce"))
TypeLibTypeFlags
{
    TypeLibTypeFlags_FAppObject = 1,
    TypeLibTypeFlags_FCanCreate = 2,
    TypeLibTypeFlags_FLicensed = 4,
    TypeLibTypeFlags_FPreDeclId = 8,
    TypeLibTypeFlags_FHidden = 16,
    TypeLibTypeFlags_FControl = 32,
    TypeLibTypeFlags_FDual = 64,
    TypeLibTypeFlags_FNonExtensible = 128,
    TypeLibTypeFlags_FOleAutomation = 256,
    TypeLibTypeFlags_FRestricted = 512,
    TypeLibTypeFlags_FAggregatable = 1024,
    TypeLibTypeFlags_FReplaceable = 2048,
    TypeLibTypeFlags_FDispatchable = 4096,
    TypeLibTypeFlags_FReverseBind = 8192
};

enum __declspec(uuid("bf1bf727-537f-3284-9ca9-5adf12641ab5"))
TypeLibFuncFlags
{
    TypeLibFuncFlags_FRestricted = 1,
    TypeLibFuncFlags_FSource = 2,
    TypeLibFuncFlags_FBindable = 4,
    TypeLibFuncFlags_FRequestEdit = 8,
    TypeLibFuncFlags_FDisplayBind = 16,
    TypeLibFuncFlags_FDefaultBind = 32,
    TypeLibFuncFlags_FHidden = 64,
    TypeLibFuncFlags_FUsesGetLastError = 128,
    TypeLibFuncFlags_FDefaultCollelem = 256,
    TypeLibFuncFlags_FUiDefault = 512,
    TypeLibFuncFlags_FNonBrowsable = 1024,
    TypeLibFuncFlags_FReplaceable = 2048,
    TypeLibFuncFlags_FImmediateBind = 4096
};

enum __declspec(uuid("c660d7a6-d1dd-3e9d-85eb-f844791e2dae"))
TypeLibVarFlags
{
    TypeLibVarFlags_FReadOnly = 1,
    TypeLibVarFlags_FSource = 2,
    TypeLibVarFlags_FBindable = 4,
    TypeLibVarFlags_FRequestEdit = 8,
    TypeLibVarFlags_FDisplayBind = 16,
    TypeLibVarFlags_FDefaultBind = 32,
    TypeLibVarFlags_FHidden = 64,
    TypeLibVarFlags_FRestricted = 128,
    TypeLibVarFlags_FDefaultCollelem = 256,
    TypeLibVarFlags_FUiDefault = 512,
    TypeLibVarFlags_FNonBrowsable = 1024,
    TypeLibVarFlags_FReplaceable = 2048,
    TypeLibVarFlags_FImmediateBind = 4096
};

struct __declspec(uuid("2f53c69e-f1f0-3e98-ad3b-eeaa89a88906"))
TypeLibTypeAttribute;
    // [ default ] interface _TypeLibTypeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("05074a9c-0b30-3a78-aaef-99356e49df45"))
TypeLibFuncAttribute;
    // [ default ] interface _TypeLibFuncAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("36bdd1da-2b15-3428-b055-bdabf4667c3f"))
TypeLibVarAttribute;
    // [ default ] interface _TypeLibVarAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("875eb8b7-663d-3b83-b702-5af34662b9b5"))
VarEnum
{
    VarEnum_VT_EMPTY = 0,
    VarEnum_VT_NULL = 1,
    VarEnum_VT_I2 = 2,
    VarEnum_VT_I4 = 3,
    VarEnum_VT_R4 = 4,
    VarEnum_VT_R8 = 5,
    VarEnum_VT_CY = 6,
    VarEnum_VT_DATE = 7,
    VarEnum_VT_BSTR = 8,
    VarEnum_VT_DISPATCH = 9,
    VarEnum_VT_ERROR = 10,
    VarEnum_VT_BOOL = 11,
    VarEnum_VT_VARIANT = 12,
    VarEnum_VT_UNKNOWN = 13,
    VarEnum_VT_DECIMAL = 14,
    VarEnum_VT_I1 = 16,
    VarEnum_VT_UI1 = 17,
    VarEnum_VT_UI2 = 18,
    VarEnum_VT_UI4 = 19,
    VarEnum_VT_I8 = 20,
    VarEnum_VT_UI8 = 21,
    VarEnum_VT_INT = 22,
    VarEnum_VT_UINT = 23,
    VarEnum_VT_VOID = 24,
    VarEnum_VT_HRESULT = 25,
    VarEnum_VT_PTR = 26,
    VarEnum_VT_SAFEARRAY = 27,
    VarEnum_VT_CARRAY = 28,
    VarEnum_VT_USERDEFINED = 29,
    VarEnum_VT_LPSTR = 30,
    VarEnum_VT_LPWSTR = 31,
    VarEnum_VT_RECORD = 36,
    VarEnum_VT_FILETIME = 64,
    VarEnum_VT_BLOB = 65,
    VarEnum_VT_STREAM = 66,
    VarEnum_VT_STORAGE = 67,
    VarEnum_VT_STREAMED_OBJECT = 68,
    VarEnum_VT_STORED_OBJECT = 69,
    VarEnum_VT_BLOB_OBJECT = 70,
    VarEnum_VT_CF = 71,
    VarEnum_VT_CLSID = 72,
    VarEnum_VT_VECTOR = 4096,
    VarEnum_VT_ARRAY = 8192,
    VarEnum_VT_BYREF = 16384
};

enum __declspec(uuid("03d65b1a-bbf6-3bdc-bc53-85e02415670d"))
UnmanagedType
{
    UnmanagedType_Bool = 2,
    UnmanagedType_I1 = 3,
    UnmanagedType_U1 = 4,
    UnmanagedType_I2 = 5,
    UnmanagedType_U2 = 6,
    UnmanagedType_I4 = 7,
    UnmanagedType_U4 = 8,
    UnmanagedType_I8 = 9,
    UnmanagedType_U8 = 10,
    UnmanagedType_R4 = 11,
    UnmanagedType_R8 = 12,
    UnmanagedType_Currency = 15,
    UnmanagedType_BStr = 19,
    UnmanagedType_LPStr = 20,
    UnmanagedType_LPWStr = 21,
    UnmanagedType_LPTStr = 22,
    UnmanagedType_ByValTStr = 23,
    UnmanagedType_IUnknown = 25,
    UnmanagedType_IDispatch = 26,
    UnmanagedType_Struct = 27,
    UnmanagedType_Interface = 28,
    UnmanagedType_SafeArray = 29,
    UnmanagedType_ByValArray = 30,
    UnmanagedType_SysInt = 31,
    UnmanagedType_SysUInt = 32,
    UnmanagedType_VBByRefStr = 34,
    UnmanagedType_AnsiBStr = 35,
    UnmanagedType_TBStr = 36,
    UnmanagedType_VariantBool = 37,
    UnmanagedType_FunctionPtr = 38,
    UnmanagedType_AsAny = 40,
    UnmanagedType_LPArray = 42,
    UnmanagedType_LPStruct = 43,
    UnmanagedType_CustomMarshaler = 44,
    UnmanagedType_Error = 45
};

struct __declspec(uuid("aaffef00-519d-3ee0-8763-d4b650611e0d"))
MarshalAsAttribute;
    // [ default ] interface _MarshalAsAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("f1eba909-6621-346d-9ce2-39f266c9d011"))
ComImportAttribute;
    // [ default ] interface _ComImportAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("fde6d643-768a-3c91-a169-2c8fb7c1cd1f"))
GuidAttribute;
    // [ default ] interface _GuidAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("204d5a28-46a0-3f04-bd7c-b5672631e57f"))
PreserveSigAttribute;
    // [ default ] interface _PreserveSigAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("96a058cd-faf7-386c-85bf-e47f00c81795"))
InAttribute;
    // [ default ] interface _InAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("fdb2dc94-b5a0-3702-ae84-bbfa752acb36"))
OutAttribute;
    // [ default ] interface _OutAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("b81cb5ed-e654-399f-9698-c83c50665786"))
OptionalAttribute;
    // [ default ] interface _OptionalAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("3c52777e-f51c-300a-8122-479a19164325"))
DllImportAttribute;
    // [ default ] interface _DllImportAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("a0fff774-26bd-3de7-95ce-dbcea6088f96"))
StructLayoutAttribute;
    // [ default ] interface _StructLayoutAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("3ba14c59-4c61-3d7c-8161-9962d7a89292"))
FieldOffsetAttribute;
    // [ default ] interface _FieldOffsetAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("e1aa0b69-ca47-3749-aeb1-133dce4c705f"))
ComAliasNameAttribute;
    // [ default ] interface _ComAliasNameAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("0e67c08b-d921-33d0-82fe-b6fd28bbaeff"))
AutomationProxyAttribute;
    // [ default ] interface _AutomationProxyAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("6dd18f5d-7a5c-3868-b1c2-7e19da873386"))
PrimaryInteropAssemblyAttribute;
    // [ default ] interface _PrimaryInteropAssemblyAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("03e4c7f5-974c-3253-9be0-41470697bbad"))
CoClassAttribute;
    // [ default ] interface _CoClassAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("830ac1f5-98ee-39a3-9212-fa5626ca855a"))
ComEventInterfaceAttribute;
    // [ default ] interface _ComEventInterfaceAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("5f8dc45f-a2d8-3e34-8c86-586ed6a74984"))
TypeLibVersionAttribute;
    // [ default ] interface _TypeLibVersionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("7f962ebf-2220-30f0-8b92-24a73b7cd268"))
ComCompatibleVersionAttribute;
    // [ default ] interface _ComCompatibleVersionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("84fee617-858b-364b-a662-8bf7ed5330ca"))
BestFitMappingAttribute;
    // [ default ] interface _BestFitMappingAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("66708447-ecce-3422-b3a3-c8161c1c693b"))
DefaultCharSetAttribute;
    // [ default ] interface _DefaultCharSetAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("9d309f77-4655-372e-84b0-b0fb4030f3b8"))
SetWin32ContextInIDispatchAttribute;
    // [ default ] interface _SetWin32ContextInIDispatchAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("79c2c4a6-8d21-371c-995f-52c38701b91e"))
CallingConvention
{
    CallingConvention_Winapi = 1,
    CallingConvention_Cdecl = 2,
    CallingConvention_StdCall = 3,
    CallingConvention_ThisCall = 4,
    CallingConvention_FastCall = 5
};

enum __declspec(uuid("deae387d-c9a7-3a9c-b772-0153a2538502"))
CharSet
{
    CharSet_None = 1,
    CharSet_Ansi = 2,
    CharSet_Unicode = 3,
    CharSet_Auto = 4
};

struct __declspec(uuid("afc681cf-e82f-361a-8280-cf4e1f844c3e"))
ExternalException;
    // [ default ] interface _ExternalException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("07f94112-a42e-328b-b508-702ef62bcc29"))
COMException;
    // [ default ] interface _COMException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("0e71f38e-c5e1-3094-9487-5c7dd1e998ec"))
GCHandleType
{
    GCHandleType_Weak = 0,
    GCHandleType_WeakTrackResurrection = 1,
    GCHandleType_Normal = 2,
    GCHandleType_Pinned = 3
};

#pragma pack(push, 4)

struct __declspec(uuid("66e1f723-e57f-35ce-8306-3c09fb68a322"))
GCHandle
{
    long m_handle;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("c71dce2b-b87f-37a9-89ed-f1145955bcd6"))
HandleRef
{
    IUnknown * m_wrapper;
    long m_handle;
};

#pragma pack(pop)

struct __declspec(uuid("601cd486-04bf-3213-9ea9-06ebe4351d74"))
ICustomMarshaler : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall MarshalNativeToManaged (
        /*[in]*/ long pNativeData,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall MarshalManagedToNative (
        /*[in]*/ VARIANT ManagedObj,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall CleanUpNativeData (
        /*[in]*/ long pNativeData ) = 0;
      virtual HRESULT __stdcall CleanUpManagedData (
        /*[in]*/ VARIANT ManagedObj ) = 0;
      virtual HRESULT __stdcall GetNativeDataSize (
        /*[out,retval]*/ long * pRetVal ) = 0;
};

struct __declspec(uuid("9a944885-edaf-3a81-a2ff-6a9d5d1abfc7"))
InvalidOleVariantTypeException;
    // [ default ] interface _InvalidOleVariantTypeException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("9abe23bd-d5d5-30f6-b127-9b3ab98f7dbb"))
LayoutKind
{
    LayoutKind_Sequential = 0,
    LayoutKind_Explicit = 2,
    LayoutKind_Auto = 3
};

struct __declspec(uuid("742ad1fb-b2f0-3681-b4aa-e736a3bce4e1"))
MarshalDirectiveException;
    // [ default ] interface _MarshalDirectiveException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("78d22140-40cf-303e-be96-b3ac0407a34d"))
RuntimeEnvironment;
    // [ default ] interface _RuntimeEnvironment
    // interface _Object

struct __declspec(uuid("ca805b13-468c-3a22-bf9a-818e97efa6b7"))
SEHException;
    // [ default ] interface _SEHException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("e5de21f2-12d7-3604-8251-1c5dbc64ca66"))
BStrWrapper;
    // [ default ] interface _BStrWrapper
    // interface _Object

enum __declspec(uuid("96e0dee8-c1ca-38a5-a3c9-52da9b5440ef"))
ComMemberType
{
    ComMemberType_Method = 0,
    ComMemberType_PropGet = 1,
    ComMemberType_PropSet = 2
};

struct __declspec(uuid("d540a482-8fb8-3720-b52e-08c7a2c1b9df"))
CurrencyWrapper;
    // [ default ] interface _CurrencyWrapper
    // interface _Object

struct __declspec(uuid("da7109d3-bcd8-3d4c-b172-dfc2e585562a"))
DispatchWrapper;
    // [ default ] interface _DispatchWrapper
    // interface _Object

struct __declspec(uuid("d7900ebd-ff28-3ae6-b517-7e32714f578b"))
ErrorWrapper;
    // [ default ] interface _ErrorWrapper
    // interface _Object

struct __declspec(uuid("58734403-8382-3110-b729-14c7855982f9"))
ExtensibleClassFactory;
    // [ default ] interface _ExtensibleClassFactory
    // interface _Object

struct __declspec(uuid("3cc86595-feb5-3ce9-ba14-d05c8dc3321c"))
ICustomAdapter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetUnderlyingObject (
        /*[out,retval]*/ IUnknown * * pRetVal ) = 0;
};

struct __declspec(uuid("a7248ec6-a8a5-3d07-890e-6107f8c247e5"))
InvalidComObjectException;
    // [ default ] interface _InvalidComObjectException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("765653a0-2b24-38e4-a6f6-5cb325e8ccc9"))
AssemblyRegistrationFlags
{
    AssemblyRegistrationFlags_None = 0,
    AssemblyRegistrationFlags_SetCodeBase = 1
};

enum __declspec(uuid("c335350a-892d-37f7-967c-99b3c4c4a301"))
TypeLibImporterFlags
{
    TypeLibImporterFlags_None = 0,
    TypeLibImporterFlags_PrimaryInteropAssembly = 1,
    TypeLibImporterFlags_UnsafeInterfaces = 2,
    TypeLibImporterFlags_SafeArrayAsSystemArray = 4,
    TypeLibImporterFlags_TransformDispRetVals = 8,
    TypeLibImporterFlags_PreventClassMembers = 16,
    TypeLibImporterFlags_SerializableValueClasses = 32,
    TypeLibImporterFlags_ImportAsX86 = 256,
    TypeLibImporterFlags_ImportAsX64 = 512,
    TypeLibImporterFlags_ImportAsItanium = 1024,
    TypeLibImporterFlags_ImportAsAgnostic = 2048,
    TypeLibImporterFlags_ReflectionOnlyLoading = 4096
};

enum __declspec(uuid("ad92602f-55f2-3552-a977-d93c79db346e"))
TypeLibExporterFlags
{
    TypeLibExporterFlags_None = 0,
    TypeLibExporterFlags_OnlyReferenceRegistered = 1,
    TypeLibExporterFlags_CallerResolvedReferences = 2,
    TypeLibExporterFlags_OldNames = 4,
    TypeLibExporterFlags_ExportAs32Bit = 16,
    TypeLibExporterFlags_ExportAs64Bit = 32
};

enum __declspec(uuid("b42619b4-0edc-3f55-aa64-2140275fa115"))
ImporterEventKind
{
    ImporterEventKind_NOTIF_TYPECONVERTED = 0,
    ImporterEventKind_NOTIF_CONVERTWARNING = 1,
    ImporterEventKind_ERROR_REFTOINVALIDTYPELIB = 2
};

enum __declspec(uuid("26170123-45fd-30f7-987d-bf3689662b6c"))
ExporterEventKind
{
    ExporterEventKind_NOTIF_TYPECONVERTED = 0,
    ExporterEventKind_NOTIF_CONVERTWARNING = 1,
    ExporterEventKind_ERROR_REFTOINVALIDASSEMBLY = 2
};

struct __declspec(uuid("fa1f3615-acb9-486d-9eac-1bef87e36b09"))
ITypeLibExporterNameProvider : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetNames (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("8a21df64-f31a-306f-9db8-0dfa164ed9ee"))
ObjectCreationDelegate;
    // [ default ] interface _ObjectCreationDelegate
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("475e398f-8afa-43a7-a3be-f4ef8d6787c9"))
RegistrationServices;
    // interface _Object
    // [ default ] interface IRegistrationServices

struct __declspec(uuid("4be89ac3-603d-36b2-ab9b-9c38866f56d5"))
SafeArrayRankMismatchException;
    // [ default ] interface _SafeArrayRankMismatchException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("2d5ec63c-1b3e-3ee4-9052-eb0d0303549c"))
SafeArrayTypeMismatchException;
    // [ default ] interface _SafeArrayTypeMismatchException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("f1c3bf79-c3e4-11d3-88e7-00902754c43a"))
TypeLibConverter;
    // interface _Object
    // [ default ] interface ITypeLibConverter

struct __declspec(uuid("887d4d94-31d1-37f3-9938-643ed2a46155"))
UnknownWrapper;
    // [ default ] interface _UnknownWrapper
    // interface _Object

struct __declspec(uuid("e331083b-c22d-3046-8ec7-d222d6be031f"))
Stream;
    // [ default ] interface _Stream
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("2484afda-7b47-3cd7-97b5-951f5c6ab5b6"))
BinaryReader;
    // [ default ] interface _BinaryReader
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("d92ccd03-5c88-3339-8011-46e8b01a2ba8"))
BinaryWriter;
    // [ default ] interface _BinaryWriter
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("1500abc0-1dd4-37dd-985f-82430314c798"))
BufferedStream;
    // [ default ] interface _BufferedStream
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("0ebd869e-64bf-3682-80bb-690a70114be0"))
Directory;
    // [ default ] interface _Directory
    // interface _Object

struct __declspec(uuid("1f0e8db5-8f52-3360-8a47-9d3dc3a5acaf"))
FileSystemInfo;
    // [ default ] interface _FileSystemInfo
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("40a8b2fa-e055-3f59-8ba6-54c4e35649b5"))
DirectoryInfo;
    // [ default ] interface _DirectoryInfo
    // interface _Object
    // interface ISerializable

enum __declspec(uuid("8d583b4d-52c8-3243-829e-999d660d3947"))
SearchOption
{
    SearchOption_TopDirectoryOnly = 0,
    SearchOption_AllDirectories = 1
};

struct __declspec(uuid("a164c0bf-67ae-3c7e-bc05-bfe24a8cdb62"))
IOException;
    // [ default ] interface _IOException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("8833bc41-dc6b-34b9-a799-682d2554f02f"))
DirectoryNotFoundException;
    // [ default ] interface _DirectoryNotFoundException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("72e8197d-904b-3371-ae0e-b70d9d53771c"))
DriveType
{
    DriveType_Unknown = 0,
    DriveType_NoRootDirectory = 1,
    DriveType_Removable = 2,
    DriveType_Fixed = 3,
    DriveType_Network = 4,
    DriveType_CDRom = 5,
    DriveType_Ram = 6
};

struct __declspec(uuid("b7c87928-b1ad-35ce-aa58-3dc3aab7ac67"))
DriveInfo;
    // [ default ] interface _DriveInfo
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("a8f9f740-70c9-30a7-937c-59785a9bb5a4"))
DriveNotFoundException;
    // [ default ] interface _DriveNotFoundException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("58d052bc-a3df-3508-ac95-ff297bdc9f0c"))
EndOfStreamException;
    // [ default ] interface _EndOfStreamException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("2a96793e-4cf3-3976-a893-b66886d89a03"))
File;
    // [ default ] interface _File
    // interface _Object

enum __declspec(uuid("74caa246-be0e-3ae5-a17c-946e10d89626"))
FileAccess
{
    FileAccess_Read = 1,
    FileAccess_Write = 2,
    FileAccess_ReadWrite = 3
};

struct __declspec(uuid("d6dffead-0b46-3ded-83de-1943413b94d5"))
FileInfo;
    // [ default ] interface _FileInfo
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("af8c5f8a-9999-3e92-bb41-c5f4955174cd"))
FileLoadException;
    // [ default ] interface _FileLoadException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("f9a5bd62-8da3-3b2d-a556-864cdad150f6"))
FileMode
{
    FileMode_CreateNew = 1,
    FileMode_Create = 2,
    FileMode_Open = 3,
    FileMode_OpenOrCreate = 4,
    FileMode_Truncate = 5,
    FileMode_Append = 6
};

struct __declspec(uuid("48c6e96f-a2f3-33e7-ba7f-c8f74866760b"))
FileNotFoundException;
    // [ default ] interface _FileNotFoundException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("68db6e95-f774-3ae3-b1de-b0cc80f6e174"))
FileOptions
{
    FileOptions_None = 0,
    FileOptions_WriteThrough = 0x80000000,
    FileOptions_Asynchronous = 1073741824,
    FileOptions_RandomAccess = 268435456,
    FileOptions_DeleteOnClose = 67108864,
    FileOptions_SequentialScan = 134217728,
    FileOptions_Encrypted = 16384
};

enum __declspec(uuid("791ec67c-5a1b-35fd-832d-80b02d07ed6d"))
FileShare
{
    FileShare_None = 0,
    FileShare_Read = 1,
    FileShare_Write = 2,
    FileShare_ReadWrite = 3,
    FileShare_Delete = 4,
    FileShare_Inheritable = 16
};

struct __declspec(uuid("7f25e491-33be-31e2-a334-cb506d4ee471"))
FileStream;
    // [ default ] interface _FileStream
    // interface _Object
    // interface IDisposable

enum __declspec(uuid("38512cf6-ff94-3ad8-8299-f5f64a8956aa"))
FileAttributes
{
    FileAttributes_ReadOnly = 1,
    FileAttributes_Hidden = 2,
    FileAttributes_System = 4,
    FileAttributes_Directory = 16,
    FileAttributes_Archive = 32,
    FileAttributes_Device = 64,
    FileAttributes_Normal = 128,
    FileAttributes_Temporary = 256,
    FileAttributes_SparseFile = 512,
    FileAttributes_ReparsePoint = 1024,
    FileAttributes_Compressed = 2048,
    FileAttributes_Offline = 4096,
    FileAttributes_NotContentIndexed = 8192,
    FileAttributes_Encrypted = 16384
};

struct __declspec(uuid("f5e692d9-8a87-349d-9657-f96e5799d2f4"))
MemoryStream;
    // [ default ] interface _MemoryStream
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("b7ae0cae-979e-3ebf-b33f-8f121dafd78e"))
Path;
    // [ default ] interface _Path
    // interface _Object

struct __declspec(uuid("c016a313-9606-36d3-a823-33ebf5006189"))
PathTooLongException;
    // [ default ] interface _PathTooLongException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("0cfe1abf-373d-3208-85c2-947434046704"))
SeekOrigin
{
    SeekOrigin_Begin = 0,
    SeekOrigin_Current = 1,
    SeekOrigin_End = 2
};

struct __declspec(uuid("7457d481-248a-3c89-b7e0-fceb8fd827e5"))
TextReader;
    // [ default ] interface _TextReader
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("405fb68b-360d-382c-8a64-1da3c853d161"))
StreamReader;
    // [ default ] interface _StreamReader
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("08416c5b-a003-327c-9f0f-93942467e6e0"))
TextWriter;
    // [ default ] interface _TextWriter
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("ef1ab726-0b87-3e09-aef4-3a87c5dcdda0"))
StreamWriter;
    // [ default ] interface _StreamWriter
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("0247d5af-d61d-341c-8615-0ff28865b7cb"))
StringReader;
    // [ default ] interface _StringReader
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("27f31d55-d6c6-3676-9d42-c40f3a918636"))
StringWriter;
    // [ default ] interface _StringWriter
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("5efb687d-2b50-3216-bd74-52d06c8d3cd1"))
AccessedThroughPropertyAttribute;
    // [ default ] interface _AccessedThroughPropertyAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("a3a1f076-1fa7-3a26-886d-8841cb45382f"))
CallConvCdecl;
    // [ default ] interface _CallConvCdecl
    // interface _Object

struct __declspec(uuid("bcb67d4d-2096-36be-974c-a003fc95041b"))
CallConvStdcall;
    // [ default ] interface _CallConvStdcall
    // interface _Object

struct __declspec(uuid("46080ca7-7cb8-3a55-a72e-8e50eca4d4fc"))
CallConvThiscall;
    // [ default ] interface _CallConvThiscall
    // interface _Object

struct __declspec(uuid("ed0bc45c-2438-31a9-bbb6-e2a3b5916419"))
CallConvFastcall;
    // [ default ] interface _CallConvFastcall
    // interface _Object

struct __declspec(uuid("6f7a3516-efd9-31c3-bc9a-a89df19f64e7"))
CustomConstantAttribute;
    // [ default ] interface _CustomConstantAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("3178fd5d-2a5b-30b9-9c5c-7593802f9c1a"))
DateTimeConstantAttribute;
    // [ default ] interface _DateTimeConstantAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("837a6733-1675-3bc9-bbf8-13889f84daf4"))
DiscardableAttribute;
    // [ default ] interface _DiscardableAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("ac8de863-b115-3179-810f-162b43abd2b5"))
DecimalConstantAttribute;
    // [ default ] interface _DecimalConstantAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("1e552dae-602e-3cb5-9bfa-22aeb1fc38a5"))
CompilationRelaxations
{
    CompilationRelaxations_NoStringInterning = 8
};

struct __declspec(uuid("76cec05b-c55e-3adf-92a2-0698f1cf2017"))
CompilationRelaxationsAttribute;
    // [ default ] interface _CompilationRelaxationsAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("4b601364-a04b-38bc-bd38-a18e981324cf"))
CompilerGlobalScopeAttribute;
    // [ default ] interface _CompilerGlobalScopeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("9599c078-dc94-3ea2-8761-408295bd1155"))
IndexerNameAttribute;
    // [ default ] interface _IndexerNameAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("86527c04-536a-33c6-8c84-3d5a5b458db3"))
IsVolatile;
    // [ default ] interface _IsVolatile
    // interface _Object

enum __declspec(uuid("63a2e7fd-9a9b-3d6b-a827-3c5bf8db1e6a"))
MethodImplOptions
{
    MethodImplOptions_Unmanaged = 4,
    MethodImplOptions_ForwardRef = 16,
    MethodImplOptions_PreserveSig = 128,
    MethodImplOptions_InternalCall = 4096,
    MethodImplOptions_Synchronized = 32,
    MethodImplOptions_NoInlining = 8
};

enum __declspec(uuid("6b7f18ae-f5ac-368f-8dfd-ab5e2d229ed7"))
MethodCodeType
{
    MethodCodeType_IL = 0,
    MethodCodeType_Native = 1,
    MethodCodeType_OPTIL = 2,
    MethodCodeType_Runtime = 3
};

struct __declspec(uuid("48d0cfe7-3128-3d2c-a5b5-8c7b82b4ab4f"))
MethodImplAttribute;
    // [ default ] interface _MethodImplAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("d49c12a2-c401-3894-8005-716c2f692d38"))
RequiredAttributeAttribute;
    // [ default ] interface _RequiredAttributeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("2d6b9536-e9ca-317c-b62f-8e5876351e10"))
IsCopyConstructed;
    // [ default ] interface _IsCopyConstructed
    // interface _Object

struct __declspec(uuid("c437ab2e-865b-321d-ba15-0c8ec4ca119b"))
NativeCppClassAttribute;
    // [ default ] interface _NativeCppClassAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("e947a0b0-d47f-3aa3-9b77-4624e0f3aca4"))
IDispatchConstantAttribute;
    // [ default ] interface _IDispatchConstantAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("590e4a07-dafc-3be7-a178-da349bba980b"))
IUnknownConstantAttribute;
    // [ default ] interface _IUnknownConstantAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("b9033cd1-c905-3059-9d29-562ecb13b0b3"))
SecurityElement;
    // [ default ] interface _SecurityElement
    // interface _Object

struct __declspec(uuid("e38da416-8050-3786-8201-46f187c15213"))
XmlSyntaxException;
    // [ default ] interface _XmlSyntaxException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("ec73fceb-1aea-3a57-b953-21368e992507"))
EnvironmentPermissionAccess
{
    EnvironmentPermissionAccess_NoAccess = 0,
    EnvironmentPermissionAccess_Read = 1,
    EnvironmentPermissionAccess_Write = 2,
    EnvironmentPermissionAccess_AllAccess = 3
};

struct __declspec(uuid("a19b3fc6-d680-3dd4-a17a-f58a7d481494"))
IPermission : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ struct IPermission * * pRetVal ) = 0;
      virtual HRESULT __stdcall Intersect (
        /*[in]*/ struct IPermission * Target,
        /*[out,retval]*/ struct IPermission * * pRetVal ) = 0;
      virtual HRESULT __stdcall Union (
        /*[in]*/ struct IPermission * Target,
        /*[out,retval]*/ struct IPermission * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsSubsetOf (
        /*[in]*/ struct IPermission * Target,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Demand ( ) = 0;
};

struct __declspec(uuid("60fc57b0-4a46-32a0-a5b4-b05b0de8e781"))
IStackWalk : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Assert ( ) = 0;
      virtual HRESULT __stdcall Demand ( ) = 0;
      virtual HRESULT __stdcall Deny ( ) = 0;
      virtual HRESULT __stdcall PermitOnly ( ) = 0;
};

struct __declspec(uuid("af6550fa-7c4b-3477-86dd-235f8286eaac"))
CodeAccessPermission;
    // [ default ] interface _CodeAccessPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

struct __declspec(uuid("0f1284e6-4399-3963-8ddd-a6a4904f66c8"))
IUnrestrictedPermission : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall IsUnrestricted (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("801f6e40-b384-3d27-b75f-de2df38f1192"))
EnvironmentPermission;
    // [ default ] interface _EnvironmentPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

enum __declspec(uuid("0df04a9b-dddc-3777-a6b1-9604b5ced191"))
FileDialogPermissionAccess
{
    FileDialogPermissionAccess_None = 0,
    FileDialogPermissionAccess_Open = 1,
    FileDialogPermissionAccess_Save = 2,
    FileDialogPermissionAccess_OpenSave = 3
};

struct __declspec(uuid("9e1239b4-493a-3d2d-8f91-6636ec9eca21"))
FileDialogPermission;
    // [ default ] interface _FileDialogPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

enum __declspec(uuid("ca10c1a1-9fdc-36a3-ad74-8fac60e6541c"))
FileIOPermissionAccess
{
    FileIOPermissionAccess_NoAccess = 0,
    FileIOPermissionAccess_Read = 1,
    FileIOPermissionAccess_Write = 2,
    FileIOPermissionAccess_Append = 4,
    FileIOPermissionAccess_PathDiscovery = 8,
    FileIOPermissionAccess_AllAccess = 15
};

struct __declspec(uuid("dc50cd5a-0cad-3b47-bf0d-79e85f3c2fc7"))
FileIOPermission;
    // [ default ] interface _FileIOPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

enum __declspec(uuid("4548a129-2855-35e8-a892-ff506c877aa8"))
HostProtectionResource
{
    HostProtectionResource_None = 0,
    HostProtectionResource_Synchronization = 1,
    HostProtectionResource_SharedState = 2,
    HostProtectionResource_ExternalProcessMgmt = 4,
    HostProtectionResource_SelfAffectingProcessMgmt = 8,
    HostProtectionResource_ExternalThreading = 16,
    HostProtectionResource_SelfAffectingThreading = 32,
    HostProtectionResource_SecurityInfrastructure = 64,
    HostProtectionResource_UI = 128,
    HostProtectionResource_MayLeakOnAbort = 256,
    HostProtectionResource_All = 511
};

struct __declspec(uuid("47dcd758-df63-3226-a3a9-b0b88872a311"))
SecurityAttribute;
    // [ default ] interface _SecurityAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("21858390-fe95-33a9-a103-f322c64d85ae"))
CodeAccessSecurityAttribute;
    // [ default ] interface _CodeAccessSecurityAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("ad664904-fe8a-3217-bbf5-e6ab1d998f5f"))
HostProtectionAttribute;
    // [ default ] interface _HostProtectionAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("0d6e31df-3a76-3054-a8eb-150e92300f89"))
IsolatedStorageContainment
{
    IsolatedStorageContainment_None = 0,
    IsolatedStorageContainment_DomainIsolationByUser = 16,
    IsolatedStorageContainment_ApplicationIsolationByUser = 21,
    IsolatedStorageContainment_AssemblyIsolationByUser = 32,
    IsolatedStorageContainment_DomainIsolationByMachine = 48,
    IsolatedStorageContainment_AssemblyIsolationByMachine = 64,
    IsolatedStorageContainment_ApplicationIsolationByMachine = 69,
    IsolatedStorageContainment_DomainIsolationByRoamingUser = 80,
    IsolatedStorageContainment_AssemblyIsolationByRoamingUser = 96,
    IsolatedStorageContainment_ApplicationIsolationByRoamingUser = 101,
    IsolatedStorageContainment_AdministerIsolatedStorageByUser = 112,
    IsolatedStorageContainment_UnrestrictedIsolatedStorage = 240
};

struct __declspec(uuid("f458abf2-2b5e-3158-b0e4-228e8cdcf759"))
IsolatedStoragePermission;
    // [ default ] interface _IsolatedStoragePermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

struct __declspec(uuid("ae588447-d98e-3e39-96f7-073433db8d35"))
IsolatedStorageFilePermission;
    // [ default ] interface _IsolatedStorageFilePermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

enum __declspec(uuid("dfaecf33-4728-382d-a34d-c1b0392f8b73"))
PermissionState
{
    PermissionState_Unrestricted = 1,
    PermissionState_None = 0
};

enum __declspec(uuid("ba99ae52-d539-362f-b78c-4e84c14158bf"))
SecurityAction
{
    SecurityAction_Demand = 2,
    SecurityAction_Assert = 3,
    SecurityAction_Deny = 4,
    SecurityAction_PermitOnly = 5,
    SecurityAction_LinkDemand = 6,
    SecurityAction_InheritanceDemand = 7,
    SecurityAction_RequestMinimum = 8,
    SecurityAction_RequestOptional = 9,
    SecurityAction_RequestRefuse = 10
};

struct __declspec(uuid("6161df0c-cd78-33e1-b3e1-978b27025e40"))
EnvironmentPermissionAttribute;
    // [ default ] interface _EnvironmentPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("a141f926-e6b5-3903-8efa-1014d4970f1c"))
FileDialogPermissionAttribute;
    // [ default ] interface _FileDialogPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("de440c06-7ec3-3e59-83c8-3829090198f7"))
FileIOPermissionAttribute;
    // [ default ] interface _FileIOPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("f40ffbd5-4ca8-333e-8706-29f13fb8d4d6"))
KeyContainerPermissionAttribute;
    // [ default ] interface _KeyContainerPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("6d0ae73b-ed58-32e2-973c-765897783971"))
PrincipalPermissionAttribute;
    // [ default ] interface _PrincipalPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("64578750-937f-3b27-b631-c57e0bfff97f"))
ReflectionPermissionAttribute;
    // [ default ] interface _ReflectionPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("f69cf20d-f85b-3436-9e0e-dd3cb3e8b2cd"))
RegistryPermissionAttribute;
    // [ default ] interface _RegistryPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("5e77314c-043d-3d8c-9c9d-d18f09fb3500"))
SecurityPermissionAttribute;
    // [ default ] interface _SecurityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("5f4ed054-c453-3d2b-a0fe-64e89871d364"))
UIPermissionAttribute;
    // [ default ] interface _UIPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("c386115f-2b99-356b-b4a1-2cf57ce52988"))
ZoneIdentityPermissionAttribute;
    // [ default ] interface _ZoneIdentityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("ef2c9de4-bcda-3322-ae75-16cc3ec2665c"))
StrongNameIdentityPermissionAttribute;
    // [ default ] interface _StrongNameIdentityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("23f73179-6349-3183-a55c-bcfb1a2446e8"))
SiteIdentityPermissionAttribute;
    // [ default ] interface _SiteIdentityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("6852be7d-8c00-3f66-bee3-463f74838491"))
UrlIdentityPermissionAttribute;
    // [ default ] interface _UrlIdentityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("2335c1da-cd60-3208-ab5e-447f16a087e5"))
PublisherIdentityPermissionAttribute;
    // [ default ] interface _PublisherIdentityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("a56859a3-98ed-39a9-bd33-5807f0d6291f"))
IsolatedStoragePermissionAttribute;
    // [ default ] interface _IsolatedStoragePermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("f6610df3-8d62-38bd-bf6b-2a4ba839eb3b"))
IsolatedStorageFilePermissionAttribute;
    // [ default ] interface _IsolatedStorageFilePermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("24151ba6-6d79-3ec4-8c77-014ffbe735ae"))
PermissionSetAttribute;
    // [ default ] interface _PermissionSetAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("44c2f476-9e95-3d5a-b666-fdbef071494e"))
ReflectionPermissionFlag
{
    ReflectionPermissionFlag_NoFlags = 0,
    ReflectionPermissionFlag_TypeInformation = 1,
    ReflectionPermissionFlag_MemberAccess = 2,
    ReflectionPermissionFlag_ReflectionEmit = 4,
    ReflectionPermissionFlag_AllFlags = 7
};

struct __declspec(uuid("e71cdc85-7fe7-3f51-bcdb-02459770db87"))
ReflectionPermission;
    // [ default ] interface _ReflectionPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

struct __declspec(uuid("67100ade-60cf-33f1-8d95-f6fe1174458a"))
PrincipalPermission;
    // [ default ] interface _PrincipalPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IUnrestrictedPermission

enum __declspec(uuid("b718f0f8-e5e7-3651-a2be-97009b568250"))
SecurityPermissionFlag
{
    SecurityPermissionFlag_NoFlags = 0,
    SecurityPermissionFlag_Assertion = 1,
    SecurityPermissionFlag_UnmanagedCode = 2,
    SecurityPermissionFlag_SkipVerification = 4,
    SecurityPermissionFlag_Execution = 8,
    SecurityPermissionFlag_ControlThread = 16,
    SecurityPermissionFlag_ControlEvidence = 32,
    SecurityPermissionFlag_ControlPolicy = 64,
    SecurityPermissionFlag_SerializationFormatter = 128,
    SecurityPermissionFlag_ControlDomainPolicy = 256,
    SecurityPermissionFlag_ControlPrincipal = 512,
    SecurityPermissionFlag_ControlAppDomain = 1024,
    SecurityPermissionFlag_RemotingConfiguration = 2048,
    SecurityPermissionFlag_Infrastructure = 4096,
    SecurityPermissionFlag_BindingRedirects = 8192,
    SecurityPermissionFlag_AllFlags = 16383
};

struct __declspec(uuid("d5f5125a-3d46-3c57-8393-0e4ee9d8016b"))
SecurityPermission;
    // [ default ] interface _SecurityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

struct __declspec(uuid("3bcfc458-07dc-3ba7-8404-97eb76641080"))
SiteIdentityPermission;
    // [ default ] interface _SiteIdentityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

struct __declspec(uuid("2b00b9ec-b4f4-3243-90ab-532e64fee941"))
StrongNameIdentityPermission;
    // [ default ] interface _StrongNameIdentityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

struct __declspec(uuid("a463394f-7ba6-3721-8ad8-842748612b4c"))
StrongNamePublicKeyBlob;
    // [ default ] interface _StrongNamePublicKeyBlob
    // interface _Object

enum __declspec(uuid("b30fd15e-ced6-3977-8151-0d50e79cd703"))
UIPermissionWindow
{
    UIPermissionWindow_NoWindows = 0,
    UIPermissionWindow_SafeSubWindows = 1,
    UIPermissionWindow_SafeTopLevelWindows = 2,
    UIPermissionWindow_AllWindows = 3
};

enum __declspec(uuid("9e5c3c99-d046-3fe5-9921-21cf0f0a08ff"))
UIPermissionClipboard
{
    UIPermissionClipboard_NoClipboard = 0,
    UIPermissionClipboard_OwnClipboard = 1,
    UIPermissionClipboard_AllClipboard = 2
};

struct __declspec(uuid("05b46a2d-7c6b-3eff-a09a-1490a36811c2"))
UIPermission;
    // [ default ] interface _UIPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

struct __declspec(uuid("ab7d1ab9-d192-3a95-b34c-a3996837c6a7"))
UrlIdentityPermission;
    // [ default ] interface _UrlIdentityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

struct __declspec(uuid("caeb199e-ceb9-388a-b240-e29c9f55199b"))
ZoneIdentityPermission;
    // [ default ] interface _ZoneIdentityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

struct __declspec(uuid("52f1a8f3-7c7c-3c08-848b-8ab0ea946959"))
GacIdentityPermissionAttribute;
    // [ default ] interface _GacIdentityPermissionAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("29a6cf6f-d663-31a7-9210-1347871681fc"))
GacIdentityPermission;
    // [ default ] interface _GacIdentityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

enum __declspec(uuid("742bdc16-f04e-3e0e-8ff1-e3250940b5bf"))
KeyContainerPermissionFlags
{
    KeyContainerPermissionFlags_NoFlags = 0,
    KeyContainerPermissionFlags_Create = 1,
    KeyContainerPermissionFlags_Open = 2,
    KeyContainerPermissionFlags_Delete = 4,
    KeyContainerPermissionFlags_Import = 16,
    KeyContainerPermissionFlags_Export = 32,
    KeyContainerPermissionFlags_Sign = 256,
    KeyContainerPermissionFlags_Decrypt = 512,
    KeyContainerPermissionFlags_ViewAcl = 4096,
    KeyContainerPermissionFlags_ChangeAcl = 8192,
    KeyContainerPermissionFlags_AllFlags = 13111
};

struct __declspec(uuid("ab32dbc6-3d50-3098-8b72-fe98ba5cefba"))
KeyContainerPermissionAccessEntry;
    // [ default ] interface _KeyContainerPermissionAccessEntry
    // interface _Object

struct __declspec(uuid("a9b28590-073c-392c-82f4-b47fd3d00ec3"))
KeyContainerPermissionAccessEntryCollection;
    // [ default ] interface _KeyContainerPermissionAccessEntryCollection
    // interface _Object
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("616e9d9e-ee8a-35e6-a0a1-8bf70d536b02"))
KeyContainerPermissionAccessEntryEnumerator;
    // [ default ] interface _KeyContainerPermissionAccessEntryEnumerator
    // interface _Object
    // interface IEnumerator

struct __declspec(uuid("2d91f34b-85ec-33e5-a32e-752d8219404d"))
KeyContainerPermission;
    // [ default ] interface _KeyContainerPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

struct __declspec(uuid("73cf786b-cd2c-37e4-9835-824e4a019f11"))
PublisherIdentityPermission;
    // [ default ] interface _PublisherIdentityPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk

enum __declspec(uuid("3eb29914-f9a9-3c15-a03f-560885cfcb61"))
RegistryPermissionAccess
{
    RegistryPermissionAccess_NoAccess = 0,
    RegistryPermissionAccess_Read = 1,
    RegistryPermissionAccess_Write = 2,
    RegistryPermissionAccess_Create = 4,
    RegistryPermissionAccess_AllAccess = 7
};

struct __declspec(uuid("b35e31f2-9e50-3d43-8eaf-ec111f6b3295"))
RegistryPermission;
    // [ default ] interface _RegistryPermission
    // interface _Object
    // interface IPermission
    // interface ISecurityEncodable
    // interface IStackWalk
    // interface IUnrestrictedPermission

struct __declspec(uuid("7ae01d6c-bee7-38f6-9a86-329d8a917803"))
SuppressUnmanagedCodeSecurityAttribute;
    // [ default ] interface _SuppressUnmanagedCodeSecurityAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("7e3393ab-2ab2-320b-8f6f-eab6f5cf2caf"))
UnverifiableCodeAttribute;
    // [ default ] interface _UnverifiableCodeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("5610f042-ff1d-36d0-996c-68f7a207d1f0"))
AllowPartiallyTrustedCallersAttribute;
    // [ default ] interface _AllowPartiallyTrustedCallersAttribute
    // interface _Object
    // interface _Attribute

enum __declspec(uuid("51e1b3ca-d3cb-39bf-a016-6199569e74b2"))
HostSecurityManagerOptions
{
    HostSecurityManagerOptions_None = 0,
    HostSecurityManagerOptions_HostAppDomainEvidence = 1,
    HostSecurityManagerOptions_HostPolicyLevel = 2,
    HostSecurityManagerOptions_HostAssemblyEvidence = 4,
    HostSecurityManagerOptions_HostDetermineApplicationTrust = 8,
    HostSecurityManagerOptions_HostResolvePolicy = 16,
    HostSecurityManagerOptions_AllFlags = 31
};

struct __declspec(uuid("84589833-40d7-36e2-8545-67a92b97c408"))
HostSecurityManager;
    // [ default ] interface _HostSecurityManager
    // interface _Object

struct __declspec(uuid("afafd122-dac4-3ff9-9646-dc032a4a8806"))
PermissionSet;
    // [ default ] interface _PermissionSet
    // interface _Object
    // interface ISecurityEncodable
    // interface ICollection
    // interface IEnumerable
    // interface IStackWalk
    // interface IDeserializationCallback

struct __declspec(uuid("c23e56ce-0a9a-3733-8189-46b43c9e4fb3"))
NamedPermissionSet;
    // [ default ] interface _NamedPermissionSet
    // interface _Object
    // interface ISecurityEncodable
    // interface ICollection
    // interface IEnumerable
    // interface IStackWalk
    // interface IDeserializationCallback

struct __declspec(uuid("eef05c76-5c98-3685-a69c-6e1a26a7f846"))
SecurityException;
    // [ default ] interface _SecurityException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("ecc82a10-b731-3a01-8a17-ac0ddd7666cf"))
HostProtectionException;
    // [ default ] interface _HostProtectionException
    // interface _Object
    // interface ISerializable
    // interface _Exception

enum __declspec(uuid("ee965595-853a-331b-9cd0-d53dcce3b6f8"))
PolicyLevelType
{
    PolicyLevelType_User = 0,
    PolicyLevelType_Machine = 1,
    PolicyLevelType_Enterprise = 2,
    PolicyLevelType_AppDomain = 3
};

struct __declspec(uuid("df4e1bb0-8cdc-3c4b-a1c9-fee64bbef8c5"))
SecurityManager;
    // [ default ] interface _SecurityManager
    // interface _Object

enum __declspec(uuid("902a6b65-41bd-32f1-a233-075f009d459c"))
SecurityZone
{
    SecurityZone_MyComputer = 0,
    SecurityZone_Intranet = 1,
    SecurityZone_Trusted = 2,
    SecurityZone_Internet = 3,
    SecurityZone_Untrusted = 4,
    SecurityZone_NoZone = -1
};

struct __declspec(uuid("ebaa029c-01c0-32b6-aae6-fe21adfc3e5d"))
VerificationException;
    // [ default ] interface _VerificationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("1764148e-73c1-320a-83fc-337de81a68b4"))
ContextAttribute;
    // [ default ] interface _ContextAttribute
    // interface _Object
    // interface _Attribute
    // interface IContextAttribute
    // interface IContextProperty

struct __declspec(uuid("614e973a-b737-38f5-9ddf-5825ac923135"))
AsyncResult;
    // [ default ] interface _AsyncResult
    // interface _Object
    // interface IAsyncResult
    // interface IMessageSink

struct __declspec(uuid("9d0df3b9-107c-3392-88c8-fe629ca21dab"))
CallContext;
    // [ default ] interface _CallContext
    // interface _Object

struct __declspec(uuid("4d125449-ba27-3927-8589-3e1b34b622e5"))
ILogicalThreadAffinative : IDispatch
{};

struct __declspec(uuid("5db435a0-0db3-3f4a-bf49-191a69d451bb"))
LogicalCallContext;
    // [ default ] interface _LogicalCallContext
    // interface _Object
    // interface ISerializable
    // interface ICloneable

struct __declspec(uuid("d625ba4c-7c4c-3b86-99ea-780204ede5cd"))
ChannelServices;
    // [ default ] interface _ChannelServices
    // interface _Object

struct __declspec(uuid("dd5856e5-8151-3334-b8e9-07cb152b20a4"))
ClientChannelSinkStack;
    // [ default ] interface _ClientChannelSinkStack
    // interface _Object
    // interface IClientChannelSinkStack
    // interface IClientResponseChannelSinkStack

struct __declspec(uuid("5c35f099-165e-3225-a3a5-564150ea17f5"))
ServerChannelSinkStack;
    // [ default ] interface _ServerChannelSinkStack
    // interface _Object
    // interface IServerChannelSinkStack
    // interface IServerResponseChannelSinkStack

struct __declspec(uuid("fd8c8fce-4f85-36b2-b8e8-f5a183654539"))
ClientSponsor;
    // [ default ] interface _ClientSponsor
    // interface _Object
    // interface ISponsor

enum __declspec(uuid("669212cb-7972-3073-bdb0-6782534b6590"))
WellKnownObjectMode
{
    WellKnownObjectMode_Singleton = 1,
    WellKnownObjectMode_SingleCall = 2
};

struct __declspec(uuid("8de7f105-07f6-31a8-8469-bafcdc5024b8"))
CrossContextDelegate;
    // [ default ] interface _CrossContextDelegate
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("a36e4eaf-ea3f-30a6-906d-374bbf7903b1"))
Context;
    // [ default ] interface _Context
    // interface _Object

struct __declspec(uuid("6134805f-e8ff-3fd8-931e-4d847bca7551"))
ContextProperty;
    // [ default ] interface _ContextProperty
    // interface _Object

struct __declspec(uuid("563581e8-c86d-39e2-b2e8-6c23f7987a4b"))
IChannel : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ChannelPriority (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ChannelName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Parse (
        /*[in]*/ BSTR Url,
        /*[out]*/ BSTR * objectURI,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("48ad41da-0872-31da-9887-f81f213527e6"))
IChannelReceiver : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ChannelData (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetUrlsForUri (
        /*[in]*/ BSTR objectURI,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall StartListening (
        /*[in]*/ VARIANT data ) = 0;
      virtual HRESULT __stdcall StopListening (
        /*[in]*/ VARIANT data ) = 0;
};

struct __declspec(uuid("bc5062b6-79e8-3f19-a87e-f9daf826960c"))
EnterpriseServicesHelper;
    // [ default ] interface _EnterpriseServicesHelper
    // interface _Object

struct __declspec(uuid("14309fab-eacd-3c64-877e-07eb01b89c91"))
Header;
    // [ default ] interface _Header
    // interface _Object

struct __declspec(uuid("cc4c81b2-365e-3ba5-b374-a949b727e929"))
HeaderHandler;
    // [ default ] interface _HeaderHandler
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

enum __declspec(uuid("b946ac61-dd6b-39f3-bbe1-e4c1540f16ea"))
ActivatorLevel
{
    ActivatorLevel_Construction = 4,
    ActivatorLevel_Context = 8,
    ActivatorLevel_AppDomain = 12,
    ActivatorLevel_Process = 16,
    ActivatorLevel_Machine = 20
};

struct __declspec(uuid("b90efaa6-25e4-33d2-aca3-94bf74dc4ab9"))
IMethodCallMessage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_InArgCount (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInArgName (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInArg (
        /*[in]*/ long argNum,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_InArgs (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("ca0ab564-f5e9-3a7f-a80b-eb0aeefa44e9"))
IConstructionReturnMessage : IDispatch
{};

struct __declspec(uuid("6d94b6f3-da91-3c2f-b876-083769667468"))
IClientFormatterSinkProvider : IDispatch
{};

struct __declspec(uuid("042b5200-4317-3e4d-b653-7e9a08f1a5f2"))
IServerFormatterSinkProvider : IDispatch
{};

enum __declspec(uuid("a026e65f-9720-3f82-8de1-a18e51180a34"))
ServerProcessing
{
    ServerProcessing_Complete = 0,
    ServerProcessing_OneWay = 1,
    ServerProcessing_Async = 2
};

struct __declspec(uuid("46527c03-b144-3cf0-86b3-b8776148a6e9"))
IClientFormatterSink : IDispatch
{};

struct __declspec(uuid("1e250ccd-dc30-3217-a7e4-148f375a0088"))
IChannelDataStore : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ChannelUris (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT key,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Item (
        /*[in]*/ VARIANT key,
        /*[in]*/ VARIANT pRetVal ) = 0;
};

struct __declspec(uuid("f3e38cea-40e4-33c1-9df7-bd103be2d68b"))
ChannelDataStore;
    // [ default ] interface _ChannelDataStore
    // interface _Object
    // interface IChannelDataStore

struct __declspec(uuid("1ac82fbe-4ff0-383c-bbfd-fe40ecb3628d"))
ITransportHeaders : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT key,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Item (
        /*[in]*/ VARIANT key,
        /*[in]*/ VARIANT pRetVal ) = 0;
      virtual HRESULT __stdcall GetEnumerator (
        /*[out,retval]*/ struct IEnumVARIANT * * pRetVal ) = 0;
};

struct __declspec(uuid("48728b3f-f7d9-36c1-b3e7-8bf2e63ce1b3"))
TransportHeaders;
    // [ default ] interface _TransportHeaders
    // interface _Object
    // interface ITransportHeaders

struct __declspec(uuid("b8be8d68-5fe6-38c5-838e-67ce2fca9d70"))
SinkProviderData;
    // [ default ] interface _SinkProviderData
    // interface _Object

struct __declspec(uuid("f369a73e-78d8-3bcc-ae36-522d116e19f9"))
BaseChannelObjectWithProperties;
    // [ default ] interface _BaseChannelObjectWithProperties
    // interface _Object
    // interface IDictionary
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("0e9eb6e5-d899-3132-90c5-7376970c4fb5"))
BaseChannelSinkWithProperties;
    // [ default ] interface _BaseChannelSinkWithProperties
    // interface _Object
    // interface IDictionary
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("22282340-9e30-3591-bd1e-6571930e8582"))
BaseChannelWithProperties;
    // [ default ] interface _BaseChannelWithProperties
    // interface _Object
    // interface IDictionary
    // interface ICollection
    // interface IEnumerable

struct __declspec(uuid("00a358d4-4d58-3b9d-8fb6-fb7f6bc1713b"))
IDynamicProperty : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("3677cbb0-784d-3c15-bbc8-75cd7dc3901e"))
IMessageCtrl : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Cancel (
        /*[in]*/ long msToCancel ) = 0;
};

enum __declspec(uuid("a2c06560-e728-39d5-8230-7eb08001c79e"))
LeaseState
{
    LeaseState_Null = 0,
    LeaseState_Initial = 1,
    LeaseState_Active = 2,
    LeaseState_Renewing = 3,
    LeaseState_Expired = 4
};

struct __declspec(uuid("8fd730c1-dd1b-3694-84a1-8ce7159e266b"))
LifetimeServices;
    // [ default ] interface _LifetimeServices
    // interface _Object

struct __declspec(uuid("7b3bbd13-c870-3105-b123-ffca166cdc04"))
ReturnMessage;
    // [ default ] interface _ReturnMessage
    // interface _Object
    // interface IMethodReturnMessage
    // interface IMethodMessage
    // interface IMessage

struct __declspec(uuid("4f592b1f-4a0c-3fc0-9914-3677f64fc5a8"))
MethodCall;
    // [ default ] interface _MethodCall
    // interface _Object
    // interface IMethodCallMessage
    // interface IMethodMessage
    // interface IMessage
    // interface ISerializable

struct __declspec(uuid("54dac96d-ecaf-38db-a27b-3ddb102130c4"))
ConstructionCall;
    // [ default ] interface _ConstructionCall
    // interface _Object
    // interface IMethodCallMessage
    // interface IMethodMessage
    // interface IMessage
    // interface ISerializable
    // interface IConstructionCallMessage

struct __declspec(uuid("7e7bf3c0-b07b-3209-a424-7bc35d76ea7d"))
MethodResponse;
    // [ default ] interface _MethodResponse
    // interface _Object
    // interface IMethodReturnMessage
    // interface IMethodMessage
    // interface IMessage
    // interface ISerializable

struct __declspec(uuid("cc18fd4d-aa2d-3ab4-9848-584bbae4ab44"))
IFieldInfo : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_FieldNames (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_FieldNames (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
      virtual HRESULT __stdcall get_FieldTypes (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_FieldTypes (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
};

struct __declspec(uuid("25e8547a-6b49-3f00-b963-d45fdcef4f11"))
ConstructionResponse;
    // [ default ] interface _ConstructionResponse
    // interface _Object
    // interface IMethodReturnMessage
    // interface IMethodMessage
    // interface IMessage
    // interface ISerializable
    // interface IConstructionReturnMessage

struct __declspec(uuid("30c4cd02-66a2-3abe-bc6c-638e6730e534"))
InternalMessageWrapper;
    // [ default ] interface _InternalMessageWrapper
    // interface _Object

struct __declspec(uuid("40133645-ffaf-3a9c-b408-997e049d5c11"))
MethodCallMessageWrapper;
    // [ default ] interface _MethodCallMessageWrapper
    // interface _Object
    // interface IMethodCallMessage
    // interface IMethodMessage
    // interface IMessage

struct __declspec(uuid("2ec528fb-b987-3b3b-a444-9f94c3a257c1"))
MethodReturnMessageWrapper;
    // [ default ] interface _MethodReturnMessageWrapper
    // interface _Object
    // interface IMethodReturnMessage
    // interface IMethodMessage
    // interface IMessage

//struct __declspec(uuid("abeb0459-03b9-35af-96e1-66bb7bc923f7"))
//ObjectHandle;
    // [ default ] interface _ObjectHandle
    // interface _Object
    // interface IObjectHandle

struct __declspec(uuid("855e6566-014a-3fe8-aa70-1eac771e3a88"))
IChannelInfo : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ChannelData (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ChannelData (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
};

struct __declspec(uuid("21f5a790-53ea-3d73-86c3-a5ba6cf65fe9"))
ObjRef;
    // [ default ] interface _ObjRef
    // interface _Object
    // interface IObjectReference
    // interface ISerializable

struct __declspec(uuid("c30abd41-7b5a-3d10-a6ef-56862e2979b6"))
OneWayAttribute;
    // [ default ] interface _OneWayAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("1163d0ca-2a02-37c1-bf3f-a9b9e9d49245"))
ProxyAttribute;
    // [ default ] interface _ProxyAttribute
    // interface _Object
    // interface _Attribute
    // interface IContextAttribute

struct __declspec(uuid("531d00a5-2cff-30d7-8245-97e18cd4d037"))
RealProxy;
    // [ default ] interface _RealProxy
    // interface _Object

enum __declspec(uuid("c888351b-5dfd-3a9f-8d36-96e7770d0ebf"))
SoapOption
{
    SoapOption_None = 0,
    SoapOption_AlwaysIncludeTypes = 1,
    SoapOption_XsdString = 2,
    SoapOption_EmbedAll = 4,
    SoapOption_Option1 = 8,
    SoapOption_Option2 = 16
};

enum __declspec(uuid("0ad279c7-05fb-3a46-9031-92e00c9f7c29"))
XmlFieldOrderOption
{
    XmlFieldOrderOption_All = 0,
    XmlFieldOrderOption_Sequence = 1,
    XmlFieldOrderOption_Choice = 2
};

struct __declspec(uuid("9b924ec5-bf13-3a98-8ac0-80877995d403"))
SoapAttribute;
    // [ default ] interface _SoapAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("9c67f424-22dc-3d05-ab36-17eaf95881f2"))
SoapTypeAttribute;
    // [ default ] interface _SoapTypeAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("01ff4e4b-8ad0-3171-8c82-5c2f48b87e3d"))
SoapMethodAttribute;
    // [ default ] interface _SoapMethodAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("5b76534c-3acc-3d52-aa61-d788b134abe2"))
SoapFieldAttribute;
    // [ default ] interface _SoapFieldAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("c76b435d-86c2-30fd-9329-e2603246095c"))
SoapParameterAttribute;
    // [ default ] interface _SoapParameterAttribute
    // interface _Object
    // interface _Attribute

struct __declspec(uuid("3db6f309-9dab-36ec-8036-d901172c994c"))
RemotingConfiguration;
    // [ default ] interface _RemotingConfiguration
    // interface _Object

struct __declspec(uuid("4e52d7d6-9fdf-3b59-b318-778e0f40f37c"))
TypeEntry;
    // [ default ] interface _TypeEntry
    // interface _Object

struct __declspec(uuid("3ed0f148-e447-3efe-8488-3c834082cc96"))
ActivatedClientTypeEntry;
    // [ default ] interface _ActivatedClientTypeEntry
    // interface _Object

struct __declspec(uuid("6cd360cd-d53d-3775-87ef-00d72e6645f5"))
ActivatedServiceTypeEntry;
    // [ default ] interface _ActivatedServiceTypeEntry
    // interface _Object

struct __declspec(uuid("6b3b6647-b39d-3ed4-992f-df6c49ace82e"))
WellKnownClientTypeEntry;
    // [ default ] interface _WellKnownClientTypeEntry
    // interface _Object

struct __declspec(uuid("2ce0da26-18ef-3cf4-abac-be90965f5f90"))
WellKnownServiceTypeEntry;
    // [ default ] interface _WellKnownServiceTypeEntry
    // interface _Object

enum __declspec(uuid("82febf4c-9fc8-3285-8d5a-f00dd1e1ba40"))
CustomErrorsModes
{
    CustomErrorsModes_On = 0,
    CustomErrorsModes_Off = 1,
    CustomErrorsModes_RemoteOnly = 2
};

struct __declspec(uuid("24540ebc-316e-35d2-80db-8a535caf6a35"))
RemotingException;
    // [ default ] interface _RemotingException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("db13821e-9835-3958-8539-1e021399ab6c"))
ServerException;
    // [ default ] interface _ServerException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("3cded51a-86b4-39f0-a12a-5d1fdced6546"))
RemotingTimeoutException;
    // [ default ] interface _RemotingTimeoutException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("8df4c38a-8492-3c47-8332-d9d04faf3c59"))
RemotingServices;
    // [ default ] interface _RemotingServices
    // interface _Object

struct __declspec(uuid("53a3c917-bb24-3908-b58b-09ecda99265f"))
InternalRemotingServices;
    // [ default ] interface _InternalRemotingServices
    // interface _Object

struct __declspec(uuid("c48ca9bc-bbdb-3059-aec8-763cf7e9a88c"))
MessageSurrogateFilter;
    // [ default ] interface _MessageSurrogateFilter
    // interface _Delegate
    // interface _Object
    // interface ICloneable
    // interface ISerializable

struct __declspec(uuid("24eec005-3938-3c71-821d-7f68fd850b2d"))
RemotingSurrogateSelector;
    // [ default ] interface _RemotingSurrogateSelector
    // interface _Object
    // interface ISurrogateSelector

struct __declspec(uuid("da5681da-7c21-3a2d-afac-69e3a4d11f4d"))
SoapServices;
    // [ default ] interface _SoapServices
    // interface _Object

struct __declspec(uuid("80031d2a-ad59-3fb4-97f3-b864d71da86b"))
ISoapXsd : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetXsdType (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("48ad62e8-bd40-37f4-8fd7-f7a17478a8e6"))
SoapDateTime;
    // [ default ] interface _SoapDateTime
    // interface _Object

struct __declspec(uuid("de47d9cf-0107-3d66-93e9-a8acb06b4583"))
SoapDuration;
    // [ default ] interface _SoapDuration
    // interface _Object

struct __declspec(uuid("d049dc2b-82c3-3350-a1cc-bf69fee3825e"))
SoapTime;
    // [ default ] interface _SoapTime
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("2decbcb7-bac0-316d-9131-43035c5cb480"))
SoapDate;
    // [ default ] interface _SoapDate
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("a7136bdf-b141-3913-9d1c-9bc5aff21470"))
SoapYearMonth;
    // [ default ] interface _SoapYearMonth
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("75999eba-0679-3d43-bdc4-02e4d637f1b1"))
SoapYear;
    // [ default ] interface _SoapYear
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("463ae13f-c7e5-357e-a41c-df8762fff85c"))
SoapMonthDay;
    // [ default ] interface _SoapMonthDay
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("c9f0a842-3ce1-338f-a1d4-6d7bb397bdaa"))
SoapDay;
    // [ default ] interface _SoapDay
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("caec7d4f-0b02-3579-943f-821738ee78cc"))
SoapMonth;
    // [ default ] interface _SoapMonth
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("8c1425c9-a7d3-35cd-8248-928ca52ad49b"))
SoapHexBinary;
    // [ default ] interface _SoapHexBinary
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("f59d514c-f200-319f-bf3f-9e4e23b2848c"))
SoapBase64Binary;
    // [ default ] interface _SoapBase64Binary
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("09a60795-31c0-3a79-9250-8d93c74fe540"))
SoapInteger;
    // [ default ] interface _SoapInteger
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("7b769b29-35f0-3bdc-aae9-e99937f6cdec"))
SoapPositiveInteger;
    // [ default ] interface _SoapPositiveInteger
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("2bb6c5e0-c2b9-3608-8868-21cfd6ddb91e"))
SoapNonPositiveInteger;
    // [ default ] interface _SoapNonPositiveInteger
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("6850404f-d7fb-32bd-8328-c94f66e8c1c7"))
SoapNonNegativeInteger;
    // [ default ] interface _SoapNonNegativeInteger
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("c41d0b30-a518-3093-a18f-364af9e71eb7"))
SoapNegativeInteger;
    // [ default ] interface _SoapNegativeInteger
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("cdfa7117-b2a4-3a3f-b393-bc19d44f9749"))
SoapAnyUri;
    // [ default ] interface _SoapAnyUri
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("d8a4f3eb-e7ec-3620-831a-b052a67c9944"))
SoapQName;
    // [ default ] interface _SoapQName
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("b54e38f8-17ff-3d0a-9ff3-5e662de2055f"))
SoapNotation;
    // [ default ] interface _SoapNotation
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("0e71f9bd-c109-3352-bd60-14f96d56b6f3"))
SoapNormalizedString;
    // [ default ] interface _SoapNormalizedString
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("777f668e-3272-39cd-a8b5-860935a35181"))
SoapToken;
    // [ default ] interface _SoapToken
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("84f70b6c-d59e-394a-b879-ffcc30ddcaa2"))
SoapLanguage;
    // [ default ] interface _SoapLanguage
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("4e515531-7a71-3cdd-8078-0a01c85c8f9d"))
SoapName;
    // [ default ] interface _SoapName
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("2763be6b-f8cf-39d9-a2e8-9e9815c0815e"))
SoapIdrefs;
    // [ default ] interface _SoapIdrefs
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("9a3a64f4-8ba5-3dcf-880c-8d3ee06c5538"))
SoapEntities;
    // [ default ] interface _SoapEntities
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("c498f2d9-a77c-3d4b-a1a5-12cc7b99115d"))
SoapNmtoken;
    // [ default ] interface _SoapNmtoken
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("14be6b21-c682-3a3a-8b24-fee75b4ff8c5"))
SoapNmtokens;
    // [ default ] interface _SoapNmtokens
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("d13b741d-051f-322f-93aa-1367a3c8aafb"))
SoapNcName;
    // [ default ] interface _SoapNcName
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("fa0b54d5-f221-3648-a20c-f67a96f4a207"))
SoapId;
    // [ default ] interface _SoapId
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("433ca926-9887-3541-89cc-5d74d0259144"))
SoapIdref;
    // [ default ] interface _SoapIdref
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("f00ca7a7-4b8d-3f2f-a5f2-ce4a4478b39c"))
SoapEntity;
    // [ default ] interface _SoapEntity
    // interface _Object
    // interface ISoapXsd

struct __declspec(uuid("5520b6d3-6ec6-3ce7-958b-e69faf6eff99"))
SynchronizationAttribute;
    // [ default ] interface _SynchronizationAttribute
    // interface _Object
    // interface _Attribute
    // interface IContextAttribute
    // interface IContextProperty
    // interface IContributeServerContextSink
    // interface IContributeClientContextSink

struct __declspec(uuid("e822f35c-ddc2-3fb2-9768-a2aebced7c40"))
TrackingServices;
    // [ default ] interface _TrackingServices
    // interface _Object

struct __declspec(uuid("79c14066-e37e-3643-a449-d166fa0e8ec2"))
UrlAttribute;
    // [ default ] interface _UrlAttribute
    // interface _Object
    // interface _Attribute
    // interface IContextAttribute
    // interface IContextProperty

enum __declspec(uuid("b3e5a7ff-afc6-3f2b-8fff-300c7c567693"))
IsolatedStorageScope
{
    IsolatedStorageScope_None = 0,
    IsolatedStorageScope_User = 1,
    IsolatedStorageScope_Domain = 2,
    IsolatedStorageScope_Assembly = 4,
    IsolatedStorageScope_Roaming = 8,
    IsolatedStorageScope_Machine = 16,
    IsolatedStorageScope_Application = 32
};

struct __declspec(uuid("70541b17-bf7e-399b-8d33-2afa4f5af395"))
IsolatedStorage;
    // [ default ] interface _IsolatedStorage
    // interface _Object

struct __declspec(uuid("5e45c68a-e894-3b38-aeee-634540bd0d57"))
IsolatedStorageFile;
    // [ default ] interface _IsolatedStorageFile
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("e5cfdffc-aeb5-3489-b12c-640f7b031b57"))
IsolatedStorageFileStream;
    // [ default ] interface _IsolatedStorageFileStream
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("4479c009-4cc3-39a2-8f92-dfcdf034f748"))
IsolatedStorageException;
    // [ default ] interface _IsolatedStorageException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("f5006531-d4d7-319e-9eda-9b4b65ad8d4f"))
INormalizeForIsolatedStorage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Normalize (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

enum __declspec(uuid("72b06367-de53-3111-9c49-b816efee3148"))
FormatterTypeStyle
{
    FormatterTypeStyle_TypesWhenNeeded = 0,
    FormatterTypeStyle_TypesAlways = 1,
    FormatterTypeStyle_XsdString = 2
};

enum __declspec(uuid("f18130e7-bd6c-37f4-9488-35f9fb832ac7"))
FormatterAssemblyStyle
{
    FormatterAssemblyStyle_Simple = 0,
    FormatterAssemblyStyle_Full = 1
};

enum __declspec(uuid("c5d299ac-63b0-3448-bcb7-6aa9b5eb598e"))
TypeFilterLevel
{
    TypeFilterLevel_Low = 2,
    TypeFilterLevel_Full = 3
};

struct __declspec(uuid("e699146c-7793-3455-9bef-964c90d8f995"))
ISoapMessage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ParamNames (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ParamNames (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ParamValues (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ParamValues (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ParamTypes (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ParamTypes (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_MethodName (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_XmlNameSpace (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_XmlNameSpace (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_headers (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall put_headers (
        /*[in]*/ SAFEARRAY * pRetVal ) = 0;
};

struct __declspec(uuid("cf8f7fcf-94fe-3516-90e9-c103156dd2d5"))
InternalRM;
    // [ default ] interface _InternalRM
    // interface _Object

struct __declspec(uuid("cbbaf6ec-251a-3480-8a3d-4d56bc7320d0"))
InternalST;
    // [ default ] interface _InternalST
    // interface _Object

struct __declspec(uuid("e772bbe6-cb52-3c19-876a-d1bfa2305f4e"))
SoapMessage;
    // [ default ] interface _SoapMessage
    // interface _Object
    // interface ISoapMessage

struct __declspec(uuid("a8d058c4-d923-3859-9490-d3888fc90439"))
SoapFault;
    // [ default ] interface _SoapFault
    // interface _Object
    // interface ISerializable

struct __declspec(uuid("817accb7-35d8-3c18-baf2-0a5ce2157b74"))
ServerFault;
    // [ default ] interface _ServerFault
    // interface _Object

struct __declspec(uuid("50369004-db9a-3a75-be7a-1d0ef017b9d3"))
BinaryFormatter;
    // [ default ] interface _BinaryFormatter
    // interface _Object
    // interface IRemotingFormatter
    // interface IFormatter

struct __declspec(uuid("bebb2505-8b54-3443-aead-142a16dd9cc7"))
_AssemblyBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("0814be2a-48e5-3d61-90f3-ef3d05df9d5e"))
AssemblyBuilder;
    // interface _Object
    // interface _Assembly
    // interface IEvidenceFactory
    // interface ICustomAttributeProvider
    // interface ISerializable
    // [ default ] interface _AssemblyBuilder

enum __declspec(uuid("f0778630-ac34-3d71-9fab-617f61243065"))
AssemblyBuilderAccess
{
    AssemblyBuilderAccess_Run = 1,
    AssemblyBuilderAccess_Save = 2,
    AssemblyBuilderAccess_RunAndSave = 3,
    AssemblyBuilderAccess_ReflectionOnly = 6
};

struct __declspec(uuid("ed3e4384-d7e2-3fa7-8ffd-8940d330519a"))
_ConstructorBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("be9acce8-aaff-3b91-81ae-8211663f5cad"))
_CustomAttributeBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("c7bd73de-9f85-3290-88ee-090b8bdfe2df"))
_EnumBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("aadaba99-895d-3d65-9760-b1f12621fae8"))
_EventBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("ce1a3bf5-975e-30cc-97c9-1ef70f8f3993"))
_FieldBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("a4924b27-6e3b-37f7-9b83-a4501955e6a7"))
_ILGenerator : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("4e6350d1-a08b-3dec-9a3e-c465f9aeec0c"))
_LocalBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("007d8a14-fdf3-363e-9a0b-fec0618260a2"))
_MethodBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("c2323c25-f57f-3880-8a4d-12ebea7a5852"))
_MethodRental : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("d05ffa9a-04af-3519-8ee1-8d93ad73430b"))
_ModuleBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("36329eba-f97a-3565-bc07-0ed5c6ef19fc"))
_ParameterBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("15f9a479-9397-3a63-acbd-f51977fb0f02"))
_PropertyBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("7d13dd37-5a04-393c-bbca-a5fea802893d"))
_SignatureHelper : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("7e5678ee-48b3-3f83-b076-c58543498a58"))
_TypeBuilder : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
};

struct __declspec(uuid("93c24cdb-4014-3efd-b564-e836ba48c765"))
ConstructorBuilder;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _MethodBase
    // interface _ConstructorInfo
    // [ default ] interface _ConstructorBuilder

struct __declspec(uuid("5a3dcd44-5855-3d89-a0ec-ce50a3b144a9"))
ILGenerator;
    // interface _Object
    // [ default ] interface _ILGenerator

struct __declspec(uuid("a6d0f5a1-9218-30d4-8ad7-18ca98ac8026"))
DynamicILInfo;
    // [ default ] interface _DynamicILInfo
    // interface _Object

struct __declspec(uuid("5b9f3fa2-dabb-3887-93f6-663d83a93858"))
DynamicMethod;
    // [ default ] interface _DynamicMethod
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _MethodBase
    // interface _MethodInfo

struct __declspec(uuid("dc18b7ec-91e4-3999-910a-188d7afa0a68"))
EventBuilder;
    // interface _Object
    // [ default ] interface _EventBuilder

#pragma pack(push, 4)

struct __declspec(uuid("4e8b1bb8-6a6f-3b57-8afa-0129550b07be"))
EventToken
{
    long m_event;
};

#pragma pack(pop)

struct __declspec(uuid("36d63e48-1646-345f-a3d4-b34e4c42c3c5"))
FieldBuilder;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _FieldInfo
    // [ default ] interface _FieldBuilder

#pragma pack(push, 4)

struct __declspec(uuid("24246833-61eb-329d-bddf-0daf3874062b"))
FieldToken
{
    long m_fieldTok;
    IUnknown * m_class;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("a419b664-dabd-383d-a0db-991487d41e14"))
Label
{
    long m_label;
};

#pragma pack(pop)

struct __declspec(uuid("a6bcaa25-d357-3f79-a716-ad1434e4d832"))
LocalBuilder;
    // interface _Object
    // [ default ] interface _LocalBuilder

struct __declspec(uuid("53df4fb3-a164-37d3-8310-f0d15730ab32"))
MethodBuilder;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _MethodBase
    // interface _MethodInfo
    // [ default ] interface _MethodBuilder

struct __declspec(uuid("71bc3e08-0082-320a-8ba5-efa8d2b9798a"))
CustomAttributeBuilder;
    // interface _Object
    // [ default ] interface _CustomAttributeBuilder

struct __declspec(uuid("726d83b0-9a52-36b0-919c-60e625f03211"))
MethodRental;
    // interface _Object
    // [ default ] interface _MethodRental

#pragma pack(push, 4)

struct __declspec(uuid("0efe423a-a87e-33d9-8bf4-2d212620ee5f"))
MethodToken
{
    long m_method;
};

#pragma pack(pop)

struct __declspec(uuid("fb2ed445-2862-3a63-9f5a-bbf6c2195dce"))
ModuleBuilder;
    // interface _Object
    // interface _Module
    // interface ISerializable
    // interface ICustomAttributeProvider
    // [ default ] interface _ModuleBuilder

enum __declspec(uuid("e87fa4d7-0caa-3c24-be83-cf98b50186e2"))
PEFileKinds
{
    PEFileKinds_Dll = 1,
    PEFileKinds_ConsoleApplication = 2,
    PEFileKinds_WindowApplication = 3
};

struct __declspec(uuid("2a59a0e6-11b2-3025-92de-e036a6ddbc00"))
OpCodes;
    // [ default ] interface _OpCodes
    // interface _Object

enum __declspec(uuid("8abd8cb3-a365-32f9-9914-f08ec1fec4ca"))
OpCodeType
{
    OpCodeType_Annotation = 0,
    OpCodeType_Macro = 1,
    OpCodeType_Nternal = 2,
    OpCodeType_Objmodel = 3,
    OpCodeType_Prefix = 4,
    OpCodeType_Primitive = 5
};

enum __declspec(uuid("d25ed092-a7a8-3bbe-820c-42f5a4604768"))
StackBehaviour
{
    StackBehaviour_Pop0 = 0,
    StackBehaviour_Pop1 = 1,
    StackBehaviour_Pop1_pop1 = 2,
    StackBehaviour_Popi = 3,
    StackBehaviour_Popi_pop1 = 4,
    StackBehaviour_Popi_popi = 5,
    StackBehaviour_Popi_popi8 = 6,
    StackBehaviour_Popi_popi_popi = 7,
    StackBehaviour_Popi_popr4 = 8,
    StackBehaviour_Popi_popr8 = 9,
    StackBehaviour_Popref = 10,
    StackBehaviour_Popref_pop1 = 11,
    StackBehaviour_Popref_popi = 12,
    StackBehaviour_Popref_popi_popi = 13,
    StackBehaviour_Popref_popi_popi8 = 14,
    StackBehaviour_Popref_popi_popr4 = 15,
    StackBehaviour_Popref_popi_popr8 = 16,
    StackBehaviour_Popref_popi_popref = 17,
    StackBehaviour_Push0 = 18,
    StackBehaviour_Push1 = 19,
    StackBehaviour_Push1_push1 = 20,
    StackBehaviour_Pushi = 21,
    StackBehaviour_Pushi8 = 22,
    StackBehaviour_Pushr4 = 23,
    StackBehaviour_Pushr8 = 24,
    StackBehaviour_Pushref = 25,
    StackBehaviour_Varpop = 26,
    StackBehaviour_Varpush = 27,
    StackBehaviour_Popref_popi_pop1 = 28
};

enum __declspec(uuid("b125618b-1b4e-37c3-b31a-331d6021b52d"))
OperandType
{
    OperandType_InlineBrTarget = 0,
    OperandType_InlineField = 1,
    OperandType_InlineI = 2,
    OperandType_InlineI8 = 3,
    OperandType_InlineMethod = 4,
    OperandType_InlineNone = 5,
    OperandType_InlinePhi = 6,
    OperandType_InlineR = 7,
    OperandType_InlineSig = 9,
    OperandType_InlineString = 10,
    OperandType_InlineSwitch = 11,
    OperandType_InlineTok = 12,
    OperandType_InlineType = 13,
    OperandType_InlineVar = 14,
    OperandType_ShortInlineBrTarget = 15,
    OperandType_ShortInlineI = 16,
    OperandType_ShortInlineR = 17,
    OperandType_ShortInlineVar = 18
};

enum __declspec(uuid("75a7861c-767e-3a5e-a57b-6ec136009654"))
FlowControl
{
    FlowControl_Branch = 0,
    FlowControl_Break = 1,
    FlowControl_Call = 2,
    FlowControl_Cond_Branch = 3,
    FlowControl_Meta = 4,
    FlowControl_Next = 5,
    FlowControl_Phi = 6,
    FlowControl_Return = 7,
    FlowControl_Throw = 8
};

#pragma pack(push, 4)

struct __declspec(uuid("a7ed05c6-fecf-3c35-ba3b-84163ac1d5e5"))
OpCode
{
    LPSTR m_stringname;
    enum StackBehaviour m_pop;
    enum StackBehaviour m_push;
    enum OperandType m_operand;
    enum OpCodeType m_type;
    long m_size;
    unsigned char m_s1;
    unsigned char m_s2;
    enum FlowControl m_ctrl;
    long m_endsUncondJmpBlk;
    long m_stackChange;
};

#pragma pack(pop)

struct __declspec(uuid("027ad5c3-d619-3506-b8e6-ca67a33b9c8f"))
ParameterBuilder;
    // interface _Object
    // [ default ] interface _ParameterBuilder

#pragma pack(push, 4)

struct __declspec(uuid("cfb98ca9-8121-35be-af40-c176c616a16b"))
ParameterToken
{
    long m_tkParameter;
};

#pragma pack(pop)

struct __declspec(uuid("22d4c021-1b3c-3ee3-93b6-4c9d810ce077"))
PropertyBuilder;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _PropertyInfo
    // [ default ] interface _PropertyBuilder

#pragma pack(push, 4)

struct __declspec(uuid("566833c7-f4a0-30ee-bd7e-44752ad570e6"))
PropertyToken
{
    long m_property;
};

#pragma pack(pop)

struct __declspec(uuid("798b57a2-064a-3098-9a80-e12da70e0085"))
SignatureHelper;
    // interface _Object
    // [ default ] interface _SignatureHelper

#pragma pack(push, 4)

struct __declspec(uuid("155e1466-0e84-3f2b-b825-f6525523407c"))
SignatureToken
{
    long m_signature;
    struct _ModuleBuilder * m_moduleBuilder;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("8cf0278d-d0ad-307d-be63-a785432e3fdf"))
StringToken
{
    long m_string;
};

#pragma pack(pop)

enum __declspec(uuid("3e0af669-1cd8-3afc-9f2c-e81c2b810135"))
PackingSize
{
    PackingSize_Unspecified = 0,
    PackingSize_Size1 = 1,
    PackingSize_Size2 = 2,
    PackingSize_Size4 = 4,
    PackingSize_Size8 = 8,
    PackingSize_Size16 = 16,
    PackingSize_Size32 = 32,
    PackingSize_Size64 = 64,
    PackingSize_Size128 = 128
};

struct __declspec(uuid("0f445332-e34c-3f8c-90ed-ab7f0724adab"))
TypeBuilder;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _Type
    // interface IReflect
    // [ default ] interface _TypeBuilder

struct __declspec(uuid("a2289b64-5de0-38ba-9266-b55e3598c901"))
GenericTypeParameterBuilder;
    // [ default ] interface _GenericTypeParameterBuilder
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _Type
    // interface IReflect

struct __declspec(uuid("70f855da-4948-38ab-a727-431c386ab9f5"))
EnumBuilder;
    // interface _Object
    // interface ICustomAttributeProvider
    // interface _MemberInfo
    // interface _Type
    // interface IReflect
    // [ default ] interface _EnumBuilder

#pragma pack(push, 4)

struct __declspec(uuid("048fa0c2-8ebb-3bc2-a47f-01f12a32008e"))
TypeToken
{
    long m_class;
};

#pragma pack(pop)

struct __declspec(uuid("e3c3a258-e508-3704-b9eb-264601956fe5"))
UnmanagedMarshal;
    // [ default ] interface _UnmanagedMarshal
    // interface _Object

enum __declspec(uuid("ddd019bf-d182-34de-9192-95575f7b2a31"))
AssemblyHashAlgorithm
{
    AssemblyHashAlgorithm_None = 0,
    AssemblyHashAlgorithm_MD5 = 32771,
    AssemblyHashAlgorithm_SHA1 = 32772
};

#pragma pack(push, 4)

struct __declspec(uuid("42a66664-072f-3a67-a189-7d440709a77e"))
AssemblyHash
{
    enum AssemblyHashAlgorithm _Algorithm;
    SAFEARRAY * _value;
};

#pragma pack(pop)

enum __declspec(uuid("e3dc8079-43bc-3e70-b291-1591cc9e451d"))
AssemblyVersionCompatibility
{
    AssemblyVersionCompatibility_SameMachine = 1,
    AssemblyVersionCompatibility_SameProcess = 2,
    AssemblyVersionCompatibility_SameDomain = 3
};

enum __declspec(uuid("75c9e85e-d2d1-32db-bf9c-0636f94fb0c2"))
CipherMode
{
    CipherMode_CBC = 1,
    CipherMode_ECB = 2,
    CipherMode_OFB = 3,
    CipherMode_CFB = 4,
    CipherMode_CTS = 5
};

enum __declspec(uuid("1254089d-0104-3bfb-b6ba-9168f994dca6"))
PaddingMode
{
    PaddingMode_None = 1,
    PaddingMode_PKCS7 = 2,
    PaddingMode_Zeros = 3,
    PaddingMode_ANSIX923 = 4,
    PaddingMode_ISO10126 = 5
};

struct __declspec(uuid("d7a12132-100f-37ae-a277-268a2656e476"))
KeySizes;
    // [ default ] interface _KeySizes
    // interface _Object

struct __declspec(uuid("7f8c7dc5-d8b4-3758-981f-02af6b42461a"))
CryptographicException;
    // [ default ] interface _CryptographicException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("c41fa05c-8a7a-3157-8166-4104bb4925ba"))
CryptographicUnexpectedOperationException;
    // [ default ] interface _CryptographicUnexpectedOperationException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("8abad867-f515-3cf6-bb62-5f0c88b3bb11"))
ICryptoTransform : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_InputBlockSize (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_OutputBlockSize (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CanTransformMultipleBlocks (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CanReuseTransform (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall TransformBlock (
        /*[in]*/ SAFEARRAY * inputBuffer,
        /*[in]*/ long inputOffset,
        /*[in]*/ long inputCount,
        /*[in]*/ SAFEARRAY * outputBuffer,
        /*[in]*/ long outputOffset,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall TransformFinalBlock (
        /*[in]*/ SAFEARRAY * inputBuffer,
        /*[in]*/ long inputOffset,
        /*[in]*/ long inputCount,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("3e04dc56-84ce-3893-8bef-6c9b95f9ccf4"))
RandomNumberGenerator;
    // [ default ] interface _RandomNumberGenerator
    // interface _Object

struct __declspec(uuid("40031115-09d2-3851-a13f-56930be48038"))
RNGCryptoServiceProvider;
    // [ default ] interface _RNGCryptoServiceProvider
    // interface _Object

struct __declspec(uuid("4b135d8e-7b1b-3ea8-8d06-10e34f157e9d"))
AsymmetricAlgorithm;
    // [ default ] interface _AsymmetricAlgorithm
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("0202ce16-1f18-3bfb-807d-760b157ab260"))
AsymmetricKeyExchangeDeformatter;
    // [ default ] interface _AsymmetricKeyExchangeDeformatter
    // interface _Object

struct __declspec(uuid("ce38dc2d-eb2d-3b6a-afac-8537bd0b9bf7"))
AsymmetricKeyExchangeFormatter;
    // [ default ] interface _AsymmetricKeyExchangeFormatter
    // interface _Object

struct __declspec(uuid("bee4e9fd-de7a-3512-93d8-0c5e006b167a"))
AsymmetricSignatureDeformatter;
    // [ default ] interface _AsymmetricSignatureDeformatter
    // interface _Object

struct __declspec(uuid("5b475a84-5310-3c64-b625-e2bf00476f53"))
AsymmetricSignatureFormatter;
    // [ default ] interface _AsymmetricSignatureFormatter
    // interface _Object

enum __declspec(uuid("11472518-c3b8-3bf4-9705-2135e1709883"))
FromBase64TransformMode
{
    FromBase64TransformMode_IgnoreWhiteSpaces = 0,
    FromBase64TransformMode_DoNotIgnoreWhiteSpaces = 1
};

struct __declspec(uuid("5f3a0f8d-5ef9-3ad5-94e0-53aff8bce960"))
ToBase64Transform;
    // [ default ] interface _ToBase64Transform
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("c1abb475-f198-39d5-bf8d-330bc7189661"))
FromBase64Transform;
    // [ default ] interface _FromBase64Transform
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("ae746923-16bb-3d31-9d08-ce50ef6f7b1a"))
CryptoAPITransform;
    // [ default ] interface _CryptoAPITransform
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

enum __declspec(uuid("6be41cdf-29d7-32db-8181-5117f580ba68"))
CspProviderFlags
{
    CspProviderFlags_NoFlags = 0,
    CspProviderFlags_UseMachineKeyStore = 1,
    CspProviderFlags_UseDefaultKeyContainer = 2,
    CspProviderFlags_UseNonExportableKey = 4,
    CspProviderFlags_UseExistingKey = 8,
    CspProviderFlags_UseArchivableKey = 16,
    CspProviderFlags_UseUserProtectedKey = 32,
    CspProviderFlags_NoPrompt = 64
};

struct __declspec(uuid("af60343f-6c7b-3761-839f-0c44e3ca06da"))
CspParameters;
    // [ default ] interface _CspParameters
    // interface _Object

struct __declspec(uuid("9ea60eca-3dcd-340f-8e95-67845d185999"))
CryptoConfig;
    // [ default ] interface _CryptoConfig
    // interface _Object

enum __declspec(uuid("8990cb3b-227e-3a43-8264-0057ec763fa0"))
CryptoStreamMode
{
    CryptoStreamMode_Read = 0,
    CryptoStreamMode_Write = 1
};

struct __declspec(uuid("b5c4e3ca-476a-3961-bca5-a6c0ad73e7b1"))
CryptoStream;
    // [ default ] interface _CryptoStream
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("5b67ea6b-d85d-3f48-86d2-8581db230c43"))
SymmetricAlgorithm;
    // [ default ] interface _SymmetricAlgorithm
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("f30d404c-a350-36fa-a6fc-054c3f583420"))
DES;
    // [ default ] interface _DES
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("b6eb52d5-bb1c-3380-8bca-345ff43f4b04"))
DESCryptoServiceProvider;
    // [ default ] interface _DESCryptoServiceProvider
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("7d62db2d-86e3-3ade-90c4-215950643d10"))
DeriveBytes;
    // [ default ] interface _DeriveBytes
    // interface _Object

#pragma pack(push, 4)

struct __declspec(uuid("0c646f46-aa27-350d-88dd-d8c920ce6c2d"))
DSAParameters
{
    SAFEARRAY * P;
    SAFEARRAY * Q;
    SAFEARRAY * G;
    SAFEARRAY * y;
    SAFEARRAY * J;
    SAFEARRAY * x;
    SAFEARRAY * Seed;
    long Counter;
};

#pragma pack(pop)

struct __declspec(uuid("c13e7301-9b3f-3530-b60a-7f141d6dde83"))
DSA;
    // [ default ] interface _DSA
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("673dfe75-9f93-304f-aba8-d2a86ba87d7c"))
DSACryptoServiceProvider;
    // [ default ] interface _DSACryptoServiceProvider
    // interface _Object
    // interface IDisposable
    // interface ICspAsymmetricAlgorithm

struct __declspec(uuid("1f17c39c-99d5-37e0-8e98-8f27044bd50a"))
DSASignatureDeformatter;
    // [ default ] interface _DSASignatureDeformatter
    // interface _Object

struct __declspec(uuid("8f6d198c-e66f-3a87-aa3f-f885dd09ea13"))
DSASignatureFormatter;
    // [ default ] interface _DSASignatureFormatter
    // interface _Object

struct __declspec(uuid("68549fc3-f82c-3387-8578-e5fb09833740"))
HashAlgorithm;
    // [ default ] interface _HashAlgorithm
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("bf1b2d6a-e41e-3645-8257-a08d7483bd41"))
KeyedHashAlgorithm;
    // [ default ] interface _KeyedHashAlgorithm
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("c67d3b5f-8b7f-3720-b35f-3b49d058a900"))
HMAC;
    // [ default ] interface _HMAC
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("a7eddcb5-6043-3988-921c-25e3dee6322b"))
HMACMD5;
    // [ default ] interface _HMACMD5
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("20051d1b-321f-3e4d-a3da-5fbe892f7ec5"))
HMACRIPEMD160;
    // [ default ] interface _HMACRIPEMD160
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("00b01b2e-b1fe-33a6-ad40-57de8358dc7d"))
HMACSHA1;
    // [ default ] interface _HMACSHA1
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("2c314899-8f99-3041-a49d-2f6afc0e6296"))
HMACSHA256;
    // [ default ] interface _HMACSHA256
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("ae53ed01-cab4-39ce-854a-8bf544eeec35"))
HMACSHA384;
    // [ default ] interface _HMACSHA384
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("477a7d8e-8d26-3959-88f6-f6ab7e7f50cf"))
HMACSHA512;
    // [ default ] interface _HMACSHA512
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

enum __declspec(uuid("d7dd91c9-91e4-38e9-8ec6-37836572a66a"))
KeyNumber
{
    KeyNumber_Exchange = 1,
    KeyNumber_Signature = 2
};

struct __declspec(uuid("e5e5b585-8a68-3f26-bb61-f34ef3ad27f8"))
CspKeyContainerInfo;
    // [ default ] interface _CspKeyContainerInfo
    // interface _Object

struct __declspec(uuid("39b68485-6773-3c46-82e9-56d8f0b4570c"))
MACTripleDES;
    // [ default ] interface _MACTripleDES
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("668515a6-213d-377a-8fe4-5a1e59a10ac9"))
MD5;
    // [ default ] interface _MD5
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("d2548bf2-801a-36af-8800-1f11fbf54361"))
MD5CryptoServiceProvider;
    // [ default ] interface _MD5CryptoServiceProvider
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("be1e426e-676b-3524-9ced-21e306e9b827"))
MaskGenerationMethod;
    // [ default ] interface _MaskGenerationMethod
    // interface _Object

struct __declspec(uuid("eed31dd9-aa11-3993-80e0-0088c1f5feba"))
PasswordDeriveBytes;
    // [ default ] interface _PasswordDeriveBytes
    // interface _Object

struct __declspec(uuid("7ae844f0-eca8-3f15-ae27-afa21a2aa6f8"))
PKCS1MaskGenerationMethod;
    // [ default ] interface _PKCS1MaskGenerationMethod
    // interface _Object

struct __declspec(uuid("1c6dc255-62d6-3366-bb25-01c509085473"))
RC2;
    // [ default ] interface _RC2
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("62e92675-cb77-3fc9-8597-1a81a5f18013"))
RC2CryptoServiceProvider;
    // [ default ] interface _RC2CryptoServiceProvider
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("7107ab85-4c6d-3890-af8a-90b2e2d82f5b"))
Rfc2898DeriveBytes;
    // [ default ] interface _Rfc2898DeriveBytes
    // interface _Object

struct __declspec(uuid("7813009a-0f6f-3f40-b73a-fae619971619"))
RIPEMD160;
    // [ default ] interface _RIPEMD160
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("3d367908-928f-3c13-8b93-5e1718820f6d"))
RIPEMD160Managed;
    // [ default ] interface _RIPEMD160Managed
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

#pragma pack(push, 4)

struct __declspec(uuid("094e9135-483d-334a-aae7-8690895ab70a"))
RSAParameters
{
    SAFEARRAY * Exponent;
    SAFEARRAY * Modulus;
    SAFEARRAY * P;
    SAFEARRAY * Q;
    SAFEARRAY * DP;
    SAFEARRAY * DQ;
    SAFEARRAY * InverseQ;
    SAFEARRAY * D;
};

#pragma pack(pop)

struct __declspec(uuid("3e39ca4f-cd6f-3cfe-8659-7fdc8d1c9f0b"))
RSA;
    // [ default ] interface _RSA
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("d9035152-6b1f-33e3-86f4-411cd21cde0e"))
RSACryptoServiceProvider;
    // [ default ] interface _RSACryptoServiceProvider
    // interface _Object
    // interface IDisposable
    // interface ICspAsymmetricAlgorithm

struct __declspec(uuid("4d187ac2-d815-3b7e-bcea-8e0bbc702f7c"))
RSAOAEPKeyExchangeDeformatter;
    // [ default ] interface _RSAOAEPKeyExchangeDeformatter
    // interface _Object

struct __declspec(uuid("a0e2e749-63ce-3651-8f4f-f5f996344c32"))
RSAOAEPKeyExchangeFormatter;
    // [ default ] interface _RSAOAEPKeyExchangeFormatter
    // interface _Object

struct __declspec(uuid("ee96f4e1-377e-315c-aef5-874dc8c7a2aa"))
RSAPKCS1KeyExchangeDeformatter;
    // [ default ] interface _RSAPKCS1KeyExchangeDeformatter
    // interface _Object

struct __declspec(uuid("92755472-2059-3f96-8938-8ac767b5187b"))
RSAPKCS1KeyExchangeFormatter;
    // [ default ] interface _RSAPKCS1KeyExchangeFormatter
    // interface _Object

struct __declspec(uuid("6f674828-9081-3b45-bc39-791bd84ccf8f"))
RSAPKCS1SignatureDeformatter;
    // [ default ] interface _RSAPKCS1SignatureDeformatter
    // interface _Object

struct __declspec(uuid("7bc115cd-1ee2-3068-894d-e3d3f7632f40"))
RSAPKCS1SignatureFormatter;
    // [ default ] interface _RSAPKCS1SignatureFormatter
    // interface _Object

struct __declspec(uuid("48cbeb8f-db77-3103-899c-cd24a832b5cc"))
Rijndael;
    // [ default ] interface _Rijndael
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("1f9f18a3-efc0-3913-84a5-90678a4a9a80"))
RijndaelManaged;
    // [ default ] interface _RijndaelManaged
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("fa28c8e8-6b89-3ec5-ac16-720d8e31dc97"))
RijndaelManagedTransform;
    // [ default ] interface _RijndaelManagedTransform
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("eb52b161-afb3-3dea-bfaf-c183aeb57e56"))
SHA1;
    // [ default ] interface _SHA1
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("fc13a7d5-e2b3-37ba-b807-7fa6238284d5"))
SHA1CryptoServiceProvider;
    // [ default ] interface _SHA1CryptoServiceProvider
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("fdf9c30d-ccab-3e2d-b584-9e24ce8038e3"))
SHA1Managed;
    // [ default ] interface _SHA1Managed
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("e29b25fc-9402-3a80-aaa5-eb07d9ef5488"))
SHA256;
    // [ default ] interface _SHA256
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("44181b13-ae94-3cfb-81d1-37db59145030"))
SHA256Managed;
    // [ default ] interface _SHA256Managed
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("0c00c2e9-7bbe-359e-8261-fd9b9c882a15"))
SHA384;
    // [ default ] interface _SHA384
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("7fd3958d-0a14-3001-8074-0d15ead7f05c"))
SHA384Managed;
    // [ default ] interface _SHA384Managed
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("8de638d4-0575-3083-9cd7-41619ef9ac75"))
SHA512;
    // [ default ] interface _SHA512
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("a6673c32-3943-3bbb-b476-c09a0ec0bcd6"))
SHA512Managed;
    // [ default ] interface _SHA512Managed
    // interface _Object
    // interface ICryptoTransform
    // interface IDisposable

struct __declspec(uuid("3fa7a1c5-812c-3b56-b957-cb14af670c09"))
SignatureDescription;
    // [ default ] interface _SignatureDescription
    // interface _Object

struct __declspec(uuid("3d79ae1a-a949-3601-978f-02bea1e70a98"))
TripleDES;
    // [ default ] interface _TripleDES
    // interface _Object
    // interface IDisposable

struct __declspec(uuid("daa132bf-1170-3d8b-a0ef-e2f55a68a91d"))
TripleDESCryptoServiceProvider;
    // [ default ] interface _TripleDESCryptoServiceProvider
    // interface _Object
    // interface IDisposable

enum __declspec(uuid("70446b90-f93b-3578-9b7b-95d05a12da60"))
X509ContentType
{
    X509ContentType_Unknown = 0,
    X509ContentType_Cert = 1,
    X509ContentType_SerializedCert = 2,
    X509ContentType_Pfx = 3,
    X509ContentType_Pkcs12 = 3,
    X509ContentType_SerializedStore = 4,
    X509ContentType_Pkcs7 = 5,
    X509ContentType_Authenticode = 6
};

enum __declspec(uuid("2530ee1e-6d70-3a79-a864-7cc0e2120da1"))
X509KeyStorageFlags
{
    X509KeyStorageFlags_DefaultKeySet = 0,
    X509KeyStorageFlags_UserKeySet = 1,
    X509KeyStorageFlags_MachineKeySet = 2,
    X509KeyStorageFlags_Exportable = 4,
    X509KeyStorageFlags_UserProtected = 8,
    X509KeyStorageFlags_PersistKeySet = 16
};

struct __declspec(uuid("4c69c54f-9824-38cc-8387-a22dc67e0bab"))
X509Certificate;
    // [ default ] interface _X509Certificate
    // interface _Object
    // interface IDeserializationCallback
    // interface ISerializable

struct __declspec(uuid("2b67cece-71c3-36a9-a136-925ccc1935a8"))
_Array : IDispatch
{};

struct __declspec(uuid("de8db6f8-d101-3a92-8d1c-e72e5f10e992"))
ICollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CopyTo (
        /*[in]*/ struct _Array * Array,
        /*[in]*/ long index ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_SyncRoot (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSynchronized (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("6a6841df-3287-3d87-8060-ce0b4c77d2a1"))
IDictionary : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT key,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Item (
        /*[in]*/ VARIANT key,
        /*[in]*/ VARIANT pRetVal ) = 0;
      virtual HRESULT __stdcall get_Keys (
        /*[out,retval]*/ struct ICollection * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Values (
        /*[out,retval]*/ struct ICollection * * pRetVal ) = 0;
      virtual HRESULT __stdcall Contains (
        /*[in]*/ VARIANT key,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT key,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall get_IsReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFixedSize (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetEnumerator (
        /*[out,retval]*/ struct IDictionaryEnumerator * * pRetVal ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ VARIANT key ) = 0;
};

struct __declspec(uuid("308de042-acc8-32f8-b632-7cb9799d9aa6"))
IChannelSinkBase : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Properties (
        /*[out,retval]*/ struct IDictionary * * pRetVal ) = 0;
};

struct __declspec(uuid("1a8b0de6-b825-38c5-b744-8f93075fd6fa"))
IMessage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Properties (
        /*[out,retval]*/ struct IDictionary * * pRetVal ) = 0;
};

struct __declspec(uuid("941f8aaa-a353-3b1d-a019-12e44377f1cd"))
IMessageSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall SyncProcessMessage (
        /*[in]*/ struct IMessage * msg,
        /*[out,retval]*/ struct IMessage * * pRetVal ) = 0;
      virtual HRESULT __stdcall AsyncProcessMessage (
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct IMessageSink * replySink,
        /*[out,retval]*/ struct IMessageCtrl * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_NextSink (
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("10f1d605-e201-3145-b7ae-3ad746701986"))
IChannelSender : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CreateMessageSink (
        /*[in]*/ BSTR Url,
        /*[in]*/ VARIANT remoteChannelData,
        /*[out]*/ BSTR * objectURI,
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("4db956b7-69d0-312a-aa75-44fb55fd5d4b"))
IContributeClientContextSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetClientContextSink (
        /*[in]*/ struct IMessageSink * NextSink,
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("0caa23ec-f78c-39c9-8d25-b7a9ce4097a7"))
IContributeServerContextSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetServerContextSink (
        /*[in]*/ struct IMessageSink * NextSink,
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("c74076bb-8a2d-3c20-a542-625329e9af04"))
IDynamicMessageSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ProcessMessageStart (
        /*[in]*/ struct IMessage * reqMsg,
        /*[in]*/ VARIANT_BOOL bCliSide,
        /*[in]*/ VARIANT_BOOL bAsync ) = 0;
      virtual HRESULT __stdcall ProcessMessageFinish (
        /*[in]*/ struct IMessage * replyMsg,
        /*[in]*/ VARIANT_BOOL bCliSide,
        /*[in]*/ VARIANT_BOOL bAsync ) = 0;
};

struct __declspec(uuid("a0fe9b86-0c06-32ce-85fa-2ff1b58697fb"))
IContributeDynamicSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetDynamicSink (
        /*[out,retval]*/ struct IDynamicMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("2a6e91b9-a874-38e4-99c2-c5d83d78140d"))
IEnvoyInfo : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_EnvoySinks (
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_EnvoySinks (
        /*[in]*/ struct IMessageSink * pRetVal ) = 0;
};

struct __declspec(uuid("139e041d-0e41-39f5-a302-c4387e9d0a6c"))
_ValueType : IDispatch
{};

struct __declspec(uuid("d09d1e04-d590-39a3-b517-b734a49a9277"))
_Enum : IDispatch
{};

struct __declspec(uuid("36936699-fc79-324d-ab43-e33c1f94e263"))
_String : IDispatch
{};

struct __declspec(uuid("7499e7e8-df01-3948-b8d4-fa4b9661d36b"))
_StringComparer : IDispatch
{};

struct __declspec(uuid("9fb09782-8d39-3b0c-b79e-f7a37a65b3da"))
_StringBuilder : IDispatch
{};

struct __declspec(uuid("4c482cc2-68e9-37c6-8353-9a94bd2d7f0b"))
_SystemException : IDispatch
{};

struct __declspec(uuid("cf3edb7e-0574-3383-a44f-292f7c145db4"))
_OutOfMemoryException : IDispatch
{};

struct __declspec(uuid("9cf4339a-2911-3b8a-8f30-e5c6b5be9a29"))
_StackOverflowException : IDispatch
{};

struct __declspec(uuid("152a6b4d-09af-3edf-8cba-11797eeeea4e"))
_DataMisalignedException : IDispatch
{};

struct __declspec(uuid("ccf0139c-79f7-3d0a-affe-2b0762c65b07"))
_ExecutionEngineException : IDispatch
{};

struct __declspec(uuid("16fe0885-9129-3884-a232-90b58c5b2aa9"))
_MulticastDelegate : IDispatch
{};

struct __declspec(uuid("7eaba4e2-1259-3cf2-b084-9854278e5897"))
_MemberAccessException : IDispatch
{};

struct __declspec(uuid("13ef674a-6327-3caf-8772-fa0395612669"))
_AccessViolationException : IDispatch
{};

struct __declspec(uuid("d1204423-01f0-336a-8911-a7e8fbe185a3"))
_ApplicationActivator : IDispatch
{};

struct __declspec(uuid("d81130bf-d627-3b91-a7c7-cea597093464"))
_ApplicationException : IDispatch
{};

struct __declspec(uuid("1f9ec719-343a-3cb3-8040-3927626777c1"))
_EventArgs : IDispatch
{};

struct __declspec(uuid("98947cf0-77e7-328e-b709-5dd1aa1c9c96"))
_ResolveEventArgs : IDispatch
{};

struct __declspec(uuid("7a0325f0-22c2-31f9-8823-9b8aee9456b1"))
_AssemblyLoadEventArgs : IDispatch
{};

struct __declspec(uuid("8e54a9cc-7aa4-34ca-985b-bd7d7527b110"))
_ResolveEventHandler : IDispatch
{};

struct __declspec(uuid("deece11f-a893-3e35-a4c3-dab7fa0911eb"))
_AssemblyLoadEventHandler : IDispatch
{};

struct __declspec(uuid("5e6f9edb-3ce1-3a56-86d9-cd2ddf7a6fff"))
_AppDomainInitializer : IDispatch
{};

struct __declspec(uuid("2c358e27-8c1a-3c03-b086-a40465625557"))
_MarshalByRefObject : IDispatch
{};

struct __declspec(uuid("124777b6-0308-3569-97e5-e6fe88eae4eb"))
IContributeEnvoySink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetEnvoySink (
        /*[in]*/ struct _MarshalByRefObject * obj,
        /*[in]*/ struct IMessageSink * NextSink,
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("6a5d38bc-2789-3546-81a1-f10c0fb59366"))
IContributeObjectSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetObjectSink (
        /*[in]*/ struct _MarshalByRefObject * obj,
        /*[in]*/ struct IMessageSink * NextSink,
        /*[out,retval]*/ struct IMessageSink * * pRetVal ) = 0;
};

struct __declspec(uuid("af93163f-c2f4-3fab-9ff1-728a7aaad1cb"))
_CrossAppDomainDelegate : IDispatch
{};

struct __declspec(uuid("63e53e04-d31b-3099-9f0c-c7a1c883c1d9"))
_AppDomainManager : IDispatch
{};

struct __declspec(uuid("ce59d7ad-05ca-33b4-a1dd-06028d46e9d2"))
_LoaderOptimizationAttribute : IDispatch
{};

struct __declspec(uuid("6e96aa70-9ffb-399d-96bf-a68436095c54"))
_AppDomainUnloadedException : IDispatch
{};

struct __declspec(uuid("cfd9ca27-f0ba-388a-acde-b7e20fcad79c"))
_ActivationArguments : IDispatch
{};

struct __declspec(uuid("2f218f95-4215-3cc6-8a51-bd2770c090e4"))
_ApplicationId : IDispatch
{};

struct __declspec(uuid("4db2c2b7-cbc2-3185-b966-875d4625b1a8"))
_ArgumentException : IDispatch
{};

struct __declspec(uuid("c991949b-e623-3f24-885c-bbb01ff43564"))
_ArgumentNullException : IDispatch
{};

struct __declspec(uuid("77da3028-bc45-3e82-bf76-2c123ee2c021"))
_ArgumentOutOfRangeException : IDispatch
{};

struct __declspec(uuid("9b012cf1-acf6-3389-a336-c023040c62a2"))
_ArithmeticException : IDispatch
{};

struct __declspec(uuid("dd7488a6-1b3f-3823-9556-c2772b15150f"))
_ArrayTypeMismatchException : IDispatch
{};

struct __declspec(uuid("3612706e-0239-35fd-b900-0819d16d442d"))
_AsyncCallback : IDispatch
{};

struct __declspec(uuid("a902a192-49ba-3ec8-b444-af5f7743f61a"))
_AttributeUsageAttribute : IDispatch
{};

struct __declspec(uuid("f98bce04-4a4b-398c-a512-fd8348d51e3b"))
_BadImageFormatException : IDispatch
{};

struct __declspec(uuid("f036bca4-f8df-3682-8290-75285ce7456c"))
_Buffer : IDispatch
{};

struct __declspec(uuid("6d4b6adb-b9fa-3809-b5ea-fa57b56c546f"))
_CannotUnloadAppDomainException : IDispatch
{};

struct __declspec(uuid("1dd627fc-89e3-384f-bb9d-58cb4efb9456"))
_CharEnumerator : IDispatch
{};

struct __declspec(uuid("bf1af177-94ca-3e6d-9d91-55cf9e859d22"))
_CLSCompliantAttribute : IDispatch
{};

struct __declspec(uuid("c2a10f3a-356a-3c77-aab9-8991d73a2561"))
_TypeUnloadedException : IDispatch
{};

struct __declspec(uuid("6b3f9834-1725-38c5-955e-20f051d067bd"))
_CriticalFinalizerObject : IDispatch
{};

struct __declspec(uuid("7386f4d7-7c11-389f-bb75-895714b12bb5"))
_ContextMarshalException : IDispatch
{};

struct __declspec(uuid("3eb1d909-e8bf-3c6b-ada5-0e86e31e186e"))
_ContextBoundObject : IDispatch
{};

struct __declspec(uuid("160d517f-f175-3b61-8264-6d2305b8246c"))
_ContextStaticAttribute : IDispatch
{};

struct __declspec(uuid("3025f666-7891-33d7-aacd-23d169ef354e"))
_TimeZone : IDispatch
{};

struct __declspec(uuid("0d9f1b65-6d27-3e9f-baf3-0597837e0f33"))
_DBNull : IDispatch
{};

struct __declspec(uuid("bdeea460-8241-3b41-9ed3-6e3e9977ac7f"))
_DivideByZeroException : IDispatch
{};

struct __declspec(uuid("d345a42b-cfe0-3eee-861c-f3322812b388"))
_DuplicateWaitObjectException : IDispatch
{};

struct __declspec(uuid("82d6b3bf-a633-3b3b-a09e-2363e4b24a41"))
_TypeLoadException : IDispatch
{};

struct __declspec(uuid("67388f3f-b600-3bcf-84aa-bb2b88dd9ee2"))
_EntryPointNotFoundException : IDispatch
{};

struct __declspec(uuid("24ae6464-2834-32cd-83d6-fa06953de62a"))
_DllNotFoundException : IDispatch
{};

struct __declspec(uuid("29dc56cf-b981-3432-97c8-3680ab6d862d"))
_Environment : IDispatch
{};

struct __declspec(uuid("7cefc46e-16e0-3e65-9c38-55b4342ba7f0"))
_EventHandler : IDispatch
{};

struct __declspec(uuid("8d5f5811-ffa1-3306-93e3-8afc572b9b82"))
_FieldAccessException : IDispatch
{};

struct __declspec(uuid("ebe3746d-ddec-3d23-8e8d-9361ba87bac6"))
_FlagsAttribute : IDispatch
{};

struct __declspec(uuid("07f92156-398a-3548-90b7-2e58026353d0"))
_FormatException : IDispatch
{};

struct __declspec(uuid("e5a5f1e4-82c1-391f-a1c6-f39eae9dc72f"))
_IndexOutOfRangeException : IDispatch
{};

struct __declspec(uuid("fa047cbd-9ba5-3a13-9b1f-6694d622cd76"))
_InvalidCastException : IDispatch
{};

struct __declspec(uuid("8d520d10-0b8a-3553-8874-d30a4ad2ff4c"))
_InvalidOperationException : IDispatch
{};

struct __declspec(uuid("3410e0fb-636f-3cd1-8045-3993ca113f25"))
_InvalidProgramException : IDispatch
{};

struct __declspec(uuid("dc77f976-318d-3a1a-9b60-abb9dd9406d6"))
_LocalDataStoreSlot : IDispatch
{};

struct __declspec(uuid("ff0bf77d-8f81-3d31-a3bb-6f54440fa7e5"))
_MethodAccessException : IDispatch
{};

struct __declspec(uuid("8897d14b-7fb3-3d8b-9ee4-221c3dbad6fe"))
_MissingMemberException : IDispatch
{};

struct __declspec(uuid("9717176d-1179-3487-8849-cf5f63de356e"))
_MissingFieldException : IDispatch
{};

struct __declspec(uuid("e5c659f6-92c8-3887-a07e-74d0d9c6267a"))
_MissingMethodException : IDispatch
{};

struct __declspec(uuid("d2ba71cc-1b3d-3966-a0d7-c61e957ad325"))
_MulticastNotSupportedException : IDispatch
{};

struct __declspec(uuid("665c9669-b9c6-3add-9213-099f0127c893"))
_NonSerializedAttribute : IDispatch
{};

struct __declspec(uuid("8e21ce22-4f17-347b-b3b5-6a6df3e0e58a"))
_NotFiniteNumberException : IDispatch
{};

struct __declspec(uuid("1e4d31a2-63ea-397a-a77e-b20ad87a9614"))
_NotImplementedException : IDispatch
{};

struct __declspec(uuid("40e5451f-b237-33f8-945b-0230db700bbb"))
_NotSupportedException : IDispatch
{};

struct __declspec(uuid("ecbe2313-cf41-34b4-9fd0-b6cd602b023f"))
_NullReferenceException : IDispatch
{};

struct __declspec(uuid("17b730ba-45ef-3ddf-9f8d-a490bac731f4"))
_ObjectDisposedException : IDispatch
{};

struct __declspec(uuid("e84307be-3036-307a-acc2-5d5de8a006a8"))
_ObsoleteAttribute : IDispatch
{};

struct __declspec(uuid("9e230640-a5d0-30e1-b217-9d2b6cc0fc40"))
_OperatingSystem : IDispatch
{};

struct __declspec(uuid("9df9af5a-7853-3d55-9b48-bd1f5d8367ab"))
_OperationCanceledException : IDispatch
{};

struct __declspec(uuid("37c69a5d-7619-3a0f-a96b-9c9578ae00ef"))
_OverflowException : IDispatch
{};

struct __declspec(uuid("d54500ae-8cf4-3092-9054-90dc91ac65c9"))
_ParamArrayAttribute : IDispatch
{};

struct __declspec(uuid("1eb8340b-8190-3d9d-92f8-51244b9804c5"))
_PlatformNotSupportedException : IDispatch
{};

struct __declspec(uuid("0f240708-629a-31ab-94a5-2bb476fe1783"))
_Random : IDispatch
{};

struct __declspec(uuid("871ddc46-b68e-3fee-a09a-c808b0f827e6"))
_RankException : IDispatch
{};

struct __declspec(uuid("1b96e53c-4028-38bc-9dc3-8d7a9555c311"))
_SerializableAttribute : IDispatch
{};

struct __declspec(uuid("7ab88ca9-17f4-385e-ad41-4ee0aa316fa1"))
_TimeoutException : IDispatch
{};

struct __declspec(uuid("feb0323d-8ce4-36a4-a41e-0ba0c32e1a6a"))
_TypeInitializationException : IDispatch
{};

struct __declspec(uuid("6193c5f6-6807-3561-a7f3-b64c80b5f00f"))
_UnauthorizedAccessException : IDispatch
{};

struct __declspec(uuid("a218e20a-0905-3741-b0b3-9e3193162e50"))
_UnhandledExceptionEventArgs : IDispatch
{};

struct __declspec(uuid("84199e64-439c-3011-b249-3c9065735adb"))
_UnhandledExceptionEventHandler : IDispatch
{};

struct __declspec(uuid("011a90c5-4910-3c29-bbb7-50d05ccbaa4a"))
_Version : IDispatch
{};

struct __declspec(uuid("c5df3568-c251-3c58-afb4-32e79e8261f0"))
_WeakReference : IDispatch
{};

struct __declspec(uuid("40dfc50a-e93a-3c08-b9ef-e2b4f28b5676"))
_WaitHandle : IDispatch
{};

struct __declspec(uuid("11ab34e7-0176-3c9e-9efe-197858400a3d"))
IAsyncResult : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_IsCompleted (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AsyncWaitHandle (
        /*[out,retval]*/ struct _WaitHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AsyncState (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CompletedSynchronously (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("e142db4a-1a52-34ce-965e-13affd5447d0"))
_EventWaitHandle : IDispatch
{};

struct __declspec(uuid("3f243ebd-612f-3db8-9e03-bd92343a8371"))
_AutoResetEvent : IDispatch
{};

struct __declspec(uuid("56d201f1-3e5d-39d9-b5de-064710818905"))
_ContextCallback : IDispatch
{};

struct __declspec(uuid("c0bb9361-268f-3e72-bf6f-4120175a1500"))
_ManualResetEvent : IDispatch
{};

struct __declspec(uuid("ee22485e-4c45-3c9d-9027-a8d61c5f53f2"))
_Monitor : IDispatch
{};

struct __declspec(uuid("36cb559b-87c6-3ad2-9225-62a7ed499b37"))
_Mutex : IDispatch
{};

struct __declspec(uuid("dd846fcc-8d04-3665-81b6-aacbe99c19c3"))
_Overlapped : IDispatch
{};

struct __declspec(uuid("ad89b568-4fd4-3f8d-8327-b396b20a460e"))
_ReaderWriterLock : IDispatch
{};

struct __declspec(uuid("87f55344-17e0-30fd-8eb9-38eaf6a19b3f"))
_SynchronizationLockException : IDispatch
{};

struct __declspec(uuid("95b525db-6b81-3cdc-8fe7-713f7fc793c0"))
_ThreadAbortException : IDispatch
{};

struct __declspec(uuid("b9e07599-7c44-33be-a70e-efa16f51f54a"))
_ThreadInterruptedException : IDispatch
{};

struct __declspec(uuid("64409425-f8c9-370e-809e-3241ce804541"))
_RegisteredWaitHandle : IDispatch
{};

struct __declspec(uuid("ce949142-4d4c-358d-89a9-e69a531aa363"))
_WaitCallback : IDispatch
{};

struct __declspec(uuid("f078f795-f452-3d2d-8cc8-16d66ae46c67"))
_WaitOrTimerCallback : IDispatch
{};

struct __declspec(uuid("bbae942d-bff4-36e2-a3bc-508bb3801f4f"))
_IOCompletionCallback : IDispatch
{};

struct __declspec(uuid("b45bbd7e-a977-3f56-a626-7a693e5dbbc5"))
_ThreadStart : IDispatch
{};

struct __declspec(uuid("a13a41cf-e066-3b90-82f4-73109104e348"))
_ThreadStateException : IDispatch
{};

struct __declspec(uuid("a6b94b6d-854e-3172-a4ec-a17edd16f85e"))
_ThreadStaticAttribute : IDispatch
{};

struct __declspec(uuid("81456e86-22af-31d1-a91a-9c370c0e2530"))
_Timeout : IDispatch
{};

struct __declspec(uuid("3741bc6f-101b-36d7-a9d5-03fcc0ecda35"))
_TimerCallback : IDispatch
{};

struct __declspec(uuid("b49a029b-406b-3b1e-88e4-f86690d20364"))
_Timer : IDispatch
{};

struct __declspec(uuid("85d72f83-be91-3cb1-b4f0-76b56ff04033"))
_STAThreadAttribute : IDispatch
{};

struct __declspec(uuid("c02468d1-8713-3225-bda3-49b2fe37ddbb"))
_MTAThreadAttribute : IDispatch
{};

struct __declspec(uuid("401f89cb-c127-3041-82fd-b67035395c56"))
_ArrayList : IDispatch
{};

struct __declspec(uuid("f145c46a-d170-3170-b52f-4678dfca0300"))
_BitArray : IDispatch
{};

struct __declspec(uuid("ea6795ac-97d6-3377-be64-829abd67607b"))
_CaseInsensitiveComparer : IDispatch
{};

struct __declspec(uuid("0422b845-b636-3688-8f61-9b6d93096336"))
_CaseInsensitiveHashCodeProvider : IDispatch
{};

struct __declspec(uuid("b7d29e26-7798-3fa4-90f4-e6a22d2099f9"))
_CollectionBase : IDispatch
{};

struct __declspec(uuid("8064a157-b5c8-3a4a-ad3d-02dc1a39c417"))
_Comparer : IDispatch
{};

struct __declspec(uuid("ddd44da2-bc6b-3620-9317-c0372968c741"))
_DictionaryBase : IDispatch
{};

struct __declspec(uuid("d25a197e-3e69-3271-a989-23d85e97f920"))
_Hashtable : IDispatch
{};

struct __declspec(uuid("3a7d3ca4-b7d1-3a2a-800c-8fc2acfcbda4"))
_Queue : IDispatch
{};

struct __declspec(uuid("bd32d878-a59b-3e5c-bfe0-a96b1a1e9d6f"))
_ReadOnlyCollectionBase : IDispatch
{};

struct __declspec(uuid("56421139-a143-3ae9-9852-1dbdfe3d6bfa"))
_SortedList : IDispatch
{};

struct __declspec(uuid("ab538809-3c2f-35d9-80e6-7bad540484a1"))
_Stack : IDispatch
{};

struct __declspec(uuid("84e7ac09-795a-3ea9-a36a-5b81ebab0558"))
_Nullable : IDispatch
{};

struct __declspec(uuid("8039c41f-4399-38a2-99b7-d234b5cf7a7b"))
_KeyNotFoundException : IDispatch
{};

struct __declspec(uuid("e40a025c-645b-3c8e-a1ac-9c5cca279625"))
_ConditionalAttribute : IDispatch
{};

struct __declspec(uuid("a9b4786c-08e3-344f-a651-2f9926deac5e"))
_Debugger : IDispatch
{};

struct __declspec(uuid("3344e8b4-a5c3-3882-8d30-63792485eccf"))
_DebuggerStepThroughAttribute : IDispatch
{};

struct __declspec(uuid("b3276180-b23e-3034-b18f-e0122ba4e4cf"))
_DebuggerStepperBoundaryAttribute : IDispatch
{};

struct __declspec(uuid("55b6903b-55fe-35e0-804f-e42a096d2eb0"))
_DebuggerHiddenAttribute : IDispatch
{};

struct __declspec(uuid("cc6dcafd-0185-308a-891c-83812fe574e7"))
_DebuggerNonUserCodeAttribute : IDispatch
{};

struct __declspec(uuid("428e3627-2b1f-302c-a7e6-6388cd535e75"))
_DebuggableAttribute : IDispatch
{};

struct __declspec(uuid("a3fc6319-7355-3d7d-8621-b598561152fc"))
_DebuggerBrowsableAttribute : IDispatch
{};

struct __declspec(uuid("404fafdd-1e3f-3602-bff6-755c00613ed8"))
_DebuggerTypeProxyAttribute : IDispatch
{};

struct __declspec(uuid("22fdabc0-eec7-33e0-b4f2-f3b739e19a5e"))
_DebuggerDisplayAttribute : IDispatch
{};

struct __declspec(uuid("e19ea1a2-67ff-31a5-b95c-e0b753403f6b"))
_DebuggerVisualizerAttribute : IDispatch
{};

struct __declspec(uuid("9a2669ec-ff84-3726-89a0-663a3ef3b5cd"))
_StackTrace : IDispatch
{};

struct __declspec(uuid("0e9b8e47-ca67-38b6-b9db-2c42ee757b08"))
_StackFrame : IDispatch
{};

struct __declspec(uuid("5141d79c-7b01-37da-b7e9-53e5a271baf8"))
_SymDocumentType : IDispatch
{};

struct __declspec(uuid("22bb8891-fd21-313d-92e4-8a892dc0b39c"))
_SymLanguageType : IDispatch
{};

struct __declspec(uuid("01364e7b-c983-3651-b7d8-fd1b64fc0e00"))
_SymLanguageVendor : IDispatch
{};

struct __declspec(uuid("81aa0d59-c3b1-36a3-b2e7-054928fbfc1a"))
_AmbiguousMatchException : IDispatch
{};

struct __declspec(uuid("05532e88-e0f2-3263-9b57-805ac6b6bb72"))
_ModuleResolveEventHandler : IDispatch
{};

struct __declspec(uuid("6163f792-3cd6-38f1-b5f7-000b96a5082b"))
_AssemblyCopyrightAttribute : IDispatch
{};

struct __declspec(uuid("64c26bf9-c9e5-3f66-ad74-bebaade36214"))
_AssemblyTrademarkAttribute : IDispatch
{};

struct __declspec(uuid("de10d587-a188-3dcb-8000-92dfdb9b8021"))
_AssemblyProductAttribute : IDispatch
{};

struct __declspec(uuid("c6802233-ef82-3c91-ad72-b3a5d7230ed5"))
_AssemblyCompanyAttribute : IDispatch
{};

struct __declspec(uuid("6b2c0bc4-ddb7-38ea-8a86-f0b59e192816"))
_AssemblyDescriptionAttribute : IDispatch
{};

struct __declspec(uuid("df44cad3-cef2-36a9-b013-383cc03177d7"))
_AssemblyTitleAttribute : IDispatch
{};

struct __declspec(uuid("746d1d1e-ee37-393b-b6fa-e387d37553aa"))
_AssemblyConfigurationAttribute : IDispatch
{};

struct __declspec(uuid("04311d35-75ec-347b-bedf-969487ce4014"))
_AssemblyDefaultAliasAttribute : IDispatch
{};

struct __declspec(uuid("c6f5946c-143a-3747-a7c0-abfada6bdeb7"))
_AssemblyInformationalVersionAttribute : IDispatch
{};

struct __declspec(uuid("b101fe3c-4479-311a-a945-1225ee1731e8"))
_AssemblyFileVersionAttribute : IDispatch
{};

struct __declspec(uuid("177c4e63-9e0b-354d-838b-b52aa8683ef6"))
_AssemblyCultureAttribute : IDispatch
{};

struct __declspec(uuid("a1693c5c-101f-3557-94db-c480ceb4c16b"))
_AssemblyVersionAttribute : IDispatch
{};

struct __declspec(uuid("a9fcda18-c237-3c6f-a6ef-749be22ba2bf"))
_AssemblyKeyFileAttribute : IDispatch
{};

struct __declspec(uuid("6cf1c077-c974-38e1-90a4-976e4835e165"))
_AssemblyDelaySignAttribute : IDispatch
{};

struct __declspec(uuid("57b849aa-d8ef-3ea6-9538-c5b4d498c2f7"))
_AssemblyAlgorithmIdAttribute : IDispatch
{};

struct __declspec(uuid("0ecd8635-f5eb-3e4a-8989-4d684d67c48a"))
_AssemblyFlagsAttribute : IDispatch
{};

struct __declspec(uuid("322a304d-11ac-3814-a905-a019f6e3dae9"))
_AssemblyKeyNameAttribute : IDispatch
{};

struct __declspec(uuid("fe52f19a-8aa8-309c-bf99-9d0a566fb76a"))
_AssemblyNameProxy : IDispatch
{};

struct __declspec(uuid("1660eb67-ee41-363e-beb0-c2de09214abf"))
_CustomAttributeFormatException : IDispatch
{};

struct __declspec(uuid("f4e5539d-0a65-3073-bf27-8dce8ef1def1"))
_CustomAttributeData : IDispatch
{};

struct __declspec(uuid("c462b072-fe6e-3bdc-9fab-4cdbfcbcd124"))
_DefaultMemberAttribute : IDispatch
{};

struct __declspec(uuid("e6df0ae7-ba15-3f80-8afa-27773ae414fc"))
_InvalidFilterCriteriaException : IDispatch
{};

struct __declspec(uuid("3188878c-deb3-3558-80e8-84e9ed95f92c"))
_ManifestResourceInfo : IDispatch
{};

struct __declspec(uuid("fae5d9b7-40c1-3de1-be06-a91c9da1ba9f"))
_MemberFilter : IDispatch
{};

struct __declspec(uuid("0c48f55d-5240-30c7-a8f1-af87a640cefe"))
_Missing : IDispatch
{};

struct __declspec(uuid("8a5f0da2-7b43-3767-b623-2424cf7cd268"))
_ObfuscateAssemblyAttribute : IDispatch
{};

struct __declspec(uuid("71fb8dcf-3fa7-3483-8464-9d8200e57c43"))
_ObfuscationAttribute : IDispatch
{};

struct __declspec(uuid("643a4016-1b16-3ccf-ae86-9c2d9135ecb0"))
_ExceptionHandlingClause : IDispatch
{};

struct __declspec(uuid("b072efe2-c943-3977-bfd9-91d5232b0d53"))
_MethodBody : IDispatch
{};

struct __declspec(uuid("f2ecd8ca-91a2-31e8-b808-e028b4f5ca67"))
_LocalVariableInfo : IDispatch
{};

struct __declspec(uuid("f0deafe9-5eba-3737-9950-c1795739cdcd"))
_Pointer : IDispatch
{};

struct __declspec(uuid("22c26a41-5fa3-34e3-a76f-ba480252d8ec"))
_ReflectionTypeLoadException : IDispatch
{};

struct __declspec(uuid("fc4963cb-e52b-32d8-a418-d058fa51a1fa"))
_StrongNameKeyPair : IDispatch
{};

struct __declspec(uuid("98b1524d-da12-3c4b-8a69-7539a6dec4fa"))
_TargetException : IDispatch
{};

struct __declspec(uuid("a90106ed-9099-3329-8a5a-2044b3d8552b"))
_TargetInvocationException : IDispatch
{};

struct __declspec(uuid("6032b3cd-9bed-351c-a145-9d500b0f636f"))
_TargetParameterCountException : IDispatch
{};

struct __declspec(uuid("34e00ef9-83e2-3bbc-b6af-4cae703838bd"))
_TypeDelegator : IDispatch
{};

struct __declspec(uuid("e1817846-3745-3c97-b4a6-ee20a1641b29"))
_TypeFilter : IDispatch
{};

struct __declspec(uuid("d9bd3c8d-9395-3657-b6ee-d1b509c38b70"))
_Formatter : IDispatch
{};

struct __declspec(uuid("3faa35ee-c867-3e2e-bf48-2da271f88303"))
_FormatterConverter : IDispatch
{};

struct __declspec(uuid("f859954a-78cf-3d00-86ab-ef661e6a4b8d"))
_FormatterServices : IDispatch
{};

struct __declspec(uuid("a30646cc-f710-3bfa-a356-b4c858d4ed8e"))
_ObjectIDGenerator : IDispatch
{};

struct __declspec(uuid("f28e7d04-3319-3968-8201-c6e55becd3d4"))
_ObjectManager : IDispatch
{};

struct __declspec(uuid("feca70d4-ae27-3d94-93dd-a90f02e299d5"))
_OptionalFieldAttribute : IDispatch
{};

struct __declspec(uuid("9ec28d2c-04c0-35f3-a7ee-0013271ff65e"))
_OnSerializingAttribute : IDispatch
{};

struct __declspec(uuid("547bf8cd-f2a8-3b41-966d-98db33ded06d"))
_OnSerializedAttribute : IDispatch
{};

struct __declspec(uuid("f5aef88f-9ac4-320c-95d2-88e863a35762"))
_OnDeserializingAttribute : IDispatch
{};

struct __declspec(uuid("dd36c803-73d1-338d-88ba-dc9eb7620ef7"))
_OnDeserializedAttribute : IDispatch
{};

struct __declspec(uuid("450222d0-87ca-3699-a7b4-d8a0fdb72357"))
_SerializationBinder : IDispatch
{};

struct __declspec(uuid("b58d62cf-b03a-3a14-b0b6-b1e5ad4e4ad5"))
_SerializationInfo : IDispatch
{};

struct __declspec(uuid("d0eeaa62-3d30-3ee2-b896-a2f34dda47d8"))
ISerializable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetObjectData (
        /*[in]*/ struct _SerializationInfo * info,
        /*[in]*/ struct StreamingContext Context ) = 0;
};

struct __declspec(uuid("607056c6-1bca-36c8-ab87-33b202ebf0d8"))
_SerializationInfoEnumerator : IDispatch
{};

struct __declspec(uuid("245fe7fd-e020-3053-b5f6-7467fd2c6883"))
_SerializationException : IDispatch
{};

struct __declspec(uuid("6de1230e-1f52-3779-9619-f5184103466c"))
_SurrogateSelector : IDispatch
{};

struct __declspec(uuid("4cca29e4-584b-3cd0-ad25-855dc5799c16"))
_Calendar : IDispatch
{};

struct __declspec(uuid("89e148c4-2424-30ae-80f5-c5d21ea3366c"))
_EastAsianLunisolarCalendar : IDispatch
{};

struct __declspec(uuid("505defe5-aefa-3e23-82b0-d5eb085bb840"))
_CompareInfo : IDispatch
{};

struct __declspec(uuid("152722c2-f0b1-3d19-ada8-f40ca5caecb8"))
_CultureInfo : IDispatch
{};

struct __declspec(uuid("015e9f67-337c-398a-a0c1-da4af1905571"))
_DateTimeFormatInfo : IDispatch
{};

struct __declspec(uuid("efea8feb-ee7f-3e48-8a36-6206a6acbf73"))
_DaylightTime : IDispatch
{};

struct __declspec(uuid("677ad8b5-8a0e-3c39-92fb-72fb817cf694"))
_GregorianCalendar : IDispatch
{};

struct __declspec(uuid("96a62d6c-72a9-387a-81fa-e6dd5998caee"))
_HebrewCalendar : IDispatch
{};

struct __declspec(uuid("28ddc187-56b2-34cf-a078-48bd1e113d1e"))
_HijriCalendar : IDispatch
{};

struct __declspec(uuid("d662ae3f-cef9-38b4-bb8e-5d8dd1dbf806"))
_JapaneseCalendar : IDispatch
{};

struct __declspec(uuid("36e2de92-1fb3-3d7d-ba26-9cad5b98dd52"))
_JulianCalendar : IDispatch
{};

struct __declspec(uuid("48bea6c4-752e-3974-8ca8-cfb6274e2379"))
_KoreanCalendar : IDispatch
{};

struct __declspec(uuid("f9e97e04-4e1e-368f-b6c6-5e96ce4362d6"))
_RegionInfo : IDispatch
{};

struct __declspec(uuid("f4c70e15-2ca6-3e90-96ed-92e28491f538"))
_SortKey : IDispatch
{};

struct __declspec(uuid("0a25141f-51b3-3121-aa30-0af4556a52d9"))
_StringInfo : IDispatch
{};

struct __declspec(uuid("0c08ed74-0acf-32a9-99df-09a9dc4786dd"))
_TaiwanCalendar : IDispatch
{};

struct __declspec(uuid("8c248251-3e6c-3151-9f8e-a255fb8d2b12"))
_TextElementEnumerator : IDispatch
{};

struct __declspec(uuid("db8de23f-f264-39ac-b61c-cc1e7eb4a5e6"))
_TextInfo : IDispatch
{};

struct __declspec(uuid("c70c8ae8-925b-37ce-8944-34f15ff94307"))
_ThaiBuddhistCalendar : IDispatch
{};

struct __declspec(uuid("25e47d71-20dd-31be-b261-7ae76497d6b9"))
_NumberFormatInfo : IDispatch
{};

struct __declspec(uuid("ddedb94d-4f3f-35c1-97c9-3f1d87628d9e"))
_Encoding : IDispatch
{};

struct __declspec(uuid("8fd56502-8724-3df0-a1b5-9d0e8d4e4f78"))
_Encoder : IDispatch
{};

struct __declspec(uuid("2adb0d4a-5976-38e4-852b-c131797430f5"))
_Decoder : IDispatch
{};

struct __declspec(uuid("0cbe0204-12a1-3d40-9d9e-195de6aaa534"))
_ASCIIEncoding : IDispatch
{};

struct __declspec(uuid("f7dd3b7f-2b05-3894-8eda-59cdf9395b6a"))
_UnicodeEncoding : IDispatch
{};

struct __declspec(uuid("89b9f00b-aa2a-3a49-91b4-e8d1f1c00e58"))
_UTF7Encoding : IDispatch
{};

struct __declspec(uuid("010fc1d0-3ef9-3f3b-aa0a-b78a1ff83a37"))
_UTF8Encoding : IDispatch
{};

struct __declspec(uuid("1a4e1878-fe8c-3f59-b6a9-21ab82be57e9"))
_MissingManifestResourceException : IDispatch
{};

struct __declspec(uuid("5a8de087-d9d7-3bba-92b4-fe1034a1242f"))
_MissingSatelliteAssemblyException : IDispatch
{};

struct __declspec(uuid("f48df808-8b7d-3f4e-9159-1dfd60f298d6"))
_NeutralResourcesLanguageAttribute : IDispatch
{};

struct __declspec(uuid("4de671b7-7c85-37e9-aff8-1222abe4883e"))
_ResourceManager : IDispatch
{};

struct __declspec(uuid("7fbcfdc7-5cec-3945-8095-daed61be5fb1"))
_ResourceReader : IDispatch
{};

struct __declspec(uuid("44d5f81a-727c-35ae-8df8-9ff6722f1c6c"))
_ResourceSet : IDispatch
{};

struct __declspec(uuid("af170258-aac6-3a86-bd34-303e62ced10e"))
_ResourceWriter : IDispatch
{};

struct __declspec(uuid("5cbb1f47-fba5-33b9-9d4a-57d6e3d133d2"))
_SatelliteContractVersionAttribute : IDispatch
{};

struct __declspec(uuid("23bae0c0-3a36-32f0-9dad-0e95add67d23"))
_Registry : IDispatch
{};

struct __declspec(uuid("2eac6733-8d92-31d9-be04-dc467efc3eb1"))
_RegistryKey : IDispatch
{};

struct __declspec(uuid("99f01720-3cc2-366d-9ab9-50e36647617f"))
_AllMembershipCondition : IDispatch
{};

struct __declspec(uuid("9ccc831b-1ba7-34be-a966-56d5a6db5aad"))
_ApplicationDirectory : IDispatch
{};

struct __declspec(uuid("a02a2b22-1dba-3f92-9f84-5563182851bb"))
_ApplicationDirectoryMembershipCondition : IDispatch
{};

struct __declspec(uuid("18e473f6-637b-3c01-8d46-d011aad26c95"))
_ApplicationSecurityInfo : IDispatch
{};

struct __declspec(uuid("c664fe09-0a55-316d-b25b-6b3200ecaf70"))
_ApplicationSecurityManager : IDispatch
{};

struct __declspec(uuid("e66a9755-58e2-3fcb-a265-835851cbf063"))
_ApplicationTrust : IDispatch
{};

struct __declspec(uuid("bb03c920-1c05-3ecb-982d-53324d5ac9ff"))
_ApplicationTrustCollection : IDispatch
{};

struct __declspec(uuid("01afd447-60ca-3b67-803a-e57b727f3a5b"))
_ApplicationTrustEnumerator : IDispatch
{};

struct __declspec(uuid("d7093f61-ed6b-343f-b1e9-02472fcc710e"))
_CodeGroup : IDispatch
{};

struct __declspec(uuid("a505edbc-380e-3b23-9e1a-0974d4ef02ef"))
_Evidence : IDispatch
{};

struct __declspec(uuid("35a8f3ac-fe28-360f-a0c0-9a4d50c4682a"))
IEvidenceFactory : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Evidence (
        /*[out,retval]*/ struct _Evidence * * pRetVal ) = 0;
};

struct __declspec(uuid("6844eff4-4f86-3ca1-a1ea-aaf583a6395e"))
IMembershipCondition : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Check (
        /*[in]*/ struct _Evidence * Evidence,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ struct IMembershipCondition * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("4e95244e-c6fc-3a86-8db7-1712454de3b6"))
IIdentityPermissionFactory : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CreateIdentityPermission (
        /*[in]*/ struct _Evidence * Evidence,
        /*[out,retval]*/ struct IPermission * * pRetVal ) = 0;
};

struct __declspec(uuid("dfad74dc-8390-32f6-9612-1bd293b233f4"))
_FileCodeGroup : IDispatch
{};

struct __declspec(uuid("54b0afb1-e7d3-3770-bb0e-75a95e8d2656"))
_FirstMatchCodeGroup : IDispatch
{};

struct __declspec(uuid("d89eac5e-0331-3fcd-9c16-4f1ed3fe1be2"))
_TrustManagerContext : IDispatch
{};

struct __declspec(uuid("427e255d-af02-3b0d-8ce3-a2bb94ba300f"))
IApplicationTrustManager : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall DetermineApplicationTrust (
        /*[in]*/ IUnknown * activationContext,
        /*[in]*/ struct _TrustManagerContext * Context,
        /*[out,retval]*/ struct _ApplicationTrust * * pRetVal ) = 0;
};

struct __declspec(uuid("fe8a2546-3478-3fad-be1d-da7bc25c4e4e"))
_CodeConnectAccess : IDispatch
{};

struct __declspec(uuid("a8f69eca-8c48-3b5e-92a1-654925058059"))
_NetCodeGroup : IDispatch
{};

struct __declspec(uuid("34b0417e-e71d-304c-9fac-689350a1b41c"))
_PermissionRequestEvidence : IDispatch
{};

struct __declspec(uuid("a9c9f3d9-e153-39b8-a533-b8df4664407b"))
_PolicyException : IDispatch
{};

struct __declspec(uuid("44494e35-c370-3014-bc78-0f2ecbf83f53"))
_PolicyLevel : IDispatch
{};

struct __declspec(uuid("3eefd1fc-4d8d-3177-99f6-6c19d9e088d3"))
_PolicyStatement : IDispatch
{};

struct __declspec(uuid("90c40b4c-b0d0-30f5-b520-fdba97bc31a0"))
_Site : IDispatch
{};

struct __declspec(uuid("0a7c3542-8031-3593-872c-78d85d7cc273"))
_SiteMembershipCondition : IDispatch
{};

struct __declspec(uuid("2a75c1fd-06b0-3cbb-b467-2545d4d6c865"))
_StrongName : IDispatch
{};

struct __declspec(uuid("579e93bc-ffab-3b8d-9181-ce9c22b51915"))
_StrongNameMembershipCondition : IDispatch
{};

struct __declspec(uuid("d9d822de-44e5-33ce-a43f-173e475cecb1"))
_UnionCodeGroup : IDispatch
{};

struct __declspec(uuid("d94ed9bf-c065-3703-81a2-2f76ea8e312f"))
_Url : IDispatch
{};

struct __declspec(uuid("bb7a158d-dbd9-3e13-b137-8e61e87e1128"))
_UrlMembershipCondition : IDispatch
{};

struct __declspec(uuid("742e0c26-0e23-3d20-968c-d221094909aa"))
_Zone : IDispatch
{};

struct __declspec(uuid("adbc3463-0101-3429-a06c-db2f1dd6b724"))
_ZoneMembershipCondition : IDispatch
{};

struct __declspec(uuid("a7aef52c-b47b-3660-bb3e-34347d56db46"))
_GacInstalled : IDispatch
{};

struct __declspec(uuid("b2217ab5-6e55-3ff6-a1a9-1b0dc0585040"))
_GacMembershipCondition : IDispatch
{};

struct __declspec(uuid("7574e121-74a6-3626-b578-0783badb19d2"))
_Hash : IDispatch
{};

struct __declspec(uuid("6ba6ea7a-c9fc-3e73-82ec-18f29d83eefd"))
_HashMembershipCondition : IDispatch
{};

struct __declspec(uuid("77cca693-abf6-3773-bf58-c0b02701a744"))
_Publisher : IDispatch
{};

struct __declspec(uuid("3515cf63-9863-3044-b3e1-210e98efc702"))
_PublisherMembershipCondition : IDispatch
{};

struct __declspec(uuid("9a37d8b2-2256-3fe3-8bf0-4fc421a1244f"))
_GenericIdentity : IDispatch
{};

struct __declspec(uuid("b4701c26-1509-3726-b2e1-409a636c9b4f"))
_GenericPrincipal : IDispatch
{};

struct __declspec(uuid("d8cf3f23-1a66-3344-8230-07eb53970b85"))
_WindowsIdentity : IDispatch
{};

struct __declspec(uuid("60ecfdda-650a-324c-b4b3-f4d75b563bb1"))
_WindowsImpersonationContext : IDispatch
{};

struct __declspec(uuid("6c42baf9-1893-34fc-b3af-06931e9b34a3"))
_WindowsPrincipal : IDispatch
{};

struct __declspec(uuid("1b6ed26a-4b7f-34fc-b2c8-8109d684b3df"))
_UnmanagedFunctionPointerAttribute : IDispatch
{};

struct __declspec(uuid("bbe41ac5-8692-3427-9ae1-c1058a38d492"))
_DispIdAttribute : IDispatch
{};

struct __declspec(uuid("a2145f38-cac1-33dd-a318-21948af6825d"))
_InterfaceTypeAttribute : IDispatch
{};

struct __declspec(uuid("0c1e7b57-b9b1-36e4-8396-549c29062a81"))
_ComDefaultInterfaceAttribute : IDispatch
{};

struct __declspec(uuid("6b6391ee-842f-3e9a-8eee-f13325e10996"))
_ClassInterfaceAttribute : IDispatch
{};

struct __declspec(uuid("1e7fffe2-aad9-34ee-8a9f-3c016b880ff0"))
_ComVisibleAttribute : IDispatch
{};

struct __declspec(uuid("288a86d1-6f4f-39c9-9e42-162cf1c37226"))
_TypeLibImportClassAttribute : IDispatch
{};

struct __declspec(uuid("4ab67927-3c86-328a-8186-f85357dd5527"))
_LCIDConversionAttribute : IDispatch
{};

struct __declspec(uuid("51ba926f-aab5-3945-b8a6-c8f0f4a7d12b"))
_ComRegisterFunctionAttribute : IDispatch
{};

struct __declspec(uuid("9f164188-34eb-3f86-9f74-0bbe4155e65e"))
_ComUnregisterFunctionAttribute : IDispatch
{};

struct __declspec(uuid("2b9f01df-5a12-3688-98d6-c34bf5ed1865"))
_ProgIdAttribute : IDispatch
{};

struct __declspec(uuid("3f3311ce-6baf-3fb0-b855-489aff740b6e"))
_ImportedFromTypeLibAttribute : IDispatch
{};

struct __declspec(uuid("5778e7c7-2040-330e-b47a-92974dffcfd4"))
_IDispatchImplAttribute : IDispatch
{};

struct __declspec(uuid("e1984175-55f5-3065-82d8-a683fdfcf0ac"))
_ComSourceInterfacesAttribute : IDispatch
{};

struct __declspec(uuid("fd5b6aac-ff8c-3472-b894-cd6dfadb6939"))
_ComConversionLossAttribute : IDispatch
{};

struct __declspec(uuid("b5a1729e-b721-3121-a838-fde43af13468"))
_TypeLibTypeAttribute : IDispatch
{};

struct __declspec(uuid("3d18a8e2-eede-3139-b29d-8cac057955df"))
_TypeLibFuncAttribute : IDispatch
{};

struct __declspec(uuid("7b89862a-02a4-3279-8b42-4095fa3a778e"))
_TypeLibVarAttribute : IDispatch
{};

struct __declspec(uuid("d858399f-e19e-3423-a720-ac12abe2e5e8"))
_MarshalAsAttribute : IDispatch
{};

struct __declspec(uuid("1b093056-5454-386f-8971-bbcbc4e9a8f3"))
_ComImportAttribute : IDispatch
{};

struct __declspec(uuid("74435dad-ec55-354b-8f5b-fa70d13b6293"))
_GuidAttribute : IDispatch
{};

struct __declspec(uuid("fdf2a2ee-c882-3198-a48b-e37f0e574dfa"))
_PreserveSigAttribute : IDispatch
{};

struct __declspec(uuid("8474b65c-c39a-3d05-893d-577b9a314615"))
_InAttribute : IDispatch
{};

struct __declspec(uuid("0697fc8c-9b04-3783-95c7-45eccac1ca27"))
_OutAttribute : IDispatch
{};

struct __declspec(uuid("0d6bd9ad-198e-3904-ad99-f6f82a2787c4"))
_OptionalAttribute : IDispatch
{};

struct __declspec(uuid("a1a26181-d55e-3ee2-96e6-70b354ef9371"))
_DllImportAttribute : IDispatch
{};

struct __declspec(uuid("23753322-c7b3-3f9a-ac96-52672c1b1ca9"))
_StructLayoutAttribute : IDispatch
{};

struct __declspec(uuid("c14342b8-bafd-322a-bb71-62c672da284e"))
_FieldOffsetAttribute : IDispatch
{};

struct __declspec(uuid("e78785c4-3a73-3c15-9390-618bf3a14719"))
_ComAliasNameAttribute : IDispatch
{};

struct __declspec(uuid("57b908a8-c082-3581-8a47-6b41b86e8fdc"))
_AutomationProxyAttribute : IDispatch
{};

struct __declspec(uuid("c69e96b2-6161-3621-b165-5805198c6b8d"))
_PrimaryInteropAssemblyAttribute : IDispatch
{};

struct __declspec(uuid("15d54c00-7c95-38d7-b859-e19346677dcd"))
_CoClassAttribute : IDispatch
{};

struct __declspec(uuid("76cc0491-9a10-35c0-8a66-7931ec345b7f"))
_ComEventInterfaceAttribute : IDispatch
{};

struct __declspec(uuid("a03b61a4-ca61-3460-8232-2f4ec96aa88f"))
_TypeLibVersionAttribute : IDispatch
{};

struct __declspec(uuid("ad419379-2ac8-3588-ab1e-0115413277c4"))
_ComCompatibleVersionAttribute : IDispatch
{};

struct __declspec(uuid("ed47abe7-c84b-39f9-be1b-828cfb925afe"))
_BestFitMappingAttribute : IDispatch
{};

struct __declspec(uuid("b26b3465-28e4-33b5-b9bf-dd7c4f6461f5"))
_DefaultCharSetAttribute : IDispatch
{};

struct __declspec(uuid("a54ac093-bfce-37b0-a81f-148dfed0971f"))
_SetWin32ContextInIDispatchAttribute : IDispatch
{};

struct __declspec(uuid("a83f04e9-fd28-384a-9dff-410688ac23ab"))
_ExternalException : IDispatch
{};

struct __declspec(uuid("a28c19df-b488-34ae-becc-7de744d17f7b"))
_COMException : IDispatch
{};

struct __declspec(uuid("76e5dbd6-f960-3c65-8ea6-fc8ad6a67022"))
_InvalidOleVariantTypeException : IDispatch
{};

struct __declspec(uuid("523f42a5-1fd2-355d-82bf-0d67c4a0a0e7"))
_MarshalDirectiveException : IDispatch
{};

struct __declspec(uuid("edcee21a-3e3a-331e-a86d-274028be6716"))
_RuntimeEnvironment : IDispatch
{};

struct __declspec(uuid("3e72e067-4c5e-36c8-bbef-1e2978c7780d"))
_SEHException : IDispatch
{};

struct __declspec(uuid("80da5818-609f-32b8-a9f8-95fcfbdb9c8e"))
_BStrWrapper : IDispatch
{};

struct __declspec(uuid("7df6f279-da62-3c9f-8944-4dd3c0f08170"))
_CurrencyWrapper : IDispatch
{};

struct __declspec(uuid("72103c67-d511-329c-b19a-dd5ec3f1206c"))
_DispatchWrapper : IDispatch
{};

struct __declspec(uuid("f79db336-06be-3959-a5ab-58b2ab6c5fd1"))
_ErrorWrapper : IDispatch
{};

struct __declspec(uuid("519eb857-7a2d-3a95-a2a3-8bb8ed63d41b"))
_ExtensibleClassFactory : IDispatch
{};

struct __declspec(uuid("de9156b5-5e7a-3041-bf45-a29a6c2cf48a"))
_InvalidComObjectException : IDispatch
{};

struct __declspec(uuid("e4a369d3-6cf0-3b05-9c0c-1a91e331641a"))
_ObjectCreationDelegate : IDispatch
{};

struct __declspec(uuid("8608fe7b-2fdc-318a-b711-6f7b2feded06"))
_SafeArrayRankMismatchException : IDispatch
{};

struct __declspec(uuid("e093fb32-e43b-3b3f-a163-742c920c2af3"))
_SafeArrayTypeMismatchException : IDispatch
{};

struct __declspec(uuid("1c8d8b14-4589-3dca-8e0f-a30e80fbd1a8"))
_UnknownWrapper : IDispatch
{};

struct __declspec(uuid("2752364a-924f-3603-8f6f-6586df98b292"))
_Stream : IDispatch
{};

struct __declspec(uuid("9be679a6-61fd-38fc-a7b2-89982d33338b"))
IServerResponseChannelSinkStack : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AsyncProcessResponse (
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[in]*/ struct _Stream * Stream ) = 0;
      virtual HRESULT __stdcall GetResponseStream (
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[out,retval]*/ struct _Stream * * pRetVal ) = 0;
};

struct __declspec(uuid("442e3c03-a205-3f21-aa4d-31768bb8ea28"))
_BinaryReader : IDispatch
{};

struct __declspec(uuid("4ca8147e-baa3-3a7f-92ce-a4fd7f17d8da"))
_BinaryWriter : IDispatch
{};

struct __declspec(uuid("4b7571c3-1275-3457-8fee-9976fd3937e3"))
_BufferedStream : IDispatch
{};

struct __declspec(uuid("8ce58ff5-f26d-38a4-9195-0e2ecb3b56b9"))
_Directory : IDispatch
{};

struct __declspec(uuid("a5d29a57-36a8-3e36-a099-7458b1fabaa2"))
_FileSystemInfo : IDispatch
{};

struct __declspec(uuid("487e52f1-2bb9-3bd0-a0ca-6728b3a1d051"))
_DirectoryInfo : IDispatch
{};

struct __declspec(uuid("c5bfc9bf-27a7-3a59-a986-44c85f3521bf"))
_IOException : IDispatch
{};

struct __declspec(uuid("c8a200e4-9735-30e4-b168-ed861a3020f2"))
_DirectoryNotFoundException : IDispatch
{};

struct __declspec(uuid("ce83a763-940f-341f-b880-332325eb6f4b"))
_DriveInfo : IDispatch
{};

struct __declspec(uuid("b24e9559-a662-3762-ae33-bc7dfdd538f4"))
_DriveNotFoundException : IDispatch
{};

struct __declspec(uuid("d625afd0-8fd9-3113-a900-43912a54c421"))
_EndOfStreamException : IDispatch
{};

struct __declspec(uuid("5d59051f-e19d-329a-9962-fd00d552e13d"))
_File : IDispatch
{};

struct __declspec(uuid("c3c429f9-8590-3a01-b2b2-434837f3d16d"))
_FileInfo : IDispatch
{};

struct __declspec(uuid("51d2c393-9b70-3551-84b5-ff5409fb3ada"))
_FileLoadException : IDispatch
{};

struct __declspec(uuid("a15a976b-81e3-3ef4-8ff1-d75ddbe20aef"))
_FileNotFoundException : IDispatch
{};

struct __declspec(uuid("74265195-4a46-3d6f-a9dd-69c367ea39c8"))
_FileStream : IDispatch
{};

struct __declspec(uuid("2dbc46fe-b3dd-3858-afc2-d3a2d492a588"))
_MemoryStream : IDispatch
{};

struct __declspec(uuid("6df93530-d276-31d9-8573-346778c650af"))
_Path : IDispatch
{};

struct __declspec(uuid("468b8eb4-89ac-381b-8f86-5e47ec0648b4"))
_PathTooLongException : IDispatch
{};

struct __declspec(uuid("897471f2-9450-3f03-a41f-d2e1f1397854"))
_TextReader : IDispatch
{};

struct __declspec(uuid("e645b470-dc3f-3ce0-8104-5837feda04b3"))
_StreamReader : IDispatch
{};

struct __declspec(uuid("556137ea-8825-30bc-9d49-e47a9db034ee"))
_TextWriter : IDispatch
{};

struct __declspec(uuid("1f124e1c-d05d-3643-a59f-c3de6051994f"))
_StreamWriter : IDispatch
{};

struct __declspec(uuid("59733b03-0ea5-358c-95b5-659fcd9aa0b4"))
_StringReader : IDispatch
{};

struct __declspec(uuid("cb9f94c0-d691-3b62-b0b2-3ce5309cfa62"))
_StringWriter : IDispatch
{};

struct __declspec(uuid("998dcf16-f603-355d-8c89-3b675947997f"))
_AccessedThroughPropertyAttribute : IDispatch
{};

struct __declspec(uuid("a6c2239b-08e6-3822-9769-e3d4b0431b82"))
_CallConvCdecl : IDispatch
{};

struct __declspec(uuid("8e17a5cd-1160-32dc-8548-407e7c3827c9"))
_CallConvStdcall : IDispatch
{};

struct __declspec(uuid("fa73dd3d-a472-35ed-b8be-f99a13581f72"))
_CallConvThiscall : IDispatch
{};

struct __declspec(uuid("3b452d17-3c5e-36c4-a12d-5e9276036cf8"))
_CallConvFastcall : IDispatch
{};

struct __declspec(uuid("62caf4a2-6a78-3fc7-af81-a6bbf930761f"))
_CustomConstantAttribute : IDispatch
{};

struct __declspec(uuid("ef387020-b664-3acd-a1d2-806345845953"))
_DateTimeConstantAttribute : IDispatch
{};

struct __declspec(uuid("3c3a8c69-7417-32fa-aa20-762d85e1b594"))
_DiscardableAttribute : IDispatch
{};

struct __declspec(uuid("7e133967-ccec-3e89-8bd2-6cfca649ecbf"))
_DecimalConstantAttribute : IDispatch
{};

struct __declspec(uuid("c5c4f625-2329-3382-8994-aaf561e5dfe9"))
_CompilationRelaxationsAttribute : IDispatch
{};

struct __declspec(uuid("1eed213e-656a-3a73-a4b9-0d3b26fd942b"))
_CompilerGlobalScopeAttribute : IDispatch
{};

struct __declspec(uuid("243368f5-67c9-3510-9424-335a8a67772f"))
_IndexerNameAttribute : IDispatch
{};

struct __declspec(uuid("0278c819-0c06-3756-b053-601a3e566d9b"))
_IsVolatile : IDispatch
{};

struct __declspec(uuid("98966503-5d80-3242-83ef-79e136f6b954"))
_MethodImplAttribute : IDispatch
{};

struct __declspec(uuid("db2c11d9-3870-35e7-a10c-a3ddc3dc79b1"))
_RequiredAttributeAttribute : IDispatch
{};

struct __declspec(uuid("f68a4008-ab94-3370-a9ac-8cc99939f534"))
_IsCopyConstructed : IDispatch
{};

struct __declspec(uuid("40e8e914-dc23-38a6-936b-90e4e3ab01fa"))
_NativeCppClassAttribute : IDispatch
{};

struct __declspec(uuid("97d0b28a-6932-3d74-b67f-6bcd3c921e7d"))
_IDispatchConstantAttribute : IDispatch
{};

struct __declspec(uuid("54542649-ce64-3f96-bce5-fde3bb22f242"))
_IUnknownConstantAttribute : IDispatch
{};

struct __declspec(uuid("8d597c42-2cfd-32b6-b6d6-86c9e2cff00a"))
_SecurityElement : IDispatch
{};

struct __declspec(uuid("fd46bde5-acdf-3ca5-b189-f0678387077f"))
ISecurityEncodable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ToXml (
        /*[out,retval]*/ struct _SecurityElement * * pRetVal ) = 0;
      virtual HRESULT __stdcall FromXml (
        /*[in]*/ struct _SecurityElement * e ) = 0;
};

struct __declspec(uuid("e6c21ba7-21bb-34e9-8e57-db66d8ce4a70"))
ISecurityPolicyEncodable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ToXml (
        /*[in]*/ struct _PolicyLevel * level,
        /*[out,retval]*/ struct _SecurityElement * * pRetVal ) = 0;
      virtual HRESULT __stdcall FromXml (
        /*[in]*/ struct _SecurityElement * e,
        /*[in]*/ struct _PolicyLevel * level ) = 0;
};

struct __declspec(uuid("d9fcad88-d869-3788-a802-1b1e007c7a22"))
_XmlSyntaxException : IDispatch
{};

struct __declspec(uuid("4803ce39-2f30-31fc-b84b-5a0141385269"))
_CodeAccessPermission : IDispatch
{};

struct __declspec(uuid("0720590d-5218-352a-a337-5449e6bd19da"))
_EnvironmentPermission : IDispatch
{};

struct __declspec(uuid("a8b7138c-8932-3d78-a585-a91569c743ac"))
_FileDialogPermission : IDispatch
{};

struct __declspec(uuid("a2ed7efc-8e59-3ccc-ae92-ea2377f4d5ef"))
_FileIOPermission : IDispatch
{};

struct __declspec(uuid("48815668-6c27-3312-803e-2757f55ce96a"))
_SecurityAttribute : IDispatch
{};

struct __declspec(uuid("9c5149cb-d3c6-32fd-a0d5-95350de7b813"))
_CodeAccessSecurityAttribute : IDispatch
{};

struct __declspec(uuid("9f8f73a3-1e99-3e51-a41b-179a41dc747c"))
_HostProtectionAttribute : IDispatch
{};

struct __declspec(uuid("7fee7903-f97c-3350-ad42-196b00ad2564"))
_IsolatedStoragePermission : IDispatch
{};

struct __declspec(uuid("0d0c83e8-bde1-3ba5-b1ef-a8fc686d8bc9"))
_IsolatedStorageFilePermission : IDispatch
{};

struct __declspec(uuid("4164071a-ed12-3bdd-af40-fdabcaa77d5f"))
_EnvironmentPermissionAttribute : IDispatch
{};

struct __declspec(uuid("0ccca629-440f-313e-96cd-ba1b4b4997f7"))
_FileDialogPermissionAttribute : IDispatch
{};

struct __declspec(uuid("0dca817d-f21a-3943-b54c-5e800ce5bc50"))
_FileIOPermissionAttribute : IDispatch
{};

struct __declspec(uuid("edb51d1c-08ad-346a-be6f-d74fd6d6f965"))
_KeyContainerPermissionAttribute : IDispatch
{};

struct __declspec(uuid("68ab69e4-5d68-3b51-b74d-1beab9f37f2b"))
_PrincipalPermissionAttribute : IDispatch
{};

struct __declspec(uuid("d31eed10-a5f0-308f-a951-e557961ec568"))
_ReflectionPermissionAttribute : IDispatch
{};

struct __declspec(uuid("38b6068c-1e94-3119-8841-1eca35ed8578"))
_RegistryPermissionAttribute : IDispatch
{};

struct __declspec(uuid("3a5b876c-cde4-32d2-9c7e-020a14aca332"))
_SecurityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("1d5c0f70-af29-38a3-9436-3070a310c73b"))
_UIPermissionAttribute : IDispatch
{};

struct __declspec(uuid("2e3be3ed-2f22-3b20-9f92-bd29b79d6f42"))
_ZoneIdentityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("c9a740f4-26e9-39a8-8885-8ca26bd79b21"))
_StrongNameIdentityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("6fe6894a-2a53-3fb6-a06e-348f9bdad23b"))
_SiteIdentityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("ca4a2073-48c5-3e61-8349-11701a90dd9b"))
_UrlIdentityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("6722c730-1239-3784-ac94-c285ae5b901a"))
_PublisherIdentityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("5c4c522f-de4e-3595-9aa9-9319c86a5283"))
_IsolatedStoragePermissionAttribute : IDispatch
{};

struct __declspec(uuid("6f1f8aae-d667-39cc-98fa-722bebbbeac3"))
_IsolatedStorageFilePermissionAttribute : IDispatch
{};

struct __declspec(uuid("947a1995-bc16-3e7c-b65a-99e71f39c091"))
_PermissionSetAttribute : IDispatch
{};

struct __declspec(uuid("aeb3727f-5c3a-34c4-bf18-a38f088ac8c7"))
_ReflectionPermission : IDispatch
{};

struct __declspec(uuid("7c6b06d1-63ad-35ef-a938-149b4ad9a71f"))
_PrincipalPermission : IDispatch
{};

struct __declspec(uuid("33c54a2d-02bd-3848-80b6-742d537085e5"))
_SecurityPermission : IDispatch
{};

struct __declspec(uuid("790b3ee9-7e06-3cd0-8243-5848486d6a78"))
_SiteIdentityPermission : IDispatch
{};

struct __declspec(uuid("5f1562fb-0160-3655-baea-b15bef609161"))
_StrongNameIdentityPermission : IDispatch
{};

struct __declspec(uuid("af53d21a-d6af-3406-b399-7df9d2aad48a"))
_StrongNamePublicKeyBlob : IDispatch
{};

struct __declspec(uuid("47698389-f182-3a67-87df-aed490e14dc6"))
_UIPermission : IDispatch
{};

struct __declspec(uuid("ec7cac31-08a2-393b-bdf2-d052eb53af2c"))
_UrlIdentityPermission : IDispatch
{};

struct __declspec(uuid("38b2f8d7-8cf4-323b-9c17-9c55ee287a63"))
_ZoneIdentityPermission : IDispatch
{};

struct __declspec(uuid("5f19e082-26f8-3361-b338-9bacb98809a4"))
_GacIdentityPermissionAttribute : IDispatch
{};

struct __declspec(uuid("a9637792-5be8-3c93-a501-49f0e840de38"))
_GacIdentityPermission : IDispatch
{};

struct __declspec(uuid("094351ea-dbc1-327f-8a83-913b593a66be"))
_KeyContainerPermissionAccessEntry : IDispatch
{};

struct __declspec(uuid("28ecf94e-3510-3a3e-8bd1-f866f45f3b06"))
_KeyContainerPermissionAccessEntryCollection : IDispatch
{};

struct __declspec(uuid("293187ea-5f88-316f-86a5-533b0c7b353f"))
_KeyContainerPermissionAccessEntryEnumerator : IDispatch
{};

struct __declspec(uuid("107a3cf1-b35e-3a23-b660-60264b231225"))
_KeyContainerPermission : IDispatch
{};

struct __declspec(uuid("e86cc74a-1233-3df3-b13f-8b27eeaac1f6"))
_PublisherIdentityPermission : IDispatch
{};

struct __declspec(uuid("c3fb5510-3454-3b31-b64f-de6aad6be820"))
_RegistryPermission : IDispatch
{};

struct __declspec(uuid("8000e51a-541c-3b20-a8ec-c8a8b41116c4"))
_SuppressUnmanagedCodeSecurityAttribute : IDispatch
{};

struct __declspec(uuid("41f41c1b-7b8d-39a3-a28f-aae20787f469"))
_UnverifiableCodeAttribute : IDispatch
{};

struct __declspec(uuid("f1c930c4-2233-3924-9840-231d008259b4"))
_AllowPartiallyTrustedCallersAttribute : IDispatch
{};

struct __declspec(uuid("9deae196-48c1-3590-9d0a-33716a214acd"))
_HostSecurityManager : IDispatch
{};

struct __declspec(uuid("c2af4970-4fb6-319c-a8aa-0614d27f2b2c"))
_PermissionSet : IDispatch
{};

struct __declspec(uuid("ba3e053f-ade3-3233-874a-16e624c9a49b"))
_NamedPermissionSet : IDispatch
{};

struct __declspec(uuid("f174290f-e4cf-3976-88aa-4f8e32eb03db"))
_SecurityException : IDispatch
{};

struct __declspec(uuid("ed727a9b-6fc5-3fed-bedd-7b66c847f87a"))
_HostProtectionException : IDispatch
{};

struct __declspec(uuid("abc04b16-5539-3c7e-92ec-0905a4a24464"))
_SecurityManager : IDispatch
{};

struct __declspec(uuid("f65070df-57af-3ae3-b951-d2ad7d513347"))
_VerificationException : IDispatch
{};

struct __declspec(uuid("f042505b-7aac-313b-a8c7-3f1ac949c311"))
_ContextAttribute : IDispatch
{};

struct __declspec(uuid("3936abe1-b29e-3593-83f1-793d1a7f3898"))
_AsyncResult : IDispatch
{};

struct __declspec(uuid("53bce4d4-6209-396d-bd4a-0b0a0a177df9"))
_CallContext : IDispatch
{};

struct __declspec(uuid("9aff21f5-1c9c-35e7-aea4-c3aa0beb3b77"))
_LogicalCallContext : IDispatch
{};

struct __declspec(uuid("ffb2e16e-e5c7-367c-b326-965abf510f24"))
_ChannelServices : IDispatch
{};

struct __declspec(uuid("e1796120-c324-30d8-86f4-20086711463b"))
_ClientChannelSinkStack : IDispatch
{};

struct __declspec(uuid("52da9f90-89b3-35ab-907b-3562642967de"))
_ServerChannelSinkStack : IDispatch
{};

struct __declspec(uuid("ff19d114-3bda-30ac-8e89-36ca64a87120"))
_ClientSponsor : IDispatch
{};

struct __declspec(uuid("ee949b7b-439f-363e-b9fc-34db1fb781d7"))
_CrossContextDelegate : IDispatch
{};

struct __declspec(uuid("11a2ea7a-d600-307b-a606-511a6c7950d1"))
_Context : IDispatch
{};

struct __declspec(uuid("f01d896d-8d5f-3235-be59-20e1e10dc22a"))
IContextProperty : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall IsNewContextOK (
        /*[in]*/ struct _Context * newCtx,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Freeze (
        /*[in]*/ struct _Context * newContext ) = 0;
};

struct __declspec(uuid("4acb3495-05db-381b-890a-d12f5340dca3"))
_ContextProperty : IDispatch
{};

struct __declspec(uuid("77c9bceb-9958-33c0-a858-599f66697da7"))
_EnterpriseServicesHelper : IDispatch
{};

struct __declspec(uuid("0d296515-ad19-3602-b415-d8ec77066081"))
_Header : IDispatch
{};

struct __declspec(uuid("5dbbaf39-a3df-30b7-aaea-9fd11394123f"))
_HeaderHandler : IDispatch
{};

struct __declspec(uuid("ae1850fd-3596-3727-a242-2fc31c5a0312"))
IRemotingFormatter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Deserialize (
        /*[in]*/ struct _Stream * serializationStream,
        /*[in]*/ struct _HeaderHandler * handler,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Serialize (
        /*[in]*/ struct _Stream * serializationStream,
        /*[in]*/ VARIANT graph,
        /*[in]*/ SAFEARRAY * headers ) = 0;
};

struct __declspec(uuid("aa6da581-f972-36de-a53b-7585428a68ab"))
_ChannelDataStore : IDispatch
{};

struct __declspec(uuid("65887f70-c646-3a66-8697-8a3f7d8fe94d"))
_TransportHeaders : IDispatch
{};

struct __declspec(uuid("a18545b7-e5ee-31ee-9b9b-41199b11c995"))
_SinkProviderData : IDispatch
{};

struct __declspec(uuid("a1329ec9-e567-369f-8258-18366d89eaf8"))
_BaseChannelObjectWithProperties : IDispatch
{};

struct __declspec(uuid("8af3451e-154d-3d86-80d8-f8478b9733ed"))
_BaseChannelSinkWithProperties : IDispatch
{};

struct __declspec(uuid("94bb98ed-18bb-3843-a7fe-642824ab4e01"))
_BaseChannelWithProperties : IDispatch
{};

struct __declspec(uuid("b0ad9a21-5439-3d88-8975-4018b828d74c"))
_LifetimeServices : IDispatch
{};

struct __declspec(uuid("0eeff4c2-84bf-3e4e-bf22-b7bdbb5df899"))
_ReturnMessage : IDispatch
{};

struct __declspec(uuid("95e01216-5467-371b-8597-4074402ccb06"))
_MethodCall : IDispatch
{};

struct __declspec(uuid("a2246ae7-eb81-3a20-8e70-c9fa341c7e10"))
_ConstructionCall : IDispatch
{};

struct __declspec(uuid("9e9ea93a-d000-3ab9-bfca-ddeb398a55b9"))
_MethodResponse : IDispatch
{};

struct __declspec(uuid("be457280-6ffa-3e76-9822-83de63c0c4e0"))
_ConstructionResponse : IDispatch
{};

struct __declspec(uuid("ef926e1f-3ee7-32bc-8b01-c6e98c24bc19"))
_InternalMessageWrapper : IDispatch
{};

struct __declspec(uuid("c9614d78-10ea-3310-87ea-821b70632898"))
_MethodCallMessageWrapper : IDispatch
{};

struct __declspec(uuid("89304439-a24f-30f6-9a8f-89ce472d85da"))
_MethodReturnMessageWrapper : IDispatch
{};

struct __declspec(uuid("1dd3cf3d-df8e-32ff-91ec-e19aa10b63fb"))
_ObjRef : IDispatch
{};

struct __declspec(uuid("03ec7d10-17a5-3585-9a2e-0596fcac3870"))
ITrackingHandler : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall MarshaledObject (
        /*[in]*/ VARIANT obj,
        /*[in]*/ struct _ObjRef * or ) = 0;
      virtual HRESULT __stdcall UnmarshaledObject (
        /*[in]*/ VARIANT obj,
        /*[in]*/ struct _ObjRef * or ) = 0;
      virtual HRESULT __stdcall DisconnectedObject (
        /*[in]*/ VARIANT obj ) = 0;
};

struct __declspec(uuid("8ffedc68-5233-3fa8-813d-405aabb33ecb"))
_OneWayAttribute : IDispatch
{};

struct __declspec(uuid("d80ff312-2930-3680-a5e9-b48296c7415f"))
_ProxyAttribute : IDispatch
{};

struct __declspec(uuid("e0cf3f77-c7c3-33da-beb4-46147fc905de"))
_RealProxy : IDispatch
{};

struct __declspec(uuid("725692a5-9e12-37f6-911c-e3da77e5faca"))
_SoapAttribute : IDispatch
{};

struct __declspec(uuid("ebcdcd84-8c74-39fd-821c-f5eb3a2704d7"))
_SoapTypeAttribute : IDispatch
{};

struct __declspec(uuid("c58145b5-bd5a-3896-95d9-b358f54fbc44"))
_SoapMethodAttribute : IDispatch
{};

struct __declspec(uuid("46a3f9ff-f73c-33c7-bcc3-1bef4b25e4ae"))
_SoapFieldAttribute : IDispatch
{};

struct __declspec(uuid("c32abfc9-3917-30bf-a7bc-44250bdfc5d8"))
_SoapParameterAttribute : IDispatch
{};

struct __declspec(uuid("4b10971e-d61d-373f-bc8d-2ccf31126215"))
_RemotingConfiguration : IDispatch
{};

struct __declspec(uuid("8359f3ab-643f-3bcf-91e8-16e779edebe1"))
_TypeEntry : IDispatch
{};

struct __declspec(uuid("bac12781-6865-3558-a8d1-f1cadd2806dd"))
_ActivatedClientTypeEntry : IDispatch
{};

struct __declspec(uuid("94855a3b-5ca2-32cf-b1ab-48fd3915822c"))
_ActivatedServiceTypeEntry : IDispatch
{};

struct __declspec(uuid("4d0bc339-e3f9-3e9e-8f68-92168e6f6981"))
_WellKnownClientTypeEntry : IDispatch
{};

struct __declspec(uuid("60b8b604-0aed-3093-ac05-eb98fb29fc47"))
_WellKnownServiceTypeEntry : IDispatch
{};

struct __declspec(uuid("7264843f-f60c-39a9-99e1-029126aa0815"))
_RemotingException : IDispatch
{};

struct __declspec(uuid("19373c44-55b4-3487-9ad8-4c621aae85ea"))
_ServerException : IDispatch
{};

struct __declspec(uuid("44db8e15-acb1-34ee-81f9-56ed7ae37a5c"))
_RemotingTimeoutException : IDispatch
{};

struct __declspec(uuid("7b91368d-a50a-3d36-be8e-5b8836a419ad"))
_RemotingServices : IDispatch
{};

struct __declspec(uuid("f4efb305-cdc4-31c5-8102-33c9b91774f3"))
_InternalRemotingServices : IDispatch
{};

struct __declspec(uuid("04a35d22-0b08-34e7-a573-88ef2374375e"))
_MessageSurrogateFilter : IDispatch
{};

struct __declspec(uuid("551f7a57-8651-37db-a94a-6a3ca09c0ed7"))
_RemotingSurrogateSelector : IDispatch
{};

struct __declspec(uuid("7416b6ee-82e8-3a16-966b-018a40e7b1aa"))
_SoapServices : IDispatch
{};

struct __declspec(uuid("1738adbc-156e-3897-844f-c3147c528dea"))
_SoapDateTime : IDispatch
{};

struct __declspec(uuid("7ef50ddb-32a5-30a1-b412-47fab911404a"))
_SoapDuration : IDispatch
{};

struct __declspec(uuid("a3bf0bcd-ec32-38e6-92f2-5f37bad8030d"))
_SoapTime : IDispatch
{};

struct __declspec(uuid("cfa6e9d2-b3de-39a6-94d1-cc691de193f8"))
_SoapDate : IDispatch
{};

struct __declspec(uuid("103c7ef9-a9ee-35fb-84c5-3086c9725a20"))
_SoapYearMonth : IDispatch
{};

struct __declspec(uuid("c20769f3-858d-316a-be6d-c347a47948ad"))
_SoapYear : IDispatch
{};

struct __declspec(uuid("f9ead0aa-4156-368f-ae05-fd59d70f758d"))
_SoapMonthDay : IDispatch
{};

struct __declspec(uuid("d9e8314d-5053-3497-8a33-97d3dcfe33e2"))
_SoapDay : IDispatch
{};

struct __declspec(uuid("b4e32423-e473-3562-aa12-62fde5a7d4a2"))
_SoapMonth : IDispatch
{};

struct __declspec(uuid("63b9da95-fb91-358a-b7b7-90c34aa34ab7"))
_SoapHexBinary : IDispatch
{};

struct __declspec(uuid("8ed115a1-5e7b-34dc-ab85-90316f28015d"))
_SoapBase64Binary : IDispatch
{};

struct __declspec(uuid("30c65c40-4e54-3051-9d8f-4709b6ab214c"))
_SoapInteger : IDispatch
{};

struct __declspec(uuid("4979ec29-c2b7-3ad6-986d-5aaf7344cc4e"))
_SoapPositiveInteger : IDispatch
{};

struct __declspec(uuid("aaf5401e-f71c-3fe3-8a73-a25074b20d3a"))
_SoapNonPositiveInteger : IDispatch
{};

struct __declspec(uuid("bc261fc6-7132-3fb5-9aac-224845d3aa99"))
_SoapNonNegativeInteger : IDispatch
{};

struct __declspec(uuid("e384aa10-a70c-3943-97cf-0f7c282c3bdc"))
_SoapNegativeInteger : IDispatch
{};

struct __declspec(uuid("818ec118-be7e-3cde-92c8-44b99160920e"))
_SoapAnyUri : IDispatch
{};

struct __declspec(uuid("3ac646b6-6b84-382f-9aed-22c2433244e6"))
_SoapQName : IDispatch
{};

struct __declspec(uuid("974f01f4-6086-3137-9448-6a31fc9bef08"))
_SoapNotation : IDispatch
{};

struct __declspec(uuid("f4926b50-3f23-37e0-9afa-aa91ff89a7bd"))
_SoapNormalizedString : IDispatch
{};

struct __declspec(uuid("ab4e97b9-651d-36f4-aaba-28acf5746624"))
_SoapToken : IDispatch
{};

struct __declspec(uuid("14aed851-a168-3462-b877-8f9a01126653"))
_SoapLanguage : IDispatch
{};

struct __declspec(uuid("5eb06bef-4adf-3cc1-a6f2-62f76886b13a"))
_SoapName : IDispatch
{};

struct __declspec(uuid("7947a829-adb5-34d0-9cc8-6c172742c803"))
_SoapIdrefs : IDispatch
{};

struct __declspec(uuid("aca96da3-96ed-397e-8a72-ee1be1025f5e"))
_SoapEntities : IDispatch
{};

struct __declspec(uuid("e941fa15-e6c8-3dd4-b060-c0ddfbc0240a"))
_SoapNmtoken : IDispatch
{};

struct __declspec(uuid("a5e385ae-27fb-3708-baf7-0bf1f3955747"))
_SoapNmtokens : IDispatch
{};

struct __declspec(uuid("725cdaf7-b739-35c1-8463-e2a923e1f618"))
_SoapNcName : IDispatch
{};

struct __declspec(uuid("6a46b6a2-2d2c-3c67-af67-aae0175f17ae"))
_SoapId : IDispatch
{};

struct __declspec(uuid("7db7fd83-de89-38e1-9645-d4cabde694c0"))
_SoapIdref : IDispatch
{};

struct __declspec(uuid("37171746-b784-3586-a7d5-692a7604a66b"))
_SoapEntity : IDispatch
{};

struct __declspec(uuid("2d985674-231c-33d4-b14d-f3a6bd2ebe19"))
_SynchronizationAttribute : IDispatch
{};

struct __declspec(uuid("f51728f2-2def-308c-874a-cbb1baa9cf9e"))
_TrackingServices : IDispatch
{};

struct __declspec(uuid("717105a3-739b-3bc3-a2b7-ad215903fad2"))
_UrlAttribute : IDispatch
{};

struct __declspec(uuid("34ec3bd7-f2f6-3c20-a639-804bff89df65"))
_IsolatedStorage : IDispatch
{};

struct __declspec(uuid("6bbb7dee-186f-3d51-9486-be0a71e915ce"))
_IsolatedStorageFile : IDispatch
{};

struct __declspec(uuid("68d5592b-47c8-381a-8d51-3925c16cf025"))
_IsolatedStorageFileStream : IDispatch
{};

struct __declspec(uuid("aec2b0de-9898-3607-b845-63e2e307cb5f"))
_IsolatedStorageException : IDispatch
{};

struct __declspec(uuid("361a5049-1bc8-35a9-946a-53a877902f25"))
_InternalRM : IDispatch
{};

struct __declspec(uuid("a864fb13-f945-3dc0-a01c-b903f944fc97"))
_InternalST : IDispatch
{};

struct __declspec(uuid("bc0847b2-bd5c-37b3-ba67-7d2d54b17238"))
_SoapMessage : IDispatch
{};

struct __declspec(uuid("a1c392fc-314c-39d5-8de6-1f8ebca0a1e2"))
_SoapFault : IDispatch
{};

struct __declspec(uuid("02d1bd78-3bb6-37ad-a9f8-f7d5da273e4e"))
_ServerFault : IDispatch
{};

struct __declspec(uuid("3bcf0cb2-a849-375e-8189-1ba5f1f4a9b0"))
_BinaryFormatter : IDispatch
{};

struct __declspec(uuid("0daeaee7-007b-3fca-8755-a5c6c3158955"))
_DynamicILInfo : IDispatch
{};

struct __declspec(uuid("eaaa2670-0fb1-33ea-852b-f1c97fed1797"))
_DynamicMethod : IDispatch
{};

struct __declspec(uuid("1db1cc2a-da73-389e-828b-5c616f4fac49"))
_OpCodes : IDispatch
{};

struct __declspec(uuid("b1a62835-fc19-35a4-b206-a452463d7ee7"))
_GenericTypeParameterBuilder : IDispatch
{};

struct __declspec(uuid("fd302d86-240a-3694-a31f-9ef59e6e41bc"))
_UnmanagedMarshal : IDispatch
{};

struct __declspec(uuid("8978b0be-a89e-3ff9-9834-77862cebff3d"))
_KeySizes : IDispatch
{};

struct __declspec(uuid("4311e8f5-b249-3f81-8ff4-cf853d85306d"))
_CryptographicException : IDispatch
{};

struct __declspec(uuid("7fb08423-038f-3acc-b600-e6d072bae160"))
_CryptographicUnexpectedOperationException : IDispatch
{};

struct __declspec(uuid("7ae4b03c-414a-36e0-ba68-f9603004c925"))
_RandomNumberGenerator : IDispatch
{};

struct __declspec(uuid("2c65d4c0-584c-3e4e-8e6d-1afb112bff69"))
_RNGCryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("09343ac0-d19a-3e62-bc16-0f600f10180a"))
_AsymmetricAlgorithm : IDispatch
{};

struct __declspec(uuid("b6685cca-7a49-37d1-a805-3de829cb8deb"))
_AsymmetricKeyExchangeDeformatter : IDispatch
{};

struct __declspec(uuid("1365b84b-6477-3c40-be6a-089dc01eced9"))
_AsymmetricKeyExchangeFormatter : IDispatch
{};

struct __declspec(uuid("7ca5fe57-d1ac-3064-bb0b-f450be40f194"))
_AsymmetricSignatureDeformatter : IDispatch
{};

struct __declspec(uuid("5363d066-6295-3618-be33-3f0b070b7976"))
_AsymmetricSignatureFormatter : IDispatch
{};

struct __declspec(uuid("23ded1e1-7d5f-3936-aa4e-18bbcc39b155"))
_ToBase64Transform : IDispatch
{};

struct __declspec(uuid("fc0717a6-2e86-372f-81f4-b35ed4bdf0de"))
_FromBase64Transform : IDispatch
{};

struct __declspec(uuid("983b8639-2ed7-364c-9899-682abb2ce850"))
_CryptoAPITransform : IDispatch
{};

struct __declspec(uuid("d5331d95-fff2-358f-afd5-588f469ff2e4"))
_CspParameters : IDispatch
{};

struct __declspec(uuid("ab00f3f8-7dde-3ff5-b805-6c5dbb200549"))
_CryptoConfig : IDispatch
{};

struct __declspec(uuid("4134f762-d0ec-3210-93c0-de4f443d5669"))
_CryptoStream : IDispatch
{};

struct __declspec(uuid("05bc0e38-7136-3825-9e34-26c1cf2142c9"))
_SymmetricAlgorithm : IDispatch
{};

struct __declspec(uuid("c7ef0214-b91c-3799-98dd-c994aabfc741"))
_DES : IDispatch
{};

struct __declspec(uuid("65e8495e-5207-3248-9250-0fc849b4f096"))
_DESCryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("140ee78f-067f-3765-9258-c3bc72fe976b"))
_DeriveBytes : IDispatch
{};

struct __declspec(uuid("0eb5b5e0-1be6-3a5f-87b3-e3323342f44e"))
_DSA : IDispatch
{};

struct __declspec(uuid("1f38aafe-7502-332f-971f-c2fc700a1d55"))
_DSACryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("0e774498-ade6-3820-b1d5-426b06397be7"))
_DSASignatureDeformatter : IDispatch
{};

struct __declspec(uuid("4b5fc561-5983-31e4-903b-1404231b2c89"))
_DSASignatureFormatter : IDispatch
{};

struct __declspec(uuid("69d3baba-1c3d-354c-acfe-f19109ec3896"))
_HashAlgorithm : IDispatch
{};

struct __declspec(uuid("d182cf91-628c-3ff6-87f0-41ba51cc7433"))
_KeyedHashAlgorithm : IDispatch
{};

struct __declspec(uuid("e5456726-33f6-34e4-95c2-db2bfa581462"))
_HMAC : IDispatch
{};

struct __declspec(uuid("486360f5-6213-322b-befb-45221579d4af"))
_HMACMD5 : IDispatch
{};

struct __declspec(uuid("9fd974a5-338c-37b9-a1b2-d45f0c2b25c2"))
_HMACRIPEMD160 : IDispatch
{};

struct __declspec(uuid("63ac7c37-c51a-3d82-8fdd-2a567039e46d"))
_HMACSHA1 : IDispatch
{};

struct __declspec(uuid("1377ce34-8921-3bd4-96e9-c8d5d5aa1adf"))
_HMACSHA256 : IDispatch
{};

struct __declspec(uuid("786f8ac3-93e4-3b6f-9f62-1901b0e5f433"))
_HMACSHA384 : IDispatch
{};

struct __declspec(uuid("eb081b9d-a766-3abe-b720-505c42162d83"))
_HMACSHA512 : IDispatch
{};

struct __declspec(uuid("be8619cb-3731-3cb2-a3a8-cd0bfa5566ec"))
_CspKeyContainerInfo : IDispatch
{};

struct __declspec(uuid("494a7583-190e-3693-9ec4-de54dc6a84a2"))
ICspAsymmetricAlgorithm : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_CspKeyContainerInfo (
        /*[out,retval]*/ struct _CspKeyContainerInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall ExportCspBlob (
        /*[in]*/ VARIANT_BOOL includePrivateParameters,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall ImportCspBlob (
        /*[in]*/ SAFEARRAY * rawData ) = 0;
};

struct __declspec(uuid("1cac0bda-ac58-31bc-b624-63f77d0c3d2f"))
_MACTripleDES : IDispatch
{};

struct __declspec(uuid("9aa8765e-69a0-30e3-9cde-ebc70662ae37"))
_MD5 : IDispatch
{};

struct __declspec(uuid("d3f5c812-5867-33c9-8cee-cb170e8d844a"))
_MD5CryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("85601fee-a79d-3710-af21-099089edc0bf"))
_MaskGenerationMethod : IDispatch
{};

struct __declspec(uuid("3cd62d67-586f-309e-a6d8-1f4baac5ac28"))
_PasswordDeriveBytes : IDispatch
{};

struct __declspec(uuid("425bff0d-59e4-36a8-b1ff-1f5d39d698f4"))
_PKCS1MaskGenerationMethod : IDispatch
{};

struct __declspec(uuid("f7c0c4cc-0d49-31ee-a3d3-b8b551e4928c"))
_RC2 : IDispatch
{};

struct __declspec(uuid("875715c5-cb64-3920-8156-0ee9cb0e07ea"))
_RC2CryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("a6589897-5a67-305f-9497-72e5fe8bead5"))
_Rfc2898DeriveBytes : IDispatch
{};

struct __declspec(uuid("e5481be9-3422-3506-bc35-b96d4535014d"))
_RIPEMD160 : IDispatch
{};

struct __declspec(uuid("814f9c35-b7f8-3ceb-8e43-e01f09157060"))
_RIPEMD160Managed : IDispatch
{};

struct __declspec(uuid("0b3fb710-a25c-3310-8774-1cf117f95bd4"))
_RSA : IDispatch
{};

struct __declspec(uuid("bd9df856-2300-3254-bcf0-679ba03c7a13"))
_RSACryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("37625095-7baa-377d-a0dc-7f465c0167aa"))
_RSAOAEPKeyExchangeDeformatter : IDispatch
{};

struct __declspec(uuid("77a416e7-2ac6-3d0e-98ff-3ba0f586f56f"))
_RSAOAEPKeyExchangeFormatter : IDispatch
{};

struct __declspec(uuid("8034aaf4-3666-3b6f-85cf-463f9bfd31a9"))
_RSAPKCS1KeyExchangeDeformatter : IDispatch
{};

struct __declspec(uuid("9ff67f8e-a7aa-3ba6-90ee-9d44af6e2f8c"))
_RSAPKCS1KeyExchangeFormatter : IDispatch
{};

struct __declspec(uuid("fc38507e-06a4-3300-8652-8d7b54341f65"))
_RSAPKCS1SignatureDeformatter : IDispatch
{};

struct __declspec(uuid("fb7a5ff4-cfa8-3f24-ad5f-d5eb39359707"))
_RSAPKCS1SignatureFormatter : IDispatch
{};

struct __declspec(uuid("21b52a91-856f-373c-ad42-4cf3f1021f5a"))
_Rijndael : IDispatch
{};

struct __declspec(uuid("427ea9d3-11d8-3e38-9e05-a4f7fa684183"))
_RijndaelManaged : IDispatch
{};

struct __declspec(uuid("5767c78f-f344-35a5-84bc-53b9eaeb68cb"))
_RijndaelManagedTransform : IDispatch
{};

struct __declspec(uuid("48600dd2-0099-337f-92d6-961d1e5010d4"))
_SHA1 : IDispatch
{};

struct __declspec(uuid("a16537bc-1edf-3516-b75e-cc65caf873ab"))
_SHA1CryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("c27990bb-3cfd-3d29-8dc0-bbe5fbadeafd"))
_SHA1Managed : IDispatch
{};

struct __declspec(uuid("3b274703-dfae-3f9c-a1b5-9990df9d7fa3"))
_SHA256 : IDispatch
{};

struct __declspec(uuid("3d077954-7bcc-325b-9dda-3b17a03378e0"))
_SHA256Managed : IDispatch
{};

struct __declspec(uuid("b60ad5d7-2c2e-35b7-8d77-7946156cfe8e"))
_SHA384 : IDispatch
{};

struct __declspec(uuid("de541460-f838-3698-b2da-510b09070118"))
_SHA384Managed : IDispatch
{};

struct __declspec(uuid("49dd9e4b-84f3-3d6d-91fb-3fedcef634c7"))
_SHA512 : IDispatch
{};

struct __declspec(uuid("dc8ce439-7954-36ed-803c-674f72f27249"))
_SHA512Managed : IDispatch
{};

struct __declspec(uuid("8017b414-4886-33da-80a3-7865c1350d43"))
_SignatureDescription : IDispatch
{};

struct __declspec(uuid("c040b889-5278-3132-aff9-afa61707a81d"))
_TripleDES : IDispatch
{};

struct __declspec(uuid("ec69d083-3cd0-3c0c-998c-3b738db535d5"))
_TripleDESCryptoServiceProvider : IDispatch
{};

struct __declspec(uuid("68fd6f14-a7b2-36c8-a724-d01f90d73477"))
_X509Certificate : IDispatch
{};

struct __declspec(uuid("9a604ee7-e630-3ded-9444-baae247075ab"))
IFormattable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[in]*/ BSTR format,
        /*[in]*/ struct IFormatProvider * formatProvider,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("805e3b62-b5e9-393d-8941-377d8bf4556b"))
IConvertible : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeCode (
        /*[out,retval]*/ enum TypeCode * pRetVal ) = 0;
      virtual HRESULT __stdcall ToBoolean (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall ToChar (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ unsigned short * pRetVal ) = 0;
      virtual HRESULT __stdcall ToSByte (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ char * pRetVal ) = 0;
      virtual HRESULT __stdcall ToByte (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ unsigned char * pRetVal ) = 0;
      virtual HRESULT __stdcall ToInt16 (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ short * pRetVal ) = 0;
      virtual HRESULT __stdcall ToUInt16 (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ unsigned short * pRetVal ) = 0;
      virtual HRESULT __stdcall ToInt32 (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall ToUInt32 (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ unsigned long * pRetVal ) = 0;
      virtual HRESULT __stdcall ToInt64 (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ __int64 * pRetVal ) = 0;
      virtual HRESULT __stdcall ToUInt64 (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ unsigned __int64 * pRetVal ) = 0;
      virtual HRESULT __stdcall ToSingle (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ float * pRetVal ) = 0;
      virtual HRESULT __stdcall ToDouble (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ double * pRetVal ) = 0;
      virtual HRESULT __stdcall ToDecimal (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ DECIMAL * pRetVal ) = 0;
      virtual HRESULT __stdcall ToDateTime (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ DATE * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall ToType (
        /*[in]*/ struct _Type * conversionType,
        /*[in]*/ struct IFormatProvider * provider,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("b36b5c63-42ef-38bc-a07e-0b34c98f164a"))
_Exception : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Message (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetBaseException (
        /*[out,retval]*/ struct _Exception * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_StackTrace (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_HelpLink (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_HelpLink (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_Source (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Source (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall GetObjectData (
        /*[in]*/ struct _SerializationInfo * info,
        /*[in]*/ struct StreamingContext Context ) = 0;
      virtual HRESULT __stdcall get_InnerException (
        /*[out,retval]*/ struct _Exception * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_TargetSite (
        /*[out,retval]*/ struct _MethodBase * * pRetVal ) = 0;
};

struct __declspec(uuid("3afab213-f5a2-3241-93ba-329ea4ba8016"))
IClientResponseChannelSinkStack : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AsyncProcessResponse (
        /*[in]*/ struct ITransportHeaders * headers,
        /*[in]*/ struct _Stream * Stream ) = 0;
      virtual HRESULT __stdcall DispatchReplyMessage (
        /*[in]*/ struct IMessage * msg ) = 0;
      virtual HRESULT __stdcall DispatchException (
        /*[in]*/ struct _Exception * e ) = 0;
};

struct __declspec(uuid("f617690a-55f4-36af-9149-d199831f8594"))
IMethodReturnMessage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_OutArgCount (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetOutArgName (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetOutArg (
        /*[in]*/ long argNum,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_OutArgs (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Exception (
        /*[out,retval]*/ struct _Exception * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReturnValue (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("05f696dc-2b29-3663-ad8b-c4389cf2a713"))
_AppDomain : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall InitializeLifetimeService (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetLifetimeService (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Evidence (
        /*[out,retval]*/ struct _Evidence * * pRetVal ) = 0;
      virtual HRESULT __stdcall add_DomainUnload (
        /*[in]*/ struct _EventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_DomainUnload (
        /*[in]*/ struct _EventHandler * value ) = 0;
      virtual HRESULT __stdcall add_AssemblyLoad (
        /*[in]*/ struct _AssemblyLoadEventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_AssemblyLoad (
        /*[in]*/ struct _AssemblyLoadEventHandler * value ) = 0;
      virtual HRESULT __stdcall add_ProcessExit (
        /*[in]*/ struct _EventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_ProcessExit (
        /*[in]*/ struct _EventHandler * value ) = 0;
      virtual HRESULT __stdcall add_TypeResolve (
        /*[in]*/ struct _ResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_TypeResolve (
        /*[in]*/ struct _ResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall add_ResourceResolve (
        /*[in]*/ struct _ResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_ResourceResolve (
        /*[in]*/ struct _ResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall add_AssemblyResolve (
        /*[in]*/ struct _ResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_AssemblyResolve (
        /*[in]*/ struct _ResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall add_UnhandledException (
        /*[in]*/ struct _UnhandledExceptionEventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_UnhandledException (
        /*[in]*/ struct _UnhandledExceptionEventHandler * value ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_2 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ BSTR dir,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_3 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ struct _Evidence * Evidence,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_4 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ struct _PermissionSet * requiredPermissions,
        /*[in]*/ struct _PermissionSet * optionalPermissions,
        /*[in]*/ struct _PermissionSet * refusedPermissions,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_5 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ BSTR dir,
        /*[in]*/ struct _Evidence * Evidence,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_6 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ BSTR dir,
        /*[in]*/ struct _PermissionSet * requiredPermissions,
        /*[in]*/ struct _PermissionSet * optionalPermissions,
        /*[in]*/ struct _PermissionSet * refusedPermissions,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_7 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ struct _Evidence * Evidence,
        /*[in]*/ struct _PermissionSet * requiredPermissions,
        /*[in]*/ struct _PermissionSet * optionalPermissions,
        /*[in]*/ struct _PermissionSet * refusedPermissions,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_8 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ BSTR dir,
        /*[in]*/ struct _Evidence * Evidence,
        /*[in]*/ struct _PermissionSet * requiredPermissions,
        /*[in]*/ struct _PermissionSet * optionalPermissions,
        /*[in]*/ struct _PermissionSet * refusedPermissions,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall DefineDynamicAssembly_9 (
        /*[in]*/ struct _AssemblyName * name,
        /*[in]*/ enum AssemblyBuilderAccess access,
        /*[in]*/ BSTR dir,
        /*[in]*/ struct _Evidence * Evidence,
        /*[in]*/ struct _PermissionSet * requiredPermissions,
        /*[in]*/ struct _PermissionSet * optionalPermissions,
        /*[in]*/ struct _PermissionSet * refusedPermissions,
        /*[in]*/ VARIANT_BOOL IsSynchronized,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstance (
        /*[in]*/ BSTR AssemblyName,
        /*[in]*/ BSTR typeName,
        /*[out,retval]*/ struct _ObjectHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstanceFrom (
        /*[in]*/ BSTR assemblyFile,
        /*[in]*/ BSTR typeName,
        /*[out,retval]*/ struct _ObjectHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstance_2 (
        /*[in]*/ BSTR AssemblyName,
        /*[in]*/ BSTR typeName,
        /*[in]*/ SAFEARRAY * activationAttributes,
        /*[out,retval]*/ struct _ObjectHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstanceFrom_2 (
        /*[in]*/ BSTR assemblyFile,
        /*[in]*/ BSTR typeName,
        /*[in]*/ SAFEARRAY * activationAttributes,
        /*[out,retval]*/ struct _ObjectHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstance_3 (
        /*[in]*/ BSTR AssemblyName,
        /*[in]*/ BSTR typeName,
        /*[in]*/ VARIANT_BOOL ignoreCase,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * args,
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ SAFEARRAY * activationAttributes,
        /*[in]*/ struct _Evidence * securityAttributes,
        /*[out,retval]*/ struct _ObjectHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstanceFrom_3 (
        /*[in]*/ BSTR assemblyFile,
        /*[in]*/ BSTR typeName,
        /*[in]*/ VARIANT_BOOL ignoreCase,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * args,
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ SAFEARRAY * activationAttributes,
        /*[in]*/ struct _Evidence * securityAttributes,
        /*[out,retval]*/ struct _ObjectHandle * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load (
        /*[in]*/ struct _AssemblyName * assemblyRef,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load_2 (
        /*[in]*/ BSTR assemblyString,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load_3 (
        /*[in]*/ SAFEARRAY * rawAssembly,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load_4 (
        /*[in]*/ SAFEARRAY * rawAssembly,
        /*[in]*/ SAFEARRAY * rawSymbolStore,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load_5 (
        /*[in]*/ SAFEARRAY * rawAssembly,
        /*[in]*/ SAFEARRAY * rawSymbolStore,
        /*[in]*/ struct _Evidence * securityEvidence,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load_6 (
        /*[in]*/ struct _AssemblyName * assemblyRef,
        /*[in]*/ struct _Evidence * assemblySecurity,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall Load_7 (
        /*[in]*/ BSTR assemblyString,
        /*[in]*/ struct _Evidence * assemblySecurity,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall ExecuteAssembly (
        /*[in]*/ BSTR assemblyFile,
        /*[in]*/ struct _Evidence * assemblySecurity,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall ExecuteAssembly_2 (
        /*[in]*/ BSTR assemblyFile,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall ExecuteAssembly_3 (
        /*[in]*/ BSTR assemblyFile,
        /*[in]*/ struct _Evidence * assemblySecurity,
        /*[in]*/ SAFEARRAY * args,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_FriendlyName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_BaseDirectory (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_RelativeSearchPath (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ShadowCopyFiles (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetAssemblies (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall AppendPrivatePath (
        /*[in]*/ BSTR Path ) = 0;
      virtual HRESULT __stdcall ClearPrivatePath ( ) = 0;
      virtual HRESULT __stdcall SetShadowCopyPath (
        /*[in]*/ BSTR s ) = 0;
      virtual HRESULT __stdcall ClearShadowCopyPath ( ) = 0;
      virtual HRESULT __stdcall SetCachePath (
        /*[in]*/ BSTR s ) = 0;
      virtual HRESULT __stdcall SetData (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT data ) = 0;
      virtual HRESULT __stdcall GetData (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall SetAppDomainPolicy (
        /*[in]*/ struct _PolicyLevel * domainPolicy ) = 0;
      virtual HRESULT __stdcall SetThreadPrincipal (
        /*[in]*/ struct IPrincipal * principal ) = 0;
      virtual HRESULT __stdcall SetPrincipalPolicy (
        /*[in]*/ enum PrincipalPolicy policy ) = 0;
      virtual HRESULT __stdcall DoCallBack (
        /*[in]*/ struct _CrossAppDomainDelegate * theDelegate ) = 0;
      virtual HRESULT __stdcall get_DynamicDirectory (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("2b130940-ca5e-3406-8385-e259e68ab039"))
ICustomFormatter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall format (
        /*[in]*/ BSTR format,
        /*[in]*/ VARIANT arg,
        /*[in]*/ struct IFormatProvider * formatProvider,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("c8cb1ded-2814-396a-9cc0-473ca49779cc"))
IFormatProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetFormat (
        /*[in]*/ struct _Type * formatType,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("b9b91146-d6c2-3a62-8159-c2d1794cdeb0"))
ICustomAttributeProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("f7102fa9-cabb-3a74-a6da-b4567ef1b079"))
_MemberInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("bca8b44d-aad6-3a86-8ab7-03349f4f2da2"))
_Type : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ GUID * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Module (
        /*[out,retval]*/ struct _Module * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Assembly (
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_TypeHandle (
        /*[out,retval]*/ struct RuntimeTypeHandle * pRetVal ) = 0;
      virtual HRESULT __stdcall get_FullName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Namespace (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_AssemblyQualifiedName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetArrayRank (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_BaseType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetConstructors (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInterface (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT_BOOL ignoreCase,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInterfaces (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall FindInterfaces (
        /*[in]*/ struct _TypeFilter * filter,
        /*[in]*/ VARIANT filterCriteria,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetEvent (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _EventInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetEvents (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetEvents_2 (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNestedTypes (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNestedType (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMember (
        /*[in]*/ BSTR name,
        /*[in]*/ enum MemberTypes Type,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetDefaultMembers (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall FindMembers (
        /*[in]*/ enum MemberTypes MemberType,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _MemberFilter * filter,
        /*[in]*/ VARIANT filterCriteria,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetElementType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsSubclassOf (
        /*[in]*/ struct _Type * c,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall IsInstanceOfType (
        /*[in]*/ VARIANT o,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall IsAssignableFrom (
        /*[in]*/ struct _Type * c,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInterfaceMap (
        /*[in]*/ struct _Type * interfaceType,
        /*[out,retval]*/ struct InterfaceMapping * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethods (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetField (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _FieldInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetFields (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ struct _Type * returnType,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperties (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMember_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMembers (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall InvokeMember (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ VARIANT Target,
        /*[in]*/ SAFEARRAY * args,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ SAFEARRAY * namedParameters,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_UnderlyingSystemType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall InvokeMember_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ VARIANT Target,
        /*[in]*/ SAFEARRAY * args,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall InvokeMember_3 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ VARIANT Target,
        /*[in]*/ SAFEARRAY * args,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetConstructor (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ enum CallingConventions callConvention,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _ConstructorInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetConstructor_2 (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _ConstructorInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetConstructor_3 (
        /*[in]*/ SAFEARRAY * types,
        /*[out,retval]*/ struct _ConstructorInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetConstructors_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_TypeInitializer (
        /*[out,retval]*/ struct _ConstructorInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_3 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ enum CallingConventions callConvention,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_4 (
        /*[in]*/ BSTR name,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_5 (
        /*[in]*/ BSTR name,
        /*[in]*/ SAFEARRAY * types,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_6 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethods_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetField_2 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _FieldInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetFields_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInterface_2 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetEvent_2 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _EventInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_3 (
        /*[in]*/ BSTR name,
        /*[in]*/ struct _Type * returnType,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_4 (
        /*[in]*/ BSTR name,
        /*[in]*/ struct _Type * returnType,
        /*[in]*/ SAFEARRAY * types,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_5 (
        /*[in]*/ BSTR name,
        /*[in]*/ SAFEARRAY * types,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_6 (
        /*[in]*/ BSTR name,
        /*[in]*/ struct _Type * returnType,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_7 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperties_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNestedTypes_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNestedType_2 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMember_3 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMembers_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum TypeAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNotPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNestedPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNestedPrivate (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNestedFamily (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNestedAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNestedFamANDAssem (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNestedFamORAssem (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAutoLayout (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsLayoutSequential (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsExplicitLayout (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsClass (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsInterface (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsValueType (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAbstract (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSealed (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsEnum (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsImport (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSerializable (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAnsiClass (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsUnicodeClass (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAutoClass (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsArray (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsByRef (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPointer (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPrimitive (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsCOMObject (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_HasElementType (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsContextful (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsMarshalByRef (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals_2 (
        /*[in]*/ struct _Type * o,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

#pragma pack(push, 4)

struct __declspec(uuid("9dc6ac40-edfa-3e34-9ad1-b7a0a9e3a40a"))
CustomAttributeTypedArgument
{
    IUnknown * m_value;
    struct _Type * m_argumentType;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("7fc47a26-aa2e-32ea-bde4-01a490842d87"))
CustomAttributeNamedArgument
{
    struct _MemberInfo * m_memberInfo;
    struct CustomAttributeTypedArgument m_value;
};

#pragma pack(pop)

#pragma pack(push, 4)

struct __declspec(uuid("5f7a2664-4778-3d72-a78f-d38b6b00180d"))
InterfaceMapping
{
    struct _Type * TargetType;
    struct _Type * interfaceType;
    SAFEARRAY * TargetMethods;
    SAFEARRAY * InterfaceMethods;
};

#pragma pack(pop)

struct __declspec(uuid("f4f5c303-fad3-3d0c-a4df-bb82b5ee308f"))
IFormatterConverter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Convert (
        /*[in]*/ VARIANT value,
        /*[in]*/ struct _Type * Type,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Convert_2 (
        /*[in]*/ VARIANT value,
        /*[in]*/ enum TypeCode TypeCode,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall ToBoolean (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall ToChar (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ unsigned short * pRetVal ) = 0;
      virtual HRESULT __stdcall ToSByte (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ char * pRetVal ) = 0;
      virtual HRESULT __stdcall ToByte (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ unsigned char * pRetVal ) = 0;
      virtual HRESULT __stdcall ToInt16 (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ short * pRetVal ) = 0;
      virtual HRESULT __stdcall ToUInt16 (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ unsigned short * pRetVal ) = 0;
      virtual HRESULT __stdcall ToInt32 (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall ToUInt32 (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ unsigned long * pRetVal ) = 0;
      virtual HRESULT __stdcall ToInt64 (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ __int64 * pRetVal ) = 0;
      virtual HRESULT __stdcall ToUInt64 (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ unsigned __int64 * pRetVal ) = 0;
      virtual HRESULT __stdcall ToSingle (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ float * pRetVal ) = 0;
      virtual HRESULT __stdcall ToDouble (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ double * pRetVal ) = 0;
      virtual HRESULT __stdcall ToDecimal (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ DECIMAL * pRetVal ) = 0;
      virtual HRESULT __stdcall ToDateTime (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ DATE * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[in]*/ VARIANT value,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

#pragma pack(push, 4)

struct __declspec(uuid("3642e7ed-5a69-3a94-98d3-a08877a0d046"))
SerializationEntry
{
    struct _Type * m_type;
    IUnknown * m_value;
    LPSTR m_name;
};

#pragma pack(pop)

struct __declspec(uuid("0ca9008e-ee90-356e-9f6d-b59e6006b9a4"))
ICustomFactory : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CreateInstance (
        /*[in]*/ struct _Type * serverType,
        /*[out,retval]*/ struct _MarshalByRefObject * * pRetVal ) = 0;
};

struct __declspec(uuid("c09effa9-1ffe-3a52-a733-6236cbc45e7b"))
IRemotingTypeInfo : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_typeName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_typeName (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall CanCastTo (
        /*[in]*/ struct _Type * fromType,
        /*[in]*/ VARIANT o,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("65074f7f-63c0-304e-af0a-d51741cb4a8d"))
_Object : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
};

struct __declspec(uuid("ea675b47-64e0-3b5f-9be7-f7dc2990730d"))
_ObjectHandle : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetLifetimeService (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall InitializeLifetimeService (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateObjRef (
        /*[in]*/ struct _Type * requestedType,
        /*[out,retval]*/ struct _ObjRef * * pRetVal ) = 0;
      virtual HRESULT __stdcall Unwrap (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("afbf15e5-c37c-11d2-b88e-00a0c9b471b8"))
IReflect : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetMethod (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethods (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetField (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _FieldInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetFields (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperty_2 (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ struct _Type * returnType,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProperties (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMember (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMembers (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall InvokeMember (
        /*[in]*/ BSTR name,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ VARIANT Target,
        /*[in]*/ SAFEARRAY * args,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ SAFEARRAY * namedParameters,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_UnderlyingSystemType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
};

struct __declspec(uuid("20808adc-cc01-3f3a-8f09-ed12940fc212"))
ISymbolBinder : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetReader (
        /*[in]*/ long importer,
        /*[in]*/ BSTR filename,
        /*[in]*/ BSTR searchPath,
        /*[out,retval]*/ struct ISymbolReader * * pRetVal ) = 0;
};

struct __declspec(uuid("027c036a-4052-3821-85de-b53319df1211"))
ISymbolBinder1 : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetReader (
        /*[in]*/ long importer,
        /*[in]*/ BSTR filename,
        /*[in]*/ BSTR searchPath,
        /*[out,retval]*/ struct ISymbolReader * * pRetVal ) = 0;
};

struct __declspec(uuid("25c72eb0-e437-3f17-946d-3b72a3acff37"))
ISymbolMethod : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Token (
        /*[out,retval]*/ struct SymbolToken * pRetVal ) = 0;
      virtual HRESULT __stdcall get_SequencePointCount (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSequencePoints (
        /*[in]*/ SAFEARRAY * offsets,
        /*[in]*/ SAFEARRAY * documents,
        /*[in]*/ SAFEARRAY * lines,
        /*[in]*/ SAFEARRAY * columns,
        /*[in]*/ SAFEARRAY * endLines,
        /*[in]*/ SAFEARRAY * endColumns ) = 0;
      virtual HRESULT __stdcall get_RootScope (
        /*[out,retval]*/ struct ISymbolScope * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetScope (
        /*[in]*/ long offset,
        /*[out,retval]*/ struct ISymbolScope * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetOffset (
        /*[in]*/ struct ISymbolDocument * document,
        /*[in]*/ long line,
        /*[in]*/ long column,
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetRanges (
        /*[in]*/ struct ISymbolDocument * document,
        /*[in]*/ long line,
        /*[in]*/ long column,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetParameters (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNamespace (
        /*[out,retval]*/ struct ISymbolNamespace * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSourceStartEnd (
        /*[in]*/ SAFEARRAY * docs,
        /*[in]*/ SAFEARRAY * lines,
        /*[in]*/ SAFEARRAY * columns,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("e809a5f1-d3d7-3144-9bef-fe8ac0364699"))
ISymbolReader : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetDocument (
        /*[in]*/ BSTR Url,
        /*[in]*/ GUID Language,
        /*[in]*/ GUID LanguageVendor,
        /*[in]*/ GUID DocumentType,
        /*[out,retval]*/ struct ISymbolDocument * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetDocuments (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_UserEntryPoint (
        /*[out,retval]*/ struct SymbolToken * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod (
        /*[in]*/ struct SymbolToken Method,
        /*[out,retval]*/ struct ISymbolMethod * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethod_2 (
        /*[in]*/ struct SymbolToken Method,
        /*[in]*/ long Version,
        /*[out,retval]*/ struct ISymbolMethod * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetVariables (
        /*[in]*/ struct SymbolToken parent,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetGlobalVariables (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethodFromDocumentPosition (
        /*[in]*/ struct ISymbolDocument * document,
        /*[in]*/ long line,
        /*[in]*/ long column,
        /*[out,retval]*/ struct ISymbolMethod * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSymAttribute (
        /*[in]*/ struct SymbolToken parent,
        /*[in]*/ BSTR name,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNamespaces (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("1cee3a11-01ae-3244-a939-4972fc9703ef"))
ISymbolScope : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Method (
        /*[out,retval]*/ struct ISymbolMethod * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_parent (
        /*[out,retval]*/ struct ISymbolScope * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetChildren (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_StartOffset (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_EndOffset (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetLocals (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNamespaces (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("17156360-2f1a-384a-bc52-fde93c215c5b"))
_Assembly : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CodeBase (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_EscapedCodeBase (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetName (
        /*[out,retval]*/ struct _AssemblyName * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetName_2 (
        /*[in]*/ VARIANT_BOOL copiedName,
        /*[out,retval]*/ struct _AssemblyName * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_FullName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_EntryPoint (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType_2 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType_3 (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT_BOOL throwOnError,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetExportedTypes (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetTypes (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetManifestResourceStream (
        /*[in]*/ struct _Type * Type,
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _Stream * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetManifestResourceStream_2 (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _Stream * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetFile (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _FileStream * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetFiles (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetFiles_2 (
        /*[in]*/ VARIANT_BOOL getResourceModules,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetManifestResourceNames (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetManifestResourceInfo (
        /*[in]*/ BSTR resourceName,
        /*[out,retval]*/ struct _ManifestResourceInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Location (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Evidence (
        /*[out,retval]*/ struct _Evidence * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetObjectData (
        /*[in]*/ struct _SerializationInfo * info,
        /*[in]*/ struct StreamingContext Context ) = 0;
      virtual HRESULT __stdcall add_ModuleResolve (
        /*[in]*/ struct _ModuleResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall remove_ModuleResolve (
        /*[in]*/ struct _ModuleResolveEventHandler * value ) = 0;
      virtual HRESULT __stdcall GetType_4 (
        /*[in]*/ BSTR name,
        /*[in]*/ VARIANT_BOOL throwOnError,
        /*[in]*/ VARIANT_BOOL ignoreCase,
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSatelliteAssembly (
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSatelliteAssembly_2 (
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ struct _Version * Version,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
      virtual HRESULT __stdcall LoadModule (
        /*[in]*/ BSTR moduleName,
        /*[in]*/ SAFEARRAY * rawModule,
        /*[out,retval]*/ struct _Module * * pRetVal ) = 0;
      virtual HRESULT __stdcall LoadModule_2 (
        /*[in]*/ BSTR moduleName,
        /*[in]*/ SAFEARRAY * rawModule,
        /*[in]*/ SAFEARRAY * rawSymbolStore,
        /*[out,retval]*/ struct _Module * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstance (
        /*[in]*/ BSTR typeName,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstance_2 (
        /*[in]*/ BSTR typeName,
        /*[in]*/ VARIANT_BOOL ignoreCase,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateInstance_3 (
        /*[in]*/ BSTR typeName,
        /*[in]*/ VARIANT_BOOL ignoreCase,
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * args,
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ SAFEARRAY * activationAttributes,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetLoadedModules (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetLoadedModules_2 (
        /*[in]*/ VARIANT_BOOL getResourceModules,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetModules (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetModules_2 (
        /*[in]*/ VARIANT_BOOL getResourceModules,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetModule (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _Module * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetReferencedAssemblies (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_GlobalAssemblyCache (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("f1c3bf76-c3e4-11d3-88e7-00902754c43a"))
ITypeLibImporterNotifySink : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall NetReportEvent (
        /*[in]*/ enum ImporterEventKind eventKind,
        /*[in]*/ long eventCode,
        /*[in]*/ BSTR eventMsg ) = 0;
      virtual HRESULT __stdcall ResolveRef (
        /*[in]*/ IUnknown * typeLib,
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
};

struct __declspec(uuid("ccbd682c-73a5-4568-b8b0-c7007e11aba2"))
IRegistrationServices : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall RegisterAssembly (
        /*[in]*/ struct _Assembly * Assembly,
        /*[in]*/ enum AssemblyRegistrationFlags flags,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall UnregisterAssembly (
        /*[in]*/ struct _Assembly * Assembly,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetRegistrableTypesInAssembly (
        /*[in]*/ struct _Assembly * Assembly,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetProgIdForType (
        /*[in]*/ struct _Type * Type,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall RegisterTypeForComClients (
        /*[in]*/ struct _Type * Type,
        /*[in,out]*/ GUID * G ) = 0;
      virtual HRESULT __stdcall GetManagedCategoryGuid (
        /*[out,retval]*/ GUID * pRetVal ) = 0;
      virtual HRESULT __stdcall TypeRequiresRegistration (
        /*[in]*/ struct _Type * Type,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall TypeRepresentsComType (
        /*[in]*/ struct _Type * Type,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("f1c3bf77-c3e4-11d3-88e7-00902754c43a"))
ITypeLibExporterNotifySink : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall NetReportEvent (
        /*[in]*/ enum ExporterEventKind eventKind,
        /*[in]*/ long eventCode,
        /*[in]*/ BSTR eventMsg ) = 0;
      virtual HRESULT __stdcall ResolveRef (
        /*[in]*/ struct _Assembly * Assembly,
        /*[out,retval]*/ IUnknown * * pRetVal ) = 0;
};

struct __declspec(uuid("f1c3bf78-c3e4-11d3-88e7-00902754c43a"))
ITypeLibConverter : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ConvertTypeLibToAssembly (
        /*[in]*/ IUnknown * typeLib,
        /*[in]*/ BSTR asmFileName,
        /*[in]*/ enum TypeLibImporterFlags flags,
        /*[in]*/ struct ITypeLibImporterNotifySink * notifySink,
        /*[in]*/ SAFEARRAY * publicKey,
        /*[in]*/ struct _StrongNameKeyPair * keyPair,
        /*[in]*/ BSTR asmNamespace,
        /*[in]*/ struct _Version * asmVersion,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
      virtual HRESULT __stdcall ConvertAssemblyToTypeLib (
        /*[in]*/ struct _Assembly * Assembly,
        /*[in]*/ BSTR typeLibName,
        /*[in]*/ enum TypeLibExporterFlags flags,
        /*[in]*/ struct ITypeLibExporterNotifySink * notifySink,
        /*[out,retval]*/ IUnknown * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetPrimaryInteropAssembly (
        /*[in]*/ GUID G,
        /*[in]*/ long major,
        /*[in]*/ long minor,
        /*[in]*/ long lcid,
        /*[out]*/ BSTR * asmName,
        /*[out]*/ BSTR * asmCodeBase,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall ConvertTypeLibToAssembly_2 (
        /*[in]*/ IUnknown * typeLib,
        /*[in]*/ BSTR asmFileName,
        /*[in]*/ long flags,
        /*[in]*/ struct ITypeLibImporterNotifySink * notifySink,
        /*[in]*/ SAFEARRAY * publicKey,
        /*[in]*/ struct _StrongNameKeyPair * keyPair,
        /*[in]*/ VARIANT_BOOL unsafeInterfaces,
        /*[out,retval]*/ struct _AssemblyBuilder * * pRetVal ) = 0;
};

struct __declspec(uuid("6240837a-707f-3181-8e98-a36ae086766b"))
_MethodBase : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetParameters (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethodImplementationFlags (
        /*[out,retval]*/ enum MethodImplAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodHandle (
        /*[out,retval]*/ struct RuntimeMethodHandle * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum MethodAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CallingConvention (
        /*[out,retval]*/ enum CallingConventions * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_2 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * parameters,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPrivate (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamily (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyAndAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyOrAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsStatic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFinal (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsVirtual (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsHideBySig (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAbstract (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsConstructor (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_3 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ SAFEARRAY * parameters,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("8e5e0b95-750e-310d-892c-8ca7231cf75b"))
IMethodMessage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Uri (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_typeName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodSignature (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ArgCount (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetArgName (
        /*[in]*/ long index,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetArg (
        /*[in]*/ long argNum,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_args (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_HasVarArgs (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_LogicalCallContext (
        /*[out,retval]*/ struct _LogicalCallContext * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodBase (
        /*[out,retval]*/ struct _MethodBase * * pRetVal ) = 0;
};

struct __declspec(uuid("ffcc1b5d-ecb8-38dd-9b01-3dc8abc2aa5f"))
_MethodInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetParameters (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethodImplementationFlags (
        /*[out,retval]*/ enum MethodImplAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodHandle (
        /*[out,retval]*/ struct RuntimeMethodHandle * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum MethodAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CallingConvention (
        /*[out,retval]*/ enum CallingConventions * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_2 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * parameters,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPrivate (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamily (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyAndAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyOrAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsStatic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFinal (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsVirtual (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsHideBySig (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAbstract (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsConstructor (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_3 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ SAFEARRAY * parameters,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_returnType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReturnTypeCustomAttributes (
        /*[out,retval]*/ struct ICustomAttributeProvider * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetBaseDefinition (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
};

struct __declspec(uuid("fb6ab00f-5096-3af8-a33d-d7885a5fa829"))
_Delegate : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetInvocationList (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall Clone (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetObjectData (
        /*[in]*/ struct _SerializationInfo * info,
        /*[in]*/ struct StreamingContext Context ) = 0;
      virtual HRESULT __stdcall DynamicInvoke (
        /*[in]*/ SAFEARRAY * args,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Method (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Target (
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("9de59c64-d889-35a1-b897-587d74469e5b"))
_EventInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetAddMethod (
        /*[in]*/ VARIANT_BOOL nonPublic,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetRemoveMethod (
        /*[in]*/ VARIANT_BOOL nonPublic,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetRaiseMethod (
        /*[in]*/ VARIANT_BOOL nonPublic,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum EventAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall GetAddMethod_2 (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetRemoveMethod_2 (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetRaiseMethod_2 (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall AddEventHandler (
        /*[in]*/ VARIANT Target,
        /*[in]*/ struct _Delegate * handler ) = 0;
      virtual HRESULT __stdcall RemoveEventHandler (
        /*[in]*/ VARIANT Target,
        /*[in]*/ struct _Delegate * handler ) = 0;
      virtual HRESULT __stdcall get_EventHandlerType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsMulticast (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("e9a19478-9646-3679-9b10-8411ae1fd57d"))
_ConstructorInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetParameters (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetMethodImplementationFlags (
        /*[out,retval]*/ enum MethodImplAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MethodHandle (
        /*[out,retval]*/ struct RuntimeMethodHandle * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum MethodAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CallingConvention (
        /*[out,retval]*/ enum CallingConventions * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_2 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * parameters,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPrivate (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamily (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyAndAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyOrAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsStatic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFinal (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsVirtual (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsHideBySig (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAbstract (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsConstructor (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_3 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ SAFEARRAY * parameters,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_4 (
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * parameters,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Invoke_5 (
        /*[in]*/ SAFEARRAY * parameters,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("8a7c1442-a9fb-366b-80d8-4939ffa6dbe0"))
_FieldInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_FieldType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetValue (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetValueDirect (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall SetValue (
        /*[in]*/ VARIANT obj,
        /*[in]*/ VARIANT value,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ struct _CultureInfo * culture ) = 0;
      virtual HRESULT __stdcall SetValueDirect (
        /*[in]*/ VARIANT obj,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall get_FieldHandle (
        /*[out,retval]*/ struct RuntimeFieldHandle * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum FieldAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall SetValue_2 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall get_IsPublic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPrivate (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamily (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyAndAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsFamilyOrAssembly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsStatic (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsInitOnly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsLiteral (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsNotSerialized (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsPinvokeImpl (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("f59ed4e4-e68f-3218-bd77-061aa82824bf"))
_PropertyInfo : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTypeInfoCount (
        /*[out]*/ unsigned long * pcTInfo ) = 0;
      virtual HRESULT __stdcall GetTypeInfo (
        /*[in]*/ unsigned long iTInfo,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long ppTInfo ) = 0;
      virtual HRESULT __stdcall GetIDsOfNames (
        /*[in]*/ GUID * riid,
        /*[in]*/ long rgszNames,
        /*[in]*/ unsigned long cNames,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ long rgDispId ) = 0;
      virtual HRESULT __stdcall Invoke (
        /*[in]*/ unsigned long dispIdMember,
        /*[in]*/ GUID * riid,
        /*[in]*/ unsigned long lcid,
        /*[in]*/ short wFlags,
        /*[in]*/ long pDispParams,
        /*[in]*/ long pVarResult,
        /*[in]*/ long pExcepInfo,
        /*[in]*/ long puArgErr ) = 0;
      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT other,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_MemberType (
        /*[out,retval]*/ enum MemberTypes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_DeclaringType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReflectedType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetCustomAttributes_2 (
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall IsDefined (
        /*[in]*/ struct _Type * attributeType,
        /*[in]*/ VARIANT_BOOL inherit,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_PropertyType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetValue (
        /*[in]*/ VARIANT obj,
        /*[in]*/ SAFEARRAY * index,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall GetValue_2 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * index,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall SetValue (
        /*[in]*/ VARIANT obj,
        /*[in]*/ VARIANT value,
        /*[in]*/ SAFEARRAY * index ) = 0;
      virtual HRESULT __stdcall SetValue_2 (
        /*[in]*/ VARIANT obj,
        /*[in]*/ VARIANT value,
        /*[in]*/ enum BindingFlags invokeAttr,
        /*[in]*/ struct _Binder * Binder,
        /*[in]*/ SAFEARRAY * index,
        /*[in]*/ struct _CultureInfo * culture ) = 0;
      virtual HRESULT __stdcall GetAccessors (
        /*[in]*/ VARIANT_BOOL nonPublic,
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetGetMethod (
        /*[in]*/ VARIANT_BOOL nonPublic,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSetMethod (
        /*[in]*/ VARIANT_BOOL nonPublic,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetIndexParameters (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ enum PropertyAttributes * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CanRead (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CanWrite (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetAccessors_2 (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetGetMethod_2 (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetSetMethod_2 (
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsSpecialName (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("afbf15e6-c37c-11d2-b88e-00a0c9b471b8"))
IExpando : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddField (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _FieldInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall AddProperty (
        /*[in]*/ BSTR name,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall AddMethod (
        /*[in]*/ BSTR name,
        /*[in]*/ struct _Delegate * Method,
        /*[out,retval]*/ struct _MethodInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall RemoveMember (
        /*[in]*/ struct _MemberInfo * m ) = 0;
};

struct __declspec(uuid("3169ab11-7109-3808-9a61-ef4ba0534fd9"))
_Binder : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ToString (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall Equals (
        /*[in]*/ VARIANT obj,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetHashCode (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall GetType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall BindToMethod (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ SAFEARRAY * match,
        /*[in,out]*/ SAFEARRAY * * args,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[in]*/ struct _CultureInfo * culture,
        /*[in]*/ SAFEARRAY * names,
        /*[out]*/ VARIANT * state,
        /*[out,retval]*/ struct _MethodBase * * pRetVal ) = 0;
      virtual HRESULT __stdcall BindToField (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ SAFEARRAY * match,
        /*[in]*/ VARIANT value,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ struct _FieldInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall SelectMethod (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ SAFEARRAY * match,
        /*[in]*/ SAFEARRAY * types,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _MethodBase * * pRetVal ) = 0;
      virtual HRESULT __stdcall SelectProperty (
        /*[in]*/ enum BindingFlags bindingAttr,
        /*[in]*/ SAFEARRAY * match,
        /*[in]*/ struct _Type * returnType,
        /*[in]*/ SAFEARRAY * indexes,
        /*[in]*/ SAFEARRAY * modifiers,
        /*[out,retval]*/ struct _PropertyInfo * * pRetVal ) = 0;
      virtual HRESULT __stdcall ChangeType (
        /*[in]*/ VARIANT value,
        /*[in]*/ struct _Type * Type,
        /*[in]*/ struct _CultureInfo * culture,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall ReorderArgumentArray (
        /*[in,out]*/ SAFEARRAY * * args,
        /*[in]*/ VARIANT state ) = 0;
};

struct __declspec(uuid("93d7a8c5-d2eb-319b-a374-a65d321f2aa9"))
IFormatter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Deserialize (
        /*[in]*/ struct _Stream * serializationStream,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Serialize (
        /*[in]*/ struct _Stream * serializationStream,
        /*[in]*/ VARIANT graph ) = 0;
      virtual HRESULT __stdcall get_SurrogateSelector (
        /*[out,retval]*/ struct ISurrogateSelector * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_SurrogateSelector (
        /*[in]*/ struct ISurrogateSelector * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Binder (
        /*[out,retval]*/ struct _SerializationBinder * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Binder (
        /*[in]*/ struct _SerializationBinder * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Context (
        /*[out,retval]*/ struct StreamingContext * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Context (
        /*[in]*/ struct StreamingContext pRetVal ) = 0;
};

struct __declspec(uuid("62339172-dbfa-337b-8ac8-053b241e06ab"))
ISerializationSurrogate : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetObjectData (
        /*[in]*/ VARIANT obj,
        /*[in]*/ struct _SerializationInfo * info,
        /*[in]*/ struct StreamingContext Context ) = 0;
      virtual HRESULT __stdcall SetObjectData (
        /*[in]*/ VARIANT obj,
        /*[in]*/ struct _SerializationInfo * info,
        /*[in]*/ struct StreamingContext Context,
        /*[in]*/ struct ISurrogateSelector * selector,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("7c66ff18-a1a5-3e19-857b-0e7b6a9e3f38"))
ISurrogateSelector : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ChainSelector (
        /*[in]*/ struct ISurrogateSelector * selector ) = 0;
      virtual HRESULT __stdcall GetSurrogate (
        /*[in]*/ struct _Type * Type,
        /*[in]*/ struct StreamingContext Context,
        /*[out]*/ struct ISurrogateSelector * * selector,
        /*[out,retval]*/ struct ISerializationSurrogate * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetNextSelector (
        /*[out,retval]*/ struct ISurrogateSelector * * pRetVal ) = 0;
};

struct __declspec(uuid("4a68baa3-27aa-314a-bdbb-6ae9bdfc0420"))
IContextAttribute : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall IsContextOK (
        /*[in]*/ struct _Context * ctx,
        /*[in]*/ struct IConstructionCallMessage * msg,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetPropertiesForNewContext (
        /*[in]*/ struct IConstructionCallMessage * msg ) = 0;
};

struct __declspec(uuid("c02bbb79-5aa8-390d-927f-717b7bff06a1"))
IActivator : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_NextActivator (
        /*[out,retval]*/ struct IActivator * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_NextActivator (
        /*[in]*/ struct IActivator * pRetVal ) = 0;
      virtual HRESULT __stdcall Activate (
        /*[in]*/ struct IConstructionCallMessage * msg,
        /*[out,retval]*/ struct IConstructionReturnMessage * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_level (
        /*[out,retval]*/ enum ActivatorLevel * pRetVal ) = 0;
};

struct __declspec(uuid("fa28e3af-7d09-31d5-beeb-7f2626497cde"))
IConstructionCallMessage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Activator (
        /*[out,retval]*/ struct IActivator * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Activator (
        /*[in]*/ struct IActivator * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CallSiteActivationAttributes (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ActivationTypeName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ActivationType (
        /*[out,retval]*/ struct _Type * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ContextProperties (
        /*[out,retval]*/ struct IList * * pRetVal ) = 0;
};

struct __declspec(uuid("7197b56b-5fa1-31ef-b38b-62fee737277f"))
IContextPropertyActivator : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall IsOKToActivate (
        /*[in]*/ struct IConstructionCallMessage * msg,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall CollectFromClientContext (
        /*[in]*/ struct IConstructionCallMessage * msg ) = 0;
      virtual HRESULT __stdcall DeliverClientContextToServerContext (
        /*[in]*/ struct IConstructionCallMessage * msg,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall CollectFromServerContext (
        /*[in]*/ struct IConstructionReturnMessage * msg ) = 0;
      virtual HRESULT __stdcall DeliverServerContextToClientContext (
        /*[in]*/ struct IConstructionReturnMessage * msg,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
};

struct __declspec(uuid("3a5fde6b-db46-34e8-bacd-16ea5a440540"))
IClientChannelSinkStack : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Push (
        /*[in]*/ struct IClientChannelSink * sink,
        /*[in]*/ VARIANT state ) = 0;
      virtual HRESULT __stdcall Pop (
        /*[in]*/ struct IClientChannelSink * sink,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
};

struct __declspec(uuid("ff726320-6b92-3e6c-aaac-f97063d0b142"))
IClientChannelSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ProcessMessage (
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * requestHeaders,
        /*[in]*/ struct _Stream * requestStream,
        /*[out]*/ struct ITransportHeaders * * responseHeaders,
        /*[out]*/ struct _Stream * * responseStream ) = 0;
      virtual HRESULT __stdcall AsyncProcessRequest (
        /*[in]*/ struct IClientChannelSinkStack * sinkStack,
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[in]*/ struct _Stream * Stream ) = 0;
      virtual HRESULT __stdcall AsyncProcessResponse (
        /*[in]*/ struct IClientResponseChannelSinkStack * sinkStack,
        /*[in]*/ VARIANT state,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[in]*/ struct _Stream * Stream ) = 0;
      virtual HRESULT __stdcall GetRequestStream (
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[out,retval]*/ struct _Stream * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_NextChannelSink (
        /*[out,retval]*/ struct IClientChannelSink * * pRetVal ) = 0;
};

struct __declspec(uuid("3f8742c2-ac57-3440-a283-fe5ff4c75025"))
IClientChannelSinkProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CreateSink (
        /*[in]*/ struct IChannelSender * channel,
        /*[in]*/ BSTR Url,
        /*[in]*/ VARIANT remoteChannelData,
        /*[out,retval]*/ struct IClientChannelSink * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Next (
        /*[out,retval]*/ struct IClientChannelSinkProvider * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Next (
        /*[in]*/ struct IClientChannelSinkProvider * pRetVal ) = 0;
};

struct __declspec(uuid("e694a733-768d-314d-b317-dcead136b11d"))
IServerChannelSinkStack : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Push (
        /*[in]*/ struct IServerChannelSink * sink,
        /*[in]*/ VARIANT state ) = 0;
      virtual HRESULT __stdcall Pop (
        /*[in]*/ struct IServerChannelSink * sink,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall Store (
        /*[in]*/ struct IServerChannelSink * sink,
        /*[in]*/ VARIANT state ) = 0;
      virtual HRESULT __stdcall StoreAndDispatch (
        /*[in]*/ struct IServerChannelSink * sink,
        /*[in]*/ VARIANT state ) = 0;
      virtual HRESULT __stdcall ServerCallback (
        /*[in]*/ struct IAsyncResult * ar ) = 0;
};

struct __declspec(uuid("21b5f37b-bef3-354c-8f84-0f9f0863f5c5"))
IServerChannelSink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ProcessMessage (
        /*[in]*/ struct IServerChannelSinkStack * sinkStack,
        /*[in]*/ struct IMessage * requestMsg,
        /*[in]*/ struct ITransportHeaders * requestHeaders,
        /*[in]*/ struct _Stream * requestStream,
        /*[out]*/ struct IMessage * * responseMsg,
        /*[out]*/ struct ITransportHeaders * * responseHeaders,
        /*[out]*/ struct _Stream * * responseStream,
        /*[out,retval]*/ enum ServerProcessing * pRetVal ) = 0;
      virtual HRESULT __stdcall AsyncProcessResponse (
        /*[in]*/ struct IServerResponseChannelSinkStack * sinkStack,
        /*[in]*/ VARIANT state,
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[in]*/ struct _Stream * Stream ) = 0;
      virtual HRESULT __stdcall GetResponseStream (
        /*[in]*/ struct IServerResponseChannelSinkStack * sinkStack,
        /*[in]*/ VARIANT state,
        /*[in]*/ struct IMessage * msg,
        /*[in]*/ struct ITransportHeaders * headers,
        /*[out,retval]*/ struct _Stream * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_NextChannelSink (
        /*[out,retval]*/ struct IServerChannelSink * * pRetVal ) = 0;
};

struct __declspec(uuid("7dd6e975-24ea-323c-a98c-0fde96f9c4e6"))
IServerChannelSinkProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetChannelData (
        /*[in]*/ struct IChannelDataStore * ChannelData ) = 0;
      virtual HRESULT __stdcall CreateSink (
        /*[in]*/ struct IChannelReceiver * channel,
        /*[out,retval]*/ struct IServerChannelSink * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Next (
        /*[out,retval]*/ struct IServerChannelSinkProvider * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Next (
        /*[in]*/ struct IServerChannelSinkProvider * pRetVal ) = 0;
};

struct __declspec(uuid("3a02d3f7-3f40-3022-853d-cfda765182fe"))
IChannelReceiverHook : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ChannelScheme (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_WantsToListen (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_ChannelSinkChain (
        /*[out,retval]*/ struct IServerChannelSink * * pRetVal ) = 0;
      virtual HRESULT __stdcall AddHookChannelUri (
        /*[in]*/ BSTR channelUri ) = 0;
};

struct __declspec(uuid("675591af-0508-3131-a7cc-287d265ca7d6"))
ISponsor : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Renewal (
        /*[in]*/ struct ILease * lease,
        /*[out,retval]*/ struct TimeSpan * pRetVal ) = 0;
};

struct __declspec(uuid("53a561f2-cbbf-3748-bffe-2180002db3df"))
ILease : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Register (
        /*[in]*/ struct ISponsor * obj,
        /*[in]*/ struct TimeSpan renewalTime ) = 0;
      virtual HRESULT __stdcall Register_2 (
        /*[in]*/ struct ISponsor * obj ) = 0;
      virtual HRESULT __stdcall Unregister (
        /*[in]*/ struct ISponsor * obj ) = 0;
      virtual HRESULT __stdcall Renew (
        /*[in]*/ struct TimeSpan renewalTime,
        /*[out,retval]*/ struct TimeSpan * pRetVal ) = 0;
      virtual HRESULT __stdcall get_RenewOnCallTime (
        /*[out,retval]*/ struct TimeSpan * pRetVal ) = 0;
      virtual HRESULT __stdcall put_RenewOnCallTime (
        /*[in]*/ struct TimeSpan pRetVal ) = 0;
      virtual HRESULT __stdcall get_SponsorshipTimeout (
        /*[out,retval]*/ struct TimeSpan * pRetVal ) = 0;
      virtual HRESULT __stdcall put_SponsorshipTimeout (
        /*[in]*/ struct TimeSpan pRetVal ) = 0;
      virtual HRESULT __stdcall get_InitialLeaseTime (
        /*[out,retval]*/ struct TimeSpan * pRetVal ) = 0;
      virtual HRESULT __stdcall put_InitialLeaseTime (
        /*[in]*/ struct TimeSpan pRetVal ) = 0;
      virtual HRESULT __stdcall get_CurrentLeaseTime (
        /*[out,retval]*/ struct TimeSpan * pRetVal ) = 0;
      virtual HRESULT __stdcall get_CurrentState (
        /*[out,retval]*/ enum LeaseState * pRetVal ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_mscorlib =
    {0xbed7f4ea,0x1a96,0x11d2,{0x8f,0x08,0x00,0xa0,0xc9,0xa6,0x18,0x6d}};
extern "C" const GUID __declspec(selectany) CLSID_Object =
    {0x81c5fe01,0x027c,0x3e1c,{0x98,0xd5,0xda,0x9c,0x98,0x62,0xaa,0x21}};
extern "C" const GUID __declspec(selectany) IID_ICloneable =
    {0x0cb251a7,0x3ab3,0x3b5c,{0xa0,0xb8,0x9d,0xdf,0x88,0x82,0x4b,0x85}};
extern "C" const GUID __declspec(selectany) IID_IEnumerable =
    {0x496b0abe,0xcdee,0x11d3,{0x88,0xe8,0x00,0x90,0x27,0x54,0xc4,0x3a}};
extern "C" const GUID __declspec(selectany) IID_IList =
    {0x7bcfa00f,0xf764,0x3113,{0x91,0x40,0x3b,0xbd,0x12,0x7a,0x96,0xbb}};
extern "C" const GUID __declspec(selectany) CLSID_Array =
    {0x200fb91c,0x815d,0x39e0,{0x9e,0x07,0x0e,0x1b,0xdb,0x2e,0xd4,0x7b}};
extern "C" const GUID __declspec(selectany) CLSID_ValueType =
    {0xce8ad32f,0xb6db,0x31ea,{0x9f,0x1e,0xc2,0x42,0x4e,0x0f,0x5e,0xee}};
extern "C" const GUID __declspec(selectany) IID_IEnumerator =
    {0x496b0abf,0xcdee,0x11d3,{0x88,0xe8,0x00,0x90,0x27,0x54,0xc4,0x3a}};
extern "C" const GUID __declspec(selectany) IID_IDisposable =
    {0x805d7a98,0xd4af,0x3f0f,{0x96,0x7f,0xe5,0xcf,0x45,0x31,0x2d,0x2c}};
extern "C" const GUID __declspec(selectany) IID_IComparable =
    {0xdeb0e770,0x91fd,0x3cf6,{0x9a,0x6c,0xe6,0xa3,0x65,0x6f,0x39,0x65}};
extern "C" const GUID __declspec(selectany) CLSID_Enum =
    {0xc43345b9,0x7fed,0x3fc7,{0x8f,0xc2,0x7b,0x1b,0x82,0xbc,0x10,0x9e}};
extern "C" const GUID __declspec(selectany) CLSID_String =
    {0x296afbff,0x1b0b,0x3ff5,{0x9d,0x6c,0x4e,0x7e,0x59,0x9f,0x8b,0x57}};
extern "C" const GUID __declspec(selectany) IID_IComparer =
    {0xc20fd3eb,0x7022,0x3d14,{0x84,0x77,0x76,0x0f,0xab,0x54,0xe5,0x0d}};
extern "C" const GUID __declspec(selectany) IID_IEqualityComparer =
    {0xaab7c6ea,0xcab0,0x3adb,{0x82,0xaa,0xcf,0x32,0xe2,0x9a,0xf2,0x38}};
extern "C" const GUID __declspec(selectany) CLSID_StringComparer =
    {0x8ea98c90,0x180d,0x39ae,{0xaa,0x70,0x2a,0xa3,0xd5,0xeb,0xb7,0xae}};
extern "C" const GUID __declspec(selectany) CLSID_StringBuilder =
    {0xe724b749,0x18d6,0x36ab,{0x9f,0x6d,0x09,0xc3,0x6d,0x9c,0x60,0x16}};
extern "C" const GUID __declspec(selectany) CLSID_Exception =
    {0xa1c0a095,0xdf97,0x3441,{0xbf,0xc1,0xc9,0xf1,0x94,0xe4,0x94,0xdb}};
extern "C" const GUID __declspec(selectany) CLSID_SystemException =
    {0x4224ac84,0x9b11,0x3561,{0x89,0x23,0xc8,0x93,0xca,0x77,0xac,0xbe}};
extern "C" const GUID __declspec(selectany) CLSID_OutOfMemoryException =
    {0xccf306ae,0x33bd,0x3003,{0x9c,0xce,0xda,0xf5,0xbe,0xfe,0xf6,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_StackOverflowException =
    {0x9c125a6f,0xeae2,0x3fc1,{0x97,0xa1,0xc0,0xdc,0xea,0xb0,0xb5,0xdf}};
extern "C" const GUID __declspec(selectany) CLSID_DataMisalignedException =
    {0xaad4bdd3,0x81aa,0x3abc,{0xb5,0x3b,0xd9,0x04,0xd2,0x5b,0xc0,0x1e}};
extern "C" const GUID __declspec(selectany) CLSID_ExecutionEngineException =
    {0xe786fb32,0xb659,0x3d96,{0x94,0xc4,0xe1,0xa9,0xfc,0x03,0x78,0x68}};
extern "C" const GUID __declspec(selectany) CLSID_Delegate =
    {0x03ce85f6,0x37cb,0x3588,{0xb3,0xdb,0xd5,0x62,0x8b,0xb1,0x33,0x5b}};
extern "C" const GUID __declspec(selectany) CLSID_MulticastDelegate =
    {0x198ffbde,0xa6db,0x3cc3,{0xab,0x15,0xfb,0xbb,0x72,0x50,0xd6,0x24}};
extern "C" const GUID __declspec(selectany) CLSID_MemberAccessException =
    {0x0ff66430,0xc796,0x3ee7,{0x90,0x2b,0x16,0x6c,0x40,0x2c,0xa2,0x88}};
extern "C" const GUID __declspec(selectany) IID__Activator =
    {0x03973551,0x57a1,0x3900,{0xa2,0xb5,0x90,0x83,0xe3,0xff,0x29,0x43}};
extern "C" const GUID __declspec(selectany) CLSID_Activator =
    {0x9ba4fd4e,0x2bc2,0x31a0,{0xb7,0x21,0xd1,0x7a,0xba,0x5b,0x12,0xc3}};
extern "C" const GUID __declspec(selectany) CLSID_AccessViolationException =
    {0x4c3ebfd5,0xfc72,0x33dc,{0xbc,0x37,0x99,0x53,0xeb,0x25,0xb8,0xd7}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationActivator =
    {0x1d09b407,0xa97f,0x378a,{0xac,0xcb,0x82,0xca,0x00,0x82,0xf9,0xf3}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationException =
    {0x682d63b8,0x1692,0x31be,{0x88,0xcd,0x5c,0xb1,0xf7,0x9e,0xdb,0x7b}};
extern "C" const GUID __declspec(selectany) CLSID_EventArgs =
    {0x3fb717af,0x9d21,0x3016,{0x87,0x1a,0xdf,0x81,0x7a,0xbd,0xdd,0x51}};
extern "C" const GUID __declspec(selectany) CLSID_ResolveEventArgs =
    {0x1c1d34a9,0x3f45,0x3b51,{0xa9,0xaf,0x03,0x54,0x97,0x5b,0xf8,0xcc}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyLoadEventArgs =
    {0x81548590,0x3849,0x32a8,{0xaa,0x6f,0xf2,0xb3,0x13,0x7c,0xf4,0xa3}};
extern "C" const GUID __declspec(selectany) CLSID_ResolveEventHandler =
    {0xa4b8c851,0x941a,0x3dee,{0xbd,0x08,0xd9,0xe2,0xee,0xd1,0x01,0xc5}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyLoadEventHandler =
    {0x2e130dc8,0x564e,0x397f,{0xa6,0x28,0x39,0x77,0x09,0xda,0x52,0xe9}};
extern "C" const GUID __declspec(selectany) CLSID_AppDomainInitializer =
    {0xfa525b27,0x3d69,0x3116,{0x8d,0x15,0x00,0x64,0xf6,0x29,0x95,0x48}};
extern "C" const GUID __declspec(selectany) CLSID_MarshalByRefObject =
    {0x14b542c6,0x1c5a,0x3869,{0xb8,0xf8,0xfe,0xef,0xd7,0xb2,0x9d,0x09}};
extern "C" const GUID __declspec(selectany) CLSID_AppDomain =
    {0x5fe0a145,0xa82b,0x3d96,{0x94,0xe3,0xfd,0x21,0x4c,0x9d,0x6e,0xb9}};
extern "C" const GUID __declspec(selectany) CLSID_CrossAppDomainDelegate =
    {0x496219c1,0x3fb7,0x3dcf,{0x8a,0xf7,0xd5,0x60,0x32,0xf7,0x89,0x1f}};
extern "C" const GUID __declspec(selectany) CLSID_AppDomainManager =
    {0xc03880a5,0x0b5e,0x39ad,{0x95,0x4a,0xce,0x0d,0xcb,0xd5,0xef,0x7d}};
extern "C" const GUID __declspec(selectany) IID_IAppDomainSetup =
    {0x27fff232,0xa7a8,0x40dd,{0x8d,0x4a,0x73,0x4a,0xd5,0x9f,0xcd,0x41}};
extern "C" const GUID __declspec(selectany) CLSID_AppDomainSetup =
    {0x3e8e0f03,0xd3fd,0x3a93,{0xba,0xe0,0xc7,0x4a,0x64,0x94,0xdb,0xca}};
extern "C" const GUID __declspec(selectany) IID__Attribute =
    {0x917b14d0,0x2d9e,0x38b8,{0x92,0xa9,0x38,0x1a,0xcf,0x52,0xf7,0xc0}};
extern "C" const GUID __declspec(selectany) CLSID_Attribute =
    {0x1765714b,0xe628,0x34c3,{0xb6,0x6f,0x76,0x86,0xfa,0xf4,0x62,0xda}};
extern "C" const GUID __declspec(selectany) CLSID_LoaderOptimizationAttribute =
    {0xb39742fd,0x1a55,0x3810,{0x9e,0xa5,0xf6,0xe8,0x6e,0xbe,0xb4,0x72}};
extern "C" const GUID __declspec(selectany) CLSID_AppDomainUnloadedException =
    {0x61b3e12b,0x3586,0x3a58,{0xa4,0x97,0x7e,0xd7,0xc4,0xc7,0x94,0xb9}};
extern "C" const GUID __declspec(selectany) CLSID_ActivationArguments =
    {0xd12b05f9,0x0654,0x351a,{0x92,0xd1,0x8f,0xda,0xc1,0xf2,0x43,0xde}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationId =
    {0xaf3866ad,0xf70a,0x3cf8,{0x98,0x4e,0x85,0x8c,0x5a,0x68,0x6d,0x57}};
extern "C" const GUID __declspec(selectany) CLSID_ArgumentException =
    {0x3fdceec6,0xb14b,0x37e2,{0xbb,0x69,0xab,0xc7,0xca,0x0d,0xa2,0x2f}};
extern "C" const GUID __declspec(selectany) CLSID_ArgumentNullException =
    {0x3bd1f243,0x9bc4,0x305d,{0x9b,0x1c,0x0d,0x10,0xc8,0x03,0x29,0xfc}};
extern "C" const GUID __declspec(selectany) CLSID_ArgumentOutOfRangeException =
    {0x74bdd0b9,0x38d7,0x3fda,{0xa6,0x7e,0xd4,0x04,0xee,0x68,0x4f,0x24}};
extern "C" const GUID __declspec(selectany) CLSID_ArithmeticException =
    {0x647053c3,0x1879,0x34d7,{0xae,0x57,0x67,0x01,0x5c,0x91,0xfc,0x70}};
extern "C" const GUID __declspec(selectany) CLSID_ArrayTypeMismatchException =
    {0x676e1164,0x752c,0x3a74,{0x8d,0x3f,0xbc,0xd3,0x2a,0x20,0x26,0xd6}};
extern "C" const GUID __declspec(selectany) CLSID_AsyncCallback =
    {0xb2a87ddb,0x5dab,0x395f,{0xb7,0xbe,0xad,0x83,0x05,0x8f,0xb5,0x16}};
extern "C" const GUID __declspec(selectany) CLSID_AttributeUsageAttribute =
    {0x53a62bb1,0x75b9,0x3b52,{0xae,0x98,0x92,0xaf,0xd5,0x73,0xcd,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_BadImageFormatException =
    {0xe9148312,0xa9bf,0x3a45,{0xbb,0xca,0x35,0x09,0x67,0xfd,0x78,0xf5}};
extern "C" const GUID __declspec(selectany) CLSID_Buffer =
    {0x830fe109,0x4566,0x3af2,{0x9b,0x57,0x56,0x02,0x72,0x4f,0xca,0xce}};
extern "C" const GUID __declspec(selectany) CLSID_CannotUnloadAppDomainException =
    {0x29c69707,0x875f,0x3678,{0x8f,0x01,0x28,0x30,0x94,0xa2,0xdf,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_CharEnumerator =
    {0x277eabd6,0xf03a,0x3c52,{0x8b,0x42,0xb8,0xe3,0x26,0xd9,0xc0,0xcc}};
extern "C" const GUID __declspec(selectany) CLSID_CLSCompliantAttribute =
    {0x15dbec24,0x0e2d,0x3db2,{0xaf,0x66,0x93,0x22,0x03,0x21,0x58,0x95}};
extern "C" const GUID __declspec(selectany) CLSID_TypeUnloadedException =
    {0xd6d2034d,0x5f67,0x30d7,{0x9c,0xc5,0x45,0x2f,0x2c,0x46,0x69,0x4f}};
extern "C" const GUID __declspec(selectany) IID__Thread =
    {0xc281c7f1,0x4aa9,0x3517,{0x96,0x1a,0x46,0x3c,0xfe,0xd5,0x7e,0x75}};
extern "C" const GUID __declspec(selectany) CLSID_CriticalFinalizerObject =
    {0x314bda5a,0x9292,0x3fc0,{0x83,0x0d,0x7a,0x4b,0x02,0x61,0xfc,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_ContextMarshalException =
    {0xcbeaa915,0x4d2c,0x3f77,{0x98,0xe8,0xa2,0x58,0xb0,0xfd,0x3c,0xef}};
extern "C" const GUID __declspec(selectany) CLSID_ContextBoundObject =
    {0x7916cbef,0x050e,0x3e39,{0xb8,0x3a,0x5a,0xb9,0x55,0x8e,0x72,0xf1}};
extern "C" const GUID __declspec(selectany) CLSID_ContextStaticAttribute =
    {0x96705ee3,0xf7ab,0x3e9a,{0x9f,0xb2,0xad,0x1d,0x53,0x6e,0x90,0x1a}};
extern "C" const GUID __declspec(selectany) CLSID_TimeZone =
    {0x543c0dd8,0xa713,0x3777,{0xb0,0x1a,0xae,0xb8,0x01,0xda,0xc0,0x01}};
extern "C" const GUID __declspec(selectany) CLSID_DBNull =
    {0x8c1a4524,0x3ceb,0x3436,{0xb4,0x49,0xca,0xc4,0x56,0xec,0xab,0x09}};
extern "C" const GUID __declspec(selectany) CLSID_Binder =
    {0x74a6b90c,0x8710,0x32da,{0xbb,0xf7,0x9d,0x44,0x45,0xe0,0x71,0xe9}};
extern "C" const GUID __declspec(selectany) CLSID_DivideByZeroException =
    {0xf6914a11,0xd95d,0x324f,{0xba,0x0f,0x39,0xa3,0x74,0x62,0x52,0x90}};
extern "C" const GUID __declspec(selectany) CLSID_DuplicateWaitObjectException =
    {0xcc20c6df,0xa054,0x3f09,{0xa5,0xf5,0xa3,0xb5,0xa2,0x5f,0x4c,0xe6}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLoadException =
    {0x112bc2e7,0x9ef9,0x3648,{0xaf,0x9e,0x45,0xc0,0xd4,0xb8,0x99,0x29}};
extern "C" const GUID __declspec(selectany) CLSID_EntryPointNotFoundException =
    {0xad326409,0xbf80,0x3e0c,{0xba,0x6f,0xee,0x2c,0x33,0xb6,0x75,0xa5}};
extern "C" const GUID __declspec(selectany) CLSID_DllNotFoundException =
    {0x46e97093,0xb2ec,0x3787,{0xa9,0xa5,0x47,0x0d,0x1a,0x27,0x41,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_Environment =
    {0xdf81b4ff,0x7226,0x30fa,{0x84,0xdf,0x80,0x79,0x5b,0xa1,0xa6,0x42}};
extern "C" const GUID __declspec(selectany) CLSID_EventHandler =
    {0xdca836de,0xc23d,0x334c,{0x86,0xb7,0x83,0x85,0xbe,0x47,0x03,0x0d}};
extern "C" const GUID __declspec(selectany) CLSID_FieldAccessException =
    {0xbda7bee5,0x85f1,0x3b66,{0xb6,0x10,0xdd,0xf1,0xd5,0x89,0x80,0x06}};
extern "C" const GUID __declspec(selectany) CLSID_FlagsAttribute =
    {0x66ce75d4,0x0334,0x3ca6,{0xbc,0xa8,0xce,0x9a,0xf2,0x8a,0x43,0x96}};
extern "C" const GUID __declspec(selectany) CLSID_FormatException =
    {0x964aa3bd,0x4b12,0x3e23,{0x9d,0x7f,0x99,0x34,0x2a,0xfa,0xe8,0x12}};
extern "C" const GUID __declspec(selectany) CLSID_IndexOutOfRangeException =
    {0x5ca9971b,0x2dc3,0x3bc8,{0x84,0x7a,0x5e,0x6d,0x15,0xcb,0xb1,0x6e}};
extern "C" const GUID __declspec(selectany) CLSID_InvalidCastException =
    {0x7f6bcbe5,0xeb30,0x370b,{0x9f,0x1b,0x92,0xa6,0x26,0x5a,0xfe,0xdd}};
extern "C" const GUID __declspec(selectany) CLSID_InvalidOperationException =
    {0x9546306b,0x1b68,0x33af,{0x80,0xdb,0x3a,0x92,0x06,0x50,0x15,0x15}};
extern "C" const GUID __declspec(selectany) CLSID_InvalidProgramException =
    {0x91591469,0xefef,0x3d63,{0x90,0xf9,0x88,0x52,0x0f,0x0a,0xa1,0xef}};
extern "C" const GUID __declspec(selectany) CLSID_LocalDataStoreSlot =
    {0xe95e800a,0xcba4,0x3613,{0x82,0x1d,0x6d,0x6e,0xf3,0xbc,0xbf,0x6b}};
extern "C" const GUID __declspec(selectany) CLSID_MethodAccessException =
    {0x92e76a74,0x2622,0x3aa9,{0xa3,0xca,0x1a,0xe8,0xbd,0x7b,0xc4,0xa8}};
extern "C" const GUID __declspec(selectany) CLSID_MissingMemberException =
    {0xcdc70043,0xd56b,0x3799,{0xb7,0xbd,0x61,0x13,0xbb,0xca,0x16,0x0a}};
extern "C" const GUID __declspec(selectany) CLSID_MissingFieldException =
    {0x8d36569b,0x14d6,0x3c3d,{0xb5,0x5c,0x9d,0x02,0xa4,0x5b,0xfc,0x3d}};
extern "C" const GUID __declspec(selectany) CLSID_MissingMethodException =
    {0x58897d76,0xef6c,0x327a,{0x93,0xf7,0x6c,0xd6,0x6c,0x42,0x4e,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_MulticastNotSupportedException =
    {0x9da2f8b8,0x59f0,0x3852,{0xb5,0x09,0x06,0x63,0xe3,0xbf,0x64,0x3b}};
extern "C" const GUID __declspec(selectany) CLSID_NonSerializedAttribute =
    {0xcc77f5f3,0x222d,0x3586,{0x88,0xc3,0x41,0x04,0x77,0xa3,0xb6,0x5d}};
extern "C" const GUID __declspec(selectany) CLSID_NotFiniteNumberException =
    {0x7e34ab89,0x0684,0x3b86,{0x8a,0x0f,0xe6,0x38,0xeb,0x4e,0x62,0x52}};
extern "C" const GUID __declspec(selectany) CLSID_NotImplementedException =
    {0xf8be2ad5,0x4e99,0x3e00,{0xb1,0x0e,0x7c,0x54,0xd3,0x1c,0x1c,0x1d}};
extern "C" const GUID __declspec(selectany) CLSID_NotSupportedException =
    {0xdafb2462,0x2a5b,0x3818,{0xb1,0x7e,0x60,0x29,0x84,0xfe,0x1b,0xb0}};
extern "C" const GUID __declspec(selectany) CLSID_NullReferenceException =
    {0x7f71db2d,0x1ea0,0x3cae,{0x80,0x87,0x26,0x09,0x5f,0x52,0x15,0xe6}};
extern "C" const GUID __declspec(selectany) CLSID_ObjectDisposedException =
    {0xf17baaf6,0xd35c,0x3c6e,{0xac,0xd3,0xd0,0xd4,0x9a,0x50,0x22,0xc4}};
extern "C" const GUID __declspec(selectany) CLSID_ObsoleteAttribute =
    {0x08295c62,0x7462,0x3633,{0xb3,0x5e,0x7a,0xe6,0x8a,0xca,0x39,0x48}};
extern "C" const GUID __declspec(selectany) CLSID_OperatingSystem =
    {0xd7ca3b25,0xa57b,0x354c,{0x87,0x58,0x9f,0xe3,0xa9,0x05,0xc1,0xac}};
extern "C" const GUID __declspec(selectany) CLSID_OperationCanceledException =
    {0x11581718,0x2434,0x32e3,{0xb5,0x59,0xe8,0x6c,0xe9,0x92,0x37,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_OverflowException =
    {0x4286fa72,0xa2fa,0x3245,{0x87,0x51,0xd4,0x20,0x60,0x70,0xa1,0x91}};
extern "C" const GUID __declspec(selectany) CLSID_ParamArrayAttribute =
    {0x3495e5fa,0x2a90,0x3ca7,{0xb3,0xb5,0x58,0x73,0x6c,0x44,0x41,0xdd}};
extern "C" const GUID __declspec(selectany) CLSID_PlatformNotSupportedException =
    {0xa36738b5,0xfa8f,0x3316,{0xa9,0x29,0x68,0x09,0x9a,0x32,0xb4,0x3b}};
extern "C" const GUID __declspec(selectany) CLSID_Random =
    {0x4e77ec8f,0x51d8,0x386c,{0x85,0xfe,0x7d,0xc9,0x31,0xb7,0xa8,0xe7}};
extern "C" const GUID __declspec(selectany) CLSID_RankException =
    {0xc9f61cbd,0x287f,0x3d24,{0x9f,0xeb,0x2c,0x3f,0x34,0x7c,0xf5,0x70}};
extern "C" const GUID __declspec(selectany) CLSID_MemberInfo =
    {0x5ae028b5,0x9a3a,0x32a9,{0x89,0x9c,0x1d,0xee,0xfb,0x85,0xcc,0x50}};
extern "C" const GUID __declspec(selectany) CLSID_Type =
    {0x6c9863dc,0x7207,0x327f,{0xa0,0x48,0xc3,0xbb,0x63,0x47,0x4b,0xfc}};
extern "C" const GUID __declspec(selectany) CLSID_SerializableAttribute =
    {0x89bcc804,0x53a5,0x3eb2,{0xa3,0x42,0x62,0x82,0xcc,0x41,0x02,0x60}};
extern "C" const GUID __declspec(selectany) CLSID_TimeoutException =
    {0xeaa78d4a,0x20a3,0x3fde,{0xab,0x72,0xd3,0xd5,0x5e,0x3a,0xef,0xe6}};
extern "C" const GUID __declspec(selectany) CLSID_TypeInitializationException =
    {0x811fb5f2,0x9bfe,0x3557,{0x83,0xde,0x12,0x79,0xf0,0xb3,0xeb,0x55}};
extern "C" const GUID __declspec(selectany) CLSID_UnauthorizedAccessException =
    {0x75215200,0xa2fe,0x30f6,{0xa3,0x4b,0x8f,0x1a,0x18,0x30,0x35,0x8e}};
extern "C" const GUID __declspec(selectany) CLSID_UnhandledExceptionEventArgs =
    {0xb55dae2e,0xc8e8,0x3c48,{0xb4,0x04,0xd9,0x91,0x97,0x9a,0x9d,0x9d}};
extern "C" const GUID __declspec(selectany) CLSID_UnhandledExceptionEventHandler =
    {0xdb4d2d94,0x3fa3,0x36f5,{0xb2,0x2e,0xa0,0x0f,0xf2,0x2f,0x08,0xbd}};
extern "C" const GUID __declspec(selectany) CLSID_Version =
    {0x43cd41ad,0x3b78,0x3531,{0x90,0x31,0x30,0x59,0xe0,0xaa,0x64,0xeb}};
extern "C" const GUID __declspec(selectany) CLSID_WeakReference =
    {0xd3f54e92,0xa0c7,0x3bf4,{0xa1,0x14,0xf1,0xf3,0x84,0xce,0x3e,0xff}};
extern "C" const GUID __declspec(selectany) CLSID_WaitHandle =
    {0x4d0e564a,0x78c8,0x31e0,{0xba,0x03,0x73,0xaf,0x7b,0xdf,0xf5,0xa9}};
extern "C" const GUID __declspec(selectany) CLSID_EventWaitHandle =
    {0x80226212,0x1832,0x310f,{0x86,0x2c,0xa5,0x11,0xe3,0x53,0x4e,0x62}};
extern "C" const GUID __declspec(selectany) CLSID_AutoResetEvent =
    {0xe35af4dd,0xeb37,0x39fc,{0x90,0x71,0x4c,0xe3,0x9b,0x1a,0x54,0xbe}};
extern "C" const GUID __declspec(selectany) CLSID_ContextCallback =
    {0x5b193863,0xa73e,0x3ec3,{0x80,0xd0,0x35,0xb3,0x6e,0x3c,0xf4,0xed}};
//extern "C" const GUID __declspec(selectany) IID_IObjectHandle =
//    {0xc460e2b4,0xe199,0x412a,{0x84,0x56,0x84,0xdc,0x3e,0x48,0x38,0xc3}};
extern "C" const GUID __declspec(selectany) CLSID_ManualResetEvent =
    {0x17a355c3,0xc65e,0x3f26,{0x8a,0x80,0x23,0x68,0x90,0xeb,0xc9,0x97}};
extern "C" const GUID __declspec(selectany) CLSID_Monitor =
    {0x9e97213a,0x0b49,0x3c05,{0xa0,0xbf,0xd2,0x03,0xc4,0xfc,0x84,0x87}};
extern "C" const GUID __declspec(selectany) CLSID_Mutex =
    {0xd74d613d,0xf27f,0x311b,{0xa9,0xa3,0x27,0xeb,0xc6,0x3a,0x1a,0x5d}};
extern "C" const GUID __declspec(selectany) CLSID_Overlapped =
    {0x7fe87a55,0x1321,0x3d9f,{0x8f,0xef,0xcd,0x2f,0x5e,0x8a,0xb2,0xe9}};
extern "C" const GUID __declspec(selectany) CLSID_ReaderWriterLock =
    {0x9173d971,0xb142,0x38a5,{0x84,0x88,0xd1,0x0a,0x9d,0xcf,0x71,0xb0}};
extern "C" const GUID __declspec(selectany) CLSID_SynchronizationLockException =
    {0x48a75519,0xcb7a,0x3d18,{0xb9,0x1e,0xbe,0x62,0xee,0x84,0x2a,0x3e}};
extern "C" const GUID __declspec(selectany) CLSID_Thread =
    {0xa5889aad,0x36a6,0x3b3e,{0x89,0xf9,0x11,0x8c,0xe3,0xa7,0x7d,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_ThreadAbortException =
    {0xea1cf67d,0x7904,0x36a3,{0xbd,0x5b,0xdd,0x02,0x89,0x85,0x86,0x1c}};
extern "C" const GUID __declspec(selectany) CLSID_ThreadInterruptedException =
    {0x27e986e1,0xbaec,0x3d48,{0x82,0xe4,0x14,0x16,0x9c,0xa8,0xce,0xcf}};
extern "C" const GUID __declspec(selectany) CLSID_RegisteredWaitHandle =
    {0x50f8ae2b,0x69f0,0x37ef,{0x95,0x4b,0xd2,0x61,0x8e,0x3e,0x82,0x67}};
extern "C" const GUID __declspec(selectany) CLSID_WaitCallback =
    {0xd8e04cc2,0xf4f5,0x367d,{0xa2,0x3f,0xf7,0x1a,0xff,0x4f,0x14,0xf3}};
extern "C" const GUID __declspec(selectany) CLSID_WaitOrTimerCallback =
    {0x3c8c9f02,0x2c23,0x39ff,{0xac,0x7b,0xcd,0x0e,0xe1,0xd1,0x4a,0x79}};
extern "C" const GUID __declspec(selectany) CLSID_IOCompletionCallback =
    {0x8a937e3b,0x9c07,0x3d4d,{0xb5,0x0a,0x4f,0x4f,0x3c,0x85,0x31,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_ThreadStart =
    {0xe7ac1e4d,0x35db,0x3432,{0xa0,0x32,0xe9,0x4c,0x01,0x2b,0x2d,0x39}};
extern "C" const GUID __declspec(selectany) CLSID_ThreadStateException =
    {0x3e5509f0,0x1fb9,0x304d,{0x81,0x74,0x75,0xd6,0xc9,0xaf,0xe5,0xda}};
extern "C" const GUID __declspec(selectany) CLSID_ThreadStaticAttribute =
    {0xffc9f9ae,0xe87a,0x3252,{0x8e,0x25,0xb2,0x24,0x23,0xa4,0x00,0x65}};
extern "C" const GUID __declspec(selectany) CLSID_Timeout =
    {0x5a49b766,0xb474,0x3501,{0x90,0x1e,0x5b,0xda,0xc8,0xb4,0x8a,0x3d}};
extern "C" const GUID __declspec(selectany) CLSID_TimerCallback =
    {0xddf7ba7f,0x4b7c,0x378d,{0xa1,0x53,0x62,0x85,0xb8,0x4c,0x65,0x93}};
extern "C" const GUID __declspec(selectany) CLSID_Timer =
    {0x490ca7a8,0xd03f,0x3459,{0x82,0x08,0xd4,0x28,0xea,0x01,0x0d,0xa0}};
extern "C" const GUID __declspec(selectany) CLSID_STAThreadAttribute =
    {0x50aad4c2,0x61fa,0x3b1f,{0x81,0x57,0x5b,0xa3,0xb2,0x7a,0xee,0x61}};
extern "C" const GUID __declspec(selectany) CLSID_MTAThreadAttribute =
    {0xb406ac70,0x4d7e,0x3d24,{0xb2,0x41,0xae,0xae,0xac,0x34,0x3b,0xd9}};
extern "C" const GUID __declspec(selectany) CLSID_ArrayList =
    {0x6896b49d,0x7afb,0x34dc,{0x93,0x4e,0x5a,0xdd,0x38,0xee,0xee,0x39}};
extern "C" const GUID __declspec(selectany) CLSID_BitArray =
    {0x5d2fb755,0xc658,0x3f51,{0x86,0xf2,0x88,0x1f,0x4a,0x1a,0x2a,0x55}};
extern "C" const GUID __declspec(selectany) CLSID_CaseInsensitiveComparer =
    {0x35e946e4,0x7cda,0x3824,{0x8b,0x24,0xd7,0x99,0xa9,0x63,0x09,0xad}};
extern "C" const GUID __declspec(selectany) IID_IHashCodeProvider =
    {0x5d573036,0x3435,0x3c5a,{0xae,0xff,0x2b,0x81,0x91,0x08,0x2c,0x71}};
extern "C" const GUID __declspec(selectany) CLSID_CaseInsensitiveHashCodeProvider =
    {0x47d3c68d,0x7d85,0x3227,{0xa9,0xe7,0x88,0x45,0x1d,0x6b,0xad,0xfc}};
extern "C" const GUID __declspec(selectany) CLSID_CollectionBase =
    {0x87259279,0x9f5d,0x3c0a,{0xbb,0x58,0x72,0x3a,0x2a,0x6e,0x4d,0xba}};
extern "C" const GUID __declspec(selectany) CLSID_Comparer =
    {0x8a63140f,0x7eb8,0x3f4e,{0xba,0x59,0x19,0xb8,0xc7,0x47,0x84,0x3f}};
extern "C" const GUID __declspec(selectany) CLSID_DictionaryBase =
    {0x9840c5c3,0x21d3,0x3b8a,{0x94,0xc1,0x3f,0xc5,0x42,0xb0,0x22,0x7e}};
extern "C" const GUID __declspec(selectany) IID_IDictionaryEnumerator =
    {0x35d574bf,0x7a4f,0x3588,{0x8c,0x19,0x12,0x21,0x2a,0x0f,0xe4,0xdc}};
extern "C" const GUID __declspec(selectany) IID_IDeserializationCallback =
    {0xab3f47e4,0xc227,0x3b05,{0xbf,0x9f,0x94,0x64,0x9b,0xef,0x98,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_Hashtable =
    {0x146855fa,0x309f,0x3d0e,{0xbb,0x3e,0xdf,0x52,0x5f,0x30,0xa7,0x15}};
extern "C" const GUID __declspec(selectany) CLSID_Queue =
    {0x7f976b72,0x4b71,0x3858,{0xbe,0xe8,0x8e,0x3a,0x31,0x89,0xa6,0x51}};
extern "C" const GUID __declspec(selectany) CLSID_ReadOnlyCollectionBase =
    {0xb66406bd,0x746d,0x3d10,{0x98,0xa1,0x41,0xd0,0x97,0xcf,0x42,0xb7}};
extern "C" const GUID __declspec(selectany) CLSID_SortedList =
    {0x026cc6d7,0x34b2,0x33d5,{0xb5,0x51,0xca,0x31,0xeb,0x6c,0xe3,0x45}};
extern "C" const GUID __declspec(selectany) CLSID_Stack =
    {0x4599202d,0x460f,0x3fb7,{0x8a,0x1c,0xc2,0xcc,0x6e,0xd6,0xc7,0xc8}};
extern "C" const GUID __declspec(selectany) CLSID_Nullable =
    {0xf358ac62,0x4569,0x3705,{0xbe,0x32,0xb0,0x7e,0x79,0x9b,0x42,0x23}};
extern "C" const GUID __declspec(selectany) CLSID_KeyNotFoundException =
    {0x0d52abe3,0x3c93,0x3d94,{0xa7,0x44,0xac,0x44,0x85,0x0b,0xac,0xcd}};
extern "C" const GUID __declspec(selectany) CLSID_ConditionalAttribute =
    {0x75b3810e,0xf2d5,0x36e2,{0x8d,0x27,0x51,0x4e,0xbc,0xad,0x45,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_Debugger =
    {0x91f672a3,0x6b82,0x3e04,{0xb2,0xd7,0xba,0xc5,0xd6,0x67,0x66,0x09}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerStepThroughAttribute =
    {0x93f551d6,0x2f9e,0x301b,{0xbe,0x63,0x85,0xae,0xf5,0x08,0xca,0xe0}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerStepperBoundaryAttribute =
    {0x1b979846,0xaaeb,0x314b,{0x8e,0x63,0xd4,0x4e,0xf1,0xcb,0x9e,0xfc}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerHiddenAttribute =
    {0x41970d73,0x92f6,0x36d9,{0x87,0x4d,0x3b,0xd0,0x76,0x2a,0x0d,0x6f}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerNonUserCodeAttribute =
    {0x29625281,0x51ce,0x3f8a,{0xac,0x4d,0xe3,0x60,0xca,0xcb,0x92,0xe2}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggableAttribute =
    {0xdf1f67b4,0x74f7,0x30af,{0x92,0x2d,0x29,0xf0,0xb9,0x1a,0xbc,0x25}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerBrowsableAttribute =
    {0xa709ebbe,0xbdb2,0x30f4,{0x95,0x9b,0x37,0xb7,0xa6,0x8e,0x42,0x99}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerTypeProxyAttribute =
    {0x8366ee18,0xbbe6,0x3061,{0xb9,0x9f,0xba,0x87,0xe2,0x69,0x19,0xd1}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerDisplayAttribute =
    {0xf640e47b,0x67d0,0x31a2,{0x86,0x21,0x02,0xe2,0xdd,0x41,0xb4,0x96}};
extern "C" const GUID __declspec(selectany) CLSID_DebuggerVisualizerAttribute =
    {0x29813e13,0x8772,0x3b1f,{0x87,0x8d,0x26,0xc3,0x3b,0x04,0x5d,0x5a}};
extern "C" const GUID __declspec(selectany) CLSID_StackTrace =
    {0x405c2d81,0x315b,0x3cb0,{0x84,0x42,0xef,0x5a,0x38,0xd4,0xc3,0xb8}};
extern "C" const GUID __declspec(selectany) CLSID_StackFrame =
    {0x14910622,0x09d4,0x3b4a,{0x8c,0x1e,0x99,0x91,0xdb,0xdc,0xc5,0x53}};
extern "C" const GUID __declspec(selectany) IID_ISymbolDocument =
    {0x1c32f012,0x2684,0x3efe,{0x8d,0x50,0x9c,0x29,0x73,0xac,0xc0,0x0b}};
extern "C" const GUID __declspec(selectany) IID_ISymbolDocumentWriter =
    {0xfa682f24,0x3a3c,0x390d,{0xb8,0xa2,0x96,0xf1,0x10,0x6f,0x4b,0x37}};
extern "C" const GUID __declspec(selectany) IID_ISymbolNamespace =
    {0x23ed2454,0x6899,0x3c28,{0xba,0xb7,0x6e,0xc8,0x66,0x83,0x96,0x4a}};
extern "C" const GUID __declspec(selectany) IID_ISymbolVariable =
    {0x4042bd4d,0xb5ab,0x30e8,{0x91,0x9b,0x14,0x91,0x06,0x87,0xba,0xae}};
extern "C" const GUID __declspec(selectany) CLSID_SymDocumentType =
    {0x40ae2088,0xce00,0x33ad,{0x93,0x20,0x5d,0x20,0x1c,0xb4,0x6f,0xc9}};
extern "C" const GUID __declspec(selectany) CLSID_SymLanguageType =
    {0x5a18d43e,0x115b,0x3b8b,{0x82,0x45,0x9a,0x06,0xb2,0x04,0xb7,0x17}};
extern "C" const GUID __declspec(selectany) CLSID_SymLanguageVendor =
    {0xdfd888a7,0xa6b0,0x3b1b,{0x98,0x5e,0x4c,0xda,0xb0,0xe4,0xc1,0x7d}};
extern "C" const GUID __declspec(selectany) CLSID_AmbiguousMatchException =
    {0x2846ae5e,0xa9fa,0x36cf,{0xb2,0xd1,0x6e,0x95,0x59,0x6d,0xbd,0xe7}};
extern "C" const GUID __declspec(selectany) CLSID_ModuleResolveEventHandler =
    {0xaaaa10c6,0x9902,0x3dbb,{0xb1,0x73,0xeb,0xa1,0xeb,0xa2,0xcd,0x5e}};
extern "C" const GUID __declspec(selectany) CLSID_Assembly =
    {0x28e89a9f,0xe67d,0x3028,{0xaa,0x1b,0xe5,0xeb,0xcd,0xe6,0xf3,0xc8}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyCopyrightAttribute =
    {0x8687959f,0xd86d,0x3217,{0x8d,0x58,0xbe,0x9a,0x04,0x27,0xbb,0x84}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyTrademarkAttribute =
    {0xe64c95df,0xeadc,0x3d08,{0x9c,0x6f,0x80,0xf2,0x9d,0x92,0xcb,0x4e}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyProductAttribute =
    {0xcfe2bcf1,0x683c,0x39b5,{0x83,0xce,0x4b,0x18,0x6a,0x52,0x15,0x13}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyCompanyAttribute =
    {0x62342fb2,0x16bf,0x30a9,{0x88,0xad,0x6b,0xc7,0x81,0xee,0xc9,0x4f}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyDescriptionAttribute =
    {0x432e5e9f,0x03ba,0x37b2,{0x8e,0xdf,0x7f,0xac,0x14,0xb0,0x3b,0x4f}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyTitleAttribute =
    {0x51b4f67c,0x2fcb,0x391d,{0xa3,0x81,0xd0,0x40,0x10,0x0d,0x67,0x17}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyConfigurationAttribute =
    {0x09dd9840,0x5e39,0x317a,{0xaa,0xb3,0x0a,0x46,0x79,0x98,0xde,0x25}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyDefaultAliasAttribute =
    {0x8beb1256,0x5d9b,0x3262,{0xbf,0x85,0xbe,0xb6,0x28,0x7e,0x4e,0xea}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyInformationalVersionAttribute =
    {0x894593b9,0x99e5,0x3b61,{0xa5,0x92,0xee,0x44,0xb9,0x39,0x62,0x77}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyFileVersionAttribute =
    {0x14152cb5,0xdc51,0x3c42,{0x8a,0x43,0x09,0x85,0x4d,0xea,0x1b,0x8f}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyCultureAttribute =
    {0x4265ab21,0xa68f,0x38a9,{0x98,0xd8,0x5d,0x62,0xb8,0x03,0x5e,0xa0}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyVersionAttribute =
    {0x2d0fa06f,0x88fd,0x3643,{0x8d,0xbc,0x1f,0x42,0x8a,0x2b,0x1a,0x3b}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyKeyFileAttribute =
    {0xff408450,0x1db9,0x3203,{0x84,0xec,0xb7,0x0a,0x01,0xf4,0x8a,0x06}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyDelaySignAttribute =
    {0x4804184f,0x4741,0x396b,{0xaf,0x5b,0x71,0x13,0x49,0x37,0xf2,0x1a}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyAlgorithmIdAttribute =
    {0x0d052b0a,0x23d1,0x3bac,{0x85,0xee,0x4e,0x76,0x4b,0x81,0x4c,0xee}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyFlagsAttribute =
    {0x4554ed74,0x4243,0x3e7c,{0x9b,0x33,0xe9,0xa8,0x93,0x79,0xc4,0xf1}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyKeyNameAttribute =
    {0x3dace301,0x6c51,0x3bf7,{0xb9,0x75,0xe4,0xa0,0x5f,0x00,0xfd,0x4d}};
extern "C" const GUID __declspec(selectany) IID__AssemblyName =
    {0xb42b6aac,0x317e,0x34d5,{0x9f,0xa9,0x09,0x3b,0xb4,0x16,0x0c,0x50}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyName =
    {0xf12fde6a,0x9394,0x3c32,{0x8e,0x4d,0xf3,0xd4,0x70,0x94,0x72,0x84}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyNameProxy =
    {0x3f4a4283,0x6a08,0x3e90,{0xa9,0x76,0x2c,0x2d,0x3b,0xe4,0xeb,0x0b}};
extern "C" const GUID __declspec(selectany) CLSID_CustomAttributeFormatException =
    {0xd5cb383d,0x99f4,0x3c7e,{0xa9,0xc3,0x85,0xb5,0x36,0x61,0x44,0x8f}};
extern "C" const GUID __declspec(selectany) IID__ParameterInfo =
    {0x993634c4,0xe47a,0x32cc,{0xbe,0x08,0x85,0xf5,0x67,0xdc,0x27,0xd6}};
extern "C" const GUID __declspec(selectany) IID__Module =
    {0xd002e9ba,0xd9e3,0x3749,{0xb1,0xd3,0xd5,0x65,0xa0,0x8b,0x13,0xe7}};
extern "C" const GUID __declspec(selectany) CLSID_CustomAttributeData =
    {0xc2655ae8,0x0193,0x35d4,{0x85,0x5e,0xf6,0x49,0x09,0x06,0x5c,0x1e}};
extern "C" const GUID __declspec(selectany) CLSID_DefaultMemberAttribute =
    {0xcf452b26,0x6040,0x3acb,{0x9c,0x72,0xce,0x5b,0xb8,0x6e,0x50,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_InvalidFilterCriteriaException =
    {0x7b938a6f,0x77bf,0x351c,{0xa7,0x12,0x69,0x48,0x3c,0x91,0x11,0x5d}};
extern "C" const GUID __declspec(selectany) CLSID_ManifestResourceInfo =
    {0xf695c021,0xdcf5,0x397b,{0xa3,0x00,0xed,0xaa,0x51,0xda,0x5a,0x5b}};
extern "C" const GUID __declspec(selectany) CLSID_MemberFilter =
    {0xf52fd74c,0xada6,0x38cc,{0xae,0x0f,0x69,0x3a,0xfb,0x9b,0x9a,0x8f}};
extern "C" const GUID __declspec(selectany) CLSID_Missing =
    {0xd5faac26,0xdb25,0x34e7,{0xad,0xbd,0xad,0x5e,0xd5,0x1f,0x94,0x33}};
extern "C" const GUID __declspec(selectany) CLSID_Module =
    {0x128191c5,0xb188,0x3054,{0x81,0xb7,0xe4,0xf5,0x88,0xea,0xcf,0x0e}};
extern "C" const GUID __declspec(selectany) CLSID_ObfuscateAssemblyAttribute =
    {0xd495920d,0x00a0,0x3d6f,{0x92,0x0c,0x67,0x2d,0xf1,0x86,0xce,0xc8}};
extern "C" const GUID __declspec(selectany) CLSID_ObfuscationAttribute =
    {0x93d11de9,0x5f6c,0x354a,{0xa7,0xc5,0x16,0xcc,0xca,0x64,0xa9,0xb8}};
extern "C" const GUID __declspec(selectany) CLSID_ExceptionHandlingClause =
    {0x17ca8e14,0xf624,0x3879,{0x94,0xca,0x6b,0x95,0x56,0xa9,0x7d,0x1f}};
extern "C" const GUID __declspec(selectany) CLSID_MethodBody =
    {0x8e2ea778,0x34a7,0x32a0,{0x8c,0xc2,0x0b,0xaa,0x5a,0xa2,0x06,0x6a}};
extern "C" const GUID __declspec(selectany) CLSID_LocalVariableInfo =
    {0x14c0b634,0xa0e7,0x3e5d,{0xbe,0x59,0xb2,0xbf,0x1a,0x57,0x1f,0xfc}};
extern "C" const GUID __declspec(selectany) IID_ISymbolWriter =
    {0xda295a1b,0xc5bd,0x3b34,{0x8a,0xcd,0x1d,0x7d,0x33,0x4f,0xfb,0x7f}};
extern "C" const GUID __declspec(selectany) CLSID_Pointer =
    {0x0517463e,0x1139,0x3970,{0xbf,0xa9,0xdc,0xc9,0x97,0xb2,0x3e,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_ReflectionTypeLoadException =
    {0x843b19ad,0xa02b,0x3852,{0xac,0x56,0xfd,0xc7,0x98,0x93,0x56,0x30}};
extern "C" const GUID __declspec(selectany) CLSID_StrongNameKeyPair =
    {0xd633f013,0x0563,0x312a,{0xb9,0xd6,0xd0,0x67,0xa7,0xd5,0x92,0x31}};
extern "C" const GUID __declspec(selectany) CLSID_TargetException =
    {0x0d23f8b4,0xf2a6,0x3eff,{0x9d,0x37,0xbd,0xf7,0x9a,0xc6,0xb4,0x40}};
extern "C" const GUID __declspec(selectany) CLSID_TargetInvocationException =
    {0x03d016e3,0xcae1,0x3068,{0x88,0x0e,0xaf,0x8d,0x08,0xd5,0x17,0xf0}};
extern "C" const GUID __declspec(selectany) CLSID_TargetParameterCountException =
    {0xda317be2,0x1a0d,0x37b3,{0x83,0xf2,0xa0,0xf3,0x27,0x87,0xfc,0x67}};
extern "C" const GUID __declspec(selectany) CLSID_TypeDelegator =
    {0x19e2e2f7,0xb53c,0x366b,{0x88,0x40,0xab,0xa2,0xf8,0xcb,0x98,0xb5}};
extern "C" const GUID __declspec(selectany) CLSID_TypeFilter =
    {0x37e24f25,0x5ef0,0x366f,{0x9d,0x0f,0xf7,0xb9,0xe3,0xed,0xff,0xd9}};
extern "C" const GUID __declspec(selectany) CLSID_MethodBase =
    {0xca308c9f,0x3b97,0x3152,{0xac,0xfa,0x8a,0xb2,0x3c,0x17,0xdf,0x73}};
extern "C" const GUID __declspec(selectany) CLSID_ConstructorInfo =
    {0x0a541f87,0xebd7,0x36a0,{0x9a,0x7d,0x9b,0xbf,0x86,0x18,0x87,0x66}};
extern "C" const GUID __declspec(selectany) CLSID_MethodInfo =
    {0x0e22cc27,0xca1e,0x3138,{0x96,0x40,0xbe,0x83,0x1f,0x72,0x16,0x59}};
extern "C" const GUID __declspec(selectany) CLSID_FieldInfo =
    {0x98ba57dc,0x4cf2,0x3ed1,{0xb4,0xa2,0x89,0x0c,0x21,0xbb,0xbf,0x4b}};
extern "C" const GUID __declspec(selectany) CLSID_EventInfo =
    {0x15762ca5,0xbc5c,0x3b86,{0xa4,0x50,0xac,0xf3,0x2f,0xc9,0x8a,0xa5}};
extern "C" const GUID __declspec(selectany) CLSID_PropertyInfo =
    {0xbfdf1f57,0x230d,0x394a,{0xb7,0x73,0xd9,0xec,0x58,0xcb,0xef,0x9a}};
extern "C" const GUID __declspec(selectany) CLSID_ParameterInfo =
    {0xe5ce8078,0x0ca7,0x3578,{0x80,0xdb,0xf2,0x0f,0xca,0x87,0x86,0xa6}};
extern "C" const GUID __declspec(selectany) CLSID_Formatter =
    {0xe6854c08,0x0666,0x3939,{0xbd,0xf1,0xe1,0x55,0x5a,0x2c,0x49,0xfa}};
extern "C" const GUID __declspec(selectany) CLSID_FormatterConverter =
    {0xd23d2f41,0x1d69,0x3e03,{0xa2,0x75,0x32,0xae,0x38,0x12,0x23,0xac}};
extern "C" const GUID __declspec(selectany) CLSID_FormatterServices =
    {0x688c32ea,0x1e9c,0x3a4b,{0x90,0xe0,0xa4,0xd2,0xa1,0xd7,0x3f,0x3f}};
extern "C" const GUID __declspec(selectany) CLSID_ObjectIDGenerator =
    {0x4f272c37,0xf0a8,0x350c,{0x86,0x7b,0x2c,0x03,0xb2,0xb1,0x6b,0x80}};
extern "C" const GUID __declspec(selectany) CLSID_ObjectManager =
    {0xc3a27c9a,0x5f79,0x3b7a,{0x96,0x3d,0x39,0xb1,0xe5,0x20,0x2b,0x55}};
extern "C" const GUID __declspec(selectany) CLSID_OptionalFieldAttribute =
    {0x1c97ef1d,0x74ed,0x3d21,{0x84,0xa4,0x86,0x31,0xd9,0x59,0x63,0x4a}};
extern "C" const GUID __declspec(selectany) CLSID_OnSerializingAttribute =
    {0x9bf86f6e,0xb0e1,0x348b,{0x96,0x27,0x69,0x70,0x67,0x2e,0xb3,0xd3}};
extern "C" const GUID __declspec(selectany) CLSID_OnSerializedAttribute =
    {0x6f8527bf,0x5aad,0x3236,{0xb6,0x39,0xa0,0x51,0x77,0x33,0x2e,0xfe}};
extern "C" const GUID __declspec(selectany) CLSID_OnDeserializingAttribute =
    {0x30ac0b94,0x3bdb,0x3199,{0x8a,0x5d,0xec,0xa0,0xc5,0x45,0x83,0x81}};
extern "C" const GUID __declspec(selectany) CLSID_OnDeserializedAttribute =
    {0x18b1c7ee,0x68e3,0x35bb,{0x9e,0x40,0x46,0x9a,0x22,0x32,0x85,0xf7}};
extern "C" const GUID __declspec(selectany) CLSID_SerializationBinder =
    {0x25d97db7,0xbdc3,0x3205,{0xb8,0x6b,0x95,0x6b,0x85,0x2e,0xce,0x76}};
extern "C" const GUID __declspec(selectany) CLSID_SerializationInfo =
    {0xd69398c1,0x7541,0x33e7,{0xb5,0x44,0xa8,0x03,0xf3,0x80,0xff,0xb6}};
extern "C" const GUID __declspec(selectany) CLSID_SerializationInfoEnumerator =
    {0x341ba870,0xb7fe,0x3cbc,{0x9a,0x72,0xb7,0x89,0x4c,0x6e,0xc1,0x71}};
extern "C" const GUID __declspec(selectany) CLSID_SerializationException =
    {0x57154c7c,0xedb2,0x3bfd,{0xa8,0xba,0x92,0x4c,0x60,0x91,0x3e,0xbf}};
extern "C" const GUID __declspec(selectany) IID_IObjectReference =
    {0x6e70ed5f,0x0439,0x38ce,{0x83,0xbb,0x86,0x0f,0x14,0x21,0xf2,0x9f}};
extern "C" const GUID __declspec(selectany) CLSID_SurrogateSelector =
    {0x88c8a919,0xeb24,0x3cca,{0x84,0xf7,0x2e,0xa8,0x2b,0xb3,0xf3,0xed}};
extern "C" const GUID __declspec(selectany) CLSID_Calendar =
    {0x8a93390f,0x4331,0x317f,{0xb4,0x50,0x1e,0x0e,0x49,0x14,0xe3,0x35}};
extern "C" const GUID __declspec(selectany) CLSID_EastAsianLunisolarCalendar =
    {0x47ff8f5e,0xf989,0x39ff,{0xa9,0x85,0x89,0x8b,0xf3,0x61,0x09,0xbd}};
extern "C" const GUID __declspec(selectany) CLSID_CompareInfo =
    {0x6747ff61,0xf8da,0x3689,{0xbb,0x01,0x47,0xf2,0x26,0x6a,0xe2,0x61}};
extern "C" const GUID __declspec(selectany) CLSID_CultureInfo =
    {0x348a8c6d,0x464a,0x3f21,{0x85,0x6b,0x06,0x13,0x70,0xd5,0x45,0x99}};
extern "C" const GUID __declspec(selectany) CLSID_DateTimeFormatInfo =
    {0x70a738d1,0x1bc5,0x3175,{0xbd,0x42,0x60,0x3e,0x2b,0x82,0xc0,0x8b}};
extern "C" const GUID __declspec(selectany) CLSID_DaylightTime =
    {0x5050fe97,0x72a6,0x3bc6,{0x92,0xf2,0x9d,0xd0,0x41,0x30,0x41,0xe3}};
extern "C" const GUID __declspec(selectany) CLSID_GregorianCalendar =
    {0x68f8aea9,0x1968,0x35b9,{0x8a,0x0e,0x6f,0xdc,0x63,0x7a,0x4f,0x8e}};
extern "C" const GUID __declspec(selectany) CLSID_HebrewCalendar =
    {0x2206d773,0xca1c,0x3258,{0x94,0x56,0xce,0xb7,0x70,0x6c,0x37,0x10}};
extern "C" const GUID __declspec(selectany) CLSID_HijriCalendar =
    {0xee832ce3,0x06ca,0x33ef,{0x8f,0x01,0x61,0xc7,0xc2,0x18,0xbd,0x7e}};
extern "C" const GUID __declspec(selectany) CLSID_JapaneseCalendar =
    {0x374050dd,0x6190,0x3257,{0x88,0x12,0x82,0x30,0xbf,0x09,0x51,0x47}};
extern "C" const GUID __declspec(selectany) CLSID_JulianCalendar =
    {0x5c3e6ce8,0xb218,0x3762,{0x88,0x3c,0x91,0xbc,0x98,0x7c,0xdc,0x2d}};
extern "C" const GUID __declspec(selectany) CLSID_KoreanCalendar =
    {0x1a06a4dc,0xe239,0x3717,{0x89,0xe1,0xd0,0x68,0x3f,0x3a,0x53,0x20}};
extern "C" const GUID __declspec(selectany) CLSID_RegionInfo =
    {0x0c630393,0x7583,0x333c,{0xab,0x5d,0xcb,0x10,0xb9,0x10,0xf6,0x9b}};
extern "C" const GUID __declspec(selectany) CLSID_SortKey =
    {0xf34b5293,0x82d0,0x32a5,{0x91,0x65,0xae,0x78,0x9f,0xd3,0xcf,0x15}};
extern "C" const GUID __declspec(selectany) CLSID_StringInfo =
    {0x31c967b5,0x2f8a,0x3957,{0x9c,0x6d,0x34,0xa0,0x73,0x1d,0xb3,0x6c}};
extern "C" const GUID __declspec(selectany) CLSID_TaiwanCalendar =
    {0x769b8b68,0x64f7,0x3b61,{0xb7,0x44,0x16,0x0a,0x9f,0xcc,0x32,0x16}};
extern "C" const GUID __declspec(selectany) CLSID_TextElementEnumerator =
    {0x4c96da7c,0x8858,0x3c24,{0xa9,0x73,0xcb,0x50,0xf2,0x86,0x0a,0x91}};
extern "C" const GUID __declspec(selectany) CLSID_TextInfo =
    {0xbca1528c,0x6369,0x37ad,{0x8c,0xc1,0xdb,0x24,0xa9,0x2c,0xc6,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_ThaiBuddhistCalendar =
    {0xec3dac94,0xdf80,0x3017,{0xb3,0x81,0xb1,0x3d,0xce,0xd6,0xc4,0xd8}};
extern "C" const GUID __declspec(selectany) CLSID_NumberFormatInfo =
    {0x146a47ab,0xa2cf,0x3587,{0xbb,0x25,0x2b,0x28,0x6d,0x75,0x66,0xb4}};
extern "C" const GUID __declspec(selectany) CLSID_Encoding =
    {0xeaecc459,0x5ce4,0x35a2,{0xa0,0x85,0x5a,0xfc,0x04,0x51,0xc0,0x3a}};
extern "C" const GUID __declspec(selectany) CLSID_Encoder =
    {0xcc9d4538,0x57e8,0x3a82,{0x88,0x6a,0x5f,0xe6,0x5a,0x12,0x7a,0x5a}};
extern "C" const GUID __declspec(selectany) CLSID_Decoder =
    {0xa924269d,0x5df2,0x33af,{0xb7,0x2a,0x32,0x50,0xc4,0x10,0x5e,0xbe}};
extern "C" const GUID __declspec(selectany) CLSID_ASCIIEncoding =
    {0x9e28ef95,0x9c6f,0x3a00,{0xb5,0x25,0x36,0xa7,0x61,0x78,0xcc,0x9c}};
extern "C" const GUID __declspec(selectany) CLSID_UnicodeEncoding =
    {0xa0f5f5dc,0x337b,0x38d7,{0xb1,0xa3,0xfb,0x1b,0x95,0x66,0x6b,0xbf}};
extern "C" const GUID __declspec(selectany) CLSID_UTF7Encoding =
    {0x3c9dca8b,0x4410,0x3143,{0xb8,0x01,0x55,0x95,0x53,0xeb,0x67,0x25}};
extern "C" const GUID __declspec(selectany) CLSID_UTF8Encoding =
    {0x8c40d44a,0x4ede,0x3760,{0x9b,0x61,0x50,0x25,0x50,0x56,0xd3,0xc7}};
extern "C" const GUID __declspec(selectany) IID_IResourceReader =
    {0x8965a22f,0xfba8,0x36ad,{0x81,0x32,0x70,0xbb,0xd0,0xda,0x45,0x7d}};
extern "C" const GUID __declspec(selectany) IID_IResourceWriter =
    {0xe97aa6e5,0x595e,0x31c3,{0x82,0xf0,0x68,0x8f,0xb9,0x19,0x54,0xc6}};
extern "C" const GUID __declspec(selectany) CLSID_MissingManifestResourceException =
    {0x726bbdf4,0x6c6d,0x30f4,{0xb3,0xa0,0xf1,0x4d,0x6a,0xec,0x08,0xc7}};
extern "C" const GUID __declspec(selectany) CLSID_MissingSatelliteAssemblyException =
    {0xd41969a6,0xc394,0x34b9,{0xbd,0x24,0xdd,0x40,0x8f,0x39,0xf2,0x61}};
extern "C" const GUID __declspec(selectany) CLSID_NeutralResourcesLanguageAttribute =
    {0x87797538,0x6bae,0x366a,{0xa9,0xbc,0x01,0x2c,0x8f,0x62,0xea,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_ResourceManager =
    {0x9afb3b93,0xe6da,0x35d6,{0xb9,0xfe,0x44,0x81,0x5e,0x2b,0xfd,0x45}};
extern "C" const GUID __declspec(selectany) CLSID_ResourceReader =
    {0xdd78b5ed,0xaa52,0x3b2b,{0xa1,0xb4,0x6c,0xe3,0xce,0x31,0x55,0xea}};
extern "C" const GUID __declspec(selectany) CLSID_ResourceSet =
    {0xa907f7cd,0x8c99,0x31ea,{0xac,0x00,0x80,0xfa,0x4d,0x94,0x78,0x0a}};
extern "C" const GUID __declspec(selectany) CLSID_ResourceWriter =
    {0x9187a0d6,0x508c,0x36cc,{0xa7,0x9f,0xf9,0x0b,0x89,0xa0,0xe1,0x54}};
extern "C" const GUID __declspec(selectany) CLSID_SatelliteContractVersionAttribute =
    {0xf4ae34f8,0x6ce4,0x32dc,{0x96,0xba,0x9c,0x7a,0x0a,0x9c,0x6d,0x06}};
extern "C" const GUID __declspec(selectany) CLSID_Registry =
    {0x9b4ef4fa,0x742e,0x3878,{0x95,0x3a,0x47,0x49,0x99,0x71,0x10,0x87}};
extern "C" const GUID __declspec(selectany) CLSID_RegistryKey =
    {0x2c8fa9bd,0xcbe4,0x3223,{0xb5,0x92,0x41,0xb5,0xa2,0x2f,0xb8,0x20}};
extern "C" const GUID __declspec(selectany) CLSID_AllMembershipCondition =
    {0x06b81c12,0xa5da,0x340d,{0xaf,0xf7,0xfa,0x14,0x53,0xfb,0xc2,0x9a}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationDirectory =
    {0x720bf501,0x75aa,0x39f3,{0xb6,0xc2,0xea,0xbe,0x2f,0x47,0xce,0xe5}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationDirectoryMembershipCondition =
    {0x3ddb2114,0x9285,0x30a6,{0x90,0x6d,0xb1,0x17,0x64,0x0c,0xa9,0x27}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationSecurityInfo =
    {0x80472d32,0xef68,0x3988,{0xbe,0x44,0xbd,0x9e,0x33,0x6d,0x4d,0xf8}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationSecurityManager =
    {0x2fb9ac2a,0x8724,0x32d0,{0x98,0xfa,0x21,0x8c,0x1b,0x2b,0x3e,0x1d}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationTrust =
    {0xa5448b7a,0xaa07,0x3c56,{0xb4,0x2b,0x7d,0x88,0x1f,0xa1,0x09,0x34}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationTrustCollection =
    {0x45cd6d50,0xa8b4,0x3783,{0x97,0x59,0x44,0x5f,0xc3,0xd4,0x73,0x1c}};
extern "C" const GUID __declspec(selectany) CLSID_ApplicationTrustEnumerator =
    {0x128ba7d4,0xe68f,0x3223,{0x85,0xbe,0x73,0x72,0xd0,0xfb,0x54,0x23}};
extern "C" const GUID __declspec(selectany) CLSID_CodeGroup =
    {0x05c4d71e,0xfb7d,0x30be,{0xb6,0xb4,0x1d,0xf8,0x99,0x9c,0xee,0xe1}};
extern "C" const GUID __declspec(selectany) CLSID_Evidence =
    {0x62545937,0x20a9,0x3d0f,{0xb0,0x4b,0x32,0x2e,0x85,0x4e,0xac,0xb0}};
extern "C" const GUID __declspec(selectany) CLSID_FileCodeGroup =
    {0x3f8d7e3a,0x24e7,0x3f7c,{0x9d,0xc5,0x4c,0xa2,0x2e,0xe7,0xc7,0x82}};
extern "C" const GUID __declspec(selectany) CLSID_FirstMatchCodeGroup =
    {0x28635cc7,0x4c39,0x3779,{0x8c,0x31,0x83,0x91,0x01,0x00,0x1f,0x78}};
extern "C" const GUID __declspec(selectany) CLSID_TrustManagerContext =
    {0xafaef10f,0x1bc4,0x351f,{0x88,0x6a,0x87,0x8a,0x26,0x5c,0x18,0x62}};
extern "C" const GUID __declspec(selectany) CLSID_CodeConnectAccess =
    {0xe7473f93,0xeccf,0x38ed,{0x92,0x85,0xe9,0x3c,0xd2,0xd2,0x76,0x08}};
extern "C" const GUID __declspec(selectany) CLSID_NetCodeGroup =
    {0xa601b6b7,0x422d,0x3b21,{0xa6,0x1c,0xa7,0x7c,0x55,0x12,0xf3,0x6a}};
extern "C" const GUID __declspec(selectany) CLSID_PermissionRequestEvidence =
    {0xe1c3e338,0xb088,0x3c69,{0x99,0x89,0xa0,0xe5,0x9e,0x96,0xfe,0xa8}};
extern "C" const GUID __declspec(selectany) CLSID_PolicyException =
    {0x89d26277,0x8408,0x3fc8,{0xbd,0x44,0xcf,0x5f,0x0e,0x61,0x4c,0x82}};
extern "C" const GUID __declspec(selectany) CLSID_PolicyLevel =
    {0x64e304c1,0xd80d,0x3388,{0x94,0xef,0x00,0x2f,0x45,0xd5,0xac,0x05}};
extern "C" const GUID __declspec(selectany) CLSID_PolicyStatement =
    {0xabcc3df5,0x7e59,0x3780,{0xa3,0xcc,0x4f,0x41,0x20,0x08,0xa5,0xea}};
extern "C" const GUID __declspec(selectany) CLSID_Site =
    {0x0f71b36d,0x4006,0x35b5,{0x9f,0x42,0x4c,0x46,0x85,0x14,0xaf,0x70}};
extern "C" const GUID __declspec(selectany) CLSID_SiteMembershipCondition =
    {0x7f5e4fd8,0x9575,0x3691,{0xbf,0x0c,0x2d,0x30,0xa2,0x1e,0x43,0x76}};
extern "C" const GUID __declspec(selectany) CLSID_StrongName =
    {0xf1566aaf,0x63fe,0x3f4b,{0xb1,0x21,0xdc,0xd1,0x79,0x99,0x11,0x9b}};
extern "C" const GUID __declspec(selectany) CLSID_StrongNameMembershipCondition =
    {0x7cffac1c,0x7370,0x30f9,{0xaa,0x72,0xe3,0x0f,0xe3,0x92,0x57,0xd9}};
extern "C" const GUID __declspec(selectany) CLSID_UnionCodeGroup =
    {0xf424d0be,0xf3cb,0x3d09,{0x9b,0x18,0xc5,0x23,0xa7,0x39,0xeb,0xfe}};
extern "C" const GUID __declspec(selectany) CLSID_Url =
    {0x7a2ae0c8,0xef79,0x334e,{0xba,0xcf,0xd7,0xba,0x45,0x2c,0xaf,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_UrlMembershipCondition =
    {0x93e33d56,0x812d,0x3112,{0xbe,0xeb,0x27,0x6a,0x67,0xd1,0x17,0x2e}};
extern "C" const GUID __declspec(selectany) CLSID_Zone =
    {0x6fcf98ff,0xb4d6,0x37a4,{0x9d,0xab,0x4d,0xe1,0x1a,0x5f,0xe5,0xf2}};
extern "C" const GUID __declspec(selectany) CLSID_ZoneMembershipCondition =
    {0xd72f9aeb,0x23f8,0x3b88,{0xb6,0xfd,0x8a,0x14,0x3e,0x32,0x45,0xa1}};
extern "C" const GUID __declspec(selectany) CLSID_GacInstalled =
    {0xee24a2c3,0x3aa2,0x33da,{0x87,0x31,0xa4,0xfc,0xc1,0x10,0x58,0x13}};
extern "C" const GUID __declspec(selectany) CLSID_GacMembershipCondition =
    {0x390e92c9,0xfa66,0x3357,{0xbe,0xf2,0x45,0xa1,0xf3,0x41,0x86,0xb9}};
extern "C" const GUID __declspec(selectany) CLSID_Hash =
    {0x260356e2,0xbafa,0x3349,{0x8b,0xf7,0x86,0xee,0xb4,0x60,0xa2,0xc7}};
extern "C" const GUID __declspec(selectany) CLSID_HashMembershipCondition =
    {0x769edead,0xe3b2,0x3c89,{0xb9,0xa6,0x94,0x8c,0xd7,0x28,0x85,0x87}};
extern "C" const GUID __declspec(selectany) CLSID_Publisher =
    {0x649546a7,0x965f,0x366f,{0xa7,0x35,0x0f,0xb5,0x22,0x91,0x7b,0x5a}};
extern "C" const GUID __declspec(selectany) CLSID_PublisherMembershipCondition =
    {0x05bf00f9,0x44b8,0x39a7,{0xaf,0x36,0x7e,0x11,0xc9,0xb5,0x02,0xdd}};
extern "C" const GUID __declspec(selectany) IID_IIdentity =
    {0xf4205a87,0x4d46,0x303d,{0xb1,0xd9,0x5a,0x99,0xf7,0xc9,0x0d,0x30}};
extern "C" const GUID __declspec(selectany) CLSID_GenericIdentity =
    {0x4c534a8e,0x3c46,0x3745,{0xbd,0xae,0x51,0x19,0xc4,0x0f,0x98,0xe7}};
extern "C" const GUID __declspec(selectany) IID_IPrincipal =
    {0x4283ca6c,0xd291,0x3481,{0x83,0xc9,0x95,0x54,0x48,0x1f,0xe8,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_GenericPrincipal =
    {0x2eacb710,0xfe48,0x3c13,{0x81,0x45,0xe8,0x10,0x79,0x2c,0x58,0xa2}};
extern "C" const GUID __declspec(selectany) CLSID_WindowsIdentity =
    {0x70c7cec2,0x5bb2,0x3770,{0xa2,0x6e,0xfc,0x18,0x0c,0x81,0xf4,0xfe}};
extern "C" const GUID __declspec(selectany) CLSID_WindowsImpersonationContext =
    {0xfc1abb5c,0xd107,0x3145,{0x90,0x8a,0x3e,0xa1,0x07,0xd5,0x37,0x48}};
extern "C" const GUID __declspec(selectany) CLSID_WindowsPrincipal =
    {0x138887db,0xc015,0x3254,{0xb0,0x5a,0xd1,0x56,0x16,0xbf,0x9a,0xee}};
extern "C" const GUID __declspec(selectany) CLSID_UnmanagedFunctionPointerAttribute =
    {0x1a8e1b1f,0xef9e,0x33e6,{0x95,0x0e,0x4d,0x94,0x35,0xf1,0x33,0x5b}};
extern "C" const GUID __declspec(selectany) CLSID_DispIdAttribute =
    {0xb36860b2,0xbac3,0x3c25,{0x81,0xee,0x1f,0x62,0xcb,0x91,0xfc,0x76}};
extern "C" const GUID __declspec(selectany) CLSID_InterfaceTypeAttribute =
    {0xc8a36b3c,0xbc72,0x31e7,{0x8b,0xa2,0xef,0x94,0x9a,0x54,0xbd,0x0c}};
extern "C" const GUID __declspec(selectany) CLSID_ComDefaultInterfaceAttribute =
    {0x43c2214a,0x95fc,0x362d,{0xa7,0x92,0x73,0x16,0xc6,0x5b,0x49,0xaa}};
extern "C" const GUID __declspec(selectany) CLSID_ClassInterfaceAttribute =
    {0x5819db84,0x163f,0x3fa2,{0x85,0x3b,0x43,0xa0,0x26,0x96,0x26,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_ComVisibleAttribute =
    {0x1f4bcc99,0xe9d8,0x3aab,{0x99,0xaf,0x4d,0x1e,0xc2,0x6e,0x33,0x76}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLibImportClassAttribute =
    {0xa09b7b15,0xdfa5,0x3e98,{0x9c,0x26,0x86,0x5a,0xd9,0x07,0x9e,0x42}};
extern "C" const GUID __declspec(selectany) CLSID_LCIDConversionAttribute =
    {0xf912451b,0x8766,0x32cd,{0x91,0x7f,0x3b,0x9f,0xee,0x44,0x21,0xa8}};
extern "C" const GUID __declspec(selectany) CLSID_ComRegisterFunctionAttribute =
    {0x630a3ef1,0x23c6,0x31fe,{0x9d,0x25,0x29,0x4e,0x3b,0x3e,0x74,0x86}};
extern "C" const GUID __declspec(selectany) CLSID_ComUnregisterFunctionAttribute =
    {0x8f45c7ff,0x1e6e,0x34c1,{0xa7,0xcc,0x26,0x09,0x85,0x39,0x2a,0x05}};
extern "C" const GUID __declspec(selectany) CLSID_ProgIdAttribute =
    {0x47854ae8,0xf71c,0x3459,{0xa9,0x43,0x1e,0x91,0xed,0xc9,0x51,0xa7}};
extern "C" const GUID __declspec(selectany) CLSID_ImportedFromTypeLibAttribute =
    {0x8afeaa55,0x757f,0x3ddb,{0xa7,0x50,0xb2,0xca,0xa6,0xa0,0xb8,0x0b}};
extern "C" const GUID __declspec(selectany) CLSID_IDispatchImplAttribute =
    {0x3ab97590,0x3a62,0x36fb,{0x90,0x3f,0xbb,0x70,0xb0,0x15,0xf1,0x56}};
extern "C" const GUID __declspec(selectany) CLSID_ComSourceInterfacesAttribute =
    {0xac0c43b1,0x6ca0,0x3e6c,{0xb0,0x88,0xb1,0x1e,0x96,0xfa,0x0c,0xe3}};
extern "C" const GUID __declspec(selectany) CLSID_ComConversionLossAttribute =
    {0x8a3fd229,0xb2a9,0x347f,{0x93,0xd2,0x87,0xf3,0xb7,0xf9,0x27,0x53}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLibTypeAttribute =
    {0x2f53c69e,0xf1f0,0x3e98,{0xad,0x3b,0xee,0xaa,0x89,0xa8,0x89,0x06}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLibFuncAttribute =
    {0x05074a9c,0x0b30,0x3a78,{0xaa,0xef,0x99,0x35,0x6e,0x49,0xdf,0x45}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLibVarAttribute =
    {0x36bdd1da,0x2b15,0x3428,{0xb0,0x55,0xbd,0xab,0xf4,0x66,0x7c,0x3f}};
extern "C" const GUID __declspec(selectany) CLSID_MarshalAsAttribute =
    {0xaaffef00,0x519d,0x3ee0,{0x87,0x63,0xd4,0xb6,0x50,0x61,0x1e,0x0d}};
extern "C" const GUID __declspec(selectany) CLSID_ComImportAttribute =
    {0xf1eba909,0x6621,0x346d,{0x9c,0xe2,0x39,0xf2,0x66,0xc9,0xd0,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_GuidAttribute =
    {0xfde6d643,0x768a,0x3c91,{0xa1,0x69,0x2c,0x8f,0xb7,0xc1,0xcd,0x1f}};
extern "C" const GUID __declspec(selectany) CLSID_PreserveSigAttribute =
    {0x204d5a28,0x46a0,0x3f04,{0xbd,0x7c,0xb5,0x67,0x26,0x31,0xe5,0x7f}};
extern "C" const GUID __declspec(selectany) CLSID_InAttribute =
    {0x96a058cd,0xfaf7,0x386c,{0x85,0xbf,0xe4,0x7f,0x00,0xc8,0x17,0x95}};
extern "C" const GUID __declspec(selectany) CLSID_OutAttribute =
    {0xfdb2dc94,0xb5a0,0x3702,{0xae,0x84,0xbb,0xfa,0x75,0x2a,0xcb,0x36}};
extern "C" const GUID __declspec(selectany) CLSID_OptionalAttribute =
    {0xb81cb5ed,0xe654,0x399f,{0x96,0x98,0xc8,0x3c,0x50,0x66,0x57,0x86}};
extern "C" const GUID __declspec(selectany) CLSID_DllImportAttribute =
    {0x3c52777e,0xf51c,0x300a,{0x81,0x22,0x47,0x9a,0x19,0x16,0x43,0x25}};
extern "C" const GUID __declspec(selectany) CLSID_StructLayoutAttribute =
    {0xa0fff774,0x26bd,0x3de7,{0x95,0xce,0xdb,0xce,0xa6,0x08,0x8f,0x96}};
extern "C" const GUID __declspec(selectany) CLSID_FieldOffsetAttribute =
    {0x3ba14c59,0x4c61,0x3d7c,{0x81,0x61,0x99,0x62,0xd7,0xa8,0x92,0x92}};
extern "C" const GUID __declspec(selectany) CLSID_ComAliasNameAttribute =
    {0xe1aa0b69,0xca47,0x3749,{0xae,0xb1,0x13,0x3d,0xce,0x4c,0x70,0x5f}};
extern "C" const GUID __declspec(selectany) CLSID_AutomationProxyAttribute =
    {0x0e67c08b,0xd921,0x33d0,{0x82,0xfe,0xb6,0xfd,0x28,0xbb,0xae,0xff}};
extern "C" const GUID __declspec(selectany) CLSID_PrimaryInteropAssemblyAttribute =
    {0x6dd18f5d,0x7a5c,0x3868,{0xb1,0xc2,0x7e,0x19,0xda,0x87,0x33,0x86}};
extern "C" const GUID __declspec(selectany) CLSID_CoClassAttribute =
    {0x03e4c7f5,0x974c,0x3253,{0x9b,0xe0,0x41,0x47,0x06,0x97,0xbb,0xad}};
extern "C" const GUID __declspec(selectany) CLSID_ComEventInterfaceAttribute =
    {0x830ac1f5,0x98ee,0x39a3,{0x92,0x12,0xfa,0x56,0x26,0xca,0x85,0x5a}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLibVersionAttribute =
    {0x5f8dc45f,0xa2d8,0x3e34,{0x8c,0x86,0x58,0x6e,0xd6,0xa7,0x49,0x84}};
extern "C" const GUID __declspec(selectany) CLSID_ComCompatibleVersionAttribute =
    {0x7f962ebf,0x2220,0x30f0,{0x8b,0x92,0x24,0xa7,0x3b,0x7c,0xd2,0x68}};
extern "C" const GUID __declspec(selectany) CLSID_BestFitMappingAttribute =
    {0x84fee617,0x858b,0x364b,{0xa6,0x62,0x8b,0xf7,0xed,0x53,0x30,0xca}};
extern "C" const GUID __declspec(selectany) CLSID_DefaultCharSetAttribute =
    {0x66708447,0xecce,0x3422,{0xb3,0xa3,0xc8,0x16,0x1c,0x1c,0x69,0x3b}};
extern "C" const GUID __declspec(selectany) CLSID_SetWin32ContextInIDispatchAttribute =
    {0x9d309f77,0x4655,0x372e,{0x84,0xb0,0xb0,0xfb,0x40,0x30,0xf3,0xb8}};
extern "C" const GUID __declspec(selectany) CLSID_ExternalException =
    {0xafc681cf,0xe82f,0x361a,{0x82,0x80,0xcf,0x4e,0x1f,0x84,0x4c,0x3e}};
extern "C" const GUID __declspec(selectany) CLSID_COMException =
    {0x07f94112,0xa42e,0x328b,{0xb5,0x08,0x70,0x2e,0xf6,0x2b,0xcc,0x29}};
extern "C" const GUID __declspec(selectany) IID_ICustomMarshaler =
    {0x601cd486,0x04bf,0x3213,{0x9e,0xa9,0x06,0xeb,0xe4,0x35,0x1d,0x74}};
extern "C" const GUID __declspec(selectany) CLSID_InvalidOleVariantTypeException =
    {0x9a944885,0xedaf,0x3a81,{0xa2,0xff,0x6a,0x9d,0x5d,0x1a,0xbf,0xc7}};
extern "C" const GUID __declspec(selectany) CLSID_MarshalDirectiveException =
    {0x742ad1fb,0xb2f0,0x3681,{0xb4,0xaa,0xe7,0x36,0xa3,0xbc,0xe4,0xe1}};
extern "C" const GUID __declspec(selectany) CLSID_RuntimeEnvironment =
    {0x78d22140,0x40cf,0x303e,{0xbe,0x96,0xb3,0xac,0x04,0x07,0xa3,0x4d}};
extern "C" const GUID __declspec(selectany) CLSID_SEHException =
    {0xca805b13,0x468c,0x3a22,{0xbf,0x9a,0x81,0x8e,0x97,0xef,0xa6,0xb7}};
extern "C" const GUID __declspec(selectany) CLSID_BStrWrapper =
    {0xe5de21f2,0x12d7,0x3604,{0x82,0x51,0x1c,0x5d,0xbc,0x64,0xca,0x66}};
extern "C" const GUID __declspec(selectany) CLSID_CurrencyWrapper =
    {0xd540a482,0x8fb8,0x3720,{0xb5,0x2e,0x08,0xc7,0xa2,0xc1,0xb9,0xdf}};
extern "C" const GUID __declspec(selectany) CLSID_DispatchWrapper =
    {0xda7109d3,0xbcd8,0x3d4c,{0xb1,0x72,0xdf,0xc2,0xe5,0x85,0x56,0x2a}};
extern "C" const GUID __declspec(selectany) CLSID_ErrorWrapper =
    {0xd7900ebd,0xff28,0x3ae6,{0xb5,0x17,0x7e,0x32,0x71,0x4f,0x57,0x8b}};
extern "C" const GUID __declspec(selectany) CLSID_ExtensibleClassFactory =
    {0x58734403,0x8382,0x3110,{0xb7,0x29,0x14,0xc7,0x85,0x59,0x82,0xf9}};
extern "C" const GUID __declspec(selectany) IID_ICustomAdapter =
    {0x3cc86595,0xfeb5,0x3ce9,{0xba,0x14,0xd0,0x5c,0x8d,0xc3,0x32,0x1c}};
extern "C" const GUID __declspec(selectany) CLSID_InvalidComObjectException =
    {0xa7248ec6,0xa8a5,0x3d07,{0x89,0x0e,0x61,0x07,0xf8,0xc2,0x47,0xe5}};
extern "C" const GUID __declspec(selectany) IID_ITypeLibExporterNameProvider =
    {0xfa1f3615,0xacb9,0x486d,{0x9e,0xac,0x1b,0xef,0x87,0xe3,0x6b,0x09}};
extern "C" const GUID __declspec(selectany) CLSID_ObjectCreationDelegate =
    {0x8a21df64,0xf31a,0x306f,{0x9d,0xb8,0x0d,0xfa,0x16,0x4e,0xd9,0xee}};
extern "C" const GUID __declspec(selectany) CLSID_RegistrationServices =
    {0x475e398f,0x8afa,0x43a7,{0xa3,0xbe,0xf4,0xef,0x8d,0x67,0x87,0xc9}};
extern "C" const GUID __declspec(selectany) CLSID_SafeArrayRankMismatchException =
    {0x4be89ac3,0x603d,0x36b2,{0xab,0x9b,0x9c,0x38,0x86,0x6f,0x56,0xd5}};
extern "C" const GUID __declspec(selectany) CLSID_SafeArrayTypeMismatchException =
    {0x2d5ec63c,0x1b3e,0x3ee4,{0x90,0x52,0xeb,0x0d,0x03,0x03,0x54,0x9c}};
extern "C" const GUID __declspec(selectany) CLSID_TypeLibConverter =
    {0xf1c3bf79,0xc3e4,0x11d3,{0x88,0xe7,0x00,0x90,0x27,0x54,0xc4,0x3a}};
extern "C" const GUID __declspec(selectany) CLSID_UnknownWrapper =
    {0x887d4d94,0x31d1,0x37f3,{0x99,0x38,0x64,0x3e,0xd2,0xa4,0x61,0x55}};
extern "C" const GUID __declspec(selectany) CLSID_Stream =
    {0xe331083b,0xc22d,0x3046,{0x8e,0xc7,0xd2,0x22,0xd6,0xbe,0x03,0x1f}};
extern "C" const GUID __declspec(selectany) CLSID_BinaryReader =
    {0x2484afda,0x7b47,0x3cd7,{0x97,0xb5,0x95,0x1f,0x5c,0x6a,0xb5,0xb6}};
extern "C" const GUID __declspec(selectany) CLSID_BinaryWriter =
    {0xd92ccd03,0x5c88,0x3339,{0x80,0x11,0x46,0xe8,0xb0,0x1a,0x2b,0xa8}};
extern "C" const GUID __declspec(selectany) CLSID_BufferedStream =
    {0x1500abc0,0x1dd4,0x37dd,{0x98,0x5f,0x82,0x43,0x03,0x14,0xc7,0x98}};
extern "C" const GUID __declspec(selectany) CLSID_Directory =
    {0x0ebd869e,0x64bf,0x3682,{0x80,0xbb,0x69,0x0a,0x70,0x11,0x4b,0xe0}};
extern "C" const GUID __declspec(selectany) CLSID_FileSystemInfo =
    {0x1f0e8db5,0x8f52,0x3360,{0x8a,0x47,0x9d,0x3d,0xc3,0xa5,0xac,0xaf}};
extern "C" const GUID __declspec(selectany) CLSID_DirectoryInfo =
    {0x40a8b2fa,0xe055,0x3f59,{0x8b,0xa6,0x54,0xc4,0xe3,0x56,0x49,0xb5}};
extern "C" const GUID __declspec(selectany) CLSID_IOException =
    {0xa164c0bf,0x67ae,0x3c7e,{0xbc,0x05,0xbf,0xe2,0x4a,0x8c,0xdb,0x62}};
extern "C" const GUID __declspec(selectany) CLSID_DirectoryNotFoundException =
    {0x8833bc41,0xdc6b,0x34b9,{0xa7,0x99,0x68,0x2d,0x25,0x54,0xf0,0x2f}};
extern "C" const GUID __declspec(selectany) CLSID_DriveInfo =
    {0xb7c87928,0xb1ad,0x35ce,{0xaa,0x58,0x3d,0xc3,0xaa,0xb7,0xac,0x67}};
extern "C" const GUID __declspec(selectany) CLSID_DriveNotFoundException =
    {0xa8f9f740,0x70c9,0x30a7,{0x93,0x7c,0x59,0x78,0x5a,0x9b,0xb5,0xa4}};
extern "C" const GUID __declspec(selectany) CLSID_EndOfStreamException =
    {0x58d052bc,0xa3df,0x3508,{0xac,0x95,0xff,0x29,0x7b,0xdc,0x9f,0x0c}};
extern "C" const GUID __declspec(selectany) CLSID_File =
    {0x2a96793e,0x4cf3,0x3976,{0xa8,0x93,0xb6,0x68,0x86,0xd8,0x9a,0x03}};
extern "C" const GUID __declspec(selectany) CLSID_FileInfo =
    {0xd6dffead,0x0b46,0x3ded,{0x83,0xde,0x19,0x43,0x41,0x3b,0x94,0xd5}};
extern "C" const GUID __declspec(selectany) CLSID_FileLoadException =
    {0xaf8c5f8a,0x9999,0x3e92,{0xbb,0x41,0xc5,0xf4,0x95,0x51,0x74,0xcd}};
extern "C" const GUID __declspec(selectany) CLSID_FileNotFoundException =
    {0x48c6e96f,0xa2f3,0x33e7,{0xba,0x7f,0xc8,0xf7,0x48,0x66,0x76,0x0b}};
extern "C" const GUID __declspec(selectany) CLSID_FileStream =
    {0x7f25e491,0x33be,0x31e2,{0xa3,0x34,0xcb,0x50,0x6d,0x4e,0xe4,0x71}};
extern "C" const GUID __declspec(selectany) CLSID_MemoryStream =
    {0xf5e692d9,0x8a87,0x349d,{0x96,0x57,0xf9,0x6e,0x57,0x99,0xd2,0xf4}};
extern "C" const GUID __declspec(selectany) CLSID_Path =
    {0xb7ae0cae,0x979e,0x3ebf,{0xb3,0x3f,0x8f,0x12,0x1d,0xaf,0xd7,0x8e}};
extern "C" const GUID __declspec(selectany) CLSID_PathTooLongException =
    {0xc016a313,0x9606,0x36d3,{0xa8,0x23,0x33,0xeb,0xf5,0x00,0x61,0x89}};
extern "C" const GUID __declspec(selectany) CLSID_TextReader =
    {0x7457d481,0x248a,0x3c89,{0xb7,0xe0,0xfc,0xeb,0x8f,0xd8,0x27,0xe5}};
extern "C" const GUID __declspec(selectany) CLSID_StreamReader =
    {0x405fb68b,0x360d,0x382c,{0x8a,0x64,0x1d,0xa3,0xc8,0x53,0xd1,0x61}};
extern "C" const GUID __declspec(selectany) CLSID_TextWriter =
    {0x08416c5b,0xa003,0x327c,{0x9f,0x0f,0x93,0x94,0x24,0x67,0xe6,0xe0}};
extern "C" const GUID __declspec(selectany) CLSID_StreamWriter =
    {0xef1ab726,0x0b87,0x3e09,{0xae,0xf4,0x3a,0x87,0xc5,0xdc,0xdd,0xa0}};
extern "C" const GUID __declspec(selectany) CLSID_StringReader =
    {0x0247d5af,0xd61d,0x341c,{0x86,0x15,0x0f,0xf2,0x88,0x65,0xb7,0xcb}};
extern "C" const GUID __declspec(selectany) CLSID_StringWriter =
    {0x27f31d55,0xd6c6,0x3676,{0x9d,0x42,0xc4,0x0f,0x3a,0x91,0x86,0x36}};
extern "C" const GUID __declspec(selectany) CLSID_AccessedThroughPropertyAttribute =
    {0x5efb687d,0x2b50,0x3216,{0xbd,0x74,0x52,0xd0,0x6c,0x8d,0x3c,0xd1}};
extern "C" const GUID __declspec(selectany) CLSID_CallConvCdecl =
    {0xa3a1f076,0x1fa7,0x3a26,{0x88,0x6d,0x88,0x41,0xcb,0x45,0x38,0x2f}};
extern "C" const GUID __declspec(selectany) CLSID_CallConvStdcall =
    {0xbcb67d4d,0x2096,0x36be,{0x97,0x4c,0xa0,0x03,0xfc,0x95,0x04,0x1b}};
extern "C" const GUID __declspec(selectany) CLSID_CallConvThiscall =
    {0x46080ca7,0x7cb8,0x3a55,{0xa7,0x2e,0x8e,0x50,0xec,0xa4,0xd4,0xfc}};
extern "C" const GUID __declspec(selectany) CLSID_CallConvFastcall =
    {0xed0bc45c,0x2438,0x31a9,{0xbb,0xb6,0xe2,0xa3,0xb5,0x91,0x64,0x19}};
extern "C" const GUID __declspec(selectany) CLSID_CustomConstantAttribute =
    {0x6f7a3516,0xefd9,0x31c3,{0xbc,0x9a,0xa8,0x9d,0xf1,0x9f,0x64,0xe7}};
extern "C" const GUID __declspec(selectany) CLSID_DateTimeConstantAttribute =
    {0x3178fd5d,0x2a5b,0x30b9,{0x9c,0x5c,0x75,0x93,0x80,0x2f,0x9c,0x1a}};
extern "C" const GUID __declspec(selectany) CLSID_DiscardableAttribute =
    {0x837a6733,0x1675,0x3bc9,{0xbb,0xf8,0x13,0x88,0x9f,0x84,0xda,0xf4}};
extern "C" const GUID __declspec(selectany) CLSID_DecimalConstantAttribute =
    {0xac8de863,0xb115,0x3179,{0x81,0x0f,0x16,0x2b,0x43,0xab,0xd2,0xb5}};
extern "C" const GUID __declspec(selectany) CLSID_CompilationRelaxationsAttribute =
    {0x76cec05b,0xc55e,0x3adf,{0x92,0xa2,0x06,0x98,0xf1,0xcf,0x20,0x17}};
extern "C" const GUID __declspec(selectany) CLSID_CompilerGlobalScopeAttribute =
    {0x4b601364,0xa04b,0x38bc,{0xbd,0x38,0xa1,0x8e,0x98,0x13,0x24,0xcf}};
extern "C" const GUID __declspec(selectany) CLSID_IndexerNameAttribute =
    {0x9599c078,0xdc94,0x3ea2,{0x87,0x61,0x40,0x82,0x95,0xbd,0x11,0x55}};
extern "C" const GUID __declspec(selectany) CLSID_IsVolatile =
    {0x86527c04,0x536a,0x33c6,{0x8c,0x84,0x3d,0x5a,0x5b,0x45,0x8d,0xb3}};
extern "C" const GUID __declspec(selectany) CLSID_MethodImplAttribute =
    {0x48d0cfe7,0x3128,0x3d2c,{0xa5,0xb5,0x8c,0x7b,0x82,0xb4,0xab,0x4f}};
extern "C" const GUID __declspec(selectany) CLSID_RequiredAttributeAttribute =
    {0xd49c12a2,0xc401,0x3894,{0x80,0x05,0x71,0x6c,0x2f,0x69,0x2d,0x38}};
extern "C" const GUID __declspec(selectany) CLSID_IsCopyConstructed =
    {0x2d6b9536,0xe9ca,0x317c,{0xb6,0x2f,0x8e,0x58,0x76,0x35,0x1e,0x10}};
extern "C" const GUID __declspec(selectany) CLSID_NativeCppClassAttribute =
    {0xc437ab2e,0x865b,0x321d,{0xba,0x15,0x0c,0x8e,0xc4,0xca,0x11,0x9b}};
extern "C" const GUID __declspec(selectany) CLSID_IDispatchConstantAttribute =
    {0xe947a0b0,0xd47f,0x3aa3,{0x9b,0x77,0x46,0x24,0xe0,0xf3,0xac,0xa4}};
extern "C" const GUID __declspec(selectany) CLSID_IUnknownConstantAttribute =
    {0x590e4a07,0xdafc,0x3be7,{0xa1,0x78,0xda,0x34,0x9b,0xba,0x98,0x0b}};
extern "C" const GUID __declspec(selectany) CLSID_SecurityElement =
    {0xb9033cd1,0xc905,0x3059,{0x9d,0x29,0x56,0x2e,0xcb,0x13,0xb0,0xb3}};
extern "C" const GUID __declspec(selectany) CLSID_XmlSyntaxException =
    {0xe38da416,0x8050,0x3786,{0x82,0x01,0x46,0xf1,0x87,0xc1,0x52,0x13}};
extern "C" const GUID __declspec(selectany) IID_IPermission =
    {0xa19b3fc6,0xd680,0x3dd4,{0xa1,0x7a,0xf5,0x8a,0x7d,0x48,0x14,0x94}};
extern "C" const GUID __declspec(selectany) IID_IStackWalk =
    {0x60fc57b0,0x4a46,0x32a0,{0xa5,0xb4,0xb0,0x5b,0x0d,0xe8,0xe7,0x81}};
extern "C" const GUID __declspec(selectany) CLSID_CodeAccessPermission =
    {0xaf6550fa,0x7c4b,0x3477,{0x86,0xdd,0x23,0x5f,0x82,0x86,0xea,0xac}};
extern "C" const GUID __declspec(selectany) IID_IUnrestrictedPermission =
    {0x0f1284e6,0x4399,0x3963,{0x8d,0xdd,0xa6,0xa4,0x90,0x4f,0x66,0xc8}};
extern "C" const GUID __declspec(selectany) CLSID_EnvironmentPermission =
    {0x801f6e40,0xb384,0x3d27,{0xb7,0x5f,0xde,0x2d,0xf3,0x8f,0x11,0x92}};
extern "C" const GUID __declspec(selectany) CLSID_FileDialogPermission =
    {0x9e1239b4,0x493a,0x3d2d,{0x8f,0x91,0x66,0x36,0xec,0x9e,0xca,0x21}};
extern "C" const GUID __declspec(selectany) CLSID_FileIOPermission =
    {0xdc50cd5a,0x0cad,0x3b47,{0xbf,0x0d,0x79,0xe8,0x5f,0x3c,0x2f,0xc7}};
extern "C" const GUID __declspec(selectany) CLSID_SecurityAttribute =
    {0x47dcd758,0xdf63,0x3226,{0xa3,0xa9,0xb0,0xb8,0x88,0x72,0xa3,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_CodeAccessSecurityAttribute =
    {0x21858390,0xfe95,0x33a9,{0xa1,0x03,0xf3,0x22,0xc6,0x4d,0x85,0xae}};
extern "C" const GUID __declspec(selectany) CLSID_HostProtectionAttribute =
    {0xad664904,0xfe8a,0x3217,{0xbb,0xf5,0xe6,0xab,0x1d,0x99,0x8f,0x5f}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStoragePermission =
    {0xf458abf2,0x2b5e,0x3158,{0xb0,0xe4,0x22,0x8e,0x8c,0xdc,0xf7,0x59}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStorageFilePermission =
    {0xae588447,0xd98e,0x3e39,{0x96,0xf7,0x07,0x34,0x33,0xdb,0x8d,0x35}};
extern "C" const GUID __declspec(selectany) CLSID_EnvironmentPermissionAttribute =
    {0x6161df0c,0xcd78,0x33e1,{0xb3,0xe1,0x97,0x8b,0x27,0x02,0x5e,0x40}};
extern "C" const GUID __declspec(selectany) CLSID_FileDialogPermissionAttribute =
    {0xa141f926,0xe6b5,0x3903,{0x8e,0xfa,0x10,0x14,0xd4,0x97,0x0f,0x1c}};
extern "C" const GUID __declspec(selectany) CLSID_FileIOPermissionAttribute =
    {0xde440c06,0x7ec3,0x3e59,{0x83,0xc8,0x38,0x29,0x09,0x01,0x98,0xf7}};
extern "C" const GUID __declspec(selectany) CLSID_KeyContainerPermissionAttribute =
    {0xf40ffbd5,0x4ca8,0x333e,{0x87,0x06,0x29,0xf1,0x3f,0xb8,0xd4,0xd6}};
extern "C" const GUID __declspec(selectany) CLSID_PrincipalPermissionAttribute =
    {0x6d0ae73b,0xed58,0x32e2,{0x97,0x3c,0x76,0x58,0x97,0x78,0x39,0x71}};
extern "C" const GUID __declspec(selectany) CLSID_ReflectionPermissionAttribute =
    {0x64578750,0x937f,0x3b27,{0xb6,0x31,0xc5,0x7e,0x0b,0xff,0xf9,0x7f}};
extern "C" const GUID __declspec(selectany) CLSID_RegistryPermissionAttribute =
    {0xf69cf20d,0xf85b,0x3436,{0x9e,0x0e,0xdd,0x3c,0xb3,0xe8,0xb2,0xcd}};
extern "C" const GUID __declspec(selectany) CLSID_SecurityPermissionAttribute =
    {0x5e77314c,0x043d,0x3d8c,{0x9c,0x9d,0xd1,0x8f,0x09,0xfb,0x35,0x00}};
extern "C" const GUID __declspec(selectany) CLSID_UIPermissionAttribute =
    {0x5f4ed054,0xc453,0x3d2b,{0xa0,0xfe,0x64,0xe8,0x98,0x71,0xd3,0x64}};
extern "C" const GUID __declspec(selectany) CLSID_ZoneIdentityPermissionAttribute =
    {0xc386115f,0x2b99,0x356b,{0xb4,0xa1,0x2c,0xf5,0x7c,0xe5,0x29,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_StrongNameIdentityPermissionAttribute =
    {0xef2c9de4,0xbcda,0x3322,{0xae,0x75,0x16,0xcc,0x3e,0xc2,0x66,0x5c}};
extern "C" const GUID __declspec(selectany) CLSID_SiteIdentityPermissionAttribute =
    {0x23f73179,0x6349,0x3183,{0xa5,0x5c,0xbc,0xfb,0x1a,0x24,0x46,0xe8}};
extern "C" const GUID __declspec(selectany) CLSID_UrlIdentityPermissionAttribute =
    {0x6852be7d,0x8c00,0x3f66,{0xbe,0xe3,0x46,0x3f,0x74,0x83,0x84,0x91}};
extern "C" const GUID __declspec(selectany) CLSID_PublisherIdentityPermissionAttribute =
    {0x2335c1da,0xcd60,0x3208,{0xab,0x5e,0x44,0x7f,0x16,0xa0,0x87,0xe5}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStoragePermissionAttribute =
    {0xa56859a3,0x98ed,0x39a9,{0xbd,0x33,0x58,0x07,0xf0,0xd6,0x29,0x1f}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStorageFilePermissionAttribute =
    {0xf6610df3,0x8d62,0x38bd,{0xbf,0x6b,0x2a,0x4b,0xa8,0x39,0xeb,0x3b}};
extern "C" const GUID __declspec(selectany) CLSID_PermissionSetAttribute =
    {0x24151ba6,0x6d79,0x3ec4,{0x8c,0x77,0x01,0x4f,0xfb,0xe7,0x35,0xae}};
extern "C" const GUID __declspec(selectany) CLSID_ReflectionPermission =
    {0xe71cdc85,0x7fe7,0x3f51,{0xbc,0xdb,0x02,0x45,0x97,0x70,0xdb,0x87}};
extern "C" const GUID __declspec(selectany) CLSID_PrincipalPermission =
    {0x67100ade,0x60cf,0x33f1,{0x8d,0x95,0xf6,0xfe,0x11,0x74,0x45,0x8a}};
extern "C" const GUID __declspec(selectany) CLSID_SecurityPermission =
    {0xd5f5125a,0x3d46,0x3c57,{0x83,0x93,0x0e,0x4e,0xe9,0xd8,0x01,0x6b}};
extern "C" const GUID __declspec(selectany) CLSID_SiteIdentityPermission =
    {0x3bcfc458,0x07dc,0x3ba7,{0x84,0x04,0x97,0xeb,0x76,0x64,0x10,0x80}};
extern "C" const GUID __declspec(selectany) CLSID_StrongNameIdentityPermission =
    {0x2b00b9ec,0xb4f4,0x3243,{0x90,0xab,0x53,0x2e,0x64,0xfe,0xe9,0x41}};
extern "C" const GUID __declspec(selectany) CLSID_StrongNamePublicKeyBlob =
    {0xa463394f,0x7ba6,0x3721,{0x8a,0xd8,0x84,0x27,0x48,0x61,0x2b,0x4c}};
extern "C" const GUID __declspec(selectany) CLSID_UIPermission =
    {0x05b46a2d,0x7c6b,0x3eff,{0xa0,0x9a,0x14,0x90,0xa3,0x68,0x11,0xc2}};
extern "C" const GUID __declspec(selectany) CLSID_UrlIdentityPermission =
    {0xab7d1ab9,0xd192,0x3a95,{0xb3,0x4c,0xa3,0x99,0x68,0x37,0xc6,0xa7}};
extern "C" const GUID __declspec(selectany) CLSID_ZoneIdentityPermission =
    {0xcaeb199e,0xceb9,0x388a,{0xb2,0x40,0xe2,0x9c,0x9f,0x55,0x19,0x9b}};
extern "C" const GUID __declspec(selectany) CLSID_GacIdentityPermissionAttribute =
    {0x52f1a8f3,0x7c7c,0x3c08,{0x84,0x8b,0x8a,0xb0,0xea,0x94,0x69,0x59}};
extern "C" const GUID __declspec(selectany) CLSID_GacIdentityPermission =
    {0x29a6cf6f,0xd663,0x31a7,{0x92,0x10,0x13,0x47,0x87,0x16,0x81,0xfc}};
extern "C" const GUID __declspec(selectany) CLSID_KeyContainerPermissionAccessEntry =
    {0xab32dbc6,0x3d50,0x3098,{0x8b,0x72,0xfe,0x98,0xba,0x5c,0xef,0xba}};
extern "C" const GUID __declspec(selectany) CLSID_KeyContainerPermissionAccessEntryCollection =
    {0xa9b28590,0x073c,0x392c,{0x82,0xf4,0xb4,0x7f,0xd3,0xd0,0x0e,0xc3}};
extern "C" const GUID __declspec(selectany) CLSID_KeyContainerPermissionAccessEntryEnumerator =
    {0x616e9d9e,0xee8a,0x35e6,{0xa0,0xa1,0x8b,0xf7,0x0d,0x53,0x6b,0x02}};
extern "C" const GUID __declspec(selectany) CLSID_KeyContainerPermission =
    {0x2d91f34b,0x85ec,0x33e5,{0xa3,0x2e,0x75,0x2d,0x82,0x19,0x40,0x4d}};
extern "C" const GUID __declspec(selectany) CLSID_PublisherIdentityPermission =
    {0x73cf786b,0xcd2c,0x37e4,{0x98,0x35,0x82,0x4e,0x4a,0x01,0x9f,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_RegistryPermission =
    {0xb35e31f2,0x9e50,0x3d43,{0x8e,0xaf,0xec,0x11,0x1f,0x6b,0x32,0x95}};
extern "C" const GUID __declspec(selectany) CLSID_SuppressUnmanagedCodeSecurityAttribute =
    {0x7ae01d6c,0xbee7,0x38f6,{0x9a,0x86,0x32,0x9d,0x8a,0x91,0x78,0x03}};
extern "C" const GUID __declspec(selectany) CLSID_UnverifiableCodeAttribute =
    {0x7e3393ab,0x2ab2,0x320b,{0x8f,0x6f,0xea,0xb6,0xf5,0xcf,0x2c,0xaf}};
extern "C" const GUID __declspec(selectany) CLSID_AllowPartiallyTrustedCallersAttribute =
    {0x5610f042,0xff1d,0x36d0,{0x99,0x6c,0x68,0xf7,0xa2,0x07,0xd1,0xf0}};
extern "C" const GUID __declspec(selectany) CLSID_HostSecurityManager =
    {0x84589833,0x40d7,0x36e2,{0x85,0x45,0x67,0xa9,0x2b,0x97,0xc4,0x08}};
extern "C" const GUID __declspec(selectany) CLSID_PermissionSet =
    {0xafafd122,0xdac4,0x3ff9,{0x96,0x46,0xdc,0x03,0x2a,0x4a,0x88,0x06}};
extern "C" const GUID __declspec(selectany) CLSID_NamedPermissionSet =
    {0xc23e56ce,0x0a9a,0x3733,{0x81,0x89,0x46,0xb4,0x3c,0x9e,0x4f,0xb3}};
extern "C" const GUID __declspec(selectany) CLSID_SecurityException =
    {0xeef05c76,0x5c98,0x3685,{0xa6,0x9c,0x6e,0x1a,0x26,0xa7,0xf8,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_HostProtectionException =
    {0xecc82a10,0xb731,0x3a01,{0x8a,0x17,0xac,0x0d,0xdd,0x76,0x66,0xcf}};
extern "C" const GUID __declspec(selectany) CLSID_SecurityManager =
    {0xdf4e1bb0,0x8cdc,0x3c4b,{0xa1,0xc9,0xfe,0xe6,0x4b,0xbe,0xf8,0xc5}};
extern "C" const GUID __declspec(selectany) CLSID_VerificationException =
    {0xebaa029c,0x01c0,0x32b6,{0xaa,0xe6,0xfe,0x21,0xad,0xfc,0x3e,0x5d}};
extern "C" const GUID __declspec(selectany) CLSID_ContextAttribute =
    {0x1764148e,0x73c1,0x320a,{0x83,0xfc,0x33,0x7d,0xe8,0x1a,0x68,0xb4}};
extern "C" const GUID __declspec(selectany) CLSID_AsyncResult =
    {0x614e973a,0xb737,0x38f5,{0x9d,0xdf,0x58,0x25,0xac,0x92,0x31,0x35}};
extern "C" const GUID __declspec(selectany) CLSID_CallContext =
    {0x9d0df3b9,0x107c,0x3392,{0x88,0xc8,0xfe,0x62,0x9c,0xa2,0x1d,0xab}};
extern "C" const GUID __declspec(selectany) IID_ILogicalThreadAffinative =
    {0x4d125449,0xba27,0x3927,{0x85,0x89,0x3e,0x1b,0x34,0xb6,0x22,0xe5}};
extern "C" const GUID __declspec(selectany) CLSID_LogicalCallContext =
    {0x5db435a0,0x0db3,0x3f4a,{0xbf,0x49,0x19,0x1a,0x69,0xd4,0x51,0xbb}};
extern "C" const GUID __declspec(selectany) CLSID_ChannelServices =
    {0xd625ba4c,0x7c4c,0x3b86,{0x99,0xea,0x78,0x02,0x04,0xed,0xe5,0xcd}};
extern "C" const GUID __declspec(selectany) CLSID_ClientChannelSinkStack =
    {0xdd5856e5,0x8151,0x3334,{0xb8,0xe9,0x07,0xcb,0x15,0x2b,0x20,0xa4}};
extern "C" const GUID __declspec(selectany) CLSID_ServerChannelSinkStack =
    {0x5c35f099,0x165e,0x3225,{0xa3,0xa5,0x56,0x41,0x50,0xea,0x17,0xf5}};
extern "C" const GUID __declspec(selectany) CLSID_ClientSponsor =
    {0xfd8c8fce,0x4f85,0x36b2,{0xb8,0xe8,0xf5,0xa1,0x83,0x65,0x45,0x39}};
extern "C" const GUID __declspec(selectany) CLSID_CrossContextDelegate =
    {0x8de7f105,0x07f6,0x31a8,{0x84,0x69,0xba,0xfc,0xdc,0x50,0x24,0xb8}};
extern "C" const GUID __declspec(selectany) CLSID_Context =
    {0xa36e4eaf,0xea3f,0x30a6,{0x90,0x6d,0x37,0x4b,0xbf,0x79,0x03,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_ContextProperty =
    {0x6134805f,0xe8ff,0x3fd8,{0x93,0x1e,0x4d,0x84,0x7b,0xca,0x75,0x51}};
extern "C" const GUID __declspec(selectany) IID_IChannel =
    {0x563581e8,0xc86d,0x39e2,{0xb2,0xe8,0x6c,0x23,0xf7,0x98,0x7a,0x4b}};
extern "C" const GUID __declspec(selectany) IID_IChannelReceiver =
    {0x48ad41da,0x0872,0x31da,{0x98,0x87,0xf8,0x1f,0x21,0x35,0x27,0xe6}};
extern "C" const GUID __declspec(selectany) CLSID_EnterpriseServicesHelper =
    {0xbc5062b6,0x79e8,0x3f19,{0xa8,0x7e,0xf9,0xda,0xf8,0x26,0x96,0x0c}};
extern "C" const GUID __declspec(selectany) CLSID_Header =
    {0x14309fab,0xeacd,0x3c64,{0x87,0x7e,0x07,0xeb,0x01,0xb8,0x9c,0x91}};
extern "C" const GUID __declspec(selectany) CLSID_HeaderHandler =
    {0xcc4c81b2,0x365e,0x3ba5,{0xb3,0x74,0xa9,0x49,0xb7,0x27,0xe9,0x29}};
extern "C" const GUID __declspec(selectany) IID_IMethodCallMessage =
    {0xb90efaa6,0x25e4,0x33d2,{0xac,0xa3,0x94,0xbf,0x74,0xdc,0x4a,0xb9}};
extern "C" const GUID __declspec(selectany) IID_IConstructionReturnMessage =
    {0xca0ab564,0xf5e9,0x3a7f,{0xa8,0x0b,0xeb,0x0a,0xee,0xfa,0x44,0xe9}};
extern "C" const GUID __declspec(selectany) IID_IClientFormatterSinkProvider =
    {0x6d94b6f3,0xda91,0x3c2f,{0xb8,0x76,0x08,0x37,0x69,0x66,0x74,0x68}};
extern "C" const GUID __declspec(selectany) IID_IServerFormatterSinkProvider =
    {0x042b5200,0x4317,0x3e4d,{0xb6,0x53,0x7e,0x9a,0x08,0xf1,0xa5,0xf2}};
extern "C" const GUID __declspec(selectany) IID_IClientFormatterSink =
    {0x46527c03,0xb144,0x3cf0,{0x86,0xb3,0xb8,0x77,0x61,0x48,0xa6,0xe9}};
extern "C" const GUID __declspec(selectany) IID_IChannelDataStore =
    {0x1e250ccd,0xdc30,0x3217,{0xa7,0xe4,0x14,0x8f,0x37,0x5a,0x00,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_ChannelDataStore =
    {0xf3e38cea,0x40e4,0x33c1,{0x9d,0xf7,0xbd,0x10,0x3b,0xe2,0xd6,0x8b}};
extern "C" const GUID __declspec(selectany) IID_ITransportHeaders =
    {0x1ac82fbe,0x4ff0,0x383c,{0xbb,0xfd,0xfe,0x40,0xec,0xb3,0x62,0x8d}};
extern "C" const GUID __declspec(selectany) CLSID_TransportHeaders =
    {0x48728b3f,0xf7d9,0x36c1,{0xb3,0xe7,0x8b,0xf2,0xe6,0x3c,0xe1,0xb3}};
extern "C" const GUID __declspec(selectany) CLSID_SinkProviderData =
    {0xb8be8d68,0x5fe6,0x38c5,{0x83,0x8e,0x67,0xce,0x2f,0xca,0x9d,0x70}};
extern "C" const GUID __declspec(selectany) CLSID_BaseChannelObjectWithProperties =
    {0xf369a73e,0x78d8,0x3bcc,{0xae,0x36,0x52,0x2d,0x11,0x6e,0x19,0xf9}};
extern "C" const GUID __declspec(selectany) CLSID_BaseChannelSinkWithProperties =
    {0x0e9eb6e5,0xd899,0x3132,{0x90,0xc5,0x73,0x76,0x97,0x0c,0x4f,0xb5}};
extern "C" const GUID __declspec(selectany) CLSID_BaseChannelWithProperties =
    {0x22282340,0x9e30,0x3591,{0xbd,0x1e,0x65,0x71,0x93,0x0e,0x85,0x82}};
extern "C" const GUID __declspec(selectany) IID_IDynamicProperty =
    {0x00a358d4,0x4d58,0x3b9d,{0x8f,0xb6,0xfb,0x7f,0x6b,0xc1,0x71,0x3b}};
extern "C" const GUID __declspec(selectany) IID_IMessageCtrl =
    {0x3677cbb0,0x784d,0x3c15,{0xbb,0xc8,0x75,0xcd,0x7d,0xc3,0x90,0x1e}};
extern "C" const GUID __declspec(selectany) CLSID_LifetimeServices =
    {0x8fd730c1,0xdd1b,0x3694,{0x84,0xa1,0x8c,0xe7,0x15,0x9e,0x26,0x6b}};
extern "C" const GUID __declspec(selectany) CLSID_ReturnMessage =
    {0x7b3bbd13,0xc870,0x3105,{0xb1,0x23,0xff,0xca,0x16,0x6c,0xdc,0x04}};
extern "C" const GUID __declspec(selectany) CLSID_MethodCall =
    {0x4f592b1f,0x4a0c,0x3fc0,{0x99,0x14,0x36,0x77,0xf6,0x4f,0xc5,0xa8}};
extern "C" const GUID __declspec(selectany) CLSID_ConstructionCall =
    {0x54dac96d,0xecaf,0x38db,{0xa2,0x7b,0x3d,0xdb,0x10,0x21,0x30,0xc4}};
extern "C" const GUID __declspec(selectany) CLSID_MethodResponse =
    {0x7e7bf3c0,0xb07b,0x3209,{0xa4,0x24,0x7b,0xc3,0x5d,0x76,0xea,0x7d}};
extern "C" const GUID __declspec(selectany) IID_IFieldInfo =
    {0xcc18fd4d,0xaa2d,0x3ab4,{0x98,0x48,0x58,0x4b,0xba,0xe4,0xab,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_ConstructionResponse =
    {0x25e8547a,0x6b49,0x3f00,{0xb9,0x63,0xd4,0x5f,0xdc,0xef,0x4f,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_InternalMessageWrapper =
    {0x30c4cd02,0x66a2,0x3abe,{0xbc,0x6c,0x63,0x8e,0x67,0x30,0xe5,0x34}};
extern "C" const GUID __declspec(selectany) CLSID_MethodCallMessageWrapper =
    {0x40133645,0xffaf,0x3a9c,{0xb4,0x08,0x99,0x7e,0x04,0x9d,0x5c,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_MethodReturnMessageWrapper =
    {0x2ec528fb,0xb987,0x3b3b,{0xa4,0x44,0x9f,0x94,0xc3,0xa2,0x57,0xc1}};
extern "C" const GUID __declspec(selectany) CLSID_ObjectHandle =
    {0xabeb0459,0x03b9,0x35af,{0x96,0xe1,0x66,0xbb,0x7b,0xc9,0x23,0xf7}};
extern "C" const GUID __declspec(selectany) IID_IChannelInfo =
    {0x855e6566,0x014a,0x3fe8,{0xaa,0x70,0x1e,0xac,0x77,0x1e,0x3a,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_ObjRef =
    {0x21f5a790,0x53ea,0x3d73,{0x86,0xc3,0xa5,0xba,0x6c,0xf6,0x5f,0xe9}};
extern "C" const GUID __declspec(selectany) CLSID_OneWayAttribute =
    {0xc30abd41,0x7b5a,0x3d10,{0xa6,0xef,0x56,0x86,0x2e,0x29,0x79,0xb6}};
extern "C" const GUID __declspec(selectany) CLSID_ProxyAttribute =
    {0x1163d0ca,0x2a02,0x37c1,{0xbf,0x3f,0xa9,0xb9,0xe9,0xd4,0x92,0x45}};
extern "C" const GUID __declspec(selectany) CLSID_RealProxy =
    {0x531d00a5,0x2cff,0x30d7,{0x82,0x45,0x97,0xe1,0x8c,0xd4,0xd0,0x37}};
extern "C" const GUID __declspec(selectany) CLSID_SoapAttribute =
    {0x9b924ec5,0xbf13,0x3a98,{0x8a,0xc0,0x80,0x87,0x79,0x95,0xd4,0x03}};
extern "C" const GUID __declspec(selectany) CLSID_SoapTypeAttribute =
    {0x9c67f424,0x22dc,0x3d05,{0xab,0x36,0x17,0xea,0xf9,0x58,0x81,0xf2}};
extern "C" const GUID __declspec(selectany) CLSID_SoapMethodAttribute =
    {0x01ff4e4b,0x8ad0,0x3171,{0x8c,0x82,0x5c,0x2f,0x48,0xb8,0x7e,0x3d}};
extern "C" const GUID __declspec(selectany) CLSID_SoapFieldAttribute =
    {0x5b76534c,0x3acc,0x3d52,{0xaa,0x61,0xd7,0x88,0xb1,0x34,0xab,0xe2}};
extern "C" const GUID __declspec(selectany) CLSID_SoapParameterAttribute =
    {0xc76b435d,0x86c2,0x30fd,{0x93,0x29,0xe2,0x60,0x32,0x46,0x09,0x5c}};
extern "C" const GUID __declspec(selectany) CLSID_RemotingConfiguration =
    {0x3db6f309,0x9dab,0x36ec,{0x80,0x36,0xd9,0x01,0x17,0x2c,0x99,0x4c}};
extern "C" const GUID __declspec(selectany) CLSID_TypeEntry =
    {0x4e52d7d6,0x9fdf,0x3b59,{0xb3,0x18,0x77,0x8e,0x0f,0x40,0xf3,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_ActivatedClientTypeEntry =
    {0x3ed0f148,0xe447,0x3efe,{0x84,0x88,0x3c,0x83,0x40,0x82,0xcc,0x96}};
extern "C" const GUID __declspec(selectany) CLSID_ActivatedServiceTypeEntry =
    {0x6cd360cd,0xd53d,0x3775,{0x87,0xef,0x00,0xd7,0x2e,0x66,0x45,0xf5}};
extern "C" const GUID __declspec(selectany) CLSID_WellKnownClientTypeEntry =
    {0x6b3b6647,0xb39d,0x3ed4,{0x99,0x2f,0xdf,0x6c,0x49,0xac,0xe8,0x2e}};
extern "C" const GUID __declspec(selectany) CLSID_WellKnownServiceTypeEntry =
    {0x2ce0da26,0x18ef,0x3cf4,{0xab,0xac,0xbe,0x90,0x96,0x5f,0x5f,0x90}};
extern "C" const GUID __declspec(selectany) CLSID_RemotingException =
    {0x24540ebc,0x316e,0x35d2,{0x80,0xdb,0x8a,0x53,0x5c,0xaf,0x6a,0x35}};
extern "C" const GUID __declspec(selectany) CLSID_ServerException =
    {0xdb13821e,0x9835,0x3958,{0x85,0x39,0x1e,0x02,0x13,0x99,0xab,0x6c}};
extern "C" const GUID __declspec(selectany) CLSID_RemotingTimeoutException =
    {0x3cded51a,0x86b4,0x39f0,{0xa1,0x2a,0x5d,0x1f,0xdc,0xed,0x65,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_RemotingServices =
    {0x8df4c38a,0x8492,0x3c47,{0x83,0x32,0xd9,0xd0,0x4f,0xaf,0x3c,0x59}};
extern "C" const GUID __declspec(selectany) CLSID_InternalRemotingServices =
    {0x53a3c917,0xbb24,0x3908,{0xb5,0x8b,0x09,0xec,0xda,0x99,0x26,0x5f}};
extern "C" const GUID __declspec(selectany) CLSID_MessageSurrogateFilter =
    {0xc48ca9bc,0xbbdb,0x3059,{0xae,0xc8,0x76,0x3c,0xf7,0xe9,0xa8,0x8c}};
extern "C" const GUID __declspec(selectany) CLSID_RemotingSurrogateSelector =
    {0x24eec005,0x3938,0x3c71,{0x82,0x1d,0x7f,0x68,0xfd,0x85,0x0b,0x2d}};
extern "C" const GUID __declspec(selectany) CLSID_SoapServices =
    {0xda5681da,0x7c21,0x3a2d,{0xaf,0xac,0x69,0xe3,0xa4,0xd1,0x1f,0x4d}};
extern "C" const GUID __declspec(selectany) IID_ISoapXsd =
    {0x80031d2a,0xad59,0x3fb4,{0x97,0xf3,0xb8,0x64,0xd7,0x1d,0xa8,0x6b}};
extern "C" const GUID __declspec(selectany) CLSID_SoapDateTime =
    {0x48ad62e8,0xbd40,0x37f4,{0x8f,0xd7,0xf7,0xa1,0x74,0x78,0xa8,0xe6}};
extern "C" const GUID __declspec(selectany) CLSID_SoapDuration =
    {0xde47d9cf,0x0107,0x3d66,{0x93,0xe9,0xa8,0xac,0xb0,0x6b,0x45,0x83}};
extern "C" const GUID __declspec(selectany) CLSID_SoapTime =
    {0xd049dc2b,0x82c3,0x3350,{0xa1,0xcc,0xbf,0x69,0xfe,0xe3,0x82,0x5e}};
extern "C" const GUID __declspec(selectany) CLSID_SoapDate =
    {0x2decbcb7,0xbac0,0x316d,{0x91,0x31,0x43,0x03,0x5c,0x5c,0xb4,0x80}};
extern "C" const GUID __declspec(selectany) CLSID_SoapYearMonth =
    {0xa7136bdf,0xb141,0x3913,{0x9d,0x1c,0x9b,0xc5,0xaf,0xf2,0x14,0x70}};
extern "C" const GUID __declspec(selectany) CLSID_SoapYear =
    {0x75999eba,0x0679,0x3d43,{0xbd,0xc4,0x02,0xe4,0xd6,0x37,0xf1,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_SoapMonthDay =
    {0x463ae13f,0xc7e5,0x357e,{0xa4,0x1c,0xdf,0x87,0x62,0xff,0xf8,0x5c}};
extern "C" const GUID __declspec(selectany) CLSID_SoapDay =
    {0xc9f0a842,0x3ce1,0x338f,{0xa1,0xd4,0x6d,0x7b,0xb3,0x97,0xbd,0xaa}};
extern "C" const GUID __declspec(selectany) CLSID_SoapMonth =
    {0xcaec7d4f,0x0b02,0x3579,{0x94,0x3f,0x82,0x17,0x38,0xee,0x78,0xcc}};
extern "C" const GUID __declspec(selectany) CLSID_SoapHexBinary =
    {0x8c1425c9,0xa7d3,0x35cd,{0x82,0x48,0x92,0x8c,0xa5,0x2a,0xd4,0x9b}};
extern "C" const GUID __declspec(selectany) CLSID_SoapBase64Binary =
    {0xf59d514c,0xf200,0x319f,{0xbf,0x3f,0x9e,0x4e,0x23,0xb2,0x84,0x8c}};
extern "C" const GUID __declspec(selectany) CLSID_SoapInteger =
    {0x09a60795,0x31c0,0x3a79,{0x92,0x50,0x8d,0x93,0xc7,0x4f,0xe5,0x40}};
extern "C" const GUID __declspec(selectany) CLSID_SoapPositiveInteger =
    {0x7b769b29,0x35f0,0x3bdc,{0xaa,0xe9,0xe9,0x99,0x37,0xf6,0xcd,0xec}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNonPositiveInteger =
    {0x2bb6c5e0,0xc2b9,0x3608,{0x88,0x68,0x21,0xcf,0xd6,0xdd,0xb9,0x1e}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNonNegativeInteger =
    {0x6850404f,0xd7fb,0x32bd,{0x83,0x28,0xc9,0x4f,0x66,0xe8,0xc1,0xc7}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNegativeInteger =
    {0xc41d0b30,0xa518,0x3093,{0xa1,0x8f,0x36,0x4a,0xf9,0xe7,0x1e,0xb7}};
extern "C" const GUID __declspec(selectany) CLSID_SoapAnyUri =
    {0xcdfa7117,0xb2a4,0x3a3f,{0xb3,0x93,0xbc,0x19,0xd4,0x4f,0x97,0x49}};
extern "C" const GUID __declspec(selectany) CLSID_SoapQName =
    {0xd8a4f3eb,0xe7ec,0x3620,{0x83,0x1a,0xb0,0x52,0xa6,0x7c,0x99,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNotation =
    {0xb54e38f8,0x17ff,0x3d0a,{0x9f,0xf3,0x5e,0x66,0x2d,0xe2,0x05,0x5f}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNormalizedString =
    {0x0e71f9bd,0xc109,0x3352,{0xbd,0x60,0x14,0xf9,0x6d,0x56,0xb6,0xf3}};
extern "C" const GUID __declspec(selectany) CLSID_SoapToken =
    {0x777f668e,0x3272,0x39cd,{0xa8,0xb5,0x86,0x09,0x35,0xa3,0x51,0x81}};
extern "C" const GUID __declspec(selectany) CLSID_SoapLanguage =
    {0x84f70b6c,0xd59e,0x394a,{0xb8,0x79,0xff,0xcc,0x30,0xdd,0xca,0xa2}};
extern "C" const GUID __declspec(selectany) CLSID_SoapName =
    {0x4e515531,0x7a71,0x3cdd,{0x80,0x78,0x0a,0x01,0xc8,0x5c,0x8f,0x9d}};
extern "C" const GUID __declspec(selectany) CLSID_SoapIdrefs =
    {0x2763be6b,0xf8cf,0x39d9,{0xa2,0xe8,0x9e,0x98,0x15,0xc0,0x81,0x5e}};
extern "C" const GUID __declspec(selectany) CLSID_SoapEntities =
    {0x9a3a64f4,0x8ba5,0x3dcf,{0x88,0x0c,0x8d,0x3e,0xe0,0x6c,0x55,0x38}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNmtoken =
    {0xc498f2d9,0xa77c,0x3d4b,{0xa1,0xa5,0x12,0xcc,0x7b,0x99,0x11,0x5d}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNmtokens =
    {0x14be6b21,0xc682,0x3a3a,{0x8b,0x24,0xfe,0xe7,0x5b,0x4f,0xf8,0xc5}};
extern "C" const GUID __declspec(selectany) CLSID_SoapNcName =
    {0xd13b741d,0x051f,0x322f,{0x93,0xaa,0x13,0x67,0xa3,0xc8,0xaa,0xfb}};
extern "C" const GUID __declspec(selectany) CLSID_SoapId =
    {0xfa0b54d5,0xf221,0x3648,{0xa2,0x0c,0xf6,0x7a,0x96,0xf4,0xa2,0x07}};
extern "C" const GUID __declspec(selectany) CLSID_SoapIdref =
    {0x433ca926,0x9887,0x3541,{0x89,0xcc,0x5d,0x74,0xd0,0x25,0x91,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_SoapEntity =
    {0xf00ca7a7,0x4b8d,0x3f2f,{0xa5,0xf2,0xce,0x4a,0x44,0x78,0xb3,0x9c}};
extern "C" const GUID __declspec(selectany) CLSID_SynchronizationAttribute =
    {0x5520b6d3,0x6ec6,0x3ce7,{0x95,0x8b,0xe6,0x9f,0xaf,0x6e,0xff,0x99}};
extern "C" const GUID __declspec(selectany) CLSID_TrackingServices =
    {0xe822f35c,0xddc2,0x3fb2,{0x97,0x68,0xa2,0xae,0xbc,0xed,0x7c,0x40}};
extern "C" const GUID __declspec(selectany) CLSID_UrlAttribute =
    {0x79c14066,0xe37e,0x3643,{0xa4,0x49,0xd1,0x66,0xfa,0x0e,0x8e,0xc2}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStorage =
    {0x70541b17,0xbf7e,0x399b,{0x8d,0x33,0x2a,0xfa,0x4f,0x5a,0xf3,0x95}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStorageFile =
    {0x5e45c68a,0xe894,0x3b38,{0xae,0xee,0x63,0x45,0x40,0xbd,0x0d,0x57}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStorageFileStream =
    {0xe5cfdffc,0xaeb5,0x3489,{0xb1,0x2c,0x64,0x0f,0x7b,0x03,0x1b,0x57}};
extern "C" const GUID __declspec(selectany) CLSID_IsolatedStorageException =
    {0x4479c009,0x4cc3,0x39a2,{0x8f,0x92,0xdf,0xcd,0xf0,0x34,0xf7,0x48}};
extern "C" const GUID __declspec(selectany) IID_INormalizeForIsolatedStorage =
    {0xf5006531,0xd4d7,0x319e,{0x9e,0xda,0x9b,0x4b,0x65,0xad,0x8d,0x4f}};
extern "C" const GUID __declspec(selectany) IID_ISoapMessage =
    {0xe699146c,0x7793,0x3455,{0x9b,0xef,0x96,0x4c,0x90,0xd8,0xf9,0x95}};
extern "C" const GUID __declspec(selectany) CLSID_InternalRM =
    {0xcf8f7fcf,0x94fe,0x3516,{0x90,0xe9,0xc1,0x03,0x15,0x6d,0xd2,0xd5}};
extern "C" const GUID __declspec(selectany) CLSID_InternalST =
    {0xcbbaf6ec,0x251a,0x3480,{0x8a,0x3d,0x4d,0x56,0xbc,0x73,0x20,0xd0}};
extern "C" const GUID __declspec(selectany) CLSID_SoapMessage =
    {0xe772bbe6,0xcb52,0x3c19,{0x87,0x6a,0xd1,0xbf,0xa2,0x30,0x5f,0x4e}};
extern "C" const GUID __declspec(selectany) CLSID_SoapFault =
    {0xa8d058c4,0xd923,0x3859,{0x94,0x90,0xd3,0x88,0x8f,0xc9,0x04,0x39}};
extern "C" const GUID __declspec(selectany) CLSID_ServerFault =
    {0x817accb7,0x35d8,0x3c18,{0xba,0xf2,0x0a,0x5c,0xe2,0x15,0x7b,0x74}};
extern "C" const GUID __declspec(selectany) CLSID_BinaryFormatter =
    {0x50369004,0xdb9a,0x3a75,{0xbe,0x7a,0x1d,0x0e,0xf0,0x17,0xb9,0xd3}};
extern "C" const GUID __declspec(selectany) IID__AssemblyBuilder =
    {0xbebb2505,0x8b54,0x3443,{0xae,0xad,0x14,0x2a,0x16,0xdd,0x9c,0xc7}};
extern "C" const GUID __declspec(selectany) CLSID_AssemblyBuilder =
    {0x0814be2a,0x48e5,0x3d61,{0x90,0xf3,0xef,0x3d,0x05,0xdf,0x9d,0x5e}};
extern "C" const GUID __declspec(selectany) IID__ConstructorBuilder =
    {0xed3e4384,0xd7e2,0x3fa7,{0x8f,0xfd,0x89,0x40,0xd3,0x30,0x51,0x9a}};
extern "C" const GUID __declspec(selectany) IID__CustomAttributeBuilder =
    {0xbe9acce8,0xaaff,0x3b91,{0x81,0xae,0x82,0x11,0x66,0x3f,0x5c,0xad}};
extern "C" const GUID __declspec(selectany) IID__EnumBuilder =
    {0xc7bd73de,0x9f85,0x3290,{0x88,0xee,0x09,0x0b,0x8b,0xdf,0xe2,0xdf}};
extern "C" const GUID __declspec(selectany) IID__EventBuilder =
    {0xaadaba99,0x895d,0x3d65,{0x97,0x60,0xb1,0xf1,0x26,0x21,0xfa,0xe8}};
extern "C" const GUID __declspec(selectany) IID__FieldBuilder =
    {0xce1a3bf5,0x975e,0x30cc,{0x97,0xc9,0x1e,0xf7,0x0f,0x8f,0x39,0x93}};
extern "C" const GUID __declspec(selectany) IID__ILGenerator =
    {0xa4924b27,0x6e3b,0x37f7,{0x9b,0x83,0xa4,0x50,0x19,0x55,0xe6,0xa7}};
extern "C" const GUID __declspec(selectany) IID__LocalBuilder =
    {0x4e6350d1,0xa08b,0x3dec,{0x9a,0x3e,0xc4,0x65,0xf9,0xae,0xec,0x0c}};
extern "C" const GUID __declspec(selectany) IID__MethodBuilder =
    {0x007d8a14,0xfdf3,0x363e,{0x9a,0x0b,0xfe,0xc0,0x61,0x82,0x60,0xa2}};
extern "C" const GUID __declspec(selectany) IID__MethodRental =
    {0xc2323c25,0xf57f,0x3880,{0x8a,0x4d,0x12,0xeb,0xea,0x7a,0x58,0x52}};
extern "C" const GUID __declspec(selectany) IID__ModuleBuilder =
    {0xd05ffa9a,0x04af,0x3519,{0x8e,0xe1,0x8d,0x93,0xad,0x73,0x43,0x0b}};
extern "C" const GUID __declspec(selectany) IID__ParameterBuilder =
    {0x36329eba,0xf97a,0x3565,{0xbc,0x07,0x0e,0xd5,0xc6,0xef,0x19,0xfc}};
extern "C" const GUID __declspec(selectany) IID__PropertyBuilder =
    {0x15f9a479,0x9397,0x3a63,{0xac,0xbd,0xf5,0x19,0x77,0xfb,0x0f,0x02}};
extern "C" const GUID __declspec(selectany) IID__SignatureHelper =
    {0x7d13dd37,0x5a04,0x393c,{0xbb,0xca,0xa5,0xfe,0xa8,0x02,0x89,0x3d}};
extern "C" const GUID __declspec(selectany) IID__TypeBuilder =
    {0x7e5678ee,0x48b3,0x3f83,{0xb0,0x76,0xc5,0x85,0x43,0x49,0x8a,0x58}};
extern "C" const GUID __declspec(selectany) CLSID_ConstructorBuilder =
    {0x93c24cdb,0x4014,0x3efd,{0xb5,0x64,0xe8,0x36,0xba,0x48,0xc7,0x65}};
extern "C" const GUID __declspec(selectany) CLSID_ILGenerator =
    {0x5a3dcd44,0x5855,0x3d89,{0xa0,0xec,0xce,0x50,0xa3,0xb1,0x44,0xa9}};
extern "C" const GUID __declspec(selectany) CLSID_DynamicILInfo =
    {0xa6d0f5a1,0x9218,0x30d4,{0x8a,0xd7,0x18,0xca,0x98,0xac,0x80,0x26}};
extern "C" const GUID __declspec(selectany) CLSID_DynamicMethod =
    {0x5b9f3fa2,0xdabb,0x3887,{0x93,0xf6,0x66,0x3d,0x83,0xa9,0x38,0x58}};
extern "C" const GUID __declspec(selectany) CLSID_EventBuilder =
    {0xdc18b7ec,0x91e4,0x3999,{0x91,0x0a,0x18,0x8d,0x7a,0xfa,0x0a,0x68}};
extern "C" const GUID __declspec(selectany) CLSID_FieldBuilder =
    {0x36d63e48,0x1646,0x345f,{0xa3,0xd4,0xb3,0x4e,0x4c,0x42,0xc3,0xc5}};
extern "C" const GUID __declspec(selectany) CLSID_LocalBuilder =
    {0xa6bcaa25,0xd357,0x3f79,{0xa7,0x16,0xad,0x14,0x34,0xe4,0xd8,0x32}};
extern "C" const GUID __declspec(selectany) CLSID_MethodBuilder =
    {0x53df4fb3,0xa164,0x37d3,{0x83,0x10,0xf0,0xd1,0x57,0x30,0xab,0x32}};
extern "C" const GUID __declspec(selectany) CLSID_CustomAttributeBuilder =
    {0x71bc3e08,0x0082,0x320a,{0x8b,0xa5,0xef,0xa8,0xd2,0xb9,0x79,0x8a}};
extern "C" const GUID __declspec(selectany) CLSID_MethodRental =
    {0x726d83b0,0x9a52,0x36b0,{0x91,0x9c,0x60,0xe6,0x25,0xf0,0x32,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_ModuleBuilder =
    {0xfb2ed445,0x2862,0x3a63,{0x9f,0x5a,0xbb,0xf6,0xc2,0x19,0x5d,0xce}};
extern "C" const GUID __declspec(selectany) CLSID_OpCodes =
    {0x2a59a0e6,0x11b2,0x3025,{0x92,0xde,0xe0,0x36,0xa6,0xdd,0xbc,0x00}};
extern "C" const GUID __declspec(selectany) CLSID_ParameterBuilder =
    {0x027ad5c3,0xd619,0x3506,{0xb8,0xe6,0xca,0x67,0xa3,0x3b,0x9c,0x8f}};
extern "C" const GUID __declspec(selectany) CLSID_PropertyBuilder =
    {0x22d4c021,0x1b3c,0x3ee3,{0x93,0xb6,0x4c,0x9d,0x81,0x0c,0xe0,0x77}};
extern "C" const GUID __declspec(selectany) CLSID_SignatureHelper =
    {0x798b57a2,0x064a,0x3098,{0x9a,0x80,0xe1,0x2d,0xa7,0x0e,0x00,0x85}};
extern "C" const GUID __declspec(selectany) CLSID_TypeBuilder =
    {0x0f445332,0xe34c,0x3f8c,{0x90,0xed,0xab,0x7f,0x07,0x24,0xad,0xab}};
extern "C" const GUID __declspec(selectany) CLSID_GenericTypeParameterBuilder =
    {0xa2289b64,0x5de0,0x38ba,{0x92,0x66,0xb5,0x5e,0x35,0x98,0xc9,0x01}};
extern "C" const GUID __declspec(selectany) CLSID_EnumBuilder =
    {0x70f855da,0x4948,0x38ab,{0xa7,0x27,0x43,0x1c,0x38,0x6a,0xb9,0xf5}};
extern "C" const GUID __declspec(selectany) CLSID_UnmanagedMarshal =
    {0xe3c3a258,0xe508,0x3704,{0xb9,0xeb,0x26,0x46,0x01,0x95,0x6f,0xe5}};
extern "C" const GUID __declspec(selectany) CLSID_KeySizes =
    {0xd7a12132,0x100f,0x37ae,{0xa2,0x77,0x26,0x8a,0x26,0x56,0xe4,0x76}};
extern "C" const GUID __declspec(selectany) CLSID_CryptographicException =
    {0x7f8c7dc5,0xd8b4,0x3758,{0x98,0x1f,0x02,0xaf,0x6b,0x42,0x46,0x1a}};
extern "C" const GUID __declspec(selectany) CLSID_CryptographicUnexpectedOperationException =
    {0xc41fa05c,0x8a7a,0x3157,{0x81,0x66,0x41,0x04,0xbb,0x49,0x25,0xba}};
extern "C" const GUID __declspec(selectany) IID_ICryptoTransform =
    {0x8abad867,0xf515,0x3cf6,{0xbb,0x62,0x5f,0x0c,0x88,0xb3,0xbb,0x11}};
extern "C" const GUID __declspec(selectany) CLSID_RandomNumberGenerator =
    {0x3e04dc56,0x84ce,0x3893,{0x8b,0xef,0x6c,0x9b,0x95,0xf9,0xcc,0xf4}};
extern "C" const GUID __declspec(selectany) CLSID_RNGCryptoServiceProvider =
    {0x40031115,0x09d2,0x3851,{0xa1,0x3f,0x56,0x93,0x0b,0xe4,0x80,0x38}};
extern "C" const GUID __declspec(selectany) CLSID_AsymmetricAlgorithm =
    {0x4b135d8e,0x7b1b,0x3ea8,{0x8d,0x06,0x10,0xe3,0x4f,0x15,0x7e,0x9d}};
extern "C" const GUID __declspec(selectany) CLSID_AsymmetricKeyExchangeDeformatter =
    {0x0202ce16,0x1f18,0x3bfb,{0x80,0x7d,0x76,0x0b,0x15,0x7a,0xb2,0x60}};
extern "C" const GUID __declspec(selectany) CLSID_AsymmetricKeyExchangeFormatter =
    {0xce38dc2d,0xeb2d,0x3b6a,{0xaf,0xac,0x85,0x37,0xbd,0x0b,0x9b,0xf7}};
extern "C" const GUID __declspec(selectany) CLSID_AsymmetricSignatureDeformatter =
    {0xbee4e9fd,0xde7a,0x3512,{0x93,0xd8,0x0c,0x5e,0x00,0x6b,0x16,0x7a}};
extern "C" const GUID __declspec(selectany) CLSID_AsymmetricSignatureFormatter =
    {0x5b475a84,0x5310,0x3c64,{0xb6,0x25,0xe2,0xbf,0x00,0x47,0x6f,0x53}};
extern "C" const GUID __declspec(selectany) CLSID_ToBase64Transform =
    {0x5f3a0f8d,0x5ef9,0x3ad5,{0x94,0xe0,0x53,0xaf,0xf8,0xbc,0xe9,0x60}};
extern "C" const GUID __declspec(selectany) CLSID_FromBase64Transform =
    {0xc1abb475,0xf198,0x39d5,{0xbf,0x8d,0x33,0x0b,0xc7,0x18,0x96,0x61}};
extern "C" const GUID __declspec(selectany) CLSID_CryptoAPITransform =
    {0xae746923,0x16bb,0x3d31,{0x9d,0x08,0xce,0x50,0xef,0x6f,0x7b,0x1a}};
extern "C" const GUID __declspec(selectany) CLSID_CspParameters =
    {0xaf60343f,0x6c7b,0x3761,{0x83,0x9f,0x0c,0x44,0xe3,0xca,0x06,0xda}};
extern "C" const GUID __declspec(selectany) CLSID_CryptoConfig =
    {0x9ea60eca,0x3dcd,0x340f,{0x8e,0x95,0x67,0x84,0x5d,0x18,0x59,0x99}};
extern "C" const GUID __declspec(selectany) CLSID_CryptoStream =
    {0xb5c4e3ca,0x476a,0x3961,{0xbc,0xa5,0xa6,0xc0,0xad,0x73,0xe7,0xb1}};
extern "C" const GUID __declspec(selectany) CLSID_SymmetricAlgorithm =
    {0x5b67ea6b,0xd85d,0x3f48,{0x86,0xd2,0x85,0x81,0xdb,0x23,0x0c,0x43}};
extern "C" const GUID __declspec(selectany) CLSID_DES =
    {0xf30d404c,0xa350,0x36fa,{0xa6,0xfc,0x05,0x4c,0x3f,0x58,0x34,0x20}};
extern "C" const GUID __declspec(selectany) CLSID_DESCryptoServiceProvider =
    {0xb6eb52d5,0xbb1c,0x3380,{0x8b,0xca,0x34,0x5f,0xf4,0x3f,0x4b,0x04}};
extern "C" const GUID __declspec(selectany) CLSID_DeriveBytes =
    {0x7d62db2d,0x86e3,0x3ade,{0x90,0xc4,0x21,0x59,0x50,0x64,0x3d,0x10}};
extern "C" const GUID __declspec(selectany) CLSID_DSA =
    {0xc13e7301,0x9b3f,0x3530,{0xb6,0x0a,0x7f,0x14,0x1d,0x6d,0xde,0x83}};
extern "C" const GUID __declspec(selectany) CLSID_DSACryptoServiceProvider =
    {0x673dfe75,0x9f93,0x304f,{0xab,0xa8,0xd2,0xa8,0x6b,0xa8,0x7d,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_DSASignatureDeformatter =
    {0x1f17c39c,0x99d5,0x37e0,{0x8e,0x98,0x8f,0x27,0x04,0x4b,0xd5,0x0a}};
extern "C" const GUID __declspec(selectany) CLSID_DSASignatureFormatter =
    {0x8f6d198c,0xe66f,0x3a87,{0xaa,0x3f,0xf8,0x85,0xdd,0x09,0xea,0x13}};
extern "C" const GUID __declspec(selectany) CLSID_HashAlgorithm =
    {0x68549fc3,0xf82c,0x3387,{0x85,0x78,0xe5,0xfb,0x09,0x83,0x37,0x40}};
extern "C" const GUID __declspec(selectany) CLSID_KeyedHashAlgorithm =
    {0xbf1b2d6a,0xe41e,0x3645,{0x82,0x57,0xa0,0x8d,0x74,0x83,0xbd,0x41}};
extern "C" const GUID __declspec(selectany) CLSID_HMAC =
    {0xc67d3b5f,0x8b7f,0x3720,{0xb3,0x5f,0x3b,0x49,0xd0,0x58,0xa9,0x00}};
extern "C" const GUID __declspec(selectany) CLSID_HMACMD5 =
    {0xa7eddcb5,0x6043,0x3988,{0x92,0x1c,0x25,0xe3,0xde,0xe6,0x32,0x2b}};
extern "C" const GUID __declspec(selectany) CLSID_HMACRIPEMD160 =
    {0x20051d1b,0x321f,0x3e4d,{0xa3,0xda,0x5f,0xbe,0x89,0x2f,0x7e,0xc5}};
extern "C" const GUID __declspec(selectany) CLSID_HMACSHA1 =
    {0x00b01b2e,0xb1fe,0x33a6,{0xad,0x40,0x57,0xde,0x83,0x58,0xdc,0x7d}};
extern "C" const GUID __declspec(selectany) CLSID_HMACSHA256 =
    {0x2c314899,0x8f99,0x3041,{0xa4,0x9d,0x2f,0x6a,0xfc,0x0e,0x62,0x96}};
extern "C" const GUID __declspec(selectany) CLSID_HMACSHA384 =
    {0xae53ed01,0xcab4,0x39ce,{0x85,0x4a,0x8b,0xf5,0x44,0xee,0xec,0x35}};
extern "C" const GUID __declspec(selectany) CLSID_HMACSHA512 =
    {0x477a7d8e,0x8d26,0x3959,{0x88,0xf6,0xf6,0xab,0x7e,0x7f,0x50,0xcf}};
extern "C" const GUID __declspec(selectany) CLSID_CspKeyContainerInfo =
    {0xe5e5b585,0x8a68,0x3f26,{0xbb,0x61,0xf3,0x4e,0xf3,0xad,0x27,0xf8}};
extern "C" const GUID __declspec(selectany) CLSID_MACTripleDES =
    {0x39b68485,0x6773,0x3c46,{0x82,0xe9,0x56,0xd8,0xf0,0xb4,0x57,0x0c}};
extern "C" const GUID __declspec(selectany) CLSID_MD5 =
    {0x668515a6,0x213d,0x377a,{0x8f,0xe4,0x5a,0x1e,0x59,0xa1,0x0a,0xc9}};
extern "C" const GUID __declspec(selectany) CLSID_MD5CryptoServiceProvider =
    {0xd2548bf2,0x801a,0x36af,{0x88,0x00,0x1f,0x11,0xfb,0xf5,0x43,0x61}};
extern "C" const GUID __declspec(selectany) CLSID_MaskGenerationMethod =
    {0xbe1e426e,0x676b,0x3524,{0x9c,0xed,0x21,0xe3,0x06,0xe9,0xb8,0x27}};
extern "C" const GUID __declspec(selectany) CLSID_PasswordDeriveBytes =
    {0xeed31dd9,0xaa11,0x3993,{0x80,0xe0,0x00,0x88,0xc1,0xf5,0xfe,0xba}};
extern "C" const GUID __declspec(selectany) CLSID_PKCS1MaskGenerationMethod =
    {0x7ae844f0,0xeca8,0x3f15,{0xae,0x27,0xaf,0xa2,0x1a,0x2a,0xa6,0xf8}};
extern "C" const GUID __declspec(selectany) CLSID_RC2 =
    {0x1c6dc255,0x62d6,0x3366,{0xbb,0x25,0x01,0xc5,0x09,0x08,0x54,0x73}};
extern "C" const GUID __declspec(selectany) CLSID_RC2CryptoServiceProvider =
    {0x62e92675,0xcb77,0x3fc9,{0x85,0x97,0x1a,0x81,0xa5,0xf1,0x80,0x13}};
extern "C" const GUID __declspec(selectany) CLSID_Rfc2898DeriveBytes =
    {0x7107ab85,0x4c6d,0x3890,{0xaf,0x8a,0x90,0xb2,0xe2,0xd8,0x2f,0x5b}};
extern "C" const GUID __declspec(selectany) CLSID_RIPEMD160 =
    {0x7813009a,0x0f6f,0x3f40,{0xb7,0x3a,0xfa,0xe6,0x19,0x97,0x16,0x19}};
extern "C" const GUID __declspec(selectany) CLSID_RIPEMD160Managed =
    {0x3d367908,0x928f,0x3c13,{0x8b,0x93,0x5e,0x17,0x18,0x82,0x0f,0x6d}};
extern "C" const GUID __declspec(selectany) CLSID_RSA =
    {0x3e39ca4f,0xcd6f,0x3cfe,{0x86,0x59,0x7f,0xdc,0x8d,0x1c,0x9f,0x0b}};
extern "C" const GUID __declspec(selectany) CLSID_RSACryptoServiceProvider =
    {0xd9035152,0x6b1f,0x33e3,{0x86,0xf4,0x41,0x1c,0xd2,0x1c,0xde,0x0e}};
extern "C" const GUID __declspec(selectany) CLSID_RSAOAEPKeyExchangeDeformatter =
    {0x4d187ac2,0xd815,0x3b7e,{0xbc,0xea,0x8e,0x0b,0xbc,0x70,0x2f,0x7c}};
extern "C" const GUID __declspec(selectany) CLSID_RSAOAEPKeyExchangeFormatter =
    {0xa0e2e749,0x63ce,0x3651,{0x8f,0x4f,0xf5,0xf9,0x96,0x34,0x4c,0x32}};
extern "C" const GUID __declspec(selectany) CLSID_RSAPKCS1KeyExchangeDeformatter =
    {0xee96f4e1,0x377e,0x315c,{0xae,0xf5,0x87,0x4d,0xc8,0xc7,0xa2,0xaa}};
extern "C" const GUID __declspec(selectany) CLSID_RSAPKCS1KeyExchangeFormatter =
    {0x92755472,0x2059,0x3f96,{0x89,0x38,0x8a,0xc7,0x67,0xb5,0x18,0x7b}};
extern "C" const GUID __declspec(selectany) CLSID_RSAPKCS1SignatureDeformatter =
    {0x6f674828,0x9081,0x3b45,{0xbc,0x39,0x79,0x1b,0xd8,0x4c,0xcf,0x8f}};
extern "C" const GUID __declspec(selectany) CLSID_RSAPKCS1SignatureFormatter =
    {0x7bc115cd,0x1ee2,0x3068,{0x89,0x4d,0xe3,0xd3,0xf7,0x63,0x2f,0x40}};
extern "C" const GUID __declspec(selectany) CLSID_Rijndael =
    {0x48cbeb8f,0xdb77,0x3103,{0x89,0x9c,0xcd,0x24,0xa8,0x32,0xb5,0xcc}};
extern "C" const GUID __declspec(selectany) CLSID_RijndaelManaged =
    {0x1f9f18a3,0xefc0,0x3913,{0x84,0xa5,0x90,0x67,0x8a,0x4a,0x9a,0x80}};
extern "C" const GUID __declspec(selectany) CLSID_RijndaelManagedTransform =
    {0xfa28c8e8,0x6b89,0x3ec5,{0xac,0x16,0x72,0x0d,0x8e,0x31,0xdc,0x97}};
extern "C" const GUID __declspec(selectany) CLSID_SHA1 =
    {0xeb52b161,0xafb3,0x3dea,{0xbf,0xaf,0xc1,0x83,0xae,0xb5,0x7e,0x56}};
extern "C" const GUID __declspec(selectany) CLSID_SHA1CryptoServiceProvider =
    {0xfc13a7d5,0xe2b3,0x37ba,{0xb8,0x07,0x7f,0xa6,0x23,0x82,0x84,0xd5}};
extern "C" const GUID __declspec(selectany) CLSID_SHA1Managed =
    {0xfdf9c30d,0xccab,0x3e2d,{0xb5,0x84,0x9e,0x24,0xce,0x80,0x38,0xe3}};
extern "C" const GUID __declspec(selectany) CLSID_SHA256 =
    {0xe29b25fc,0x9402,0x3a80,{0xaa,0xa5,0xeb,0x07,0xd9,0xef,0x54,0x88}};
extern "C" const GUID __declspec(selectany) CLSID_SHA256Managed =
    {0x44181b13,0xae94,0x3cfb,{0x81,0xd1,0x37,0xdb,0x59,0x14,0x50,0x30}};
extern "C" const GUID __declspec(selectany) CLSID_SHA384 =
    {0x0c00c2e9,0x7bbe,0x359e,{0x82,0x61,0xfd,0x9b,0x9c,0x88,0x2a,0x15}};
extern "C" const GUID __declspec(selectany) CLSID_SHA384Managed =
    {0x7fd3958d,0x0a14,0x3001,{0x80,0x74,0x0d,0x15,0xea,0xd7,0xf0,0x5c}};
extern "C" const GUID __declspec(selectany) CLSID_SHA512 =
    {0x8de638d4,0x0575,0x3083,{0x9c,0xd7,0x41,0x61,0x9e,0xf9,0xac,0x75}};
extern "C" const GUID __declspec(selectany) CLSID_SHA512Managed =
    {0xa6673c32,0x3943,0x3bbb,{0xb4,0x76,0xc0,0x9a,0x0e,0xc0,0xbc,0xd6}};
extern "C" const GUID __declspec(selectany) CLSID_SignatureDescription =
    {0x3fa7a1c5,0x812c,0x3b56,{0xb9,0x57,0xcb,0x14,0xaf,0x67,0x0c,0x09}};
extern "C" const GUID __declspec(selectany) CLSID_TripleDES =
    {0x3d79ae1a,0xa949,0x3601,{0x97,0x8f,0x02,0xbe,0xa1,0xe7,0x0a,0x98}};
extern "C" const GUID __declspec(selectany) CLSID_TripleDESCryptoServiceProvider =
    {0xdaa132bf,0x1170,0x3d8b,{0xa0,0xef,0xe2,0xf5,0x5a,0x68,0xa9,0x1d}};
extern "C" const GUID __declspec(selectany) CLSID_X509Certificate =
    {0x4c69c54f,0x9824,0x38cc,{0x83,0x87,0xa2,0x2d,0xc6,0x7e,0x0b,0xab}};
extern "C" const GUID __declspec(selectany) IID__Array =
    {0x2b67cece,0x71c3,0x36a9,{0xa1,0x36,0x92,0x5c,0xcc,0x19,0x35,0xa8}};
extern "C" const GUID __declspec(selectany) IID_ICollection =
    {0xde8db6f8,0xd101,0x3a92,{0x8d,0x1c,0xe7,0x2e,0x5f,0x10,0xe9,0x92}};
extern "C" const GUID __declspec(selectany) IID_IDictionary =
    {0x6a6841df,0x3287,0x3d87,{0x80,0x60,0xce,0x0b,0x4c,0x77,0xd2,0xa1}};
extern "C" const GUID __declspec(selectany) IID_IChannelSinkBase =
    {0x308de042,0xacc8,0x32f8,{0xb6,0x32,0x7c,0xb9,0x79,0x9d,0x9a,0xa6}};
extern "C" const GUID __declspec(selectany) IID_IMessage =
    {0x1a8b0de6,0xb825,0x38c5,{0xb7,0x44,0x8f,0x93,0x07,0x5f,0xd6,0xfa}};
extern "C" const GUID __declspec(selectany) IID_IMessageSink =
    {0x941f8aaa,0xa353,0x3b1d,{0xa0,0x19,0x12,0xe4,0x43,0x77,0xf1,0xcd}};
extern "C" const GUID __declspec(selectany) IID_IChannelSender =
    {0x10f1d605,0xe201,0x3145,{0xb7,0xae,0x3a,0xd7,0x46,0x70,0x19,0x86}};
extern "C" const GUID __declspec(selectany) IID_IContributeClientContextSink =
    {0x4db956b7,0x69d0,0x312a,{0xaa,0x75,0x44,0xfb,0x55,0xfd,0x5d,0x4b}};
extern "C" const GUID __declspec(selectany) IID_IContributeServerContextSink =
    {0x0caa23ec,0xf78c,0x39c9,{0x8d,0x25,0xb7,0xa9,0xce,0x40,0x97,0xa7}};
extern "C" const GUID __declspec(selectany) IID_IDynamicMessageSink =
    {0xc74076bb,0x8a2d,0x3c20,{0xa5,0x42,0x62,0x53,0x29,0xe9,0xaf,0x04}};
extern "C" const GUID __declspec(selectany) IID_IContributeDynamicSink =
    {0xa0fe9b86,0x0c06,0x32ce,{0x85,0xfa,0x2f,0xf1,0xb5,0x86,0x97,0xfb}};
extern "C" const GUID __declspec(selectany) IID_IEnvoyInfo =
    {0x2a6e91b9,0xa874,0x38e4,{0x99,0xc2,0xc5,0xd8,0x3d,0x78,0x14,0x0d}};
extern "C" const GUID __declspec(selectany) IID__ValueType =
    {0x139e041d,0x0e41,0x39f5,{0xa3,0x02,0xc4,0x38,0x7e,0x9d,0x0a,0x6c}};
extern "C" const GUID __declspec(selectany) IID__Enum =
    {0xd09d1e04,0xd590,0x39a3,{0xb5,0x17,0xb7,0x34,0xa4,0x9a,0x92,0x77}};
extern "C" const GUID __declspec(selectany) IID__String =
    {0x36936699,0xfc79,0x324d,{0xab,0x43,0xe3,0x3c,0x1f,0x94,0xe2,0x63}};
extern "C" const GUID __declspec(selectany) IID__StringComparer =
    {0x7499e7e8,0xdf01,0x3948,{0xb8,0xd4,0xfa,0x4b,0x96,0x61,0xd3,0x6b}};
extern "C" const GUID __declspec(selectany) IID__StringBuilder =
    {0x9fb09782,0x8d39,0x3b0c,{0xb7,0x9e,0xf7,0xa3,0x7a,0x65,0xb3,0xda}};
extern "C" const GUID __declspec(selectany) IID__SystemException =
    {0x4c482cc2,0x68e9,0x37c6,{0x83,0x53,0x9a,0x94,0xbd,0x2d,0x7f,0x0b}};
extern "C" const GUID __declspec(selectany) IID__OutOfMemoryException =
    {0xcf3edb7e,0x0574,0x3383,{0xa4,0x4f,0x29,0x2f,0x7c,0x14,0x5d,0xb4}};
extern "C" const GUID __declspec(selectany) IID__StackOverflowException =
    {0x9cf4339a,0x2911,0x3b8a,{0x8f,0x30,0xe5,0xc6,0xb5,0xbe,0x9a,0x29}};
extern "C" const GUID __declspec(selectany) IID__DataMisalignedException =
    {0x152a6b4d,0x09af,0x3edf,{0x8c,0xba,0x11,0x79,0x7e,0xee,0xea,0x4e}};
extern "C" const GUID __declspec(selectany) IID__ExecutionEngineException =
    {0xccf0139c,0x79f7,0x3d0a,{0xaf,0xfe,0x2b,0x07,0x62,0xc6,0x5b,0x07}};
extern "C" const GUID __declspec(selectany) IID__MulticastDelegate =
    {0x16fe0885,0x9129,0x3884,{0xa2,0x32,0x90,0xb5,0x8c,0x5b,0x2a,0xa9}};
extern "C" const GUID __declspec(selectany) IID__MemberAccessException =
    {0x7eaba4e2,0x1259,0x3cf2,{0xb0,0x84,0x98,0x54,0x27,0x8e,0x58,0x97}};
extern "C" const GUID __declspec(selectany) IID__AccessViolationException =
    {0x13ef674a,0x6327,0x3caf,{0x87,0x72,0xfa,0x03,0x95,0x61,0x26,0x69}};
extern "C" const GUID __declspec(selectany) IID__ApplicationActivator =
    {0xd1204423,0x01f0,0x336a,{0x89,0x11,0xa7,0xe8,0xfb,0xe1,0x85,0xa3}};
extern "C" const GUID __declspec(selectany) IID__ApplicationException =
    {0xd81130bf,0xd627,0x3b91,{0xa7,0xc7,0xce,0xa5,0x97,0x09,0x34,0x64}};
extern "C" const GUID __declspec(selectany) IID__EventArgs =
    {0x1f9ec719,0x343a,0x3cb3,{0x80,0x40,0x39,0x27,0x62,0x67,0x77,0xc1}};
extern "C" const GUID __declspec(selectany) IID__ResolveEventArgs =
    {0x98947cf0,0x77e7,0x328e,{0xb7,0x09,0x5d,0xd1,0xaa,0x1c,0x9c,0x96}};
extern "C" const GUID __declspec(selectany) IID__AssemblyLoadEventArgs =
    {0x7a0325f0,0x22c2,0x31f9,{0x88,0x23,0x9b,0x8a,0xee,0x94,0x56,0xb1}};
extern "C" const GUID __declspec(selectany) IID__ResolveEventHandler =
    {0x8e54a9cc,0x7aa4,0x34ca,{0x98,0x5b,0xbd,0x7d,0x75,0x27,0xb1,0x10}};
extern "C" const GUID __declspec(selectany) IID__AssemblyLoadEventHandler =
    {0xdeece11f,0xa893,0x3e35,{0xa4,0xc3,0xda,0xb7,0xfa,0x09,0x11,0xeb}};
extern "C" const GUID __declspec(selectany) IID__AppDomainInitializer =
    {0x5e6f9edb,0x3ce1,0x3a56,{0x86,0xd9,0xcd,0x2d,0xdf,0x7a,0x6f,0xff}};
extern "C" const GUID __declspec(selectany) IID__MarshalByRefObject =
    {0x2c358e27,0x8c1a,0x3c03,{0xb0,0x86,0xa4,0x04,0x65,0x62,0x55,0x57}};
extern "C" const GUID __declspec(selectany) IID_IContributeEnvoySink =
    {0x124777b6,0x0308,0x3569,{0x97,0xe5,0xe6,0xfe,0x88,0xea,0xe4,0xeb}};
extern "C" const GUID __declspec(selectany) IID_IContributeObjectSink =
    {0x6a5d38bc,0x2789,0x3546,{0x81,0xa1,0xf1,0x0c,0x0f,0xb5,0x93,0x66}};
extern "C" const GUID __declspec(selectany) IID__CrossAppDomainDelegate =
    {0xaf93163f,0xc2f4,0x3fab,{0x9f,0xf1,0x72,0x8a,0x7a,0xaa,0xd1,0xcb}};
extern "C" const GUID __declspec(selectany) IID__AppDomainManager =
    {0x63e53e04,0xd31b,0x3099,{0x9f,0x0c,0xc7,0xa1,0xc8,0x83,0xc1,0xd9}};
extern "C" const GUID __declspec(selectany) IID__LoaderOptimizationAttribute =
    {0xce59d7ad,0x05ca,0x33b4,{0xa1,0xdd,0x06,0x02,0x8d,0x46,0xe9,0xd2}};
extern "C" const GUID __declspec(selectany) IID__AppDomainUnloadedException =
    {0x6e96aa70,0x9ffb,0x399d,{0x96,0xbf,0xa6,0x84,0x36,0x09,0x5c,0x54}};
extern "C" const GUID __declspec(selectany) IID__ActivationArguments =
    {0xcfd9ca27,0xf0ba,0x388a,{0xac,0xde,0xb7,0xe2,0x0f,0xca,0xd7,0x9c}};
extern "C" const GUID __declspec(selectany) IID__ApplicationId =
    {0x2f218f95,0x4215,0x3cc6,{0x8a,0x51,0xbd,0x27,0x70,0xc0,0x90,0xe4}};
extern "C" const GUID __declspec(selectany) IID__ArgumentException =
    {0x4db2c2b7,0xcbc2,0x3185,{0xb9,0x66,0x87,0x5d,0x46,0x25,0xb1,0xa8}};
extern "C" const GUID __declspec(selectany) IID__ArgumentNullException =
    {0xc991949b,0xe623,0x3f24,{0x88,0x5c,0xbb,0xb0,0x1f,0xf4,0x35,0x64}};
extern "C" const GUID __declspec(selectany) IID__ArgumentOutOfRangeException =
    {0x77da3028,0xbc45,0x3e82,{0xbf,0x76,0x2c,0x12,0x3e,0xe2,0xc0,0x21}};
extern "C" const GUID __declspec(selectany) IID__ArithmeticException =
    {0x9b012cf1,0xacf6,0x3389,{0xa3,0x36,0xc0,0x23,0x04,0x0c,0x62,0xa2}};
extern "C" const GUID __declspec(selectany) IID__ArrayTypeMismatchException =
    {0xdd7488a6,0x1b3f,0x3823,{0x95,0x56,0xc2,0x77,0x2b,0x15,0x15,0x0f}};
extern "C" const GUID __declspec(selectany) IID__AsyncCallback =
    {0x3612706e,0x0239,0x35fd,{0xb9,0x00,0x08,0x19,0xd1,0x6d,0x44,0x2d}};
extern "C" const GUID __declspec(selectany) IID__AttributeUsageAttribute =
    {0xa902a192,0x49ba,0x3ec8,{0xb4,0x44,0xaf,0x5f,0x77,0x43,0xf6,0x1a}};
extern "C" const GUID __declspec(selectany) IID__BadImageFormatException =
    {0xf98bce04,0x4a4b,0x398c,{0xa5,0x12,0xfd,0x83,0x48,0xd5,0x1e,0x3b}};
extern "C" const GUID __declspec(selectany) IID__Buffer =
    {0xf036bca4,0xf8df,0x3682,{0x82,0x90,0x75,0x28,0x5c,0xe7,0x45,0x6c}};
extern "C" const GUID __declspec(selectany) IID__CannotUnloadAppDomainException =
    {0x6d4b6adb,0xb9fa,0x3809,{0xb5,0xea,0xfa,0x57,0xb5,0x6c,0x54,0x6f}};
extern "C" const GUID __declspec(selectany) IID__CharEnumerator =
    {0x1dd627fc,0x89e3,0x384f,{0xbb,0x9d,0x58,0xcb,0x4e,0xfb,0x94,0x56}};
extern "C" const GUID __declspec(selectany) IID__CLSCompliantAttribute =
    {0xbf1af177,0x94ca,0x3e6d,{0x9d,0x91,0x55,0xcf,0x9e,0x85,0x9d,0x22}};
extern "C" const GUID __declspec(selectany) IID__TypeUnloadedException =
    {0xc2a10f3a,0x356a,0x3c77,{0xaa,0xb9,0x89,0x91,0xd7,0x3a,0x25,0x61}};
extern "C" const GUID __declspec(selectany) IID__CriticalFinalizerObject =
    {0x6b3f9834,0x1725,0x38c5,{0x95,0x5e,0x20,0xf0,0x51,0xd0,0x67,0xbd}};
extern "C" const GUID __declspec(selectany) IID__ContextMarshalException =
    {0x7386f4d7,0x7c11,0x389f,{0xbb,0x75,0x89,0x57,0x14,0xb1,0x2b,0xb5}};
extern "C" const GUID __declspec(selectany) IID__ContextBoundObject =
    {0x3eb1d909,0xe8bf,0x3c6b,{0xad,0xa5,0x0e,0x86,0xe3,0x1e,0x18,0x6e}};
extern "C" const GUID __declspec(selectany) IID__ContextStaticAttribute =
    {0x160d517f,0xf175,0x3b61,{0x82,0x64,0x6d,0x23,0x05,0xb8,0x24,0x6c}};
extern "C" const GUID __declspec(selectany) IID__TimeZone =
    {0x3025f666,0x7891,0x33d7,{0xaa,0xcd,0x23,0xd1,0x69,0xef,0x35,0x4e}};
extern "C" const GUID __declspec(selectany) IID__DBNull =
    {0x0d9f1b65,0x6d27,0x3e9f,{0xba,0xf3,0x05,0x97,0x83,0x7e,0x0f,0x33}};
extern "C" const GUID __declspec(selectany) IID__DivideByZeroException =
    {0xbdeea460,0x8241,0x3b41,{0x9e,0xd3,0x6e,0x3e,0x99,0x77,0xac,0x7f}};
extern "C" const GUID __declspec(selectany) IID__DuplicateWaitObjectException =
    {0xd345a42b,0xcfe0,0x3eee,{0x86,0x1c,0xf3,0x32,0x28,0x12,0xb3,0x88}};
extern "C" const GUID __declspec(selectany) IID__TypeLoadException =
    {0x82d6b3bf,0xa633,0x3b3b,{0xa0,0x9e,0x23,0x63,0xe4,0xb2,0x4a,0x41}};
extern "C" const GUID __declspec(selectany) IID__EntryPointNotFoundException =
    {0x67388f3f,0xb600,0x3bcf,{0x84,0xaa,0xbb,0x2b,0x88,0xdd,0x9e,0xe2}};
extern "C" const GUID __declspec(selectany) IID__DllNotFoundException =
    {0x24ae6464,0x2834,0x32cd,{0x83,0xd6,0xfa,0x06,0x95,0x3d,0xe6,0x2a}};
extern "C" const GUID __declspec(selectany) IID__Environment =
    {0x29dc56cf,0xb981,0x3432,{0x97,0xc8,0x36,0x80,0xab,0x6d,0x86,0x2d}};
extern "C" const GUID __declspec(selectany) IID__EventHandler =
    {0x7cefc46e,0x16e0,0x3e65,{0x9c,0x38,0x55,0xb4,0x34,0x2b,0xa7,0xf0}};
extern "C" const GUID __declspec(selectany) IID__FieldAccessException =
    {0x8d5f5811,0xffa1,0x3306,{0x93,0xe3,0x8a,0xfc,0x57,0x2b,0x9b,0x82}};
extern "C" const GUID __declspec(selectany) IID__FlagsAttribute =
    {0xebe3746d,0xddec,0x3d23,{0x8e,0x8d,0x93,0x61,0xba,0x87,0xba,0xc6}};
extern "C" const GUID __declspec(selectany) IID__FormatException =
    {0x07f92156,0x398a,0x3548,{0x90,0xb7,0x2e,0x58,0x02,0x63,0x53,0xd0}};
extern "C" const GUID __declspec(selectany) IID__IndexOutOfRangeException =
    {0xe5a5f1e4,0x82c1,0x391f,{0xa1,0xc6,0xf3,0x9e,0xae,0x9d,0xc7,0x2f}};
extern "C" const GUID __declspec(selectany) IID__InvalidCastException =
    {0xfa047cbd,0x9ba5,0x3a13,{0x9b,0x1f,0x66,0x94,0xd6,0x22,0xcd,0x76}};
extern "C" const GUID __declspec(selectany) IID__InvalidOperationException =
    {0x8d520d10,0x0b8a,0x3553,{0x88,0x74,0xd3,0x0a,0x4a,0xd2,0xff,0x4c}};
extern "C" const GUID __declspec(selectany) IID__InvalidProgramException =
    {0x3410e0fb,0x636f,0x3cd1,{0x80,0x45,0x39,0x93,0xca,0x11,0x3f,0x25}};
extern "C" const GUID __declspec(selectany) IID__LocalDataStoreSlot =
    {0xdc77f976,0x318d,0x3a1a,{0x9b,0x60,0xab,0xb9,0xdd,0x94,0x06,0xd6}};
extern "C" const GUID __declspec(selectany) IID__MethodAccessException =
    {0xff0bf77d,0x8f81,0x3d31,{0xa3,0xbb,0x6f,0x54,0x44,0x0f,0xa7,0xe5}};
extern "C" const GUID __declspec(selectany) IID__MissingMemberException =
    {0x8897d14b,0x7fb3,0x3d8b,{0x9e,0xe4,0x22,0x1c,0x3d,0xba,0xd6,0xfe}};
extern "C" const GUID __declspec(selectany) IID__MissingFieldException =
    {0x9717176d,0x1179,0x3487,{0x88,0x49,0xcf,0x5f,0x63,0xde,0x35,0x6e}};
extern "C" const GUID __declspec(selectany) IID__MissingMethodException =
    {0xe5c659f6,0x92c8,0x3887,{0xa0,0x7e,0x74,0xd0,0xd9,0xc6,0x26,0x7a}};
extern "C" const GUID __declspec(selectany) IID__MulticastNotSupportedException =
    {0xd2ba71cc,0x1b3d,0x3966,{0xa0,0xd7,0xc6,0x1e,0x95,0x7a,0xd3,0x25}};
extern "C" const GUID __declspec(selectany) IID__NonSerializedAttribute =
    {0x665c9669,0xb9c6,0x3add,{0x92,0x13,0x09,0x9f,0x01,0x27,0xc8,0x93}};
extern "C" const GUID __declspec(selectany) IID__NotFiniteNumberException =
    {0x8e21ce22,0x4f17,0x347b,{0xb3,0xb5,0x6a,0x6d,0xf3,0xe0,0xe5,0x8a}};
extern "C" const GUID __declspec(selectany) IID__NotImplementedException =
    {0x1e4d31a2,0x63ea,0x397a,{0xa7,0x7e,0xb2,0x0a,0xd8,0x7a,0x96,0x14}};
extern "C" const GUID __declspec(selectany) IID__NotSupportedException =
    {0x40e5451f,0xb237,0x33f8,{0x94,0x5b,0x02,0x30,0xdb,0x70,0x0b,0xbb}};
extern "C" const GUID __declspec(selectany) IID__NullReferenceException =
    {0xecbe2313,0xcf41,0x34b4,{0x9f,0xd0,0xb6,0xcd,0x60,0x2b,0x02,0x3f}};
extern "C" const GUID __declspec(selectany) IID__ObjectDisposedException =
    {0x17b730ba,0x45ef,0x3ddf,{0x9f,0x8d,0xa4,0x90,0xba,0xc7,0x31,0xf4}};
extern "C" const GUID __declspec(selectany) IID__ObsoleteAttribute =
    {0xe84307be,0x3036,0x307a,{0xac,0xc2,0x5d,0x5d,0xe8,0xa0,0x06,0xa8}};
extern "C" const GUID __declspec(selectany) IID__OperatingSystem =
    {0x9e230640,0xa5d0,0x30e1,{0xb2,0x17,0x9d,0x2b,0x6c,0xc0,0xfc,0x40}};
extern "C" const GUID __declspec(selectany) IID__OperationCanceledException =
    {0x9df9af5a,0x7853,0x3d55,{0x9b,0x48,0xbd,0x1f,0x5d,0x83,0x67,0xab}};
extern "C" const GUID __declspec(selectany) IID__OverflowException =
    {0x37c69a5d,0x7619,0x3a0f,{0xa9,0x6b,0x9c,0x95,0x78,0xae,0x00,0xef}};
extern "C" const GUID __declspec(selectany) IID__ParamArrayAttribute =
    {0xd54500ae,0x8cf4,0x3092,{0x90,0x54,0x90,0xdc,0x91,0xac,0x65,0xc9}};
extern "C" const GUID __declspec(selectany) IID__PlatformNotSupportedException =
    {0x1eb8340b,0x8190,0x3d9d,{0x92,0xf8,0x51,0x24,0x4b,0x98,0x04,0xc5}};
extern "C" const GUID __declspec(selectany) IID__Random =
    {0x0f240708,0x629a,0x31ab,{0x94,0xa5,0x2b,0xb4,0x76,0xfe,0x17,0x83}};
extern "C" const GUID __declspec(selectany) IID__RankException =
    {0x871ddc46,0xb68e,0x3fee,{0xa0,0x9a,0xc8,0x08,0xb0,0xf8,0x27,0xe6}};
extern "C" const GUID __declspec(selectany) IID__SerializableAttribute =
    {0x1b96e53c,0x4028,0x38bc,{0x9d,0xc3,0x8d,0x7a,0x95,0x55,0xc3,0x11}};
extern "C" const GUID __declspec(selectany) IID__TimeoutException =
    {0x7ab88ca9,0x17f4,0x385e,{0xad,0x41,0x4e,0xe0,0xaa,0x31,0x6f,0xa1}};
extern "C" const GUID __declspec(selectany) IID__TypeInitializationException =
    {0xfeb0323d,0x8ce4,0x36a4,{0xa4,0x1e,0x0b,0xa0,0xc3,0x2e,0x1a,0x6a}};
extern "C" const GUID __declspec(selectany) IID__UnauthorizedAccessException =
    {0x6193c5f6,0x6807,0x3561,{0xa7,0xf3,0xb6,0x4c,0x80,0xb5,0xf0,0x0f}};
extern "C" const GUID __declspec(selectany) IID__UnhandledExceptionEventArgs =
    {0xa218e20a,0x0905,0x3741,{0xb0,0xb3,0x9e,0x31,0x93,0x16,0x2e,0x50}};
extern "C" const GUID __declspec(selectany) IID__UnhandledExceptionEventHandler =
    {0x84199e64,0x439c,0x3011,{0xb2,0x49,0x3c,0x90,0x65,0x73,0x5a,0xdb}};
extern "C" const GUID __declspec(selectany) IID__Version =
    {0x011a90c5,0x4910,0x3c29,{0xbb,0xb7,0x50,0xd0,0x5c,0xcb,0xaa,0x4a}};
extern "C" const GUID __declspec(selectany) IID__WeakReference =
    {0xc5df3568,0xc251,0x3c58,{0xaf,0xb4,0x32,0xe7,0x9e,0x82,0x61,0xf0}};
extern "C" const GUID __declspec(selectany) IID__WaitHandle =
    {0x40dfc50a,0xe93a,0x3c08,{0xb9,0xef,0xe2,0xb4,0xf2,0x8b,0x56,0x76}};
extern "C" const GUID __declspec(selectany) IID_IAsyncResult =
    {0x11ab34e7,0x0176,0x3c9e,{0x9e,0xfe,0x19,0x78,0x58,0x40,0x0a,0x3d}};
extern "C" const GUID __declspec(selectany) IID__EventWaitHandle =
    {0xe142db4a,0x1a52,0x34ce,{0x96,0x5e,0x13,0xaf,0xfd,0x54,0x47,0xd0}};
extern "C" const GUID __declspec(selectany) IID__AutoResetEvent =
    {0x3f243ebd,0x612f,0x3db8,{0x9e,0x03,0xbd,0x92,0x34,0x3a,0x83,0x71}};
extern "C" const GUID __declspec(selectany) IID__ContextCallback =
    {0x56d201f1,0x3e5d,0x39d9,{0xb5,0xde,0x06,0x47,0x10,0x81,0x89,0x05}};
extern "C" const GUID __declspec(selectany) IID__ManualResetEvent =
    {0xc0bb9361,0x268f,0x3e72,{0xbf,0x6f,0x41,0x20,0x17,0x5a,0x15,0x00}};
extern "C" const GUID __declspec(selectany) IID__Monitor =
    {0xee22485e,0x4c45,0x3c9d,{0x90,0x27,0xa8,0xd6,0x1c,0x5f,0x53,0xf2}};
extern "C" const GUID __declspec(selectany) IID__Mutex =
    {0x36cb559b,0x87c6,0x3ad2,{0x92,0x25,0x62,0xa7,0xed,0x49,0x9b,0x37}};
extern "C" const GUID __declspec(selectany) IID__Overlapped =
    {0xdd846fcc,0x8d04,0x3665,{0x81,0xb6,0xaa,0xcb,0xe9,0x9c,0x19,0xc3}};
extern "C" const GUID __declspec(selectany) IID__ReaderWriterLock =
    {0xad89b568,0x4fd4,0x3f8d,{0x83,0x27,0xb3,0x96,0xb2,0x0a,0x46,0x0e}};
extern "C" const GUID __declspec(selectany) IID__SynchronizationLockException =
    {0x87f55344,0x17e0,0x30fd,{0x8e,0xb9,0x38,0xea,0xf6,0xa1,0x9b,0x3f}};
extern "C" const GUID __declspec(selectany) IID__ThreadAbortException =
    {0x95b525db,0x6b81,0x3cdc,{0x8f,0xe7,0x71,0x3f,0x7f,0xc7,0x93,0xc0}};
extern "C" const GUID __declspec(selectany) IID__ThreadInterruptedException =
    {0xb9e07599,0x7c44,0x33be,{0xa7,0x0e,0xef,0xa1,0x6f,0x51,0xf5,0x4a}};
extern "C" const GUID __declspec(selectany) IID__RegisteredWaitHandle =
    {0x64409425,0xf8c9,0x370e,{0x80,0x9e,0x32,0x41,0xce,0x80,0x45,0x41}};
extern "C" const GUID __declspec(selectany) IID__WaitCallback =
    {0xce949142,0x4d4c,0x358d,{0x89,0xa9,0xe6,0x9a,0x53,0x1a,0xa3,0x63}};
extern "C" const GUID __declspec(selectany) IID__WaitOrTimerCallback =
    {0xf078f795,0xf452,0x3d2d,{0x8c,0xc8,0x16,0xd6,0x6a,0xe4,0x6c,0x67}};
extern "C" const GUID __declspec(selectany) IID__IOCompletionCallback =
    {0xbbae942d,0xbff4,0x36e2,{0xa3,0xbc,0x50,0x8b,0xb3,0x80,0x1f,0x4f}};
extern "C" const GUID __declspec(selectany) IID__ThreadStart =
    {0xb45bbd7e,0xa977,0x3f56,{0xa6,0x26,0x7a,0x69,0x3e,0x5d,0xbb,0xc5}};
extern "C" const GUID __declspec(selectany) IID__ThreadStateException =
    {0xa13a41cf,0xe066,0x3b90,{0x82,0xf4,0x73,0x10,0x91,0x04,0xe3,0x48}};
extern "C" const GUID __declspec(selectany) IID__ThreadStaticAttribute =
    {0xa6b94b6d,0x854e,0x3172,{0xa4,0xec,0xa1,0x7e,0xdd,0x16,0xf8,0x5e}};
extern "C" const GUID __declspec(selectany) IID__Timeout =
    {0x81456e86,0x22af,0x31d1,{0xa9,0x1a,0x9c,0x37,0x0c,0x0e,0x25,0x30}};
extern "C" const GUID __declspec(selectany) IID__TimerCallback =
    {0x3741bc6f,0x101b,0x36d7,{0xa9,0xd5,0x03,0xfc,0xc0,0xec,0xda,0x35}};
extern "C" const GUID __declspec(selectany) IID__Timer =
    {0xb49a029b,0x406b,0x3b1e,{0x88,0xe4,0xf8,0x66,0x90,0xd2,0x03,0x64}};
extern "C" const GUID __declspec(selectany) IID__STAThreadAttribute =
    {0x85d72f83,0xbe91,0x3cb1,{0xb4,0xf0,0x76,0xb5,0x6f,0xf0,0x40,0x33}};
extern "C" const GUID __declspec(selectany) IID__MTAThreadAttribute =
    {0xc02468d1,0x8713,0x3225,{0xbd,0xa3,0x49,0xb2,0xfe,0x37,0xdd,0xbb}};
extern "C" const GUID __declspec(selectany) IID__ArrayList =
    {0x401f89cb,0xc127,0x3041,{0x82,0xfd,0xb6,0x70,0x35,0x39,0x5c,0x56}};
extern "C" const GUID __declspec(selectany) IID__BitArray =
    {0xf145c46a,0xd170,0x3170,{0xb5,0x2f,0x46,0x78,0xdf,0xca,0x03,0x00}};
extern "C" const GUID __declspec(selectany) IID__CaseInsensitiveComparer =
    {0xea6795ac,0x97d6,0x3377,{0xbe,0x64,0x82,0x9a,0xbd,0x67,0x60,0x7b}};
extern "C" const GUID __declspec(selectany) IID__CaseInsensitiveHashCodeProvider =
    {0x0422b845,0xb636,0x3688,{0x8f,0x61,0x9b,0x6d,0x93,0x09,0x63,0x36}};
extern "C" const GUID __declspec(selectany) IID__CollectionBase =
    {0xb7d29e26,0x7798,0x3fa4,{0x90,0xf4,0xe6,0xa2,0x2d,0x20,0x99,0xf9}};
extern "C" const GUID __declspec(selectany) IID__Comparer =
    {0x8064a157,0xb5c8,0x3a4a,{0xad,0x3d,0x02,0xdc,0x1a,0x39,0xc4,0x17}};
extern "C" const GUID __declspec(selectany) IID__DictionaryBase =
    {0xddd44da2,0xbc6b,0x3620,{0x93,0x17,0xc0,0x37,0x29,0x68,0xc7,0x41}};
extern "C" const GUID __declspec(selectany) IID__Hashtable =
    {0xd25a197e,0x3e69,0x3271,{0xa9,0x89,0x23,0xd8,0x5e,0x97,0xf9,0x20}};
extern "C" const GUID __declspec(selectany) IID__Queue =
    {0x3a7d3ca4,0xb7d1,0x3a2a,{0x80,0x0c,0x8f,0xc2,0xac,0xfc,0xbd,0xa4}};
extern "C" const GUID __declspec(selectany) IID__ReadOnlyCollectionBase =
    {0xbd32d878,0xa59b,0x3e5c,{0xbf,0xe0,0xa9,0x6b,0x1a,0x1e,0x9d,0x6f}};
extern "C" const GUID __declspec(selectany) IID__SortedList =
    {0x56421139,0xa143,0x3ae9,{0x98,0x52,0x1d,0xbd,0xfe,0x3d,0x6b,0xfa}};
extern "C" const GUID __declspec(selectany) IID__Stack =
    {0xab538809,0x3c2f,0x35d9,{0x80,0xe6,0x7b,0xad,0x54,0x04,0x84,0xa1}};
extern "C" const GUID __declspec(selectany) IID__Nullable =
    {0x84e7ac09,0x795a,0x3ea9,{0xa3,0x6a,0x5b,0x81,0xeb,0xab,0x05,0x58}};
extern "C" const GUID __declspec(selectany) IID__KeyNotFoundException =
    {0x8039c41f,0x4399,0x38a2,{0x99,0xb7,0xd2,0x34,0xb5,0xcf,0x7a,0x7b}};
extern "C" const GUID __declspec(selectany) IID__ConditionalAttribute =
    {0xe40a025c,0x645b,0x3c8e,{0xa1,0xac,0x9c,0x5c,0xca,0x27,0x96,0x25}};
extern "C" const GUID __declspec(selectany) IID__Debugger =
    {0xa9b4786c,0x08e3,0x344f,{0xa6,0x51,0x2f,0x99,0x26,0xde,0xac,0x5e}};
extern "C" const GUID __declspec(selectany) IID__DebuggerStepThroughAttribute =
    {0x3344e8b4,0xa5c3,0x3882,{0x8d,0x30,0x63,0x79,0x24,0x85,0xec,0xcf}};
extern "C" const GUID __declspec(selectany) IID__DebuggerStepperBoundaryAttribute =
    {0xb3276180,0xb23e,0x3034,{0xb1,0x8f,0xe0,0x12,0x2b,0xa4,0xe4,0xcf}};
extern "C" const GUID __declspec(selectany) IID__DebuggerHiddenAttribute =
    {0x55b6903b,0x55fe,0x35e0,{0x80,0x4f,0xe4,0x2a,0x09,0x6d,0x2e,0xb0}};
extern "C" const GUID __declspec(selectany) IID__DebuggerNonUserCodeAttribute =
    {0xcc6dcafd,0x0185,0x308a,{0x89,0x1c,0x83,0x81,0x2f,0xe5,0x74,0xe7}};
extern "C" const GUID __declspec(selectany) IID__DebuggableAttribute =
    {0x428e3627,0x2b1f,0x302c,{0xa7,0xe6,0x63,0x88,0xcd,0x53,0x5e,0x75}};
extern "C" const GUID __declspec(selectany) IID__DebuggerBrowsableAttribute =
    {0xa3fc6319,0x7355,0x3d7d,{0x86,0x21,0xb5,0x98,0x56,0x11,0x52,0xfc}};
extern "C" const GUID __declspec(selectany) IID__DebuggerTypeProxyAttribute =
    {0x404fafdd,0x1e3f,0x3602,{0xbf,0xf6,0x75,0x5c,0x00,0x61,0x3e,0xd8}};
extern "C" const GUID __declspec(selectany) IID__DebuggerDisplayAttribute =
    {0x22fdabc0,0xeec7,0x33e0,{0xb4,0xf2,0xf3,0xb7,0x39,0xe1,0x9a,0x5e}};
extern "C" const GUID __declspec(selectany) IID__DebuggerVisualizerAttribute =
    {0xe19ea1a2,0x67ff,0x31a5,{0xb9,0x5c,0xe0,0xb7,0x53,0x40,0x3f,0x6b}};
extern "C" const GUID __declspec(selectany) IID__StackTrace =
    {0x9a2669ec,0xff84,0x3726,{0x89,0xa0,0x66,0x3a,0x3e,0xf3,0xb5,0xcd}};
extern "C" const GUID __declspec(selectany) IID__StackFrame =
    {0x0e9b8e47,0xca67,0x38b6,{0xb9,0xdb,0x2c,0x42,0xee,0x75,0x7b,0x08}};
extern "C" const GUID __declspec(selectany) IID__SymDocumentType =
    {0x5141d79c,0x7b01,0x37da,{0xb7,0xe9,0x53,0xe5,0xa2,0x71,0xba,0xf8}};
extern "C" const GUID __declspec(selectany) IID__SymLanguageType =
    {0x22bb8891,0xfd21,0x313d,{0x92,0xe4,0x8a,0x89,0x2d,0xc0,0xb3,0x9c}};
extern "C" const GUID __declspec(selectany) IID__SymLanguageVendor =
    {0x01364e7b,0xc983,0x3651,{0xb7,0xd8,0xfd,0x1b,0x64,0xfc,0x0e,0x00}};
extern "C" const GUID __declspec(selectany) IID__AmbiguousMatchException =
    {0x81aa0d59,0xc3b1,0x36a3,{0xb2,0xe7,0x05,0x49,0x28,0xfb,0xfc,0x1a}};
extern "C" const GUID __declspec(selectany) IID__ModuleResolveEventHandler =
    {0x05532e88,0xe0f2,0x3263,{0x9b,0x57,0x80,0x5a,0xc6,0xb6,0xbb,0x72}};
extern "C" const GUID __declspec(selectany) IID__AssemblyCopyrightAttribute =
    {0x6163f792,0x3cd6,0x38f1,{0xb5,0xf7,0x00,0x0b,0x96,0xa5,0x08,0x2b}};
extern "C" const GUID __declspec(selectany) IID__AssemblyTrademarkAttribute =
    {0x64c26bf9,0xc9e5,0x3f66,{0xad,0x74,0xbe,0xba,0xad,0xe3,0x62,0x14}};
extern "C" const GUID __declspec(selectany) IID__AssemblyProductAttribute =
    {0xde10d587,0xa188,0x3dcb,{0x80,0x00,0x92,0xdf,0xdb,0x9b,0x80,0x21}};
extern "C" const GUID __declspec(selectany) IID__AssemblyCompanyAttribute =
    {0xc6802233,0xef82,0x3c91,{0xad,0x72,0xb3,0xa5,0xd7,0x23,0x0e,0xd5}};
extern "C" const GUID __declspec(selectany) IID__AssemblyDescriptionAttribute =
    {0x6b2c0bc4,0xddb7,0x38ea,{0x8a,0x86,0xf0,0xb5,0x9e,0x19,0x28,0x16}};
extern "C" const GUID __declspec(selectany) IID__AssemblyTitleAttribute =
    {0xdf44cad3,0xcef2,0x36a9,{0xb0,0x13,0x38,0x3c,0xc0,0x31,0x77,0xd7}};
extern "C" const GUID __declspec(selectany) IID__AssemblyConfigurationAttribute =
    {0x746d1d1e,0xee37,0x393b,{0xb6,0xfa,0xe3,0x87,0xd3,0x75,0x53,0xaa}};
extern "C" const GUID __declspec(selectany) IID__AssemblyDefaultAliasAttribute =
    {0x04311d35,0x75ec,0x347b,{0xbe,0xdf,0x96,0x94,0x87,0xce,0x40,0x14}};
extern "C" const GUID __declspec(selectany) IID__AssemblyInformationalVersionAttribute =
    {0xc6f5946c,0x143a,0x3747,{0xa7,0xc0,0xab,0xfa,0xda,0x6b,0xde,0xb7}};
extern "C" const GUID __declspec(selectany) IID__AssemblyFileVersionAttribute =
    {0xb101fe3c,0x4479,0x311a,{0xa9,0x45,0x12,0x25,0xee,0x17,0x31,0xe8}};
extern "C" const GUID __declspec(selectany) IID__AssemblyCultureAttribute =
    {0x177c4e63,0x9e0b,0x354d,{0x83,0x8b,0xb5,0x2a,0xa8,0x68,0x3e,0xf6}};
extern "C" const GUID __declspec(selectany) IID__AssemblyVersionAttribute =
    {0xa1693c5c,0x101f,0x3557,{0x94,0xdb,0xc4,0x80,0xce,0xb4,0xc1,0x6b}};
extern "C" const GUID __declspec(selectany) IID__AssemblyKeyFileAttribute =
    {0xa9fcda18,0xc237,0x3c6f,{0xa6,0xef,0x74,0x9b,0xe2,0x2b,0xa2,0xbf}};
extern "C" const GUID __declspec(selectany) IID__AssemblyDelaySignAttribute =
    {0x6cf1c077,0xc974,0x38e1,{0x90,0xa4,0x97,0x6e,0x48,0x35,0xe1,0x65}};
extern "C" const GUID __declspec(selectany) IID__AssemblyAlgorithmIdAttribute =
    {0x57b849aa,0xd8ef,0x3ea6,{0x95,0x38,0xc5,0xb4,0xd4,0x98,0xc2,0xf7}};
extern "C" const GUID __declspec(selectany) IID__AssemblyFlagsAttribute =
    {0x0ecd8635,0xf5eb,0x3e4a,{0x89,0x89,0x4d,0x68,0x4d,0x67,0xc4,0x8a}};
extern "C" const GUID __declspec(selectany) IID__AssemblyKeyNameAttribute =
    {0x322a304d,0x11ac,0x3814,{0xa9,0x05,0xa0,0x19,0xf6,0xe3,0xda,0xe9}};
extern "C" const GUID __declspec(selectany) IID__AssemblyNameProxy =
    {0xfe52f19a,0x8aa8,0x309c,{0xbf,0x99,0x9d,0x0a,0x56,0x6f,0xb7,0x6a}};
extern "C" const GUID __declspec(selectany) IID__CustomAttributeFormatException =
    {0x1660eb67,0xee41,0x363e,{0xbe,0xb0,0xc2,0xde,0x09,0x21,0x4a,0xbf}};
extern "C" const GUID __declspec(selectany) IID__CustomAttributeData =
    {0xf4e5539d,0x0a65,0x3073,{0xbf,0x27,0x8d,0xce,0x8e,0xf1,0xde,0xf1}};
extern "C" const GUID __declspec(selectany) IID__DefaultMemberAttribute =
    {0xc462b072,0xfe6e,0x3bdc,{0x9f,0xab,0x4c,0xdb,0xfc,0xbc,0xd1,0x24}};
extern "C" const GUID __declspec(selectany) IID__InvalidFilterCriteriaException =
    {0xe6df0ae7,0xba15,0x3f80,{0x8a,0xfa,0x27,0x77,0x3a,0xe4,0x14,0xfc}};
extern "C" const GUID __declspec(selectany) IID__ManifestResourceInfo =
    {0x3188878c,0xdeb3,0x3558,{0x80,0xe8,0x84,0xe9,0xed,0x95,0xf9,0x2c}};
extern "C" const GUID __declspec(selectany) IID__MemberFilter =
    {0xfae5d9b7,0x40c1,0x3de1,{0xbe,0x06,0xa9,0x1c,0x9d,0xa1,0xba,0x9f}};
extern "C" const GUID __declspec(selectany) IID__Missing =
    {0x0c48f55d,0x5240,0x30c7,{0xa8,0xf1,0xaf,0x87,0xa6,0x40,0xce,0xfe}};
extern "C" const GUID __declspec(selectany) IID__ObfuscateAssemblyAttribute =
    {0x8a5f0da2,0x7b43,0x3767,{0xb6,0x23,0x24,0x24,0xcf,0x7c,0xd2,0x68}};
extern "C" const GUID __declspec(selectany) IID__ObfuscationAttribute =
    {0x71fb8dcf,0x3fa7,0x3483,{0x84,0x64,0x9d,0x82,0x00,0xe5,0x7c,0x43}};
extern "C" const GUID __declspec(selectany) IID__ExceptionHandlingClause =
    {0x643a4016,0x1b16,0x3ccf,{0xae,0x86,0x9c,0x2d,0x91,0x35,0xec,0xb0}};
extern "C" const GUID __declspec(selectany) IID__MethodBody =
    {0xb072efe2,0xc943,0x3977,{0xbf,0xd9,0x91,0xd5,0x23,0x2b,0x0d,0x53}};
extern "C" const GUID __declspec(selectany) IID__LocalVariableInfo =
    {0xf2ecd8ca,0x91a2,0x31e8,{0xb8,0x08,0xe0,0x28,0xb4,0xf5,0xca,0x67}};
extern "C" const GUID __declspec(selectany) IID__Pointer =
    {0xf0deafe9,0x5eba,0x3737,{0x99,0x50,0xc1,0x79,0x57,0x39,0xcd,0xcd}};
extern "C" const GUID __declspec(selectany) IID__ReflectionTypeLoadException =
    {0x22c26a41,0x5fa3,0x34e3,{0xa7,0x6f,0xba,0x48,0x02,0x52,0xd8,0xec}};
extern "C" const GUID __declspec(selectany) IID__StrongNameKeyPair =
    {0xfc4963cb,0xe52b,0x32d8,{0xa4,0x18,0xd0,0x58,0xfa,0x51,0xa1,0xfa}};
extern "C" const GUID __declspec(selectany) IID__TargetException =
    {0x98b1524d,0xda12,0x3c4b,{0x8a,0x69,0x75,0x39,0xa6,0xde,0xc4,0xfa}};
extern "C" const GUID __declspec(selectany) IID__TargetInvocationException =
    {0xa90106ed,0x9099,0x3329,{0x8a,0x5a,0x20,0x44,0xb3,0xd8,0x55,0x2b}};
extern "C" const GUID __declspec(selectany) IID__TargetParameterCountException =
    {0x6032b3cd,0x9bed,0x351c,{0xa1,0x45,0x9d,0x50,0x0b,0x0f,0x63,0x6f}};
extern "C" const GUID __declspec(selectany) IID__TypeDelegator =
    {0x34e00ef9,0x83e2,0x3bbc,{0xb6,0xaf,0x4c,0xae,0x70,0x38,0x38,0xbd}};
extern "C" const GUID __declspec(selectany) IID__TypeFilter =
    {0xe1817846,0x3745,0x3c97,{0xb4,0xa6,0xee,0x20,0xa1,0x64,0x1b,0x29}};
extern "C" const GUID __declspec(selectany) IID__Formatter =
    {0xd9bd3c8d,0x9395,0x3657,{0xb6,0xee,0xd1,0xb5,0x09,0xc3,0x8b,0x70}};
extern "C" const GUID __declspec(selectany) IID__FormatterConverter =
    {0x3faa35ee,0xc867,0x3e2e,{0xbf,0x48,0x2d,0xa2,0x71,0xf8,0x83,0x03}};
extern "C" const GUID __declspec(selectany) IID__FormatterServices =
    {0xf859954a,0x78cf,0x3d00,{0x86,0xab,0xef,0x66,0x1e,0x6a,0x4b,0x8d}};
extern "C" const GUID __declspec(selectany) IID__ObjectIDGenerator =
    {0xa30646cc,0xf710,0x3bfa,{0xa3,0x56,0xb4,0xc8,0x58,0xd4,0xed,0x8e}};
extern "C" const GUID __declspec(selectany) IID__ObjectManager =
    {0xf28e7d04,0x3319,0x3968,{0x82,0x01,0xc6,0xe5,0x5b,0xec,0xd3,0xd4}};
extern "C" const GUID __declspec(selectany) IID__OptionalFieldAttribute =
    {0xfeca70d4,0xae27,0x3d94,{0x93,0xdd,0xa9,0x0f,0x02,0xe2,0x99,0xd5}};
extern "C" const GUID __declspec(selectany) IID__OnSerializingAttribute =
    {0x9ec28d2c,0x04c0,0x35f3,{0xa7,0xee,0x00,0x13,0x27,0x1f,0xf6,0x5e}};
extern "C" const GUID __declspec(selectany) IID__OnSerializedAttribute =
    {0x547bf8cd,0xf2a8,0x3b41,{0x96,0x6d,0x98,0xdb,0x33,0xde,0xd0,0x6d}};
extern "C" const GUID __declspec(selectany) IID__OnDeserializingAttribute =
    {0xf5aef88f,0x9ac4,0x320c,{0x95,0xd2,0x88,0xe8,0x63,0xa3,0x57,0x62}};
extern "C" const GUID __declspec(selectany) IID__OnDeserializedAttribute =
    {0xdd36c803,0x73d1,0x338d,{0x88,0xba,0xdc,0x9e,0xb7,0x62,0x0e,0xf7}};
extern "C" const GUID __declspec(selectany) IID__SerializationBinder =
    {0x450222d0,0x87ca,0x3699,{0xa7,0xb4,0xd8,0xa0,0xfd,0xb7,0x23,0x57}};
extern "C" const GUID __declspec(selectany) IID__SerializationInfo =
    {0xb58d62cf,0xb03a,0x3a14,{0xb0,0xb6,0xb1,0xe5,0xad,0x4e,0x4a,0xd5}};
extern "C" const GUID __declspec(selectany) IID_ISerializable =
    {0xd0eeaa62,0x3d30,0x3ee2,{0xb8,0x96,0xa2,0xf3,0x4d,0xda,0x47,0xd8}};
extern "C" const GUID __declspec(selectany) IID__SerializationInfoEnumerator =
    {0x607056c6,0x1bca,0x36c8,{0xab,0x87,0x33,0xb2,0x02,0xeb,0xf0,0xd8}};
extern "C" const GUID __declspec(selectany) IID__SerializationException =
    {0x245fe7fd,0xe020,0x3053,{0xb5,0xf6,0x74,0x67,0xfd,0x2c,0x68,0x83}};
extern "C" const GUID __declspec(selectany) IID__SurrogateSelector =
    {0x6de1230e,0x1f52,0x3779,{0x96,0x19,0xf5,0x18,0x41,0x03,0x46,0x6c}};
extern "C" const GUID __declspec(selectany) IID__Calendar =
    {0x4cca29e4,0x584b,0x3cd0,{0xad,0x25,0x85,0x5d,0xc5,0x79,0x9c,0x16}};
extern "C" const GUID __declspec(selectany) IID__EastAsianLunisolarCalendar =
    {0x89e148c4,0x2424,0x30ae,{0x80,0xf5,0xc5,0xd2,0x1e,0xa3,0x36,0x6c}};
extern "C" const GUID __declspec(selectany) IID__CompareInfo =
    {0x505defe5,0xaefa,0x3e23,{0x82,0xb0,0xd5,0xeb,0x08,0x5b,0xb8,0x40}};
extern "C" const GUID __declspec(selectany) IID__CultureInfo =
    {0x152722c2,0xf0b1,0x3d19,{0xad,0xa8,0xf4,0x0c,0xa5,0xca,0xec,0xb8}};
extern "C" const GUID __declspec(selectany) IID__DateTimeFormatInfo =
    {0x015e9f67,0x337c,0x398a,{0xa0,0xc1,0xda,0x4a,0xf1,0x90,0x55,0x71}};
extern "C" const GUID __declspec(selectany) IID__DaylightTime =
    {0xefea8feb,0xee7f,0x3e48,{0x8a,0x36,0x62,0x06,0xa6,0xac,0xbf,0x73}};
extern "C" const GUID __declspec(selectany) IID__GregorianCalendar =
    {0x677ad8b5,0x8a0e,0x3c39,{0x92,0xfb,0x72,0xfb,0x81,0x7c,0xf6,0x94}};
extern "C" const GUID __declspec(selectany) IID__HebrewCalendar =
    {0x96a62d6c,0x72a9,0x387a,{0x81,0xfa,0xe6,0xdd,0x59,0x98,0xca,0xee}};
extern "C" const GUID __declspec(selectany) IID__HijriCalendar =
    {0x28ddc187,0x56b2,0x34cf,{0xa0,0x78,0x48,0xbd,0x1e,0x11,0x3d,0x1e}};
extern "C" const GUID __declspec(selectany) IID__JapaneseCalendar =
    {0xd662ae3f,0xcef9,0x38b4,{0xbb,0x8e,0x5d,0x8d,0xd1,0xdb,0xf8,0x06}};
extern "C" const GUID __declspec(selectany) IID__JulianCalendar =
    {0x36e2de92,0x1fb3,0x3d7d,{0xba,0x26,0x9c,0xad,0x5b,0x98,0xdd,0x52}};
extern "C" const GUID __declspec(selectany) IID__KoreanCalendar =
    {0x48bea6c4,0x752e,0x3974,{0x8c,0xa8,0xcf,0xb6,0x27,0x4e,0x23,0x79}};
extern "C" const GUID __declspec(selectany) IID__RegionInfo =
    {0xf9e97e04,0x4e1e,0x368f,{0xb6,0xc6,0x5e,0x96,0xce,0x43,0x62,0xd6}};
extern "C" const GUID __declspec(selectany) IID__SortKey =
    {0xf4c70e15,0x2ca6,0x3e90,{0x96,0xed,0x92,0xe2,0x84,0x91,0xf5,0x38}};
extern "C" const GUID __declspec(selectany) IID__StringInfo =
    {0x0a25141f,0x51b3,0x3121,{0xaa,0x30,0x0a,0xf4,0x55,0x6a,0x52,0xd9}};
extern "C" const GUID __declspec(selectany) IID__TaiwanCalendar =
    {0x0c08ed74,0x0acf,0x32a9,{0x99,0xdf,0x09,0xa9,0xdc,0x47,0x86,0xdd}};
extern "C" const GUID __declspec(selectany) IID__TextElementEnumerator =
    {0x8c248251,0x3e6c,0x3151,{0x9f,0x8e,0xa2,0x55,0xfb,0x8d,0x2b,0x12}};
extern "C" const GUID __declspec(selectany) IID__TextInfo =
    {0xdb8de23f,0xf264,0x39ac,{0xb6,0x1c,0xcc,0x1e,0x7e,0xb4,0xa5,0xe6}};
extern "C" const GUID __declspec(selectany) IID__ThaiBuddhistCalendar =
    {0xc70c8ae8,0x925b,0x37ce,{0x89,0x44,0x34,0xf1,0x5f,0xf9,0x43,0x07}};
extern "C" const GUID __declspec(selectany) IID__NumberFormatInfo =
    {0x25e47d71,0x20dd,0x31be,{0xb2,0x61,0x7a,0xe7,0x64,0x97,0xd6,0xb9}};
extern "C" const GUID __declspec(selectany) IID__Encoding =
    {0xddedb94d,0x4f3f,0x35c1,{0x97,0xc9,0x3f,0x1d,0x87,0x62,0x8d,0x9e}};
extern "C" const GUID __declspec(selectany) IID__Encoder =
    {0x8fd56502,0x8724,0x3df0,{0xa1,0xb5,0x9d,0x0e,0x8d,0x4e,0x4f,0x78}};
extern "C" const GUID __declspec(selectany) IID__Decoder =
    {0x2adb0d4a,0x5976,0x38e4,{0x85,0x2b,0xc1,0x31,0x79,0x74,0x30,0xf5}};
extern "C" const GUID __declspec(selectany) IID__ASCIIEncoding =
    {0x0cbe0204,0x12a1,0x3d40,{0x9d,0x9e,0x19,0x5d,0xe6,0xaa,0xa5,0x34}};
extern "C" const GUID __declspec(selectany) IID__UnicodeEncoding =
    {0xf7dd3b7f,0x2b05,0x3894,{0x8e,0xda,0x59,0xcd,0xf9,0x39,0x5b,0x6a}};
extern "C" const GUID __declspec(selectany) IID__UTF7Encoding =
    {0x89b9f00b,0xaa2a,0x3a49,{0x91,0xb4,0xe8,0xd1,0xf1,0xc0,0x0e,0x58}};
extern "C" const GUID __declspec(selectany) IID__UTF8Encoding =
    {0x010fc1d0,0x3ef9,0x3f3b,{0xaa,0x0a,0xb7,0x8a,0x1f,0xf8,0x3a,0x37}};
extern "C" const GUID __declspec(selectany) IID__MissingManifestResourceException =
    {0x1a4e1878,0xfe8c,0x3f59,{0xb6,0xa9,0x21,0xab,0x82,0xbe,0x57,0xe9}};
extern "C" const GUID __declspec(selectany) IID__MissingSatelliteAssemblyException =
    {0x5a8de087,0xd9d7,0x3bba,{0x92,0xb4,0xfe,0x10,0x34,0xa1,0x24,0x2f}};
extern "C" const GUID __declspec(selectany) IID__NeutralResourcesLanguageAttribute =
    {0xf48df808,0x8b7d,0x3f4e,{0x91,0x59,0x1d,0xfd,0x60,0xf2,0x98,0xd6}};
extern "C" const GUID __declspec(selectany) IID__ResourceManager =
    {0x4de671b7,0x7c85,0x37e9,{0xaf,0xf8,0x12,0x22,0xab,0xe4,0x88,0x3e}};
extern "C" const GUID __declspec(selectany) IID__ResourceReader =
    {0x7fbcfdc7,0x5cec,0x3945,{0x80,0x95,0xda,0xed,0x61,0xbe,0x5f,0xb1}};
extern "C" const GUID __declspec(selectany) IID__ResourceSet =
    {0x44d5f81a,0x727c,0x35ae,{0x8d,0xf8,0x9f,0xf6,0x72,0x2f,0x1c,0x6c}};
extern "C" const GUID __declspec(selectany) IID__ResourceWriter =
    {0xaf170258,0xaac6,0x3a86,{0xbd,0x34,0x30,0x3e,0x62,0xce,0xd1,0x0e}};
extern "C" const GUID __declspec(selectany) IID__SatelliteContractVersionAttribute =
    {0x5cbb1f47,0xfba5,0x33b9,{0x9d,0x4a,0x57,0xd6,0xe3,0xd1,0x33,0xd2}};
extern "C" const GUID __declspec(selectany) IID__Registry =
    {0x23bae0c0,0x3a36,0x32f0,{0x9d,0xad,0x0e,0x95,0xad,0xd6,0x7d,0x23}};
extern "C" const GUID __declspec(selectany) IID__RegistryKey =
    {0x2eac6733,0x8d92,0x31d9,{0xbe,0x04,0xdc,0x46,0x7e,0xfc,0x3e,0xb1}};
extern "C" const GUID __declspec(selectany) IID__AllMembershipCondition =
    {0x99f01720,0x3cc2,0x366d,{0x9a,0xb9,0x50,0xe3,0x66,0x47,0x61,0x7f}};
extern "C" const GUID __declspec(selectany) IID__ApplicationDirectory =
    {0x9ccc831b,0x1ba7,0x34be,{0xa9,0x66,0x56,0xd5,0xa6,0xdb,0x5a,0xad}};
extern "C" const GUID __declspec(selectany) IID__ApplicationDirectoryMembershipCondition =
    {0xa02a2b22,0x1dba,0x3f92,{0x9f,0x84,0x55,0x63,0x18,0x28,0x51,0xbb}};
extern "C" const GUID __declspec(selectany) IID__ApplicationSecurityInfo =
    {0x18e473f6,0x637b,0x3c01,{0x8d,0x46,0xd0,0x11,0xaa,0xd2,0x6c,0x95}};
extern "C" const GUID __declspec(selectany) IID__ApplicationSecurityManager =
    {0xc664fe09,0x0a55,0x316d,{0xb2,0x5b,0x6b,0x32,0x00,0xec,0xaf,0x70}};
extern "C" const GUID __declspec(selectany) IID__ApplicationTrust =
    {0xe66a9755,0x58e2,0x3fcb,{0xa2,0x65,0x83,0x58,0x51,0xcb,0xf0,0x63}};
extern "C" const GUID __declspec(selectany) IID__ApplicationTrustCollection =
    {0xbb03c920,0x1c05,0x3ecb,{0x98,0x2d,0x53,0x32,0x4d,0x5a,0xc9,0xff}};
extern "C" const GUID __declspec(selectany) IID__ApplicationTrustEnumerator =
    {0x01afd447,0x60ca,0x3b67,{0x80,0x3a,0xe5,0x7b,0x72,0x7f,0x3a,0x5b}};
extern "C" const GUID __declspec(selectany) IID__CodeGroup =
    {0xd7093f61,0xed6b,0x343f,{0xb1,0xe9,0x02,0x47,0x2f,0xcc,0x71,0x0e}};
extern "C" const GUID __declspec(selectany) IID__Evidence =
    {0xa505edbc,0x380e,0x3b23,{0x9e,0x1a,0x09,0x74,0xd4,0xef,0x02,0xef}};
extern "C" const GUID __declspec(selectany) IID_IEvidenceFactory =
    {0x35a8f3ac,0xfe28,0x360f,{0xa0,0xc0,0x9a,0x4d,0x50,0xc4,0x68,0x2a}};
extern "C" const GUID __declspec(selectany) IID_IMembershipCondition =
    {0x6844eff4,0x4f86,0x3ca1,{0xa1,0xea,0xaa,0xf5,0x83,0xa6,0x39,0x5e}};
extern "C" const GUID __declspec(selectany) IID_IIdentityPermissionFactory =
    {0x4e95244e,0xc6fc,0x3a86,{0x8d,0xb7,0x17,0x12,0x45,0x4d,0xe3,0xb6}};
extern "C" const GUID __declspec(selectany) IID__FileCodeGroup =
    {0xdfad74dc,0x8390,0x32f6,{0x96,0x12,0x1b,0xd2,0x93,0xb2,0x33,0xf4}};
extern "C" const GUID __declspec(selectany) IID__FirstMatchCodeGroup =
    {0x54b0afb1,0xe7d3,0x3770,{0xbb,0x0e,0x75,0xa9,0x5e,0x8d,0x26,0x56}};
extern "C" const GUID __declspec(selectany) IID__TrustManagerContext =
    {0xd89eac5e,0x0331,0x3fcd,{0x9c,0x16,0x4f,0x1e,0xd3,0xfe,0x1b,0xe2}};
extern "C" const GUID __declspec(selectany) IID_IApplicationTrustManager =
    {0x427e255d,0xaf02,0x3b0d,{0x8c,0xe3,0xa2,0xbb,0x94,0xba,0x30,0x0f}};
extern "C" const GUID __declspec(selectany) IID__CodeConnectAccess =
    {0xfe8a2546,0x3478,0x3fad,{0xbe,0x1d,0xda,0x7b,0xc2,0x5c,0x4e,0x4e}};
extern "C" const GUID __declspec(selectany) IID__NetCodeGroup =
    {0xa8f69eca,0x8c48,0x3b5e,{0x92,0xa1,0x65,0x49,0x25,0x05,0x80,0x59}};
extern "C" const GUID __declspec(selectany) IID__PermissionRequestEvidence =
    {0x34b0417e,0xe71d,0x304c,{0x9f,0xac,0x68,0x93,0x50,0xa1,0xb4,0x1c}};
extern "C" const GUID __declspec(selectany) IID__PolicyException =
    {0xa9c9f3d9,0xe153,0x39b8,{0xa5,0x33,0xb8,0xdf,0x46,0x64,0x40,0x7b}};
extern "C" const GUID __declspec(selectany) IID__PolicyLevel =
    {0x44494e35,0xc370,0x3014,{0xbc,0x78,0x0f,0x2e,0xcb,0xf8,0x3f,0x53}};
extern "C" const GUID __declspec(selectany) IID__PolicyStatement =
    {0x3eefd1fc,0x4d8d,0x3177,{0x99,0xf6,0x6c,0x19,0xd9,0xe0,0x88,0xd3}};
extern "C" const GUID __declspec(selectany) IID__Site =
    {0x90c40b4c,0xb0d0,0x30f5,{0xb5,0x20,0xfd,0xba,0x97,0xbc,0x31,0xa0}};
extern "C" const GUID __declspec(selectany) IID__SiteMembershipCondition =
    {0x0a7c3542,0x8031,0x3593,{0x87,0x2c,0x78,0xd8,0x5d,0x7c,0xc2,0x73}};
extern "C" const GUID __declspec(selectany) IID__StrongName =
    {0x2a75c1fd,0x06b0,0x3cbb,{0xb4,0x67,0x25,0x45,0xd4,0xd6,0xc8,0x65}};
extern "C" const GUID __declspec(selectany) IID__StrongNameMembershipCondition =
    {0x579e93bc,0xffab,0x3b8d,{0x91,0x81,0xce,0x9c,0x22,0xb5,0x19,0x15}};
extern "C" const GUID __declspec(selectany) IID__UnionCodeGroup =
    {0xd9d822de,0x44e5,0x33ce,{0xa4,0x3f,0x17,0x3e,0x47,0x5c,0xec,0xb1}};
extern "C" const GUID __declspec(selectany) IID__Url =
    {0xd94ed9bf,0xc065,0x3703,{0x81,0xa2,0x2f,0x76,0xea,0x8e,0x31,0x2f}};
extern "C" const GUID __declspec(selectany) IID__UrlMembershipCondition =
    {0xbb7a158d,0xdbd9,0x3e13,{0xb1,0x37,0x8e,0x61,0xe8,0x7e,0x11,0x28}};
extern "C" const GUID __declspec(selectany) IID__Zone =
    {0x742e0c26,0x0e23,0x3d20,{0x96,0x8c,0xd2,0x21,0x09,0x49,0x09,0xaa}};
extern "C" const GUID __declspec(selectany) IID__ZoneMembershipCondition =
    {0xadbc3463,0x0101,0x3429,{0xa0,0x6c,0xdb,0x2f,0x1d,0xd6,0xb7,0x24}};
extern "C" const GUID __declspec(selectany) IID__GacInstalled =
    {0xa7aef52c,0xb47b,0x3660,{0xbb,0x3e,0x34,0x34,0x7d,0x56,0xdb,0x46}};
extern "C" const GUID __declspec(selectany) IID__GacMembershipCondition =
    {0xb2217ab5,0x6e55,0x3ff6,{0xa1,0xa9,0x1b,0x0d,0xc0,0x58,0x50,0x40}};
extern "C" const GUID __declspec(selectany) IID__Hash =
    {0x7574e121,0x74a6,0x3626,{0xb5,0x78,0x07,0x83,0xba,0xdb,0x19,0xd2}};
extern "C" const GUID __declspec(selectany) IID__HashMembershipCondition =
    {0x6ba6ea7a,0xc9fc,0x3e73,{0x82,0xec,0x18,0xf2,0x9d,0x83,0xee,0xfd}};
extern "C" const GUID __declspec(selectany) IID__Publisher =
    {0x77cca693,0xabf6,0x3773,{0xbf,0x58,0xc0,0xb0,0x27,0x01,0xa7,0x44}};
extern "C" const GUID __declspec(selectany) IID__PublisherMembershipCondition =
    {0x3515cf63,0x9863,0x3044,{0xb3,0xe1,0x21,0x0e,0x98,0xef,0xc7,0x02}};
extern "C" const GUID __declspec(selectany) IID__GenericIdentity =
    {0x9a37d8b2,0x2256,0x3fe3,{0x8b,0xf0,0x4f,0xc4,0x21,0xa1,0x24,0x4f}};
extern "C" const GUID __declspec(selectany) IID__GenericPrincipal =
    {0xb4701c26,0x1509,0x3726,{0xb2,0xe1,0x40,0x9a,0x63,0x6c,0x9b,0x4f}};
extern "C" const GUID __declspec(selectany) IID__WindowsIdentity =
    {0xd8cf3f23,0x1a66,0x3344,{0x82,0x30,0x07,0xeb,0x53,0x97,0x0b,0x85}};
extern "C" const GUID __declspec(selectany) IID__WindowsImpersonationContext =
    {0x60ecfdda,0x650a,0x324c,{0xb4,0xb3,0xf4,0xd7,0x5b,0x56,0x3b,0xb1}};
extern "C" const GUID __declspec(selectany) IID__WindowsPrincipal =
    {0x6c42baf9,0x1893,0x34fc,{0xb3,0xaf,0x06,0x93,0x1e,0x9b,0x34,0xa3}};
extern "C" const GUID __declspec(selectany) IID__UnmanagedFunctionPointerAttribute =
    {0x1b6ed26a,0x4b7f,0x34fc,{0xb2,0xc8,0x81,0x09,0xd6,0x84,0xb3,0xdf}};
extern "C" const GUID __declspec(selectany) IID__DispIdAttribute =
    {0xbbe41ac5,0x8692,0x3427,{0x9a,0xe1,0xc1,0x05,0x8a,0x38,0xd4,0x92}};
extern "C" const GUID __declspec(selectany) IID__InterfaceTypeAttribute =
    {0xa2145f38,0xcac1,0x33dd,{0xa3,0x18,0x21,0x94,0x8a,0xf6,0x82,0x5d}};
extern "C" const GUID __declspec(selectany) IID__ComDefaultInterfaceAttribute =
    {0x0c1e7b57,0xb9b1,0x36e4,{0x83,0x96,0x54,0x9c,0x29,0x06,0x2a,0x81}};
extern "C" const GUID __declspec(selectany) IID__ClassInterfaceAttribute =
    {0x6b6391ee,0x842f,0x3e9a,{0x8e,0xee,0xf1,0x33,0x25,0xe1,0x09,0x96}};
extern "C" const GUID __declspec(selectany) IID__ComVisibleAttribute =
    {0x1e7fffe2,0xaad9,0x34ee,{0x8a,0x9f,0x3c,0x01,0x6b,0x88,0x0f,0xf0}};
extern "C" const GUID __declspec(selectany) IID__TypeLibImportClassAttribute =
    {0x288a86d1,0x6f4f,0x39c9,{0x9e,0x42,0x16,0x2c,0xf1,0xc3,0x72,0x26}};
extern "C" const GUID __declspec(selectany) IID__LCIDConversionAttribute =
    {0x4ab67927,0x3c86,0x328a,{0x81,0x86,0xf8,0x53,0x57,0xdd,0x55,0x27}};
extern "C" const GUID __declspec(selectany) IID__ComRegisterFunctionAttribute =
    {0x51ba926f,0xaab5,0x3945,{0xb8,0xa6,0xc8,0xf0,0xf4,0xa7,0xd1,0x2b}};
extern "C" const GUID __declspec(selectany) IID__ComUnregisterFunctionAttribute =
    {0x9f164188,0x34eb,0x3f86,{0x9f,0x74,0x0b,0xbe,0x41,0x55,0xe6,0x5e}};
extern "C" const GUID __declspec(selectany) IID__ProgIdAttribute =
    {0x2b9f01df,0x5a12,0x3688,{0x98,0xd6,0xc3,0x4b,0xf5,0xed,0x18,0x65}};
extern "C" const GUID __declspec(selectany) IID__ImportedFromTypeLibAttribute =
    {0x3f3311ce,0x6baf,0x3fb0,{0xb8,0x55,0x48,0x9a,0xff,0x74,0x0b,0x6e}};
extern "C" const GUID __declspec(selectany) IID__IDispatchImplAttribute =
    {0x5778e7c7,0x2040,0x330e,{0xb4,0x7a,0x92,0x97,0x4d,0xff,0xcf,0xd4}};
extern "C" const GUID __declspec(selectany) IID__ComSourceInterfacesAttribute =
    {0xe1984175,0x55f5,0x3065,{0x82,0xd8,0xa6,0x83,0xfd,0xfc,0xf0,0xac}};
extern "C" const GUID __declspec(selectany) IID__ComConversionLossAttribute =
    {0xfd5b6aac,0xff8c,0x3472,{0xb8,0x94,0xcd,0x6d,0xfa,0xdb,0x69,0x39}};
extern "C" const GUID __declspec(selectany) IID__TypeLibTypeAttribute =
    {0xb5a1729e,0xb721,0x3121,{0xa8,0x38,0xfd,0xe4,0x3a,0xf1,0x34,0x68}};
extern "C" const GUID __declspec(selectany) IID__TypeLibFuncAttribute =
    {0x3d18a8e2,0xeede,0x3139,{0xb2,0x9d,0x8c,0xac,0x05,0x79,0x55,0xdf}};
extern "C" const GUID __declspec(selectany) IID__TypeLibVarAttribute =
    {0x7b89862a,0x02a4,0x3279,{0x8b,0x42,0x40,0x95,0xfa,0x3a,0x77,0x8e}};
extern "C" const GUID __declspec(selectany) IID__MarshalAsAttribute =
    {0xd858399f,0xe19e,0x3423,{0xa7,0x20,0xac,0x12,0xab,0xe2,0xe5,0xe8}};
extern "C" const GUID __declspec(selectany) IID__ComImportAttribute =
    {0x1b093056,0x5454,0x386f,{0x89,0x71,0xbb,0xcb,0xc4,0xe9,0xa8,0xf3}};
extern "C" const GUID __declspec(selectany) IID__GuidAttribute =
    {0x74435dad,0xec55,0x354b,{0x8f,0x5b,0xfa,0x70,0xd1,0x3b,0x62,0x93}};
extern "C" const GUID __declspec(selectany) IID__PreserveSigAttribute =
    {0xfdf2a2ee,0xc882,0x3198,{0xa4,0x8b,0xe3,0x7f,0x0e,0x57,0x4d,0xfa}};
extern "C" const GUID __declspec(selectany) IID__InAttribute =
    {0x8474b65c,0xc39a,0x3d05,{0x89,0x3d,0x57,0x7b,0x9a,0x31,0x46,0x15}};
extern "C" const GUID __declspec(selectany) IID__OutAttribute =
    {0x0697fc8c,0x9b04,0x3783,{0x95,0xc7,0x45,0xec,0xca,0xc1,0xca,0x27}};
extern "C" const GUID __declspec(selectany) IID__OptionalAttribute =
    {0x0d6bd9ad,0x198e,0x3904,{0xad,0x99,0xf6,0xf8,0x2a,0x27,0x87,0xc4}};
extern "C" const GUID __declspec(selectany) IID__DllImportAttribute =
    {0xa1a26181,0xd55e,0x3ee2,{0x96,0xe6,0x70,0xb3,0x54,0xef,0x93,0x71}};
extern "C" const GUID __declspec(selectany) IID__StructLayoutAttribute =
    {0x23753322,0xc7b3,0x3f9a,{0xac,0x96,0x52,0x67,0x2c,0x1b,0x1c,0xa9}};
extern "C" const GUID __declspec(selectany) IID__FieldOffsetAttribute =
    {0xc14342b8,0xbafd,0x322a,{0xbb,0x71,0x62,0xc6,0x72,0xda,0x28,0x4e}};
extern "C" const GUID __declspec(selectany) IID__ComAliasNameAttribute =
    {0xe78785c4,0x3a73,0x3c15,{0x93,0x90,0x61,0x8b,0xf3,0xa1,0x47,0x19}};
extern "C" const GUID __declspec(selectany) IID__AutomationProxyAttribute =
    {0x57b908a8,0xc082,0x3581,{0x8a,0x47,0x6b,0x41,0xb8,0x6e,0x8f,0xdc}};
extern "C" const GUID __declspec(selectany) IID__PrimaryInteropAssemblyAttribute =
    {0xc69e96b2,0x6161,0x3621,{0xb1,0x65,0x58,0x05,0x19,0x8c,0x6b,0x8d}};
extern "C" const GUID __declspec(selectany) IID__CoClassAttribute =
    {0x15d54c00,0x7c95,0x38d7,{0xb8,0x59,0xe1,0x93,0x46,0x67,0x7d,0xcd}};
extern "C" const GUID __declspec(selectany) IID__ComEventInterfaceAttribute =
    {0x76cc0491,0x9a10,0x35c0,{0x8a,0x66,0x79,0x31,0xec,0x34,0x5b,0x7f}};
extern "C" const GUID __declspec(selectany) IID__TypeLibVersionAttribute =
    {0xa03b61a4,0xca61,0x3460,{0x82,0x32,0x2f,0x4e,0xc9,0x6a,0xa8,0x8f}};
extern "C" const GUID __declspec(selectany) IID__ComCompatibleVersionAttribute =
    {0xad419379,0x2ac8,0x3588,{0xab,0x1e,0x01,0x15,0x41,0x32,0x77,0xc4}};
extern "C" const GUID __declspec(selectany) IID__BestFitMappingAttribute =
    {0xed47abe7,0xc84b,0x39f9,{0xbe,0x1b,0x82,0x8c,0xfb,0x92,0x5a,0xfe}};
extern "C" const GUID __declspec(selectany) IID__DefaultCharSetAttribute =
    {0xb26b3465,0x28e4,0x33b5,{0xb9,0xbf,0xdd,0x7c,0x4f,0x64,0x61,0xf5}};
extern "C" const GUID __declspec(selectany) IID__SetWin32ContextInIDispatchAttribute =
    {0xa54ac093,0xbfce,0x37b0,{0xa8,0x1f,0x14,0x8d,0xfe,0xd0,0x97,0x1f}};
extern "C" const GUID __declspec(selectany) IID__ExternalException =
    {0xa83f04e9,0xfd28,0x384a,{0x9d,0xff,0x41,0x06,0x88,0xac,0x23,0xab}};
extern "C" const GUID __declspec(selectany) IID__COMException =
    {0xa28c19df,0xb488,0x34ae,{0xbe,0xcc,0x7d,0xe7,0x44,0xd1,0x7f,0x7b}};
extern "C" const GUID __declspec(selectany) IID__InvalidOleVariantTypeException =
    {0x76e5dbd6,0xf960,0x3c65,{0x8e,0xa6,0xfc,0x8a,0xd6,0xa6,0x70,0x22}};
extern "C" const GUID __declspec(selectany) IID__MarshalDirectiveException =
    {0x523f42a5,0x1fd2,0x355d,{0x82,0xbf,0x0d,0x67,0xc4,0xa0,0xa0,0xe7}};
extern "C" const GUID __declspec(selectany) IID__RuntimeEnvironment =
    {0xedcee21a,0x3e3a,0x331e,{0xa8,0x6d,0x27,0x40,0x28,0xbe,0x67,0x16}};
extern "C" const GUID __declspec(selectany) IID__SEHException =
    {0x3e72e067,0x4c5e,0x36c8,{0xbb,0xef,0x1e,0x29,0x78,0xc7,0x78,0x0d}};
extern "C" const GUID __declspec(selectany) IID__BStrWrapper =
    {0x80da5818,0x609f,0x32b8,{0xa9,0xf8,0x95,0xfc,0xfb,0xdb,0x9c,0x8e}};
extern "C" const GUID __declspec(selectany) IID__CurrencyWrapper =
    {0x7df6f279,0xda62,0x3c9f,{0x89,0x44,0x4d,0xd3,0xc0,0xf0,0x81,0x70}};
extern "C" const GUID __declspec(selectany) IID__DispatchWrapper =
    {0x72103c67,0xd511,0x329c,{0xb1,0x9a,0xdd,0x5e,0xc3,0xf1,0x20,0x6c}};
extern "C" const GUID __declspec(selectany) IID__ErrorWrapper =
    {0xf79db336,0x06be,0x3959,{0xa5,0xab,0x58,0xb2,0xab,0x6c,0x5f,0xd1}};
extern "C" const GUID __declspec(selectany) IID__ExtensibleClassFactory =
    {0x519eb857,0x7a2d,0x3a95,{0xa2,0xa3,0x8b,0xb8,0xed,0x63,0xd4,0x1b}};
extern "C" const GUID __declspec(selectany) IID__InvalidComObjectException =
    {0xde9156b5,0x5e7a,0x3041,{0xbf,0x45,0xa2,0x9a,0x6c,0x2c,0xf4,0x8a}};
extern "C" const GUID __declspec(selectany) IID__ObjectCreationDelegate =
    {0xe4a369d3,0x6cf0,0x3b05,{0x9c,0x0c,0x1a,0x91,0xe3,0x31,0x64,0x1a}};
extern "C" const GUID __declspec(selectany) IID__SafeArrayRankMismatchException =
    {0x8608fe7b,0x2fdc,0x318a,{0xb7,0x11,0x6f,0x7b,0x2f,0xed,0xed,0x06}};
extern "C" const GUID __declspec(selectany) IID__SafeArrayTypeMismatchException =
    {0xe093fb32,0xe43b,0x3b3f,{0xa1,0x63,0x74,0x2c,0x92,0x0c,0x2a,0xf3}};
extern "C" const GUID __declspec(selectany) IID__UnknownWrapper =
    {0x1c8d8b14,0x4589,0x3dca,{0x8e,0x0f,0xa3,0x0e,0x80,0xfb,0xd1,0xa8}};
extern "C" const GUID __declspec(selectany) IID__Stream =
    {0x2752364a,0x924f,0x3603,{0x8f,0x6f,0x65,0x86,0xdf,0x98,0xb2,0x92}};
extern "C" const GUID __declspec(selectany) IID_IServerResponseChannelSinkStack =
    {0x9be679a6,0x61fd,0x38fc,{0xa7,0xb2,0x89,0x98,0x2d,0x33,0x33,0x8b}};
extern "C" const GUID __declspec(selectany) IID__BinaryReader =
    {0x442e3c03,0xa205,0x3f21,{0xaa,0x4d,0x31,0x76,0x8b,0xb8,0xea,0x28}};
extern "C" const GUID __declspec(selectany) IID__BinaryWriter =
    {0x4ca8147e,0xbaa3,0x3a7f,{0x92,0xce,0xa4,0xfd,0x7f,0x17,0xd8,0xda}};
extern "C" const GUID __declspec(selectany) IID__BufferedStream =
    {0x4b7571c3,0x1275,0x3457,{0x8f,0xee,0x99,0x76,0xfd,0x39,0x37,0xe3}};
extern "C" const GUID __declspec(selectany) IID__Directory =
    {0x8ce58ff5,0xf26d,0x38a4,{0x91,0x95,0x0e,0x2e,0xcb,0x3b,0x56,0xb9}};
extern "C" const GUID __declspec(selectany) IID__FileSystemInfo =
    {0xa5d29a57,0x36a8,0x3e36,{0xa0,0x99,0x74,0x58,0xb1,0xfa,0xba,0xa2}};
extern "C" const GUID __declspec(selectany) IID__DirectoryInfo =
    {0x487e52f1,0x2bb9,0x3bd0,{0xa0,0xca,0x67,0x28,0xb3,0xa1,0xd0,0x51}};
extern "C" const GUID __declspec(selectany) IID__IOException =
    {0xc5bfc9bf,0x27a7,0x3a59,{0xa9,0x86,0x44,0xc8,0x5f,0x35,0x21,0xbf}};
extern "C" const GUID __declspec(selectany) IID__DirectoryNotFoundException =
    {0xc8a200e4,0x9735,0x30e4,{0xb1,0x68,0xed,0x86,0x1a,0x30,0x20,0xf2}};
extern "C" const GUID __declspec(selectany) IID__DriveInfo =
    {0xce83a763,0x940f,0x341f,{0xb8,0x80,0x33,0x23,0x25,0xeb,0x6f,0x4b}};
extern "C" const GUID __declspec(selectany) IID__DriveNotFoundException =
    {0xb24e9559,0xa662,0x3762,{0xae,0x33,0xbc,0x7d,0xfd,0xd5,0x38,0xf4}};
extern "C" const GUID __declspec(selectany) IID__EndOfStreamException =
    {0xd625afd0,0x8fd9,0x3113,{0xa9,0x00,0x43,0x91,0x2a,0x54,0xc4,0x21}};
extern "C" const GUID __declspec(selectany) IID__File =
    {0x5d59051f,0xe19d,0x329a,{0x99,0x62,0xfd,0x00,0xd5,0x52,0xe1,0x3d}};
extern "C" const GUID __declspec(selectany) IID__FileInfo =
    {0xc3c429f9,0x8590,0x3a01,{0xb2,0xb2,0x43,0x48,0x37,0xf3,0xd1,0x6d}};
extern "C" const GUID __declspec(selectany) IID__FileLoadException =
    {0x51d2c393,0x9b70,0x3551,{0x84,0xb5,0xff,0x54,0x09,0xfb,0x3a,0xda}};
extern "C" const GUID __declspec(selectany) IID__FileNotFoundException =
    {0xa15a976b,0x81e3,0x3ef4,{0x8f,0xf1,0xd7,0x5d,0xdb,0xe2,0x0a,0xef}};
extern "C" const GUID __declspec(selectany) IID__FileStream =
    {0x74265195,0x4a46,0x3d6f,{0xa9,0xdd,0x69,0xc3,0x67,0xea,0x39,0xc8}};
extern "C" const GUID __declspec(selectany) IID__MemoryStream =
    {0x2dbc46fe,0xb3dd,0x3858,{0xaf,0xc2,0xd3,0xa2,0xd4,0x92,0xa5,0x88}};
extern "C" const GUID __declspec(selectany) IID__Path =
    {0x6df93530,0xd276,0x31d9,{0x85,0x73,0x34,0x67,0x78,0xc6,0x50,0xaf}};
extern "C" const GUID __declspec(selectany) IID__PathTooLongException =
    {0x468b8eb4,0x89ac,0x381b,{0x8f,0x86,0x5e,0x47,0xec,0x06,0x48,0xb4}};
extern "C" const GUID __declspec(selectany) IID__TextReader =
    {0x897471f2,0x9450,0x3f03,{0xa4,0x1f,0xd2,0xe1,0xf1,0x39,0x78,0x54}};
extern "C" const GUID __declspec(selectany) IID__StreamReader =
    {0xe645b470,0xdc3f,0x3ce0,{0x81,0x04,0x58,0x37,0xfe,0xda,0x04,0xb3}};
extern "C" const GUID __declspec(selectany) IID__TextWriter =
    {0x556137ea,0x8825,0x30bc,{0x9d,0x49,0xe4,0x7a,0x9d,0xb0,0x34,0xee}};
extern "C" const GUID __declspec(selectany) IID__StreamWriter =
    {0x1f124e1c,0xd05d,0x3643,{0xa5,0x9f,0xc3,0xde,0x60,0x51,0x99,0x4f}};
extern "C" const GUID __declspec(selectany) IID__StringReader =
    {0x59733b03,0x0ea5,0x358c,{0x95,0xb5,0x65,0x9f,0xcd,0x9a,0xa0,0xb4}};
extern "C" const GUID __declspec(selectany) IID__StringWriter =
    {0xcb9f94c0,0xd691,0x3b62,{0xb0,0xb2,0x3c,0xe5,0x30,0x9c,0xfa,0x62}};
extern "C" const GUID __declspec(selectany) IID__AccessedThroughPropertyAttribute =
    {0x998dcf16,0xf603,0x355d,{0x8c,0x89,0x3b,0x67,0x59,0x47,0x99,0x7f}};
extern "C" const GUID __declspec(selectany) IID__CallConvCdecl =
    {0xa6c2239b,0x08e6,0x3822,{0x97,0x69,0xe3,0xd4,0xb0,0x43,0x1b,0x82}};
extern "C" const GUID __declspec(selectany) IID__CallConvStdcall =
    {0x8e17a5cd,0x1160,0x32dc,{0x85,0x48,0x40,0x7e,0x7c,0x38,0x27,0xc9}};
extern "C" const GUID __declspec(selectany) IID__CallConvThiscall =
    {0xfa73dd3d,0xa472,0x35ed,{0xb8,0xbe,0xf9,0x9a,0x13,0x58,0x1f,0x72}};
extern "C" const GUID __declspec(selectany) IID__CallConvFastcall =
    {0x3b452d17,0x3c5e,0x36c4,{0xa1,0x2d,0x5e,0x92,0x76,0x03,0x6c,0xf8}};
extern "C" const GUID __declspec(selectany) IID__CustomConstantAttribute =
    {0x62caf4a2,0x6a78,0x3fc7,{0xaf,0x81,0xa6,0xbb,0xf9,0x30,0x76,0x1f}};
extern "C" const GUID __declspec(selectany) IID__DateTimeConstantAttribute =
    {0xef387020,0xb664,0x3acd,{0xa1,0xd2,0x80,0x63,0x45,0x84,0x59,0x53}};
extern "C" const GUID __declspec(selectany) IID__DiscardableAttribute =
    {0x3c3a8c69,0x7417,0x32fa,{0xaa,0x20,0x76,0x2d,0x85,0xe1,0xb5,0x94}};
extern "C" const GUID __declspec(selectany) IID__DecimalConstantAttribute =
    {0x7e133967,0xccec,0x3e89,{0x8b,0xd2,0x6c,0xfc,0xa6,0x49,0xec,0xbf}};
extern "C" const GUID __declspec(selectany) IID__CompilationRelaxationsAttribute =
    {0xc5c4f625,0x2329,0x3382,{0x89,0x94,0xaa,0xf5,0x61,0xe5,0xdf,0xe9}};
extern "C" const GUID __declspec(selectany) IID__CompilerGlobalScopeAttribute =
    {0x1eed213e,0x656a,0x3a73,{0xa4,0xb9,0x0d,0x3b,0x26,0xfd,0x94,0x2b}};
extern "C" const GUID __declspec(selectany) IID__IndexerNameAttribute =
    {0x243368f5,0x67c9,0x3510,{0x94,0x24,0x33,0x5a,0x8a,0x67,0x77,0x2f}};
extern "C" const GUID __declspec(selectany) IID__IsVolatile =
    {0x0278c819,0x0c06,0x3756,{0xb0,0x53,0x60,0x1a,0x3e,0x56,0x6d,0x9b}};
extern "C" const GUID __declspec(selectany) IID__MethodImplAttribute =
    {0x98966503,0x5d80,0x3242,{0x83,0xef,0x79,0xe1,0x36,0xf6,0xb9,0x54}};
extern "C" const GUID __declspec(selectany) IID__RequiredAttributeAttribute =
    {0xdb2c11d9,0x3870,0x35e7,{0xa1,0x0c,0xa3,0xdd,0xc3,0xdc,0x79,0xb1}};
extern "C" const GUID __declspec(selectany) IID__IsCopyConstructed =
    {0xf68a4008,0xab94,0x3370,{0xa9,0xac,0x8c,0xc9,0x99,0x39,0xf5,0x34}};
extern "C" const GUID __declspec(selectany) IID__NativeCppClassAttribute =
    {0x40e8e914,0xdc23,0x38a6,{0x93,0x6b,0x90,0xe4,0xe3,0xab,0x01,0xfa}};
extern "C" const GUID __declspec(selectany) IID__IDispatchConstantAttribute =
    {0x97d0b28a,0x6932,0x3d74,{0xb6,0x7f,0x6b,0xcd,0x3c,0x92,0x1e,0x7d}};
extern "C" const GUID __declspec(selectany) IID__IUnknownConstantAttribute =
    {0x54542649,0xce64,0x3f96,{0xbc,0xe5,0xfd,0xe3,0xbb,0x22,0xf2,0x42}};
extern "C" const GUID __declspec(selectany) IID__SecurityElement =
    {0x8d597c42,0x2cfd,0x32b6,{0xb6,0xd6,0x86,0xc9,0xe2,0xcf,0xf0,0x0a}};
extern "C" const GUID __declspec(selectany) IID_ISecurityEncodable =
    {0xfd46bde5,0xacdf,0x3ca5,{0xb1,0x89,0xf0,0x67,0x83,0x87,0x07,0x7f}};
extern "C" const GUID __declspec(selectany) IID_ISecurityPolicyEncodable =
    {0xe6c21ba7,0x21bb,0x34e9,{0x8e,0x57,0xdb,0x66,0xd8,0xce,0x4a,0x70}};
extern "C" const GUID __declspec(selectany) IID__XmlSyntaxException =
    {0xd9fcad88,0xd869,0x3788,{0xa8,0x02,0x1b,0x1e,0x00,0x7c,0x7a,0x22}};
extern "C" const GUID __declspec(selectany) IID__CodeAccessPermission =
    {0x4803ce39,0x2f30,0x31fc,{0xb8,0x4b,0x5a,0x01,0x41,0x38,0x52,0x69}};
extern "C" const GUID __declspec(selectany) IID__EnvironmentPermission =
    {0x0720590d,0x5218,0x352a,{0xa3,0x37,0x54,0x49,0xe6,0xbd,0x19,0xda}};
extern "C" const GUID __declspec(selectany) IID__FileDialogPermission =
    {0xa8b7138c,0x8932,0x3d78,{0xa5,0x85,0xa9,0x15,0x69,0xc7,0x43,0xac}};
extern "C" const GUID __declspec(selectany) IID__FileIOPermission =
    {0xa2ed7efc,0x8e59,0x3ccc,{0xae,0x92,0xea,0x23,0x77,0xf4,0xd5,0xef}};
extern "C" const GUID __declspec(selectany) IID__SecurityAttribute =
    {0x48815668,0x6c27,0x3312,{0x80,0x3e,0x27,0x57,0xf5,0x5c,0xe9,0x6a}};
extern "C" const GUID __declspec(selectany) IID__CodeAccessSecurityAttribute =
    {0x9c5149cb,0xd3c6,0x32fd,{0xa0,0xd5,0x95,0x35,0x0d,0xe7,0xb8,0x13}};
extern "C" const GUID __declspec(selectany) IID__HostProtectionAttribute =
    {0x9f8f73a3,0x1e99,0x3e51,{0xa4,0x1b,0x17,0x9a,0x41,0xdc,0x74,0x7c}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStoragePermission =
    {0x7fee7903,0xf97c,0x3350,{0xad,0x42,0x19,0x6b,0x00,0xad,0x25,0x64}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStorageFilePermission =
    {0x0d0c83e8,0xbde1,0x3ba5,{0xb1,0xef,0xa8,0xfc,0x68,0x6d,0x8b,0xc9}};
extern "C" const GUID __declspec(selectany) IID__EnvironmentPermissionAttribute =
    {0x4164071a,0xed12,0x3bdd,{0xaf,0x40,0xfd,0xab,0xca,0xa7,0x7d,0x5f}};
extern "C" const GUID __declspec(selectany) IID__FileDialogPermissionAttribute =
    {0x0ccca629,0x440f,0x313e,{0x96,0xcd,0xba,0x1b,0x4b,0x49,0x97,0xf7}};
extern "C" const GUID __declspec(selectany) IID__FileIOPermissionAttribute =
    {0x0dca817d,0xf21a,0x3943,{0xb5,0x4c,0x5e,0x80,0x0c,0xe5,0xbc,0x50}};
extern "C" const GUID __declspec(selectany) IID__KeyContainerPermissionAttribute =
    {0xedb51d1c,0x08ad,0x346a,{0xbe,0x6f,0xd7,0x4f,0xd6,0xd6,0xf9,0x65}};
extern "C" const GUID __declspec(selectany) IID__PrincipalPermissionAttribute =
    {0x68ab69e4,0x5d68,0x3b51,{0xb7,0x4d,0x1b,0xea,0xb9,0xf3,0x7f,0x2b}};
extern "C" const GUID __declspec(selectany) IID__ReflectionPermissionAttribute =
    {0xd31eed10,0xa5f0,0x308f,{0xa9,0x51,0xe5,0x57,0x96,0x1e,0xc5,0x68}};
extern "C" const GUID __declspec(selectany) IID__RegistryPermissionAttribute =
    {0x38b6068c,0x1e94,0x3119,{0x88,0x41,0x1e,0xca,0x35,0xed,0x85,0x78}};
extern "C" const GUID __declspec(selectany) IID__SecurityPermissionAttribute =
    {0x3a5b876c,0xcde4,0x32d2,{0x9c,0x7e,0x02,0x0a,0x14,0xac,0xa3,0x32}};
extern "C" const GUID __declspec(selectany) IID__UIPermissionAttribute =
    {0x1d5c0f70,0xaf29,0x38a3,{0x94,0x36,0x30,0x70,0xa3,0x10,0xc7,0x3b}};
extern "C" const GUID __declspec(selectany) IID__ZoneIdentityPermissionAttribute =
    {0x2e3be3ed,0x2f22,0x3b20,{0x9f,0x92,0xbd,0x29,0xb7,0x9d,0x6f,0x42}};
extern "C" const GUID __declspec(selectany) IID__StrongNameIdentityPermissionAttribute =
    {0xc9a740f4,0x26e9,0x39a8,{0x88,0x85,0x8c,0xa2,0x6b,0xd7,0x9b,0x21}};
extern "C" const GUID __declspec(selectany) IID__SiteIdentityPermissionAttribute =
    {0x6fe6894a,0x2a53,0x3fb6,{0xa0,0x6e,0x34,0x8f,0x9b,0xda,0xd2,0x3b}};
extern "C" const GUID __declspec(selectany) IID__UrlIdentityPermissionAttribute =
    {0xca4a2073,0x48c5,0x3e61,{0x83,0x49,0x11,0x70,0x1a,0x90,0xdd,0x9b}};
extern "C" const GUID __declspec(selectany) IID__PublisherIdentityPermissionAttribute =
    {0x6722c730,0x1239,0x3784,{0xac,0x94,0xc2,0x85,0xae,0x5b,0x90,0x1a}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStoragePermissionAttribute =
    {0x5c4c522f,0xde4e,0x3595,{0x9a,0xa9,0x93,0x19,0xc8,0x6a,0x52,0x83}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStorageFilePermissionAttribute =
    {0x6f1f8aae,0xd667,0x39cc,{0x98,0xfa,0x72,0x2b,0xeb,0xbb,0xea,0xc3}};
extern "C" const GUID __declspec(selectany) IID__PermissionSetAttribute =
    {0x947a1995,0xbc16,0x3e7c,{0xb6,0x5a,0x99,0xe7,0x1f,0x39,0xc0,0x91}};
extern "C" const GUID __declspec(selectany) IID__ReflectionPermission =
    {0xaeb3727f,0x5c3a,0x34c4,{0xbf,0x18,0xa3,0x8f,0x08,0x8a,0xc8,0xc7}};
extern "C" const GUID __declspec(selectany) IID__PrincipalPermission =
    {0x7c6b06d1,0x63ad,0x35ef,{0xa9,0x38,0x14,0x9b,0x4a,0xd9,0xa7,0x1f}};
extern "C" const GUID __declspec(selectany) IID__SecurityPermission =
    {0x33c54a2d,0x02bd,0x3848,{0x80,0xb6,0x74,0x2d,0x53,0x70,0x85,0xe5}};
extern "C" const GUID __declspec(selectany) IID__SiteIdentityPermission =
    {0x790b3ee9,0x7e06,0x3cd0,{0x82,0x43,0x58,0x48,0x48,0x6d,0x6a,0x78}};
extern "C" const GUID __declspec(selectany) IID__StrongNameIdentityPermission =
    {0x5f1562fb,0x0160,0x3655,{0xba,0xea,0xb1,0x5b,0xef,0x60,0x91,0x61}};
extern "C" const GUID __declspec(selectany) IID__StrongNamePublicKeyBlob =
    {0xaf53d21a,0xd6af,0x3406,{0xb3,0x99,0x7d,0xf9,0xd2,0xaa,0xd4,0x8a}};
extern "C" const GUID __declspec(selectany) IID__UIPermission =
    {0x47698389,0xf182,0x3a67,{0x87,0xdf,0xae,0xd4,0x90,0xe1,0x4d,0xc6}};
extern "C" const GUID __declspec(selectany) IID__UrlIdentityPermission =
    {0xec7cac31,0x08a2,0x393b,{0xbd,0xf2,0xd0,0x52,0xeb,0x53,0xaf,0x2c}};
extern "C" const GUID __declspec(selectany) IID__ZoneIdentityPermission =
    {0x38b2f8d7,0x8cf4,0x323b,{0x9c,0x17,0x9c,0x55,0xee,0x28,0x7a,0x63}};
extern "C" const GUID __declspec(selectany) IID__GacIdentityPermissionAttribute =
    {0x5f19e082,0x26f8,0x3361,{0xb3,0x38,0x9b,0xac,0xb9,0x88,0x09,0xa4}};
extern "C" const GUID __declspec(selectany) IID__GacIdentityPermission =
    {0xa9637792,0x5be8,0x3c93,{0xa5,0x01,0x49,0xf0,0xe8,0x40,0xde,0x38}};
extern "C" const GUID __declspec(selectany) IID__KeyContainerPermissionAccessEntry =
    {0x094351ea,0xdbc1,0x327f,{0x8a,0x83,0x91,0x3b,0x59,0x3a,0x66,0xbe}};
extern "C" const GUID __declspec(selectany) IID__KeyContainerPermissionAccessEntryCollection =
    {0x28ecf94e,0x3510,0x3a3e,{0x8b,0xd1,0xf8,0x66,0xf4,0x5f,0x3b,0x06}};
extern "C" const GUID __declspec(selectany) IID__KeyContainerPermissionAccessEntryEnumerator =
    {0x293187ea,0x5f88,0x316f,{0x86,0xa5,0x53,0x3b,0x0c,0x7b,0x35,0x3f}};
extern "C" const GUID __declspec(selectany) IID__KeyContainerPermission =
    {0x107a3cf1,0xb35e,0x3a23,{0xb6,0x60,0x60,0x26,0x4b,0x23,0x12,0x25}};
extern "C" const GUID __declspec(selectany) IID__PublisherIdentityPermission =
    {0xe86cc74a,0x1233,0x3df3,{0xb1,0x3f,0x8b,0x27,0xee,0xaa,0xc1,0xf6}};
extern "C" const GUID __declspec(selectany) IID__RegistryPermission =
    {0xc3fb5510,0x3454,0x3b31,{0xb6,0x4f,0xde,0x6a,0xad,0x6b,0xe8,0x20}};
extern "C" const GUID __declspec(selectany) IID__SuppressUnmanagedCodeSecurityAttribute =
    {0x8000e51a,0x541c,0x3b20,{0xa8,0xec,0xc8,0xa8,0xb4,0x11,0x16,0xc4}};
extern "C" const GUID __declspec(selectany) IID__UnverifiableCodeAttribute =
    {0x41f41c1b,0x7b8d,0x39a3,{0xa2,0x8f,0xaa,0xe2,0x07,0x87,0xf4,0x69}};
extern "C" const GUID __declspec(selectany) IID__AllowPartiallyTrustedCallersAttribute =
    {0xf1c930c4,0x2233,0x3924,{0x98,0x40,0x23,0x1d,0x00,0x82,0x59,0xb4}};
extern "C" const GUID __declspec(selectany) IID__HostSecurityManager =
    {0x9deae196,0x48c1,0x3590,{0x9d,0x0a,0x33,0x71,0x6a,0x21,0x4a,0xcd}};
extern "C" const GUID __declspec(selectany) IID__PermissionSet =
    {0xc2af4970,0x4fb6,0x319c,{0xa8,0xaa,0x06,0x14,0xd2,0x7f,0x2b,0x2c}};
extern "C" const GUID __declspec(selectany) IID__NamedPermissionSet =
    {0xba3e053f,0xade3,0x3233,{0x87,0x4a,0x16,0xe6,0x24,0xc9,0xa4,0x9b}};
extern "C" const GUID __declspec(selectany) IID__SecurityException =
    {0xf174290f,0xe4cf,0x3976,{0x88,0xaa,0x4f,0x8e,0x32,0xeb,0x03,0xdb}};
extern "C" const GUID __declspec(selectany) IID__HostProtectionException =
    {0xed727a9b,0x6fc5,0x3fed,{0xbe,0xdd,0x7b,0x66,0xc8,0x47,0xf8,0x7a}};
extern "C" const GUID __declspec(selectany) IID__SecurityManager =
    {0xabc04b16,0x5539,0x3c7e,{0x92,0xec,0x09,0x05,0xa4,0xa2,0x44,0x64}};
extern "C" const GUID __declspec(selectany) IID__VerificationException =
    {0xf65070df,0x57af,0x3ae3,{0xb9,0x51,0xd2,0xad,0x7d,0x51,0x33,0x47}};
extern "C" const GUID __declspec(selectany) IID__ContextAttribute =
    {0xf042505b,0x7aac,0x313b,{0xa8,0xc7,0x3f,0x1a,0xc9,0x49,0xc3,0x11}};
extern "C" const GUID __declspec(selectany) IID__AsyncResult =
    {0x3936abe1,0xb29e,0x3593,{0x83,0xf1,0x79,0x3d,0x1a,0x7f,0x38,0x98}};
extern "C" const GUID __declspec(selectany) IID__CallContext =
    {0x53bce4d4,0x6209,0x396d,{0xbd,0x4a,0x0b,0x0a,0x0a,0x17,0x7d,0xf9}};
extern "C" const GUID __declspec(selectany) IID__LogicalCallContext =
    {0x9aff21f5,0x1c9c,0x35e7,{0xae,0xa4,0xc3,0xaa,0x0b,0xeb,0x3b,0x77}};
extern "C" const GUID __declspec(selectany) IID__ChannelServices =
    {0xffb2e16e,0xe5c7,0x367c,{0xb3,0x26,0x96,0x5a,0xbf,0x51,0x0f,0x24}};
extern "C" const GUID __declspec(selectany) IID__ClientChannelSinkStack =
    {0xe1796120,0xc324,0x30d8,{0x86,0xf4,0x20,0x08,0x67,0x11,0x46,0x3b}};
extern "C" const GUID __declspec(selectany) IID__ServerChannelSinkStack =
    {0x52da9f90,0x89b3,0x35ab,{0x90,0x7b,0x35,0x62,0x64,0x29,0x67,0xde}};
extern "C" const GUID __declspec(selectany) IID__ClientSponsor =
    {0xff19d114,0x3bda,0x30ac,{0x8e,0x89,0x36,0xca,0x64,0xa8,0x71,0x20}};
extern "C" const GUID __declspec(selectany) IID__CrossContextDelegate =
    {0xee949b7b,0x439f,0x363e,{0xb9,0xfc,0x34,0xdb,0x1f,0xb7,0x81,0xd7}};
extern "C" const GUID __declspec(selectany) IID__Context =
    {0x11a2ea7a,0xd600,0x307b,{0xa6,0x06,0x51,0x1a,0x6c,0x79,0x50,0xd1}};
extern "C" const GUID __declspec(selectany) IID_IContextProperty =
    {0xf01d896d,0x8d5f,0x3235,{0xbe,0x59,0x20,0xe1,0xe1,0x0d,0xc2,0x2a}};
extern "C" const GUID __declspec(selectany) IID__ContextProperty =
    {0x4acb3495,0x05db,0x381b,{0x89,0x0a,0xd1,0x2f,0x53,0x40,0xdc,0xa3}};
extern "C" const GUID __declspec(selectany) IID__EnterpriseServicesHelper =
    {0x77c9bceb,0x9958,0x33c0,{0xa8,0x58,0x59,0x9f,0x66,0x69,0x7d,0xa7}};
extern "C" const GUID __declspec(selectany) IID__Header =
    {0x0d296515,0xad19,0x3602,{0xb4,0x15,0xd8,0xec,0x77,0x06,0x60,0x81}};
extern "C" const GUID __declspec(selectany) IID__HeaderHandler =
    {0x5dbbaf39,0xa3df,0x30b7,{0xaa,0xea,0x9f,0xd1,0x13,0x94,0x12,0x3f}};
extern "C" const GUID __declspec(selectany) IID_IRemotingFormatter =
    {0xae1850fd,0x3596,0x3727,{0xa2,0x42,0x2f,0xc3,0x1c,0x5a,0x03,0x12}};
extern "C" const GUID __declspec(selectany) IID__ChannelDataStore =
    {0xaa6da581,0xf972,0x36de,{0xa5,0x3b,0x75,0x85,0x42,0x8a,0x68,0xab}};
extern "C" const GUID __declspec(selectany) IID__TransportHeaders =
    {0x65887f70,0xc646,0x3a66,{0x86,0x97,0x8a,0x3f,0x7d,0x8f,0xe9,0x4d}};
extern "C" const GUID __declspec(selectany) IID__SinkProviderData =
    {0xa18545b7,0xe5ee,0x31ee,{0x9b,0x9b,0x41,0x19,0x9b,0x11,0xc9,0x95}};
extern "C" const GUID __declspec(selectany) IID__BaseChannelObjectWithProperties =
    {0xa1329ec9,0xe567,0x369f,{0x82,0x58,0x18,0x36,0x6d,0x89,0xea,0xf8}};
extern "C" const GUID __declspec(selectany) IID__BaseChannelSinkWithProperties =
    {0x8af3451e,0x154d,0x3d86,{0x80,0xd8,0xf8,0x47,0x8b,0x97,0x33,0xed}};
extern "C" const GUID __declspec(selectany) IID__BaseChannelWithProperties =
    {0x94bb98ed,0x18bb,0x3843,{0xa7,0xfe,0x64,0x28,0x24,0xab,0x4e,0x01}};
extern "C" const GUID __declspec(selectany) IID__LifetimeServices =
    {0xb0ad9a21,0x5439,0x3d88,{0x89,0x75,0x40,0x18,0xb8,0x28,0xd7,0x4c}};
extern "C" const GUID __declspec(selectany) IID__ReturnMessage =
    {0x0eeff4c2,0x84bf,0x3e4e,{0xbf,0x22,0xb7,0xbd,0xbb,0x5d,0xf8,0x99}};
extern "C" const GUID __declspec(selectany) IID__MethodCall =
    {0x95e01216,0x5467,0x371b,{0x85,0x97,0x40,0x74,0x40,0x2c,0xcb,0x06}};
extern "C" const GUID __declspec(selectany) IID__ConstructionCall =
    {0xa2246ae7,0xeb81,0x3a20,{0x8e,0x70,0xc9,0xfa,0x34,0x1c,0x7e,0x10}};
extern "C" const GUID __declspec(selectany) IID__MethodResponse =
    {0x9e9ea93a,0xd000,0x3ab9,{0xbf,0xca,0xdd,0xeb,0x39,0x8a,0x55,0xb9}};
extern "C" const GUID __declspec(selectany) IID__ConstructionResponse =
    {0xbe457280,0x6ffa,0x3e76,{0x98,0x22,0x83,0xde,0x63,0xc0,0xc4,0xe0}};
extern "C" const GUID __declspec(selectany) IID__InternalMessageWrapper =
    {0xef926e1f,0x3ee7,0x32bc,{0x8b,0x01,0xc6,0xe9,0x8c,0x24,0xbc,0x19}};
extern "C" const GUID __declspec(selectany) IID__MethodCallMessageWrapper =
    {0xc9614d78,0x10ea,0x3310,{0x87,0xea,0x82,0x1b,0x70,0x63,0x28,0x98}};
extern "C" const GUID __declspec(selectany) IID__MethodReturnMessageWrapper =
    {0x89304439,0xa24f,0x30f6,{0x9a,0x8f,0x89,0xce,0x47,0x2d,0x85,0xda}};
extern "C" const GUID __declspec(selectany) IID__ObjRef =
    {0x1dd3cf3d,0xdf8e,0x32ff,{0x91,0xec,0xe1,0x9a,0xa1,0x0b,0x63,0xfb}};
extern "C" const GUID __declspec(selectany) IID_ITrackingHandler =
    {0x03ec7d10,0x17a5,0x3585,{0x9a,0x2e,0x05,0x96,0xfc,0xac,0x38,0x70}};
extern "C" const GUID __declspec(selectany) IID__OneWayAttribute =
    {0x8ffedc68,0x5233,0x3fa8,{0x81,0x3d,0x40,0x5a,0xab,0xb3,0x3e,0xcb}};
extern "C" const GUID __declspec(selectany) IID__ProxyAttribute =
    {0xd80ff312,0x2930,0x3680,{0xa5,0xe9,0xb4,0x82,0x96,0xc7,0x41,0x5f}};
extern "C" const GUID __declspec(selectany) IID__RealProxy =
    {0xe0cf3f77,0xc7c3,0x33da,{0xbe,0xb4,0x46,0x14,0x7f,0xc9,0x05,0xde}};
extern "C" const GUID __declspec(selectany) IID__SoapAttribute =
    {0x725692a5,0x9e12,0x37f6,{0x91,0x1c,0xe3,0xda,0x77,0xe5,0xfa,0xca}};
extern "C" const GUID __declspec(selectany) IID__SoapTypeAttribute =
    {0xebcdcd84,0x8c74,0x39fd,{0x82,0x1c,0xf5,0xeb,0x3a,0x27,0x04,0xd7}};
extern "C" const GUID __declspec(selectany) IID__SoapMethodAttribute =
    {0xc58145b5,0xbd5a,0x3896,{0x95,0xd9,0xb3,0x58,0xf5,0x4f,0xbc,0x44}};
extern "C" const GUID __declspec(selectany) IID__SoapFieldAttribute =
    {0x46a3f9ff,0xf73c,0x33c7,{0xbc,0xc3,0x1b,0xef,0x4b,0x25,0xe4,0xae}};
extern "C" const GUID __declspec(selectany) IID__SoapParameterAttribute =
    {0xc32abfc9,0x3917,0x30bf,{0xa7,0xbc,0x44,0x25,0x0b,0xdf,0xc5,0xd8}};
extern "C" const GUID __declspec(selectany) IID__RemotingConfiguration =
    {0x4b10971e,0xd61d,0x373f,{0xbc,0x8d,0x2c,0xcf,0x31,0x12,0x62,0x15}};
extern "C" const GUID __declspec(selectany) IID__TypeEntry =
    {0x8359f3ab,0x643f,0x3bcf,{0x91,0xe8,0x16,0xe7,0x79,0xed,0xeb,0xe1}};
extern "C" const GUID __declspec(selectany) IID__ActivatedClientTypeEntry =
    {0xbac12781,0x6865,0x3558,{0xa8,0xd1,0xf1,0xca,0xdd,0x28,0x06,0xdd}};
extern "C" const GUID __declspec(selectany) IID__ActivatedServiceTypeEntry =
    {0x94855a3b,0x5ca2,0x32cf,{0xb1,0xab,0x48,0xfd,0x39,0x15,0x82,0x2c}};
extern "C" const GUID __declspec(selectany) IID__WellKnownClientTypeEntry =
    {0x4d0bc339,0xe3f9,0x3e9e,{0x8f,0x68,0x92,0x16,0x8e,0x6f,0x69,0x81}};
extern "C" const GUID __declspec(selectany) IID__WellKnownServiceTypeEntry =
    {0x60b8b604,0x0aed,0x3093,{0xac,0x05,0xeb,0x98,0xfb,0x29,0xfc,0x47}};
extern "C" const GUID __declspec(selectany) IID__RemotingException =
    {0x7264843f,0xf60c,0x39a9,{0x99,0xe1,0x02,0x91,0x26,0xaa,0x08,0x15}};
extern "C" const GUID __declspec(selectany) IID__ServerException =
    {0x19373c44,0x55b4,0x3487,{0x9a,0xd8,0x4c,0x62,0x1a,0xae,0x85,0xea}};
extern "C" const GUID __declspec(selectany) IID__RemotingTimeoutException =
    {0x44db8e15,0xacb1,0x34ee,{0x81,0xf9,0x56,0xed,0x7a,0xe3,0x7a,0x5c}};
extern "C" const GUID __declspec(selectany) IID__RemotingServices =
    {0x7b91368d,0xa50a,0x3d36,{0xbe,0x8e,0x5b,0x88,0x36,0xa4,0x19,0xad}};
extern "C" const GUID __declspec(selectany) IID__InternalRemotingServices =
    {0xf4efb305,0xcdc4,0x31c5,{0x81,0x02,0x33,0xc9,0xb9,0x17,0x74,0xf3}};
extern "C" const GUID __declspec(selectany) IID__MessageSurrogateFilter =
    {0x04a35d22,0x0b08,0x34e7,{0xa5,0x73,0x88,0xef,0x23,0x74,0x37,0x5e}};
extern "C" const GUID __declspec(selectany) IID__RemotingSurrogateSelector =
    {0x551f7a57,0x8651,0x37db,{0xa9,0x4a,0x6a,0x3c,0xa0,0x9c,0x0e,0xd7}};
extern "C" const GUID __declspec(selectany) IID__SoapServices =
    {0x7416b6ee,0x82e8,0x3a16,{0x96,0x6b,0x01,0x8a,0x40,0xe7,0xb1,0xaa}};
extern "C" const GUID __declspec(selectany) IID__SoapDateTime =
    {0x1738adbc,0x156e,0x3897,{0x84,0x4f,0xc3,0x14,0x7c,0x52,0x8d,0xea}};
extern "C" const GUID __declspec(selectany) IID__SoapDuration =
    {0x7ef50ddb,0x32a5,0x30a1,{0xb4,0x12,0x47,0xfa,0xb9,0x11,0x40,0x4a}};
extern "C" const GUID __declspec(selectany) IID__SoapTime =
    {0xa3bf0bcd,0xec32,0x38e6,{0x92,0xf2,0x5f,0x37,0xba,0xd8,0x03,0x0d}};
extern "C" const GUID __declspec(selectany) IID__SoapDate =
    {0xcfa6e9d2,0xb3de,0x39a6,{0x94,0xd1,0xcc,0x69,0x1d,0xe1,0x93,0xf8}};
extern "C" const GUID __declspec(selectany) IID__SoapYearMonth =
    {0x103c7ef9,0xa9ee,0x35fb,{0x84,0xc5,0x30,0x86,0xc9,0x72,0x5a,0x20}};
extern "C" const GUID __declspec(selectany) IID__SoapYear =
    {0xc20769f3,0x858d,0x316a,{0xbe,0x6d,0xc3,0x47,0xa4,0x79,0x48,0xad}};
extern "C" const GUID __declspec(selectany) IID__SoapMonthDay =
    {0xf9ead0aa,0x4156,0x368f,{0xae,0x05,0xfd,0x59,0xd7,0x0f,0x75,0x8d}};
extern "C" const GUID __declspec(selectany) IID__SoapDay =
    {0xd9e8314d,0x5053,0x3497,{0x8a,0x33,0x97,0xd3,0xdc,0xfe,0x33,0xe2}};
extern "C" const GUID __declspec(selectany) IID__SoapMonth =
    {0xb4e32423,0xe473,0x3562,{0xaa,0x12,0x62,0xfd,0xe5,0xa7,0xd4,0xa2}};
extern "C" const GUID __declspec(selectany) IID__SoapHexBinary =
    {0x63b9da95,0xfb91,0x358a,{0xb7,0xb7,0x90,0xc3,0x4a,0xa3,0x4a,0xb7}};
extern "C" const GUID __declspec(selectany) IID__SoapBase64Binary =
    {0x8ed115a1,0x5e7b,0x34dc,{0xab,0x85,0x90,0x31,0x6f,0x28,0x01,0x5d}};
extern "C" const GUID __declspec(selectany) IID__SoapInteger =
    {0x30c65c40,0x4e54,0x3051,{0x9d,0x8f,0x47,0x09,0xb6,0xab,0x21,0x4c}};
extern "C" const GUID __declspec(selectany) IID__SoapPositiveInteger =
    {0x4979ec29,0xc2b7,0x3ad6,{0x98,0x6d,0x5a,0xaf,0x73,0x44,0xcc,0x4e}};
extern "C" const GUID __declspec(selectany) IID__SoapNonPositiveInteger =
    {0xaaf5401e,0xf71c,0x3fe3,{0x8a,0x73,0xa2,0x50,0x74,0xb2,0x0d,0x3a}};
extern "C" const GUID __declspec(selectany) IID__SoapNonNegativeInteger =
    {0xbc261fc6,0x7132,0x3fb5,{0x9a,0xac,0x22,0x48,0x45,0xd3,0xaa,0x99}};
extern "C" const GUID __declspec(selectany) IID__SoapNegativeInteger =
    {0xe384aa10,0xa70c,0x3943,{0x97,0xcf,0x0f,0x7c,0x28,0x2c,0x3b,0xdc}};
extern "C" const GUID __declspec(selectany) IID__SoapAnyUri =
    {0x818ec118,0xbe7e,0x3cde,{0x92,0xc8,0x44,0xb9,0x91,0x60,0x92,0x0e}};
extern "C" const GUID __declspec(selectany) IID__SoapQName =
    {0x3ac646b6,0x6b84,0x382f,{0x9a,0xed,0x22,0xc2,0x43,0x32,0x44,0xe6}};
extern "C" const GUID __declspec(selectany) IID__SoapNotation =
    {0x974f01f4,0x6086,0x3137,{0x94,0x48,0x6a,0x31,0xfc,0x9b,0xef,0x08}};
extern "C" const GUID __declspec(selectany) IID__SoapNormalizedString =
    {0xf4926b50,0x3f23,0x37e0,{0x9a,0xfa,0xaa,0x91,0xff,0x89,0xa7,0xbd}};
extern "C" const GUID __declspec(selectany) IID__SoapToken =
    {0xab4e97b9,0x651d,0x36f4,{0xaa,0xba,0x28,0xac,0xf5,0x74,0x66,0x24}};
extern "C" const GUID __declspec(selectany) IID__SoapLanguage =
    {0x14aed851,0xa168,0x3462,{0xb8,0x77,0x8f,0x9a,0x01,0x12,0x66,0x53}};
extern "C" const GUID __declspec(selectany) IID__SoapName =
    {0x5eb06bef,0x4adf,0x3cc1,{0xa6,0xf2,0x62,0xf7,0x68,0x86,0xb1,0x3a}};
extern "C" const GUID __declspec(selectany) IID__SoapIdrefs =
    {0x7947a829,0xadb5,0x34d0,{0x9c,0xc8,0x6c,0x17,0x27,0x42,0xc8,0x03}};
extern "C" const GUID __declspec(selectany) IID__SoapEntities =
    {0xaca96da3,0x96ed,0x397e,{0x8a,0x72,0xee,0x1b,0xe1,0x02,0x5f,0x5e}};
extern "C" const GUID __declspec(selectany) IID__SoapNmtoken =
    {0xe941fa15,0xe6c8,0x3dd4,{0xb0,0x60,0xc0,0xdd,0xfb,0xc0,0x24,0x0a}};
extern "C" const GUID __declspec(selectany) IID__SoapNmtokens =
    {0xa5e385ae,0x27fb,0x3708,{0xba,0xf7,0x0b,0xf1,0xf3,0x95,0x57,0x47}};
extern "C" const GUID __declspec(selectany) IID__SoapNcName =
    {0x725cdaf7,0xb739,0x35c1,{0x84,0x63,0xe2,0xa9,0x23,0xe1,0xf6,0x18}};
extern "C" const GUID __declspec(selectany) IID__SoapId =
    {0x6a46b6a2,0x2d2c,0x3c67,{0xaf,0x67,0xaa,0xe0,0x17,0x5f,0x17,0xae}};
extern "C" const GUID __declspec(selectany) IID__SoapIdref =
    {0x7db7fd83,0xde89,0x38e1,{0x96,0x45,0xd4,0xca,0xbd,0xe6,0x94,0xc0}};
extern "C" const GUID __declspec(selectany) IID__SoapEntity =
    {0x37171746,0xb784,0x3586,{0xa7,0xd5,0x69,0x2a,0x76,0x04,0xa6,0x6b}};
extern "C" const GUID __declspec(selectany) IID__SynchronizationAttribute =
    {0x2d985674,0x231c,0x33d4,{0xb1,0x4d,0xf3,0xa6,0xbd,0x2e,0xbe,0x19}};
extern "C" const GUID __declspec(selectany) IID__TrackingServices =
    {0xf51728f2,0x2def,0x308c,{0x87,0x4a,0xcb,0xb1,0xba,0xa9,0xcf,0x9e}};
extern "C" const GUID __declspec(selectany) IID__UrlAttribute =
    {0x717105a3,0x739b,0x3bc3,{0xa2,0xb7,0xad,0x21,0x59,0x03,0xfa,0xd2}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStorage =
    {0x34ec3bd7,0xf2f6,0x3c20,{0xa6,0x39,0x80,0x4b,0xff,0x89,0xdf,0x65}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStorageFile =
    {0x6bbb7dee,0x186f,0x3d51,{0x94,0x86,0xbe,0x0a,0x71,0xe9,0x15,0xce}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStorageFileStream =
    {0x68d5592b,0x47c8,0x381a,{0x8d,0x51,0x39,0x25,0xc1,0x6c,0xf0,0x25}};
extern "C" const GUID __declspec(selectany) IID__IsolatedStorageException =
    {0xaec2b0de,0x9898,0x3607,{0xb8,0x45,0x63,0xe2,0xe3,0x07,0xcb,0x5f}};
extern "C" const GUID __declspec(selectany) IID__InternalRM =
    {0x361a5049,0x1bc8,0x35a9,{0x94,0x6a,0x53,0xa8,0x77,0x90,0x2f,0x25}};
extern "C" const GUID __declspec(selectany) IID__InternalST =
    {0xa864fb13,0xf945,0x3dc0,{0xa0,0x1c,0xb9,0x03,0xf9,0x44,0xfc,0x97}};
extern "C" const GUID __declspec(selectany) IID__SoapMessage =
    {0xbc0847b2,0xbd5c,0x37b3,{0xba,0x67,0x7d,0x2d,0x54,0xb1,0x72,0x38}};
extern "C" const GUID __declspec(selectany) IID__SoapFault =
    {0xa1c392fc,0x314c,0x39d5,{0x8d,0xe6,0x1f,0x8e,0xbc,0xa0,0xa1,0xe2}};
extern "C" const GUID __declspec(selectany) IID__ServerFault =
    {0x02d1bd78,0x3bb6,0x37ad,{0xa9,0xf8,0xf7,0xd5,0xda,0x27,0x3e,0x4e}};
extern "C" const GUID __declspec(selectany) IID__BinaryFormatter =
    {0x3bcf0cb2,0xa849,0x375e,{0x81,0x89,0x1b,0xa5,0xf1,0xf4,0xa9,0xb0}};
extern "C" const GUID __declspec(selectany) IID__DynamicILInfo =
    {0x0daeaee7,0x007b,0x3fca,{0x87,0x55,0xa5,0xc6,0xc3,0x15,0x89,0x55}};
extern "C" const GUID __declspec(selectany) IID__DynamicMethod =
    {0xeaaa2670,0x0fb1,0x33ea,{0x85,0x2b,0xf1,0xc9,0x7f,0xed,0x17,0x97}};
extern "C" const GUID __declspec(selectany) IID__OpCodes =
    {0x1db1cc2a,0xda73,0x389e,{0x82,0x8b,0x5c,0x61,0x6f,0x4f,0xac,0x49}};
extern "C" const GUID __declspec(selectany) IID__GenericTypeParameterBuilder =
    {0xb1a62835,0xfc19,0x35a4,{0xb2,0x06,0xa4,0x52,0x46,0x3d,0x7e,0xe7}};
extern "C" const GUID __declspec(selectany) IID__UnmanagedMarshal =
    {0xfd302d86,0x240a,0x3694,{0xa3,0x1f,0x9e,0xf5,0x9e,0x6e,0x41,0xbc}};
extern "C" const GUID __declspec(selectany) IID__KeySizes =
    {0x8978b0be,0xa89e,0x3ff9,{0x98,0x34,0x77,0x86,0x2c,0xeb,0xff,0x3d}};
extern "C" const GUID __declspec(selectany) IID__CryptographicException =
    {0x4311e8f5,0xb249,0x3f81,{0x8f,0xf4,0xcf,0x85,0x3d,0x85,0x30,0x6d}};
extern "C" const GUID __declspec(selectany) IID__CryptographicUnexpectedOperationException =
    {0x7fb08423,0x038f,0x3acc,{0xb6,0x00,0xe6,0xd0,0x72,0xba,0xe1,0x60}};
extern "C" const GUID __declspec(selectany) IID__RandomNumberGenerator =
    {0x7ae4b03c,0x414a,0x36e0,{0xba,0x68,0xf9,0x60,0x30,0x04,0xc9,0x25}};
extern "C" const GUID __declspec(selectany) IID__RNGCryptoServiceProvider =
    {0x2c65d4c0,0x584c,0x3e4e,{0x8e,0x6d,0x1a,0xfb,0x11,0x2b,0xff,0x69}};
extern "C" const GUID __declspec(selectany) IID__AsymmetricAlgorithm =
    {0x09343ac0,0xd19a,0x3e62,{0xbc,0x16,0x0f,0x60,0x0f,0x10,0x18,0x0a}};
extern "C" const GUID __declspec(selectany) IID__AsymmetricKeyExchangeDeformatter =
    {0xb6685cca,0x7a49,0x37d1,{0xa8,0x05,0x3d,0xe8,0x29,0xcb,0x8d,0xeb}};
extern "C" const GUID __declspec(selectany) IID__AsymmetricKeyExchangeFormatter =
    {0x1365b84b,0x6477,0x3c40,{0xbe,0x6a,0x08,0x9d,0xc0,0x1e,0xce,0xd9}};
extern "C" const GUID __declspec(selectany) IID__AsymmetricSignatureDeformatter =
    {0x7ca5fe57,0xd1ac,0x3064,{0xbb,0x0b,0xf4,0x50,0xbe,0x40,0xf1,0x94}};
extern "C" const GUID __declspec(selectany) IID__AsymmetricSignatureFormatter =
    {0x5363d066,0x6295,0x3618,{0xbe,0x33,0x3f,0x0b,0x07,0x0b,0x79,0x76}};
extern "C" const GUID __declspec(selectany) IID__ToBase64Transform =
    {0x23ded1e1,0x7d5f,0x3936,{0xaa,0x4e,0x18,0xbb,0xcc,0x39,0xb1,0x55}};
extern "C" const GUID __declspec(selectany) IID__FromBase64Transform =
    {0xfc0717a6,0x2e86,0x372f,{0x81,0xf4,0xb3,0x5e,0xd4,0xbd,0xf0,0xde}};
extern "C" const GUID __declspec(selectany) IID__CryptoAPITransform =
    {0x983b8639,0x2ed7,0x364c,{0x98,0x99,0x68,0x2a,0xbb,0x2c,0xe8,0x50}};
extern "C" const GUID __declspec(selectany) IID__CspParameters =
    {0xd5331d95,0xfff2,0x358f,{0xaf,0xd5,0x58,0x8f,0x46,0x9f,0xf2,0xe4}};
extern "C" const GUID __declspec(selectany) IID__CryptoConfig =
    {0xab00f3f8,0x7dde,0x3ff5,{0xb8,0x05,0x6c,0x5d,0xbb,0x20,0x05,0x49}};
extern "C" const GUID __declspec(selectany) IID__CryptoStream =
    {0x4134f762,0xd0ec,0x3210,{0x93,0xc0,0xde,0x4f,0x44,0x3d,0x56,0x69}};
extern "C" const GUID __declspec(selectany) IID__SymmetricAlgorithm =
    {0x05bc0e38,0x7136,0x3825,{0x9e,0x34,0x26,0xc1,0xcf,0x21,0x42,0xc9}};
extern "C" const GUID __declspec(selectany) IID__DES =
    {0xc7ef0214,0xb91c,0x3799,{0x98,0xdd,0xc9,0x94,0xaa,0xbf,0xc7,0x41}};
extern "C" const GUID __declspec(selectany) IID__DESCryptoServiceProvider =
    {0x65e8495e,0x5207,0x3248,{0x92,0x50,0x0f,0xc8,0x49,0xb4,0xf0,0x96}};
extern "C" const GUID __declspec(selectany) IID__DeriveBytes =
    {0x140ee78f,0x067f,0x3765,{0x92,0x58,0xc3,0xbc,0x72,0xfe,0x97,0x6b}};
extern "C" const GUID __declspec(selectany) IID__DSA =
    {0x0eb5b5e0,0x1be6,0x3a5f,{0x87,0xb3,0xe3,0x32,0x33,0x42,0xf4,0x4e}};
extern "C" const GUID __declspec(selectany) IID__DSACryptoServiceProvider =
    {0x1f38aafe,0x7502,0x332f,{0x97,0x1f,0xc2,0xfc,0x70,0x0a,0x1d,0x55}};
extern "C" const GUID __declspec(selectany) IID__DSASignatureDeformatter =
    {0x0e774498,0xade6,0x3820,{0xb1,0xd5,0x42,0x6b,0x06,0x39,0x7b,0xe7}};
extern "C" const GUID __declspec(selectany) IID__DSASignatureFormatter =
    {0x4b5fc561,0x5983,0x31e4,{0x90,0x3b,0x14,0x04,0x23,0x1b,0x2c,0x89}};
extern "C" const GUID __declspec(selectany) IID__HashAlgorithm =
    {0x69d3baba,0x1c3d,0x354c,{0xac,0xfe,0xf1,0x91,0x09,0xec,0x38,0x96}};
extern "C" const GUID __declspec(selectany) IID__KeyedHashAlgorithm =
    {0xd182cf91,0x628c,0x3ff6,{0x87,0xf0,0x41,0xba,0x51,0xcc,0x74,0x33}};
extern "C" const GUID __declspec(selectany) IID__HMAC =
    {0xe5456726,0x33f6,0x34e4,{0x95,0xc2,0xdb,0x2b,0xfa,0x58,0x14,0x62}};
extern "C" const GUID __declspec(selectany) IID__HMACMD5 =
    {0x486360f5,0x6213,0x322b,{0xbe,0xfb,0x45,0x22,0x15,0x79,0xd4,0xaf}};
extern "C" const GUID __declspec(selectany) IID__HMACRIPEMD160 =
    {0x9fd974a5,0x338c,0x37b9,{0xa1,0xb2,0xd4,0x5f,0x0c,0x2b,0x25,0xc2}};
extern "C" const GUID __declspec(selectany) IID__HMACSHA1 =
    {0x63ac7c37,0xc51a,0x3d82,{0x8f,0xdd,0x2a,0x56,0x70,0x39,0xe4,0x6d}};
extern "C" const GUID __declspec(selectany) IID__HMACSHA256 =
    {0x1377ce34,0x8921,0x3bd4,{0x96,0xe9,0xc8,0xd5,0xd5,0xaa,0x1a,0xdf}};
extern "C" const GUID __declspec(selectany) IID__HMACSHA384 =
    {0x786f8ac3,0x93e4,0x3b6f,{0x9f,0x62,0x19,0x01,0xb0,0xe5,0xf4,0x33}};
extern "C" const GUID __declspec(selectany) IID__HMACSHA512 =
    {0xeb081b9d,0xa766,0x3abe,{0xb7,0x20,0x50,0x5c,0x42,0x16,0x2d,0x83}};
extern "C" const GUID __declspec(selectany) IID__CspKeyContainerInfo =
    {0xbe8619cb,0x3731,0x3cb2,{0xa3,0xa8,0xcd,0x0b,0xfa,0x55,0x66,0xec}};
extern "C" const GUID __declspec(selectany) IID_ICspAsymmetricAlgorithm =
    {0x494a7583,0x190e,0x3693,{0x9e,0xc4,0xde,0x54,0xdc,0x6a,0x84,0xa2}};
extern "C" const GUID __declspec(selectany) IID__MACTripleDES =
    {0x1cac0bda,0xac58,0x31bc,{0xb6,0x24,0x63,0xf7,0x7d,0x0c,0x3d,0x2f}};
extern "C" const GUID __declspec(selectany) IID__MD5 =
    {0x9aa8765e,0x69a0,0x30e3,{0x9c,0xde,0xeb,0xc7,0x06,0x62,0xae,0x37}};
extern "C" const GUID __declspec(selectany) IID__MD5CryptoServiceProvider =
    {0xd3f5c812,0x5867,0x33c9,{0x8c,0xee,0xcb,0x17,0x0e,0x8d,0x84,0x4a}};
extern "C" const GUID __declspec(selectany) IID__MaskGenerationMethod =
    {0x85601fee,0xa79d,0x3710,{0xaf,0x21,0x09,0x90,0x89,0xed,0xc0,0xbf}};
extern "C" const GUID __declspec(selectany) IID__PasswordDeriveBytes =
    {0x3cd62d67,0x586f,0x309e,{0xa6,0xd8,0x1f,0x4b,0xaa,0xc5,0xac,0x28}};
extern "C" const GUID __declspec(selectany) IID__PKCS1MaskGenerationMethod =
    {0x425bff0d,0x59e4,0x36a8,{0xb1,0xff,0x1f,0x5d,0x39,0xd6,0x98,0xf4}};
extern "C" const GUID __declspec(selectany) IID__RC2 =
    {0xf7c0c4cc,0x0d49,0x31ee,{0xa3,0xd3,0xb8,0xb5,0x51,0xe4,0x92,0x8c}};
extern "C" const GUID __declspec(selectany) IID__RC2CryptoServiceProvider =
    {0x875715c5,0xcb64,0x3920,{0x81,0x56,0x0e,0xe9,0xcb,0x0e,0x07,0xea}};
extern "C" const GUID __declspec(selectany) IID__Rfc2898DeriveBytes =
    {0xa6589897,0x5a67,0x305f,{0x94,0x97,0x72,0xe5,0xfe,0x8b,0xea,0xd5}};
extern "C" const GUID __declspec(selectany) IID__RIPEMD160 =
    {0xe5481be9,0x3422,0x3506,{0xbc,0x35,0xb9,0x6d,0x45,0x35,0x01,0x4d}};
extern "C" const GUID __declspec(selectany) IID__RIPEMD160Managed =
    {0x814f9c35,0xb7f8,0x3ceb,{0x8e,0x43,0xe0,0x1f,0x09,0x15,0x70,0x60}};
extern "C" const GUID __declspec(selectany) IID__RSA =
    {0x0b3fb710,0xa25c,0x3310,{0x87,0x74,0x1c,0xf1,0x17,0xf9,0x5b,0xd4}};
extern "C" const GUID __declspec(selectany) IID__RSACryptoServiceProvider =
    {0xbd9df856,0x2300,0x3254,{0xbc,0xf0,0x67,0x9b,0xa0,0x3c,0x7a,0x13}};
extern "C" const GUID __declspec(selectany) IID__RSAOAEPKeyExchangeDeformatter =
    {0x37625095,0x7baa,0x377d,{0xa0,0xdc,0x7f,0x46,0x5c,0x01,0x67,0xaa}};
extern "C" const GUID __declspec(selectany) IID__RSAOAEPKeyExchangeFormatter =
    {0x77a416e7,0x2ac6,0x3d0e,{0x98,0xff,0x3b,0xa0,0xf5,0x86,0xf5,0x6f}};
extern "C" const GUID __declspec(selectany) IID__RSAPKCS1KeyExchangeDeformatter =
    {0x8034aaf4,0x3666,0x3b6f,{0x85,0xcf,0x46,0x3f,0x9b,0xfd,0x31,0xa9}};
extern "C" const GUID __declspec(selectany) IID__RSAPKCS1KeyExchangeFormatter =
    {0x9ff67f8e,0xa7aa,0x3ba6,{0x90,0xee,0x9d,0x44,0xaf,0x6e,0x2f,0x8c}};
extern "C" const GUID __declspec(selectany) IID__RSAPKCS1SignatureDeformatter =
    {0xfc38507e,0x06a4,0x3300,{0x86,0x52,0x8d,0x7b,0x54,0x34,0x1f,0x65}};
extern "C" const GUID __declspec(selectany) IID__RSAPKCS1SignatureFormatter =
    {0xfb7a5ff4,0xcfa8,0x3f24,{0xad,0x5f,0xd5,0xeb,0x39,0x35,0x97,0x07}};
extern "C" const GUID __declspec(selectany) IID__Rijndael =
    {0x21b52a91,0x856f,0x373c,{0xad,0x42,0x4c,0xf3,0xf1,0x02,0x1f,0x5a}};
extern "C" const GUID __declspec(selectany) IID__RijndaelManaged =
    {0x427ea9d3,0x11d8,0x3e38,{0x9e,0x05,0xa4,0xf7,0xfa,0x68,0x41,0x83}};
extern "C" const GUID __declspec(selectany) IID__RijndaelManagedTransform =
    {0x5767c78f,0xf344,0x35a5,{0x84,0xbc,0x53,0xb9,0xea,0xeb,0x68,0xcb}};
extern "C" const GUID __declspec(selectany) IID__SHA1 =
    {0x48600dd2,0x0099,0x337f,{0x92,0xd6,0x96,0x1d,0x1e,0x50,0x10,0xd4}};
extern "C" const GUID __declspec(selectany) IID__SHA1CryptoServiceProvider =
    {0xa16537bc,0x1edf,0x3516,{0xb7,0x5e,0xcc,0x65,0xca,0xf8,0x73,0xab}};
extern "C" const GUID __declspec(selectany) IID__SHA1Managed =
    {0xc27990bb,0x3cfd,0x3d29,{0x8d,0xc0,0xbb,0xe5,0xfb,0xad,0xea,0xfd}};
extern "C" const GUID __declspec(selectany) IID__SHA256 =
    {0x3b274703,0xdfae,0x3f9c,{0xa1,0xb5,0x99,0x90,0xdf,0x9d,0x7f,0xa3}};
extern "C" const GUID __declspec(selectany) IID__SHA256Managed =
    {0x3d077954,0x7bcc,0x325b,{0x9d,0xda,0x3b,0x17,0xa0,0x33,0x78,0xe0}};
extern "C" const GUID __declspec(selectany) IID__SHA384 =
    {0xb60ad5d7,0x2c2e,0x35b7,{0x8d,0x77,0x79,0x46,0x15,0x6c,0xfe,0x8e}};
extern "C" const GUID __declspec(selectany) IID__SHA384Managed =
    {0xde541460,0xf838,0x3698,{0xb2,0xda,0x51,0x0b,0x09,0x07,0x01,0x18}};
extern "C" const GUID __declspec(selectany) IID__SHA512 =
    {0x49dd9e4b,0x84f3,0x3d6d,{0x91,0xfb,0x3f,0xed,0xce,0xf6,0x34,0xc7}};
extern "C" const GUID __declspec(selectany) IID__SHA512Managed =
    {0xdc8ce439,0x7954,0x36ed,{0x80,0x3c,0x67,0x4f,0x72,0xf2,0x72,0x49}};
extern "C" const GUID __declspec(selectany) IID__SignatureDescription =
    {0x8017b414,0x4886,0x33da,{0x80,0xa3,0x78,0x65,0xc1,0x35,0x0d,0x43}};
extern "C" const GUID __declspec(selectany) IID__TripleDES =
    {0xc040b889,0x5278,0x3132,{0xaf,0xf9,0xaf,0xa6,0x17,0x07,0xa8,0x1d}};
extern "C" const GUID __declspec(selectany) IID__TripleDESCryptoServiceProvider =
    {0xec69d083,0x3cd0,0x3c0c,{0x99,0x8c,0x3b,0x73,0x8d,0xb5,0x35,0xd5}};
extern "C" const GUID __declspec(selectany) IID__X509Certificate =
    {0x68fd6f14,0xa7b2,0x36c8,{0xa7,0x24,0xd0,0x1f,0x90,0xd7,0x34,0x77}};
extern "C" const GUID __declspec(selectany) IID_IFormattable =
    {0x9a604ee7,0xe630,0x3ded,{0x94,0x44,0xba,0xae,0x24,0x70,0x75,0xab}};
extern "C" const GUID __declspec(selectany) IID_IConvertible =
    {0x805e3b62,0xb5e9,0x393d,{0x89,0x41,0x37,0x7d,0x8b,0xf4,0x55,0x6b}};
extern "C" const GUID __declspec(selectany) IID__Exception =
    {0xb36b5c63,0x42ef,0x38bc,{0xa0,0x7e,0x0b,0x34,0xc9,0x8f,0x16,0x4a}};
extern "C" const GUID __declspec(selectany) IID_IClientResponseChannelSinkStack =
    {0x3afab213,0xf5a2,0x3241,{0x93,0xba,0x32,0x9e,0xa4,0xba,0x80,0x16}};
extern "C" const GUID __declspec(selectany) IID_IMethodReturnMessage =
    {0xf617690a,0x55f4,0x36af,{0x91,0x49,0xd1,0x99,0x83,0x1f,0x85,0x94}};
extern "C" const GUID __declspec(selectany) IID__AppDomain =
    {0x05f696dc,0x2b29,0x3663,{0xad,0x8b,0xc4,0x38,0x9c,0xf2,0xa7,0x13}};
extern "C" const GUID __declspec(selectany) IID_ICustomFormatter =
    {0x2b130940,0xca5e,0x3406,{0x83,0x85,0xe2,0x59,0xe6,0x8a,0xb0,0x39}};
extern "C" const GUID __declspec(selectany) IID_IFormatProvider =
    {0xc8cb1ded,0x2814,0x396a,{0x9c,0xc0,0x47,0x3c,0xa4,0x97,0x79,0xcc}};
extern "C" const GUID __declspec(selectany) IID_ICustomAttributeProvider =
    {0xb9b91146,0xd6c2,0x3a62,{0x81,0x59,0xc2,0xd1,0x79,0x4c,0xde,0xb0}};
extern "C" const GUID __declspec(selectany) IID__MemberInfo =
    {0xf7102fa9,0xcabb,0x3a74,{0xa6,0xda,0xb4,0x56,0x7e,0xf1,0xb0,0x79}};
extern "C" const GUID __declspec(selectany) IID__Type =
    {0xbca8b44d,0xaad6,0x3a86,{0x8a,0xb7,0x03,0x34,0x9f,0x4f,0x2d,0xa2}};
extern "C" const GUID __declspec(selectany) IID_IFormatterConverter =
    {0xf4f5c303,0xfad3,0x3d0c,{0xa4,0xdf,0xbb,0x82,0xb5,0xee,0x30,0x8f}};
extern "C" const GUID __declspec(selectany) IID_ICustomFactory =
    {0x0ca9008e,0xee90,0x356e,{0x9f,0x6d,0xb5,0x9e,0x60,0x06,0xb9,0xa4}};
extern "C" const GUID __declspec(selectany) IID_IRemotingTypeInfo =
    {0xc09effa9,0x1ffe,0x3a52,{0xa7,0x33,0x62,0x36,0xcb,0xc4,0x5e,0x7b}};
extern "C" const GUID __declspec(selectany) IID__Object =
    {0x65074f7f,0x63c0,0x304e,{0xaf,0x0a,0xd5,0x17,0x41,0xcb,0x4a,0x8d}};
extern "C" const GUID __declspec(selectany) IID__ObjectHandle =
    {0xea675b47,0x64e0,0x3b5f,{0x9b,0xe7,0xf7,0xdc,0x29,0x90,0x73,0x0d}};
extern "C" const GUID __declspec(selectany) IID_IReflect =
    {0xafbf15e5,0xc37c,0x11d2,{0xb8,0x8e,0x00,0xa0,0xc9,0xb4,0x71,0xb8}};
extern "C" const GUID __declspec(selectany) IID_ISymbolBinder =
    {0x20808adc,0xcc01,0x3f3a,{0x8f,0x09,0xed,0x12,0x94,0x0f,0xc2,0x12}};
extern "C" const GUID __declspec(selectany) IID_ISymbolBinder1 =
    {0x027c036a,0x4052,0x3821,{0x85,0xde,0xb5,0x33,0x19,0xdf,0x12,0x11}};
extern "C" const GUID __declspec(selectany) IID_ISymbolMethod =
    {0x25c72eb0,0xe437,0x3f17,{0x94,0x6d,0x3b,0x72,0xa3,0xac,0xff,0x37}};
extern "C" const GUID __declspec(selectany) IID_ISymbolReader =
    {0xe809a5f1,0xd3d7,0x3144,{0x9b,0xef,0xfe,0x8a,0xc0,0x36,0x46,0x99}};
extern "C" const GUID __declspec(selectany) IID_ISymbolScope =
    {0x1cee3a11,0x01ae,0x3244,{0xa9,0x39,0x49,0x72,0xfc,0x97,0x03,0xef}};
extern "C" const GUID __declspec(selectany) IID__Assembly =
    {0x17156360,0x2f1a,0x384a,{0xbc,0x52,0xfd,0xe9,0x3c,0x21,0x5c,0x5b}};
extern "C" const GUID __declspec(selectany) IID_ITypeLibImporterNotifySink =
    {0xf1c3bf76,0xc3e4,0x11d3,{0x88,0xe7,0x00,0x90,0x27,0x54,0xc4,0x3a}};
extern "C" const GUID __declspec(selectany) IID_IRegistrationServices =
    {0xccbd682c,0x73a5,0x4568,{0xb8,0xb0,0xc7,0x00,0x7e,0x11,0xab,0xa2}};
extern "C" const GUID __declspec(selectany) IID_ITypeLibExporterNotifySink =
    {0xf1c3bf77,0xc3e4,0x11d3,{0x88,0xe7,0x00,0x90,0x27,0x54,0xc4,0x3a}};
extern "C" const GUID __declspec(selectany) IID_ITypeLibConverter =
    {0xf1c3bf78,0xc3e4,0x11d3,{0x88,0xe7,0x00,0x90,0x27,0x54,0xc4,0x3a}};
extern "C" const GUID __declspec(selectany) IID__MethodBase =
    {0x6240837a,0x707f,0x3181,{0x8e,0x98,0xa3,0x6a,0xe0,0x86,0x76,0x6b}};
extern "C" const GUID __declspec(selectany) IID_IMethodMessage =
    {0x8e5e0b95,0x750e,0x310d,{0x89,0x2c,0x8c,0xa7,0x23,0x1c,0xf7,0x5b}};
extern "C" const GUID __declspec(selectany) IID__MethodInfo =
    {0xffcc1b5d,0xecb8,0x38dd,{0x9b,0x01,0x3d,0xc8,0xab,0xc2,0xaa,0x5f}};
extern "C" const GUID __declspec(selectany) IID__Delegate =
    {0xfb6ab00f,0x5096,0x3af8,{0xa3,0x3d,0xd7,0x88,0x5a,0x5f,0xa8,0x29}};
extern "C" const GUID __declspec(selectany) IID__EventInfo =
    {0x9de59c64,0xd889,0x35a1,{0xb8,0x97,0x58,0x7d,0x74,0x46,0x9e,0x5b}};
extern "C" const GUID __declspec(selectany) IID__ConstructorInfo =
    {0xe9a19478,0x9646,0x3679,{0x9b,0x10,0x84,0x11,0xae,0x1f,0xd5,0x7d}};
extern "C" const GUID __declspec(selectany) IID__FieldInfo =
    {0x8a7c1442,0xa9fb,0x366b,{0x80,0xd8,0x49,0x39,0xff,0xa6,0xdb,0xe0}};
extern "C" const GUID __declspec(selectany) IID__PropertyInfo =
    {0xf59ed4e4,0xe68f,0x3218,{0xbd,0x77,0x06,0x1a,0xa8,0x28,0x24,0xbf}};
extern "C" const GUID __declspec(selectany) IID_IExpando =
    {0xafbf15e6,0xc37c,0x11d2,{0xb8,0x8e,0x00,0xa0,0xc9,0xb4,0x71,0xb8}};
extern "C" const GUID __declspec(selectany) IID__Binder =
    {0x3169ab11,0x7109,0x3808,{0x9a,0x61,0xef,0x4b,0xa0,0x53,0x4f,0xd9}};
extern "C" const GUID __declspec(selectany) IID_IFormatter =
    {0x93d7a8c5,0xd2eb,0x319b,{0xa3,0x74,0xa6,0x5d,0x32,0x1f,0x2a,0xa9}};
extern "C" const GUID __declspec(selectany) IID_ISerializationSurrogate =
    {0x62339172,0xdbfa,0x337b,{0x8a,0xc8,0x05,0x3b,0x24,0x1e,0x06,0xab}};
extern "C" const GUID __declspec(selectany) IID_ISurrogateSelector =
    {0x7c66ff18,0xa1a5,0x3e19,{0x85,0x7b,0x0e,0x7b,0x6a,0x9e,0x3f,0x38}};
extern "C" const GUID __declspec(selectany) IID_IContextAttribute =
    {0x4a68baa3,0x27aa,0x314a,{0xbd,0xbb,0x6a,0xe9,0xbd,0xfc,0x04,0x20}};
extern "C" const GUID __declspec(selectany) IID_IActivator =
    {0xc02bbb79,0x5aa8,0x390d,{0x92,0x7f,0x71,0x7b,0x7b,0xff,0x06,0xa1}};
extern "C" const GUID __declspec(selectany) IID_IConstructionCallMessage =
    {0xfa28e3af,0x7d09,0x31d5,{0xbe,0xeb,0x7f,0x26,0x26,0x49,0x7c,0xde}};
extern "C" const GUID __declspec(selectany) IID_IContextPropertyActivator =
    {0x7197b56b,0x5fa1,0x31ef,{0xb3,0x8b,0x62,0xfe,0xe7,0x37,0x27,0x7f}};
extern "C" const GUID __declspec(selectany) IID_IClientChannelSinkStack =
    {0x3a5fde6b,0xdb46,0x34e8,{0xba,0xcd,0x16,0xea,0x5a,0x44,0x05,0x40}};
extern "C" const GUID __declspec(selectany) IID_IClientChannelSink =
    {0xff726320,0x6b92,0x3e6c,{0xaa,0xac,0xf9,0x70,0x63,0xd0,0xb1,0x42}};
extern "C" const GUID __declspec(selectany) IID_IClientChannelSinkProvider =
    {0x3f8742c2,0xac57,0x3440,{0xa2,0x83,0xfe,0x5f,0xf4,0xc7,0x50,0x25}};
extern "C" const GUID __declspec(selectany) IID_IServerChannelSinkStack =
    {0xe694a733,0x768d,0x314d,{0xb3,0x17,0xdc,0xea,0xd1,0x36,0xb1,0x1d}};
extern "C" const GUID __declspec(selectany) IID_IServerChannelSink =
    {0x21b5f37b,0xbef3,0x354c,{0x8f,0x84,0x0f,0x9f,0x08,0x63,0xf5,0xc5}};
extern "C" const GUID __declspec(selectany) IID_IServerChannelSinkProvider =
    {0x7dd6e975,0x24ea,0x323c,{0xa9,0x8c,0x0f,0xde,0x96,0xf9,0xc4,0xe6}};
extern "C" const GUID __declspec(selectany) IID_IChannelReceiverHook =
    {0x3a02d3f7,0x3f40,0x3022,{0x85,0x3d,0xcf,0xda,0x76,0x51,0x82,0xfe}};
extern "C" const GUID __declspec(selectany) IID_ISponsor =
    {0x675591af,0x0508,0x3131,{0xa7,0xcc,0x28,0x7d,0x26,0x5c,0xa7,0xd6}};
extern "C" const GUID __declspec(selectany) IID_ILease =
    {0x53a561f2,0xcbbf,0x3748,{0xbf,0xfe,0x21,0x80,0x00,0x2d,0xb3,0xdf}};

} // namespace mscorlib

#pragma pack(pop)