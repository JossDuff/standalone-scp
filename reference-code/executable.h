#define _HAS_ITERATOR_DEBUGGING 0
struct ivy_gen {virtual int choose(int rng,const char *name) = 0;};
#include "z3++.h"

/*++
  Copyright (c) Microsoft Corporation

  This hash template is borrowed from Microsoft Z3
  (https://github.com/Z3Prover/z3).

  Simple implementation of bucket-list hash tables conforming roughly
  to SGI hash_map and hash_set interfaces, though not all members are
  implemented.

  These hash tables have the property that insert preserves iterators
  and references to elements.

  This package lives in namespace hash_space. Specializations of
  class "hash" should be made in this namespace.

  --*/

#pragma once

#ifndef HASH_H
#define HASH_H

#ifdef _WINDOWS
#pragma warning(disable:4267)
#endif

#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>

namespace hash_space {

    unsigned string_hash(const char * str, unsigned length, unsigned init_value);

    template <typename T> class hash {
    public:
        size_t operator()(const T &s) const {
            return s.__hash();
        }
    };

    template <>
        class hash<int> {
    public:
        size_t operator()(const int &s) const {
            return s;
        }
    };

    template <>
        class hash<long long> {
    public:
        size_t operator()(const long long &s) const {
            return s;
        }
    };

    template <>
        class hash<unsigned> {
    public:
        size_t operator()(const unsigned &s) const {
            return s;
        }
    };

    template <>
        class hash<unsigned long long> {
    public:
        size_t operator()(const unsigned long long &s) const {
            return s;
        }
    };

    template <>
        class hash<bool> {
    public:
        size_t operator()(const bool &s) const {
            return s;
        }
    };

    template <>
        class hash<std::string> {
    public:
        size_t operator()(const std::string &s) const {
            return string_hash(s.c_str(), (unsigned)s.size(), 0);
        }
    };

    template <>
        class hash<std::pair<int,int> > {
    public:
        size_t operator()(const std::pair<int,int> &p) const {
            return p.first + p.second;
        }
    };

    template <typename T>
        class hash<std::vector<T> > {
    public:
        size_t operator()(const std::vector<T> &p) const {
            hash<T> h;
            size_t res = 0;
            for (unsigned i = 0; i < p.size(); i++)
                res += h(p[i]);
            return res;
        }
    };

    template <typename K, typename V>
        class hash<std::map<K,V> > {
    public:
        size_t operator()(const std::map<K,V> &p) const {
            hash<K> hk;
            hash<V> hv;
            size_t res = 0;
            for (typename std::map<K,V>::const_iterator it = p.begin(), en = p.end(); it != en; ++it)
                res += hk(it->first) + hv(it->second);
            return res;
        }
    };

    template <class T>
        class hash<std::pair<T *, T *> > {
    public:
        size_t operator()(const std::pair<T *,T *> &p) const {
            return (size_t)p.first + (size_t)p.second;
        }
    };

    template <class T>
        class hash<T *> {
    public:
        size_t operator()(T * const &p) const {
            return (size_t)p;
        }
    };

    enum { num_primes = 29 };

    static const unsigned long primes[num_primes] =
        {
            7ul,
            53ul,
            97ul,
            193ul,
            389ul,
            769ul,
            1543ul,
            3079ul,
            6151ul,
            12289ul,
            24593ul,
            49157ul,
            98317ul,
            196613ul,
            393241ul,
            786433ul,
            1572869ul,
            3145739ul,
            6291469ul,
            12582917ul,
            25165843ul,
            50331653ul,
            100663319ul,
            201326611ul,
            402653189ul,
            805306457ul,
            1610612741ul,
            3221225473ul,
            4294967291ul
        };

    inline unsigned long next_prime(unsigned long n) {
        const unsigned long* to = primes + (int)num_primes;
        for(const unsigned long* p = primes; p < to; p++)
            if(*p >= n) return *p;
        return primes[num_primes-1];
    }

    template<class Value, class Key, class HashFun, class GetKey, class KeyEqFun>
        class hashtable
    {
    public:

        typedef Value &reference;
        typedef const Value &const_reference;
    
        struct Entry
        {
            Entry* next;
            Value val;
      
        Entry(const Value &_val) : val(_val) {next = 0;}
        };
    

        struct iterator
        {      
            Entry* ent;
            hashtable* tab;

