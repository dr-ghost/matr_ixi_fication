// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MatrixificationHUD.generated.h"

UCLASS()
class AMatrixificationHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMatrixificationHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

