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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpThreshold_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_JumpThreshold;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowJumpScanner_MetaData[];
#endif
		static void NewProp_bAllowJumpScanner_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowJumpScanner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AdjustedVolume_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AdjustedVolume;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AdjustedVolumeDuration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AdjustedVolumeDuration;
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
		{ "Comment", "// The sound is stopped If the distance between the Player and the Audio Component is greater than the Range. \n// Otherwise the sound fades-in.\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "The sound is stopped If the distance between the Player and the Audio Component is greater than the Range.\nOtherwise the sound fades-in." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range = { "Range", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, Range), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "AudioSpline" },
		{ "Comment", "// User-defined Tick interval\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "User-defined Tick interval" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, UpdateInterval), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_MetaData[] = {
		{ "Category", "AudioSpline" },
		{ "Comment", "// Draw a sphere around the active audio sources. \n// There will be an inner sphere to quickly visualise the sound and an outer sphere that represents the Range described above.\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Draw a sphere around the active audio sources.\nThere will be an inner sphere to quickly visualise the sound and an outer sphere that represents the Range described above." },
	};
#endif
	void Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_SetBit(void* Obj)
	{
		((AAudioSpline*)Obj)->bDebug = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug = { "bDebug", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AAudioSpline), &Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_MetaData[] = {
		{ "Category", "Dual Source Mode" },
		{ "Comment", "// The DualSource spawns a new Audio Source if the closest location on the spline jumps above a threshold.\n// Do not update this bool during PIE(Play In Editor)\n" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "The DualSource spawns a new Audio Source if the closest location on the spline jumps above a threshold.\nDo not update this bool during PIE(Play In Editor)" },
	};
#endif
	void Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_SetBit(void* Obj)
	{
		((AAudioSpline*)Obj)->bAllowDualSource = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource = { "bAllowDualSource", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AAudioSpline), &Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_SetBit, METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_JumpThreshold_MetaData[] = {
		{ "Category", "Dual Source Mode" },
		{ "Comment", "// Play the Audio Source If the difference between the old and the current source position is greater than JumpThreshold. \n// Use the Jump Scanner to find a value that suits your needs. If a Jump is detected it will be printed out into the Output Log.\n" },
		{ "EditCondition", "bAllowDualSource" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Play the Audio Source If the difference between the old and the current source position is greater than JumpThreshold.\nUse the Jump Scanner to find a value that suits your needs. If a Jump is detected it will be printed out into the Output Log." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_JumpThreshold = { "JumpThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, JumpThreshold), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_JumpThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_JumpThreshold_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner_MetaData[] = {
		{ "Category", "Dual Source Mode" },
		{ "Comment", "// Print to the Output Log the biggest jump detected during PIE (Play In Editor). \n// This will help you decide which value to put onto the Jump Threshold.\n" },
		{ "EditCondition", "bAllowDualSource" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Print to the Output Log the biggest jump detected during PIE (Play In Editor).\nThis will help you decide which value to put onto the Jump Threshold." },
	};
#endif
	void Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner_SetBit(void* Obj)
	{
		((AAudioSpline*)Obj)->bAllowJumpScanner = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner = { "bAllowJumpScanner", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AAudioSpline), &Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner_SetBit, METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolume_MetaData[] = {
		{ "Category", "Dual Source Mode" },
		{ "Comment", "// Volume of BOTH Audio Components when the Dual Source is spawned  \n" },
		{ "EditCondition", "bAllowDualSource" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "Volume of BOTH Audio Components when the Dual Source is spawned" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolume = { "AdjustedVolume", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, AdjustedVolume), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolume_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolume_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolumeDuration_MetaData[] = {
		{ "Category", "Dual Source Mode" },
		{ "Comment", "// How quick the Main Audio Component is going to fade/adjust its volume when Dual Audio Component spawns OR get killed\n" },
		{ "EditCondition", "bAllowDualSource" },
		{ "ModuleRelativePath", "Public/AudioSpline.h" },
		{ "ToolTip", "How quick the Main Audio Component is going to fade/adjust its volume when Dual Audio Component spawns OR get killed" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolumeDuration = { "AdjustedVolumeDuration", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAudioSpline, AdjustedVolumeDuration), METADATA_PARAMS(Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolumeDuration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolumeDuration_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAudioSpline_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_Range,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_UpdateInterval,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_bDebug,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowDualSource,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_JumpThreshold,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_bAllowJumpScanner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolume,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAudioSpline_Statics::NewProp_AdjustedVolumeDuration,
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
	IMPLEMENT_CLASS(AAudioSpline, 2013164703);
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