            typedef std::forward_iterator_tag iterator_category;
            typedef Value value_type;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef Value& reference;
            typedef Value* pointer;

        iterator(Entry* _ent, hashtable* _tab) : ent(_ent), tab(_tab) { }

            iterator() { }

            Value &operator*() const { return ent->val; }

            Value *operator->() const { return &(operator*()); }

            iterator &operator++() {
                Entry *old = ent;
                ent = ent->next;
                if (!ent) {
                    size_t bucket = tab->get_bucket(old->val);
                    while (!ent && ++bucket < tab->buckets.size())
                        ent = tab->buckets[bucket];
                }
                return *this;
            }

            iterator operator++(int) {
                iterator tmp = *this;
                operator++();
                return tmp;
            }


            bool operator==(const iterator& it) const { 
                return ent == it.ent;
            }

            bool operator!=(const iterator& it) const {
                return ent != it.ent;
            }
        };

        struct const_iterator
        {      
            const Entry* ent;
            const hashtable* tab;

            typedef std::forward_iterator_tag iterator_category;
            typedef Value value_type;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef const Value& reference;
            typedef const Value* pointer;

        const_iterator(const Entry* _ent, const hashtable* _tab) : ent(_ent), tab(_tab) { }

            const_iterator() { }

            const Value &operator*() const { return ent->val; }

            const Value *operator->() const { return &(operator*()); }

            const_iterator &operator++() {
                const Entry *old = ent;
                ent = ent->next;
                if (!ent) {
                    size_t bucket = tab->get_bucket(old->val);
                    while (!ent && ++bucket < tab->buckets.size())
                        ent = tab->buckets[bucket];
                }
                return *this;
            }

            const_iterator operator++(int) {
                const_iterator tmp = *this;
                operator++();
                return tmp;
            }


            bool operator==(const const_iterator& it) const { 
                return ent == it.ent;
            }

            bool operator!=(const const_iterator& it) const {
                return ent != it.ent;
            }
        };

    private:

        typedef std::vector<Entry*> Table;

        Table buckets;
        size_t entries;
        HashFun hash_fun ;
        GetKey get_key;
        KeyEqFun key_eq_fun;
    
    public:

    hashtable(size_t init_size) : buckets(init_size,(Entry *)0) {
            entries = 0;
        }
    
        hashtable(const hashtable& other) {
            dup(other);
        }

        hashtable& operator= (const hashtable& other) {
            if (&other != this)
                dup(other);
            return *this;
        }

        ~hashtable() {
            clear();
        }

        size_t size() const { 
            return entries;
        }

        bool empty() const { 
            return size() == 0;
        }

        void swap(hashtable& other) {
            buckets.swap(other.buckets);
            std::swap(entries, other.entries);
        }
    
        iterator begin() {
            for (size_t i = 0; i < buckets.size(); ++i)
                if (buckets[i])
                    return iterator(buckets[i], this);
            return end();
        }
    
        iterator end() { 
            return iterator(0, this);
        }

        const_iterator begin() const {
            for (size_t i = 0; i < buckets.size(); ++i)
                if (buckets[i])
                    return const_iterator(buckets[i], this);
            return end();
        }
    
        const_iterator end() const { 
            return const_iterator(0, this);
        }
    
        size_t get_bucket(const Value& val, size_t n) const {
            return hash_fun(get_key(val)) % n;
        }
    
        size_t get_key_bucket(const Key& key) const {
            return hash_fun(key) % buckets.size();
        }

        size_t get_bucket(const Value& val) const {
            return get_bucket(val,buckets.size());
        }

        Entry *lookup(const Value& val, bool ins = false)
        {
            resize(entries + 1);

            size_t n = get_bucket(val);
            Entry* from = buckets[n];
      
            for (Entry* ent = from; ent; ent = ent->next)
                if (key_eq_fun(get_key(ent->val), get_key(val)))
                    return ent;
      
            if(!ins) return 0;

            Entry* tmp = new Entry(val);
            tmp->next = from;
            buckets[n] = tmp;
            ++entries;
            return tmp;
        }

        Entry *lookup_key(const Key& key) const
        {
            size_t n = get_key_bucket(key);
            Entry* from = buckets[n];
      
            for (Entry* ent = from; ent; ent = ent->next)
                if (key_eq_fun(get_key(ent->val), key))
                    return ent;
      
            return 0;
        }

