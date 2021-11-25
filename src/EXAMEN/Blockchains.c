#include <stdlib.h>
#include <stdio.h>

typedef struct transaction {
    int buyer;
    int seller;
    float val
} Transaction;

typedef struct block {
    long id;
    Transaction *trans;
    struct block *prev;
} Block;

Transaction *creation_transaction(int buyer, int seller, float val) {

    Transaction *trans = (Transaction *) malloc(sizeof(Transaction));
    trans->buyer = buyer;
    trans->seller = seller;
    trans->val = val;

    return trans;
}

Block *Block_new(long id, const Transaction *trans, const Block *prev) {

    Block *block = (Block *) malloc(sizeof(Block));
    block->id = id;
    block->trans = trans;
    block->prev = prev;

    return block;

}

Block *creation_block_zero() {

    return Block_new(17, creation_transaction(0, 0, 0), NULL);
}

#define MOD_VALUE 8571
long creation_code_block(long id_prev, const Transaction *trans) {

    long x = id_prev + trans->val;
    return (2*x) % MOD_VALUE;
}

Block *ajout_nouveau_block(const Block *blockchain, Transaction *nt) {

    Block *new_block = Block_new(creation_code_block(blockchain->id, nt), nt, blockchain);
    return new_block;

}

Block *add_transaction(const Block *blockchain, int buyer, int seller, float val) {
    return ajout_nouveau_block(blockchain, creation_transaction(buyer, seller, val));
}

float valeur_transaction_personne(const Block *blockchain, int person) {

    float sum = 0;

    Block *iter = blockchain;
    Transaction *itrans = NULL;
    while (iter) {

        itrans = iter->trans;

        if (itrans) {

            if (itrans->seller == person) {
                sum += itrans->val;
            } else if (itrans->buyer == person) {
                sum -= itrans->val;
            }

        }

        iter = iter->prev;
    }

    return sum;

}

// Modify the block a_modifier
Block *modification_blockchain(Block *blockchain, Block *a_modifier, float val) {

    printf("a_modifier->id: %ld\n", a_modifier->id);

    // First thing to do is to find the block that I want to modify
    Block *iblock = blockchain;

    while (iblock) {

        // printf("searching block with id: %ld\n", iblock->id);

        if (iblock->id == a_modifier->id) { // modify block

            // printf("Found block a_modifier\n");
            iblock->trans->val = val;
            iblock->id = creation_code_block(iblock->prev->id, iblock->trans);
            break; // stop searching

        }

        iblock = iblock->prev;
    }

    if (!iblock) return blockchain; // if the desired block id is not found,

    Block *block_last_modified = iblock;

    while (block_last_modified != blockchain) { // while the last modified block is not the most recent block

        iblock = blockchain;
        // search for the NEXT block to modify...
        while (iblock) {

            if (iblock->prev == block_last_modified) { // recompute the value of the id

                // printf("Generating a new transaction id\n");
                iblock->id = creation_code_block(iblock->prev->id, iblock->trans);
                block_last_modified = iblock;
                break;
            }

            iblock = iblock->prev;
        }

    }

    // we are done here,
    return block_last_modified;
}

Block *nth_block(const Block *blockchain, int n) {

    if (n < 0) return NULL;

    Block *iblock = blockchain;

    while (n > 0) {

        iblock = iblock->prev;

        n--;
    }

    return iblock;

}


void afficher_blockchain(Block *blockchain) {

    Block *iter = blockchain;

    while (iter) {

        if (iter->trans) {

            printf("Transaction@%x id: %lu, buyer: %d, seller %d, value: %f\n", iter->trans, iter->id, iter->trans->buyer, iter->trans->seller, iter->trans->val);

        }

        iter = iter->prev;
    }
}

void liberer_memoire_blockchain(Block *blockchain) {

    Block *temp = NULL;

    while (blockchain) {

        temp = blockchain;

        blockchain = blockchain->prev;
        if (temp->trans) free(temp->trans);
        free(temp);

    }
}

int main() {

    Block *blockchain = creation_block_zero();
    // afficher_blockchain(blockchain);

    blockchain = add_transaction(blockchain, 15, 3, 900);
    blockchain = add_transaction(blockchain, 3, 98, 1.345);

    // afficher_blockchain(blockchain);

    blockchain = add_transaction(blockchain, 3, 4, 145.03);

    afficher_blockchain(blockchain);

    printf("person 3 has earned %lf dollars\n", valeur_transaction_personne(blockchain, 3));

    Block *block2 = nth_block(blockchain, 2);

    printf("Block2 has id: %ld\n", block2->id);

    blockchain = modification_blockchain(blockchain, block2, 100);

    afficher_blockchain(blockchain);

    printf("person 3 has earned %lf dollars\n", valeur_transaction_personne(blockchain, 3));


    liberer_memoire_blockchain(blockchain);

    return 0;
}