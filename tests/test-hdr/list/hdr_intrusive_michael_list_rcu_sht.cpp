/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2016

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     
*/

#include "list/hdr_intrusive_michael.h"
#include <cds/urcu/signal_threaded.h>
#include <cds/intrusive/michael_list_rcu.h>

namespace ordlist {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
    namespace {
        typedef cds::urcu::gc< cds::urcu::signal_threaded<> >    RCU;
    }
#endif

    void IntrusiveMichaelListHeaderTest::RCU_SHT_base_cmp()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< RCU > item;
        struct traits : public ci::michael_list::traits
        {
            typedef ci::michael_list::base_hook< co::gc<RCU> > hook;
            typedef cmp<item> compare;
            typedef faked_disposer disposer;
        };
        typedef ci::MichaelList< RCU, item, traits > list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_base_less()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< RCU > item;
        struct traits : public ci::michael_list::traits
        {
            typedef ci::michael_list::base_hook< co::gc<RCU> > hook;
            typedef IntrusiveMichaelListHeaderTest::less<item> less;
            typedef faked_disposer disposer;
        };
        typedef ci::MichaelList< RCU, item, traits > list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_base_cmpmix()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< RCU > item;
        typedef ci::MichaelList< RCU
            ,item
            ,ci::michael_list::make_traits<
                ci::opt::hook< ci::michael_list::base_hook< co::gc<RCU> > >
                ,co::less< less<item> >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_base_ic()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef base_int_item< RCU > item;
        typedef ci::MichaelList< RCU
            ,item
            ,ci::michael_list::make_traits<
                ci::opt::hook< ci::michael_list::base_hook< co::gc<RCU> > >
                ,co::less< less<item> >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >    list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_member_cmp()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef member_int_item< RCU > item;
        typedef ci::MichaelList< RCU
            ,item
            ,ci::michael_list::make_traits<
                ci::opt::hook< ci::michael_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_member_less()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef member_int_item< RCU > item;
        typedef ci::MichaelList< RCU
            ,item
            ,ci::michael_list::make_traits<
                ci::opt::hook< ci::michael_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::less< less<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_member_cmpmix()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef member_int_item< RCU > item;
        typedef ci::MichaelList< RCU
            ,item
            ,ci::michael_list::make_traits<
                ci::opt::hook< ci::michael_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::less< less<item> >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
            >::type
        >    list;
        test_rcu_int<list>();
#endif
    }
    void IntrusiveMichaelListHeaderTest::RCU_SHT_member_ic()
    {
#ifdef CDS_URCU_SIGNAL_HANDLING_ENABLED
        typedef member_int_item< RCU > item;
        typedef ci::MichaelList< RCU
            ,item
            ,ci::michael_list::make_traits<
                ci::opt::hook< ci::michael_list::member_hook<
                    offsetof( item, hMember ),
                    co::gc<RCU>
                > >
                ,co::compare< cmp<item> >
                ,ci::opt::disposer< faked_disposer >
                ,co::item_counter< cds::atomicity::item_counter >
            >::type
        >    list;
        test_rcu_int<list>();
#endif
    }

}
