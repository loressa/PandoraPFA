/**
 *  @file   PandoraPFANew/include/Algorithms/Cheating/PerfectClusteringAlgorithm.h
 * 
 *  @brief  Header file for the cheating clustering algorithm class.
 * 
 *  $Log: $
 */
#ifndef PERFECT_CLUSTERING_ALGORITHM_H
#define PERFECT_CLUSTERING_ALGORITHM_H 1

#include "Algorithms/Algorithm.h"

/**
 *  @brief PerfectClusteringAlgorithm class
 */
class PerfectClusteringAlgorithm : public pandora::Algorithm
{
public:
    /**
     *  @brief  Factory class for instantiating algorithm
     */
    class Factory : public pandora::AlgorithmFactory
    {
    public:
        Algorithm *CreateAlgorithm() const;
    };

protected:
    virtual bool SelectMCParticlesForClustering(const pandora::MCParticle *pMcParticle) const;

private:
    StatusCode Run();
    StatusCode ReadSettings(const TiXmlHandle xmlHandle);

    std::string         m_clusterListName;              ///< if clusterListName is set, cluster-list are stored with this name
    std::string         m_orderedCaloHitListName;       ///< if orderedCaloHitListName is set, the orderedCaloHitList containing the remaining hits are stored and set current

    pandora::IntVector  m_particleIdList;               ///< list of particle ids of MCPFOs to be selected

    bool                m_debug;                        ///< turn on additional debugging output
};

//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::Algorithm *PerfectClusteringAlgorithm::Factory::CreateAlgorithm() const
{
    return new PerfectClusteringAlgorithm();
}

#endif // #ifndef PERFECT_CLUSTERING_ALGORITHM_H
