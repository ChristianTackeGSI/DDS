// Copyright 2014 GSI, Inc. All rights reserved.
//
//
//

#ifndef __DDS__Topology__
#define __DDS__Topology__

// DDS Topo
#include "TopoIndex.h"
#include "TaskGroup.h"
#include "TopoElement.h"
#include "Task.h"
// STD
#include <ostream>
#include <string>
#include <map>

namespace dds
{
    class CTopology
    {
      public:
        /// \brief Constructor.
        CTopology();

        /// \brief Destructor.
        virtual ~CTopology();

        /// \brief Initializes topology from specified file.
        /// \throw runtime_error
        void init(const std::string& _fileName);

        /// Accessors
        TaskGroupPtr_t getMainGroup() const;
        TopoElementPtr_t getTopoElementByTopoIndex(const CTopoIndex& _index) const;

        /// \brief Returns string representation of an object.
        /// \return String representation of an object.
        virtual std::string toString() const;

        /// \brief Operator << for convenient output to ostream.
        /// \return Insertion stream in order to be able to call a succession of
        /// insertion operations.
        friend std::ostream& operator<<(std::ostream& _strm, const CTopology& _topology);

      private:
        void FillTopoIndexToTopoElementMap(const TopoElementPtr_t& _element);

        TaskGroupPtr_t m_main; ///> Main task group which we run

        typedef std::map<CTopoIndex, TopoElementPtr_t, CompareTopoIndexLess> TopoIndexToTopoElementMap_t;
        TopoIndexToTopoElementMap_t m_topoIndexToTopoElementMap;
    };
}
#endif /* defined(__DDS__Topology__) */