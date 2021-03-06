// Copyright 2014 GSI, Inc. All rights reserved.
//
//
//

#ifndef __DDS__TopoCollection__
#define __DDS__TopoCollection__

// DDS
#include "TopoContainer.h"
#include "TopoDef.h"
#include "TopoRequirement.h"
#include "TopoTask.h"

namespace dds
{
    namespace topology_api
    {
        class CTopoCollection : public CTopoContainer
        {
          public:
            typedef std::shared_ptr<CTopoCollection> Ptr_t;
            typedef std::vector<CTopoCollection::Ptr_t> PtrVector_t;

          public:
            /// \brief Constructor.
            CTopoCollection();

            /// \brief Destructor.
            virtual ~CTopoCollection();

            /// \brief Inherited from TopoElement.
            virtual size_t getNofTasks() const;

            /// \brief Inherited from TopoElement.
            virtual size_t getTotalNofTasks() const;

            /// \brief Inherited from TopoElement.
            void initFromPropertyTree(const std::string& _name, const boost::property_tree::ptree& _pt);

            /// \brief Inherited from TopoBase
            void saveToPropertyTree(boost::property_tree::ptree& _pt);

            /// \brief If parent is a group than return N, else return 1.
            size_t getTotalCounter() const;

            size_t getNofRequirements() const;
            const CTopoRequirement::PtrVector_t& getRequirements() const;
            void setRequirement(const CTopoRequirement::PtrVector_t& _requirements);
            void addRequirement(CTopoRequirement::Ptr_t _requirement);

          private:
            CTopoRequirement::PtrVector_t m_requirements; ///< Array of requirement
        };

        struct STopoRuntimeCollection
        {
            typedef std::map<Id_t, STopoRuntimeCollection> Map_t;
            typedef std::function<bool(std::pair<Id_t, const STopoRuntimeCollection&>)> Condition_t;
            typedef boost::filter_iterator<STopoRuntimeCollection::Condition_t,
                                           STopoRuntimeCollection::Map_t::const_iterator>
                FilterIterator_t;
            typedef std::pair<STopoRuntimeCollection::FilterIterator_t, STopoRuntimeCollection::FilterIterator_t>
                FilterIteratorPair_t;

            STopoRuntimeCollection()
                : m_collection(nullptr)
                , m_collectionIndex(0)
                , m_collectionPath()
            {
            }
            CTopoCollection::Ptr_t m_collection;
            size_t m_collectionIndex;
            std::string m_collectionPath;
            STopoRuntimeTask::Map_t m_idToRuntimeTaskMap; ///< Map of task ID to STopoRuntimeTask
        };
    } // namespace topology_api
} // namespace dds
#endif /* defined(__DDS__TopoCollection__) */
