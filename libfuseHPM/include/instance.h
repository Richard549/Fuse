#ifndef FUSE_INSTANCE_H
#define FUSE_INSTANCE_H

#include "fuse_types.h"

#include <map>

namespace Fuse {

	class Instance {

		public:

			std::map<Fuse::Event,int64_t> event_values;
			Fuse::Symbol symbol;
			std::vector<int> label;
			uint64_t start;
			uint64_t end;
			unsigned int cpu;
			bool is_gpu_eligible;

			// Adds, replaces, or accumulates (via additive argument) an event value
			void append_event_value(Fuse::Event event, int64_t value, bool additive);

			// Replacement will only occur if new value is greater than old
			void append_max_event_value(Fuse::Event event, int64_t value);

			int64_t get_event_value(Fuse::Event event, bool& error);

			Fuse::Event_set get_events();

			Instance();
			~Instance();

	};

	bool comp_instances_by_label_dfs(Fuse::Instance_p a, Fuse::Instance_p b);
}

#endif