        const_iterator find(const Key& key) const {
            return const_iterator(lookup_key(key),this);
        }

        iterator find(const Key& key) {
            return iterator(lookup_key(key),this);
        }

        std::pair<iterator,bool> insert(const Value& val){
            size_t old_entries = entries;
            Entry *ent = lookup(val,true);
            return std::pair<iterator,bool>(iterator(ent,this),entries > old_entries);
        }
    
        iterator insert(const iterator &it, const Value& val){
            Entry *ent = lookup(val,true);
            return iterator(ent,this);
        }

        size_t erase(const Key& key)
        {
            Entry** p = &(buckets[get_key_bucket(key)]);
            size_t count = 0;
            while(*p){
                Entry *q = *p;
                if (key_eq_fun(get_key(q->val), key)) {
                    ++count;
                    *p = q->next;
                    delete q;
                }
                else
                    p = &(q->next);
            }
            entries -= count;
            return count;
        }

        void resize(size_t new_size) {
            const size_t old_n = buckets.size();
            if (new_size <= old_n) return;
            const size_t n = next_prime(new_size);
            if (n <= old_n) return;
            Table tmp(n, (Entry*)(0));
            for (size_t i = 0; i < old_n; ++i) {
                Entry* ent = buckets[i];
                while (ent) {
                    size_t new_bucket = get_bucket(ent->val, n);
                    buckets[i] = ent->next;
                    ent->next = tmp[new_bucket];
                    tmp[new_bucket] = ent;
                    ent = buckets[i];
                }
            }
            buckets.swap(tmp);
        }
    
        void clear()
        {
            for (size_t i = 0; i < buckets.size(); ++i) {
                for (Entry* ent = buckets[i]; ent != 0;) {
                    Entry* next = ent->next;
                    delete ent;
                    ent = next;
                }
                buckets[i] = 0;
            }
            entries = 0;
        }

        void dup(const hashtable& other)
        {
            clear();
            buckets.resize(other.buckets.size());
            for (size_t i = 0; i < other.buckets.size(); ++i) {
                Entry** to = &buckets[i];
                for (Entry* from = other.buckets[i]; from; from = from->next)
                    to = &((*to = new Entry(from->val))->next);
            }
            entries = other.entries;
        }
    };

    template <typename T> 
        class equal {
    public:
        bool operator()(const T& x, const T &y) const {
            return x == y;
        }
    };

    template <typename T>
        class identity {
    public:
        const T &operator()(const T &x) const {
            return x;
        }
    };

    template <typename T, typename U>
        class proj1 {
    public:
        const T &operator()(const std::pair<T,U> &x) const {
            return x.first;
        }
    };

    template <typename Element, class HashFun = hash<Element>, 
        class EqFun = equal<Element> >
        class hash_set
        : public hashtable<Element,Element,HashFun,identity<Element>,EqFun> {

    public:

    typedef Element value_type;

    hash_set()
    : hashtable<Element,Element,HashFun,identity<Element>,EqFun>(7) {}
    };

    template <typename Key, typename Value, class HashFun = hash<Key>, 
        class EqFun = equal<Key> >
        class hash_map
        : public hashtable<std::pair<Key,Value>,Key,HashFun,proj1<Key,Value>,EqFun> {

    public:

    hash_map()
    : hashtable<std::pair<Key,Value>,Key,HashFun,proj1<Key,Value>,EqFun>(7) {}

    Value &operator[](const Key& key) {
	std::pair<Key,Value> kvp(key,Value());
	return 
	hashtable<std::pair<Key,Value>,Key,HashFun,proj1<Key,Value>,EqFun>::
        lookup(kvp,true)->val.second;
    }
    };

    template <typename D,typename R>
        class hash<hash_map<D,R> > {
    public:
        size_t operator()(const hash_map<D,R> &p) const {
            hash<D > h1;
            hash<R > h2;
            size_t res = 0;
            
            for (typename hash_map<D,R>::const_iterator it=p.begin(), en=p.end(); it!=en; ++it)
                res += (h1(it->first)+h2(it->second));
            return res;
        }
    };

