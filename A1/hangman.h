/*!
 * @file      hangman.h
 * @brief     Declaration of guessLetter and lettersRemaining.
 *
 * @author    Jonathan Anderson <jonathan.anderson@mun.ca>
 * @copyright (c) 2016 Jonathan Anderson. All rights reserved.
 * @license   Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 */

#include <string>

/**
 * Get the next guess from a player (human or computer).
 *
 * @note   do not implement this function: it should be provided by test code
 *
 * The game of Hangman consists of a player (or players) guessing letters in
 * a secret word until they guess the whole word or run out of guesses. This
 * function (which is **provided by test code**) can be used to ask the player
 * (or the computer player / test code) which letter should be guessed next.
 *
 * @param       letters     currently-visible letters in the secret word
 *                          (or '*' if the letter is still not known)
 * @param       length      the number of elements in `letters`
 *
 * @returns     a character (`'a'` through `'z'`) that the player guessed
 */
char getNextGuess(const char letters[], unsigned int length);


/**
 * Check how good a guess is in a game of Hangman.
 *
 * In Hangman, the goal is to guess letters contained in a secret word.
 * For instance, if the word is "applesauce", the player starts out seeing
 * the word as "**********". After guessing 'A', they see, "a*****a***".
 * If they guess 'P', they will see, "app***a***", etc., until they have
 * guessed all of the letters or run out of guesses.
 *
 * The purpose of this function is to evaluate how "good" a guess is:
 * how many letters does it reveal? Where are those revealed letters located?
 *
 * @param[in]  word      the word being guessed
 * @param[in]  letter    the letter being guessed
 * @param[out] letters   the letters in the secret word that have been
 *                       uncovered by the guess: if letter i is revealed,
 *                       it should be set to the same value as word[i]
 *                       (letters not revealed by the guess are not changed)
 *
 * @pre `word` is spelled in all lower-case letters
 * @pre `letters` has at least as many elements as `word`
 *
 * @returns    how many times the guessed letter was found
 */
int guessLetter(const std::string& word, char letter, char letters[]);


/**
 * Play a game of Hangman.
 *
 * This function should repeatedly call getNextGuess() to get the player's next
 * guess, then use guessLetter() to check how good a guess it is. The function
 * should end when either a) the secret word is completely revealed or
 * b) the player runs out of guesses.
 *
 * @param       word      the secret word being guessed by the player
 * @param       maxWrong  how many guesses the player can get wrong before
 *                        the game ends
 *
 * @returns     true if the word was guessed, false if we ran out of guesses
 */
bool playHangman(std::string word, unsigned int maxWrong = 8);

