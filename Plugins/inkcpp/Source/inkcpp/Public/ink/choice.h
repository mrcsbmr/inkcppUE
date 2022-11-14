#pragma once
#include "system.h"

namespace ink
{
	namespace runtime
	{
		namespace internal
		{
			class basic_stream;
			class runner_impl;
			class string_table;
			class list_table;
		}

		/**
		 * An ink choice that is being presented to the user
		 *
		 * Contains all the data about a single choice being faced
		 * by an ink runner. Of primary concern is the index and the
		 * text.
		 *
		 * @see runner
		*/
		class choice
		{
		public:
			/**
			 * Choice index
			 *
			 * Pass this to the runner to choose this choice and
			 * have it follow its branch.
			 *
			 * @returns index of the choice. 0 is the first, etc.
			*/
			int index() const { return _index; }

#ifdef INK_ENABLE_STL
			/**
			 * Choice text
			 *
			 * Text to display to the user for choosing this choice.
			 *
			 * @returns choice text as a string
			 */
			const char* text() const { return _text; }
#endif

#ifdef INK_ENABLE_UNREAL
			// Reads a line into an Unreal FString
			const FString text() const { return UTF8_TO_TCHAR(_text); }
#endif
			
		private:
			friend class internal::runner_impl;

			uint32_t path() const { return _path; }
			choice& setup(internal::basic_stream&, internal::string_table& strings, internal::list_table& lists, int index, uint32_t path, thread_t thread);
		private:
			const char* _text;
			int _index;
			uint32_t _path;
			thread_t _thread;
		};
	}
}