    template <typename D,typename R>
    inline bool operator ==(const hash_map<D,R> &s, const hash_map<D,R> &t){
        for (typename hash_map<D,R>::const_iterator it=s.begin(), en=s.end(); it!=en; ++it) {
            typename hash_map<D,R>::const_iterator it2 = t.find(it->first);
            if (it2 == t.end() || !(it->second == it2->second)) return false;
        }
        for (typename hash_map<D,R>::const_iterator it=t.begin(), en=t.end(); it!=en; ++it) {
            typename hash_map<D,R>::const_iterator it2 = s.find(it->first);
            if (it2 == t.end() || !(it->second == it2->second)) return false;
        }
        return true;
    }
}
#endif
typedef std::string __strlit;
extern std::ofstream __ivy_out;
void __ivy_exit(int);

template <typename D, typename R>
struct thunk {
    virtual R operator()(const D &) = 0;
    int ___ivy_choose(int rng,const char *name,int id) {
        return 0;
    }
};
template <typename D, typename R, class HashFun = hash_space::hash<D> >
struct hash_thunk {
    thunk<D,R> *fun;
    hash_space::hash_map<D,R,HashFun> memo;
    hash_thunk() : fun(0) {}
    hash_thunk(thunk<D,R> *fun) : fun(fun) {}
    ~hash_thunk() {
//        if (fun)
//            delete fun;
    }
    R &operator[](const D& arg){
        std::pair<typename hash_space::hash_map<D,R>::iterator,bool> foo = memo.insert(std::pair<D,R>(arg,R()));
        R &res = foo.first->second;
        if (foo.second && fun)
            res = (*fun)(arg);
        return res;
    }
};
    #include <memory>
    #include <vector>
    #include <exception>
    #include <mutex>
    #include <cstdint>

    #define USE_SPDLOG
    #include <crypto/Hex.h>
    #include <crypto/SecretKey.h>
    #include <crypto/SHA.h>
    #include <scp/SCP.h>
    #include <scp/Slot.h>
    #include <scp/QuorumSetUtils.h>
    #include <util/Logging.h>
    #include <util/XDROperators.h>
    #include <lib/json/json.h>

    // Forward-declare all the callback types so we can use them
    // in incomplete-typed unique_ptr<T> members and arguments.
    struct thunk__node__value_externalized;
    struct thunk__node__nominating_value;
    struct thunk__node__started_ballot_protocol;
    struct thunk__node__accepted_ballot_prepared;
    struct thunk__node__confirmed_ballot_prepared;
    struct thunk__node__accepted_commit;
    struct thunk__node__emit_envelope;
    struct thunk__node__emit_prepare;
    struct thunk__node__emit_confirm;
    struct thunk__node__emit_externalize;
    struct thunk__node__emit_logical_vote_nominate;
    struct thunk__node__emit_logical_accept_nominate;

    // This model only runs SCP for a single slot.
    #define SLOT 0

    namespace stellar {

        // There will be 1 instance of this Network object representing the network
        // as a whole. We have to initialize this all in one (global) place so we can
        // build a single QSet that contains all the NodeIDs. It's constant once
        // initialized.
        struct Network {
            // The network has a fixed set of nodes.
            const xdr::xvector<NodeID> mNodeIDs;

            // The network has a single quorum set built on those nodes.
            const SCPQuorumSetPtr mQSet;
            const Hash mQSetHash;

            // Envelopes are broadcast into a globally visible history which
            // individual nodes advance their consumption of.
            std::vector<SCPEnvelopeWrapperPtr> mBroadcastEnvelopes;

            Network(unsigned n);
        };

        // Each node will have an instance of this class which contains the SCP state machine
        // and also is an SCPDriver which mediates communication between Ivy and that SCP.
        //
        // NB: this class has to be called stellar__COLON____COLON__TestSCP exactly, to match a friend
        // declaration in SCP that allows us to access private members of SCP.
        class TestSCP : public SCPDriver {

            SCP mSCP;

            void signEnvelope(SCPEnvelope& envelope) override;
            SCPQuorumSetPtr getQSet(Hash const& qSetHash) override;
            void emitEnvelope(SCPEnvelope const& envelope) override;
            Hash getHashOf(std::vector<xdr::opaque_vec<>> const& vals) const override;
            ValueWrapperPtr combineCandidates(uint64 slotIndex, ValueWrapperPtrSet const& candidates) override;
            void setupTimer(uint64 slotIndex, int timerID, std::chrono::milliseconds timeout, std::function<void()> cb) override;
            ValidationLevel validateValue(uint64 slotIndex, Value const& value, bool nomination) override;

            // Hooks that are fired when various SCP state-transitions occur. These are routed
            // into the callbacks that follow.
            void valueExternalized(uint64 slotIndex, Value const& value) override;
            void nominatingValue(uint64 slotIndex, Value const& value) override;
            void startedBallotProtocol(uint64 slotIndex, SCPBallot const& ballot) override;
            void acceptedBallotPrepared(uint64 slotIndex, SCPBallot const& ballot) override;
            void confirmedBallotPrepared(uint64 slotIndex, SCPBallot const& ballot) override;
            void acceptedCommit(uint64 slotIndex, SCPBallot const& ballot) override;

            // Thunks that can be set for callbacks from the SCP driver to Ivy.
            std::unique_ptr<thunk__node__value_externalized> mValueExternalizedCb;
            std::unique_ptr<thunk__node__nominating_value> mNominatingValueCb;
            std::unique_ptr<thunk__node__started_ballot_protocol> mStartedBallotProtocolCb;
            std::unique_ptr<thunk__node__accepted_ballot_prepared> mAcceptedBallotPreparedCb;
            std::unique_ptr<thunk__node__confirmed_ballot_prepared> mConfirmedBallotPreparedCb;
            std::unique_ptr<thunk__node__accepted_commit> mAcceptedCommitCb;
            std::unique_ptr<thunk__node__emit_envelope> mEmitEnvelopeCb;
            std::unique_ptr<thunk__node__emit_prepare> mEmitPrepareCb;
            std::unique_ptr<thunk__node__emit_confirm> mEmitConfirmCb;
            std::unique_ptr<thunk__node__emit_externalize> mEmitExternalizeCb;
            std::unique_ptr<thunk__node__emit_logical_vote_nominate> mEmitLogicalVoteNominateCb;
            std::unique_ptr<thunk__node__emit_logical_accept_nominate> mEmitLogicalAcceptNominateCb;

            public:

            TestSCP(NodeID const& nodeID, SCPQuorumSet const& qSetLocal,
            std::unique_ptr<thunk__node__value_externalized>,
            std::unique_ptr<thunk__node__nominating_value>,
            std::unique_ptr<thunk__node__started_ballot_protocol>,
            std::unique_ptr<thunk__node__accepted_ballot_prepared>,
            std::unique_ptr<thunk__node__confirmed_ballot_prepared>,
            std::unique_ptr<thunk__node__accepted_commit>,
            std::unique_ptr<thunk__node__emit_envelope>,
            std::unique_ptr<thunk__node__emit_prepare>,
            std::unique_ptr<thunk__node__emit_confirm>,
            std::unique_ptr<thunk__node__emit_externalize>,
            std::unique_ptr<thunk__node__emit_logical_vote_nominate>,
            std::unique_ptr<thunk__node__emit_logical_accept_nominate>
            );

            SCP &getSCP() { return mSCP; }

            // Miscellaneous helper functions used in the implementation, that happen to need
            // to be members of TestSCP in order to access (possibly private) state in SCP.
            void setLocalLogPrefix();
            bool isLeader();
            unsigned getSCPStatementCount();
            unsigned getNomRound();
            template <typename T>
            T getSCPBallotState(std::function<T(std::string const&)> mapping) {
                setLocalLogPrefix();
                return mapping(mSCP.getSlot(0, true)->getBallotProtocol().getJsonInfo()["phase"].asString());
            }
        };

        // Free functions for working with Stellar XDR and Ivy types.
        Value fromIvyValT(unsigned);
        unsigned toIvyValT(Value const&);

        NodeID fromIvyIdT(unsigned);
        unsigned toIvyIdT(NodeID const&);
    }

    extern std::unique_ptr<stellar::Network> gNetwork;
        

    class reader;
    class timer;

