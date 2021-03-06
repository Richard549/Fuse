#ifndef FUSE_PROFILING_H
#define FUSE_PROFILING_H

#include "fuse_types.h"

#include <string>

namespace Fuse {

	namespace Profiling {

		namespace Openstream {

			bool execute(
				std::string binary,
				std::string args,
				std::string tracefile,
				Fuse::Event_set profiled_events,
				bool multiplex
			);

		};

		namespace Openmp {

			bool execute(
				std::string binary,
				std::string args,
				std::string tracefile,
				Fuse::Event_set profiled_events,
				bool multiplex
			);

		};

		void execute(
			Fuse::Runtime runtime,
			std::string binary,
			std::string args,
			std::string tracefile,
			Fuse::Event_set profiled_events,
			bool clear_cache = false,
			bool multiplex = false
		);

		Fuse::Profile_p execute_and_load(
			Fuse::Event_set filtered_events,
			Fuse::Runtime runtime,
			std::string binary,
			std::string args,
			std::string tracefile,
			Fuse::Event_set profiled_events,
			bool clear_cache = false,
			bool multiplex = false
		);

		void clear_system_cache();

		std::vector<Fuse::Event_set> greedy_generate_minimal_partitioning(
			Fuse::Event_set target_events,
			std::string papi_directory
		);

		bool compatibility_check(
			Fuse::Event_set events,
			std::string papi_directory
		);

	};

}; // Fuse namespace

#endif
