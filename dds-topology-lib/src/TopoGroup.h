// Copyright 2014 GSI, Inc. All rights reserved.
//
//
//

#ifndef DDS_TopoGroup_h
#define DDS_TopoGroup_h
// DDS
#include "TopoContainer.h"

namespace dds
{
    namespace topology_api
    {
        class CTopoGroup : public CTopoContainer
        {
          public:
            typedef std::shared_ptr<CTopoGroup> Ptr_t;
            typedef std::vector<CTopoGroup::Ptr_t> PtrVector_t;

          public:
            /// \brief Constructor.
            CTopoGroup();

            /// \brief Destructor.
            virtual ~CTopoGroup();

            /// \brief Inherited from TopoElement.
            virtual size_t getNofTasks() const;

            /// \brief Inherited from TopoElement.
            virtual size_t getTotalNofTasks() const;

            /// \brief Inherited from TopoBase.
            void initFromPropertyTree(const std::string& _name, const boost::property_tree::ptree& _pt);

            /// \brief Inherited from TopoBase
            void saveToPropertyTree(boost::property_tree::ptree& _pt);

            size_t getN() const;

            void setN(size_t _n);

            CTopoElement::PtrVector_t getElementsByType(CTopoBase::EType _type) const;

            /// \brief Returns string representation of an object.
            /// \return String representation of an object.
            virtual std::string toString() const;

            /// \brief Operator << for convenient output to ostream.
            /// \return Insertion stream in order to be able to call a succession of
            /// insertion operations.
            friend std::ostream& operator<<(std::ostream& _strm, const CTopoGroup& _taskContainer);

          private:
            size_t m_n; ///< Number of times this group has to be executed
        };
    } // namespace topology_api
} // namespace dds
#endif