class executable {
  public:
    typedef executable ivy_class;

    std::vector<std::string> __argv;
#ifdef _WIN32
    void *mutex;  // forward reference to HANDLE
#else
    pthread_mutex_t mutex;
#endif
    void __lock();
    void __unlock();

#ifdef _WIN32
    std::vector<HANDLE> thread_ids;

#else
    std::vector<pthread_t> thread_ids;

#endif
    void install_reader(reader *);
    void install_thread(reader *);
    void install_timer(timer *);
    virtual ~executable();
    std::vector<int> ___ivy_stack;
    ivy_gen *___ivy_gen;
    int ___ivy_choose(int rng,const char *name,int id);
    virtual void ivy_assert(bool,const char *){}
    virtual void ivy_assume(bool,const char *){}
    virtual void ivy_check_progress(int,int){}
    bool received[4][256];
    bool voted_nominate[4][16];
    bool _generating;
    bool accepted_nominate[4][16];
    unsigned broadcastEnvelopes;
    bool node__isLeader[4];
    long long __CARD__val_t;
    long long __CARD__nodeset_t;
    long long __CARD__counter_t;
    long long __CARD__id_t;
    virtual bool node__ballot_lt(unsigned V0, unsigned ac, unsigned av, unsigned bc, unsigned bv);
    virtual bool node__prepare_aborts(unsigned V0, unsigned pc, unsigned pv, unsigned bc, unsigned bv);
    virtual bool node__member(unsigned V0, unsigned n, unsigned s);
    virtual bool node__is_quorum(unsigned V0, unsigned s);
    std::unique_ptr<stellar::TestSCP> node__testSCP[4];
        executable();
void __init();
    virtual void node__emit_externalize(unsigned prm__V0, unsigned commit_counter, unsigned commit_value, unsigned h_counter);
    virtual void imp__node__started_ballot_protocol(unsigned prm__V0, unsigned n, unsigned x);
    virtual void node__started_ballot_protocol(unsigned prm__V0, unsigned n, unsigned x);
    virtual void node__emit_prepare(unsigned prm__V0, unsigned ballot_counter, unsigned ballot_value, bool prepared, unsigned prepared_counter, unsigned prepared_value, bool prepared_prime, unsigned prepared_prime_counter, unsigned prepared_prime_value, unsigned c_counter, unsigned h_counter);
    virtual void node__emit_confirm(unsigned prm__V0, unsigned ballot_counter, unsigned ballot_value, unsigned prepared_counter, unsigned c_counter, unsigned h_counter);
    virtual void imp__node__confirmed_ballot_prepared(unsigned prm__V0, unsigned n, unsigned x);
    virtual void imp__node__nominating_value(unsigned prm__V0, unsigned v);
    virtual void node__accepted_commit(unsigned prm__V0, unsigned n, unsigned x);
    virtual void node__nominating_value(unsigned prm__V0, unsigned v);
    virtual void node__accepted_ballot_prepared(unsigned prm__V0, unsigned n, unsigned x);
    virtual void imp__node__emit_logical_vote_nominate(unsigned prm__V0, unsigned val);
    virtual void ext__node__nominate(unsigned prm__V0, unsigned val);
    virtual void imp__node__value_externalized(unsigned prm__V0, unsigned v);
    virtual void imp__node__emit_confirm(unsigned prm__V0, unsigned ballot_counter, unsigned ballot_value, unsigned prepared_counter, unsigned c_counter, unsigned h_counter);
    virtual void imp__node__emit_logical_accept_nominate(unsigned prm__V0, unsigned val);
    virtual void imp__node__accepted_commit(unsigned prm__V0, unsigned n, unsigned x);
    virtual void imp__node__accepted_ballot_prepared(unsigned prm__V0, unsigned n, unsigned x);
    virtual void node__emit_logical_accept_nominate(unsigned prm__V0, unsigned val);
    virtual void ext__node__receive_pending_envelope(unsigned prm__V0, unsigned envNum);
    virtual void node__readLeader(unsigned prm__V0);
    virtual void imp__node__emit_prepare(unsigned prm__V0, unsigned ballot_counter, unsigned ballot_value, bool prepared, unsigned prepared_counter, unsigned prepared_value, bool prepared_prime, unsigned prepared_prime_counter, unsigned prepared_prime_value, unsigned c_counter, unsigned h_counter);
    virtual void imp__node__emit_externalize(unsigned prm__V0, unsigned commit_counter, unsigned commit_value, unsigned h_counter);
    virtual void node__emit_logical_vote_nominate(unsigned prm__V0, unsigned val);
    virtual void node__value_externalized(unsigned prm__V0, unsigned v);
    virtual void node__confirmed_ballot_prepared(unsigned prm__V0, unsigned n, unsigned x);
    virtual void node__emit_envelope(unsigned prm__V0, unsigned envNum);
    void __tick(int timeout);
};
