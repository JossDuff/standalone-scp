// #include <crypto/Hex.h>
// #include <crypto/SecretKey.h>
// #include <crypto/SHA.h>
// #include <scp/SCP.h>
// #include <scp/Slot.h>
// #include <scp/QuorumSetUtils.h>
// #include <util/Logging.h>
// #include <util/XDROperators.h>
// #include <lib/json/json.h>

// below is copied from reference-code/executable.h


namespace stellar {
    // Each node will have an instance of this class which contains the SCP state machine
    // and also is an SCPDriver which mediates communication between Ivy and that SCP.
    //
    // NB: this class has to be called stellar__COLON____COLON__TestSCP exactly, to match a friend
    // declaration in SCP that allows us to access private members of SCP.
    class TestSCP : public SCPDriver {

        SCP mSCP;

        // TODO: implement these functions
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
        /*
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
        */
        public:

        // TODO: gross inline comment. change later
        TestSCP(NodeID const& nodeID, SCPQuorumSet const& qSetLocal /*,
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
        */
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
}