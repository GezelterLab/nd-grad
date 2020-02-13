// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License.See the LICENSE file in the project root for license information.
//
// Name: testKE_RNEMD.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/24/2020-10:07:51
// Description: Provides 100% unit test coverage over all parameter parsing functions for FluxType = KE

#include <fstream>
#include "../testAssertions.hpp"

using namespace OpenMD::RNEMD;
using namespace Utilities_API::PhysicalQuantities;

RNEMDFilePtr rnemdFile {std::make_shared<RNEMDFile>("../../../rnemd/samples/thermal.rnemd")};

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testKE_RNEMD, KE_FluxTypeCorrectBlockParameters)
{
    RNEMDBlockParametersPtr rnemdBlock { rnemdFile->getRNEMDBlockParameters() };

    assertThat(rnemdFile, rnemdBlock->exchangeMethod).hasAValueOf("VSS");
    assertThat(rnemdFile, rnemdBlock->fluxType).hasAValueOf("KE");
    assertThat(rnemdFile, rnemdBlock->privilegedAxis).hasAValueOf("z");
    assertThat(rnemdFile, rnemdBlock->exchangeTime.getMagnitude()).hasAValueNear(1.0);

    assertThat(rnemdFile, rnemdBlock->objectSelection[0]).hasAValueOf("SPCE_RB_0");

    assertThat(rnemdFile, rnemdBlock->selectionA[0].getMagnitude()).hasAValueNear(-2.0);
    assertThat(rnemdFile, rnemdBlock->selectionA[1].getMagnitude()).hasAValueNear(2.0);

    assertThat(rnemdFile, rnemdBlock->selectionB[0].getMagnitude()).hasAValueNear(18);
    assertThat(rnemdFile, rnemdBlock->selectionB[1].getMagnitude()).hasAValueNear(-18);

    assertThat(rnemdFile, rnemdBlock->outputSelection[0]).hasAValueOf("SPCE_RB_0");
}

TEST(testKE_RNEMD, KE_FluxTypeCorrectInferredParameters)
{
    RNEMDInferredParametersPtr rnemdInferred { rnemdFile->getRNEMDInferredParameters() };

    assertThat(rnemdFile, rnemdInferred->numberOfRegions).hasAValueOf(4);
    assertThat(rnemdFile, rnemdInferred->slabWidth.getMagnitude()).hasAValueNear(4.0);
    assertThat(rnemdFile, rnemdInferred->dataFieldLabelIndex).hasAValueOf(35);
    assertThat(rnemdFile, rnemdInferred->boxSize.getMagnitude()).hasAValueNear(40.0);
    assertThat(rnemdFile, rnemdInferred->hasSelectionB).isTrue();
}

TEST(testKE_RNEMD, KE_FluxTypeCorrectReportParameters)
{
    RNEMDReportParametersPtr rnemdReport { rnemdFile->getRNEMDReportParameters() };

    assertThat(rnemdFile, rnemdReport->runningTime.getMagnitude()).hasAValueNear(10000002.0);


    // Target Fluxes
    assertThat(rnemdFile, rnemdReport->kineticFlux.getMagnitude()).hasAValueNear(4e-6);

    assertThat(rnemdFile, rnemdReport->momentumFlux[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->momentumFlux[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->momentumFlux[2].getMagnitude()).hasAValueNear(0.0);

    assertThat(rnemdFile, rnemdReport->angularMomentumFlux[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->angularMomentumFlux[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->angularMomentumFlux[2].getMagnitude()).hasAValueNear(0.0);

    assertThat(rnemdFile, rnemdReport->currentDensity.getMagnitude()).hasAValueNear(0.0);


    // Target One-Time Exchanges
    assertThat(rnemdFile, rnemdReport->kineticTarget.getMagnitude()).hasAValueNear(0.0030701448);

    assertThat(rnemdFile, rnemdReport->momentumTarget[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->momentumTarget[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->momentumTarget[2].getMagnitude()).hasAValueNear(0.0);

    assertThat(rnemdFile, rnemdReport->angularMomentumTarget[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->angularMomentumTarget[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->angularMomentumTarget[2].getMagnitude()).hasAValueNear(0.0);


    // Actual Exchange Totals
    assertThat(rnemdFile, rnemdReport->kineticExchange.getMagnitude()).hasAValueNear(15350.724);

    assertThat(rnemdFile, rnemdReport->momentumExchange[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->momentumExchange[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->momentumExchange[2].getMagnitude()).hasAValueNear(0.0);

    assertThat(rnemdFile, rnemdReport->angularMomentumExchange[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->angularMomentumExchange[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->angularMomentumExchange[2].getMagnitude()).hasAValueNear(0.0);


    // Actual Fluxes
    assertThat(rnemdFile, rnemdReport->Jz.getMagnitude()).hasAValueNear(1.9999996e-6);

    assertThat(rnemdFile, rnemdReport->JzP[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->JzP[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->JzP[2].getMagnitude()).hasAValueNear(0.0);

    assertThat(rnemdFile, rnemdReport->JzL[0].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->JzL[1].getMagnitude()).hasAValueNear(0.0);
    assertThat(rnemdFile, rnemdReport->JzL[2].getMagnitude()).hasAValueNear(0.0);


    // Exchange Statistics
    assertThat(rnemdFile, rnemdReport->trialCount).hasAValueOf(5000000);
    assertThat(rnemdFile, rnemdReport->failTrialCount).hasAValueOf(0);
}

TEST(testKE_RNEMD, KE_FluxTypeCorrectSplitting)
{
    int sizeOfRNEMDAxis {};
    RNEMDDataPtr rnemdData { rnemdFile->getAllDataFromFile() };

    std::vector<RNEMDRegionPtr> rnemdRegionData { rnemdFile->getRNEMDRegions() };
    RNEMDInferredParametersPtr rnemdInferred { rnemdFile->getRNEMDInferredParameters() };

    // Test Correct Region Specific Data
    for (int region {1}; region <= rnemdInferred->numberOfRegions; ++region)
    {
        RNEMDDataPtr individualRegionData { rnemdRegionData[region - 1]->getRegionSpecificData() };

        if (region == 1)
            rnemdRegionData[0]->makeFirstRegionContinuous(rnemdInferred->boxSize);

        std::vector<Length> z { individualRegionData->rnemdAxis };
        std::vector<Temperature> temp { individualRegionData->temperature };

        std::ofstream outputFile;
        outputFile.open("Thermal" + std::to_string(region) + ".txt");

        for (size_t j {}; j < z.size(); ++j)
            outputFile << z[j] << " " << temp[j] << std::endl;

        outputFile.close();

        sizeOfRNEMDAxis += z.size();
    }

    ASSERT_EQ(rnemdData->rnemdAxis.size(), sizeOfRNEMDAxis);
}
