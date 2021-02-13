// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AudioSplinePlugin/Public/AudioSpline.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAudioSpline() {}
// Cross Module References
	AUDIOSPLINEPLUGIN_API UClass* Z_Construct_UClass_AAudioSpline_NoRegister();
	AUDIOSPLINEPLUGIN_API UClass* Z_Construct_UClass_AAudioSpline();
	ENGINE_API UClass* Z_Construct_UClass_AAmbientSound();
	UPackage* Z_Construct_UPackage__Script_AudioSplinePlugin();
// End Cross Module References
	void AAudioSpline::StaticRegisterNativesAAudioSpline()
	{
	}
	UClass* Z_Construct_UClass_AAudioSpline_NoRegister()
	{
		return AAudioSpline::StaticClass();
	}
	struct Z_Construct_UClass_AAudioSpline_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Range_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Range;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDebug_MetaData[];
#endif
		static void NewProp_bDebug_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDebug;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowDualSource_MetaData[];
#endif
		static void NewProp_bAllowDualSource_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowDualSource;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAudioSpline_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAmbientSound,
		(UObject* (*)())Z_Construct_UPackage__Script_AudioSplinePlugin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Audio" },
		{ "BlueprintType", "true" },
		{ "HideCategories", "Collision Input Game" },
		{ "IncludePath", "AudioSpline.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput Game|Damage" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range_MetaData[] = {
		{ "Category", "AudioSpline" },
		{ "Comment", "// Distance between main AudioComponent and Player. The sound is Stopped when the player goes beyond the Range\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Distance between main AudioComponent and Player. The sound is Stopped when the player goes beyond the Range" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range = { "Range", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, Range), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "AudioSpline" },
		{ "Comment", "// Tick interval\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Tick interval" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, UpdateInterval), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_MetaData[] = {
		{ "Category", "AudioSpline" },
		{ "Comment", "// Debug\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Debug" },
	};
#endif
	void Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_SetBit(void* Obj)
	{
		((AAudioSpline*)Obj)->bDebug = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug = { "bDebug", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AAudioSpline), &Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_MetaData[] = {
		{ "Category", "Dual Source Mode" },
		{ "Comment", "// The DualSource spawns a new Audio Source if the closest location jumps above a threshold\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "The DualSource spawns a new Audio Source if the closest location jumps above a threshold" },
	};
#endif
	void Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_SetBit(void* Obj)
	{
		((AAudioSpline*)Obj)->bAllowDualSource = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource = { "bAllowDualSource", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AAudioSpline), &Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_SetBit, METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAudioSpline_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAudioSpline_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAudioSpline>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAudioSpline_Statics::ClassParams = {
		&AAudioSpline::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAudioSpline_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAudioSpline()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAudioSpline_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAudioSpline, 794601039);
	template<> AUDIOSPLINEPLUGIN_API UClass* StaticClass<AAudioSpline>()
	{
		return AAudioSpline::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAudioSpline(Z_Construct_UClass_AAudioSpline, &AAudioSpline::StaticClass, TEXT("/Script/AudioSplinePlugin"), TEXT("AAudioSpline"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAudioSpline);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
