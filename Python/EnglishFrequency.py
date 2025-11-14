from collections import Counter, defaultdict
import re
import sys

freq_order = "ETAOINSHRDLCUMWFGYPBVKJXQZ"
common_words = [" the ", " and ", " you ", " can ", " for ", " that ", " this ", " all ", " by ", " learn ", " students ", " of ", " to ", " in "]

def countFrequencies(text: str):
    letters = [ch.upper() for ch in text if ch.isalpha()]
    counts = Counter(letters)
    total = sum(counts.values())
    return counts, total

def rankByFrequency(counts: Counter):
    return [lt for lt, _ in sorted(counts.items(), key = lambda kv: (-kv[1], kv[0]))]

def buildMapping(cipher_rank: list, english_order: list):
    mapping = {}
    for i, c in enumerate(cipher_rank):
        if i < len(english_order):
            mapping[c] = english_order[i]

    used = set(mapping.values())
    remaining = [e for e in english_order if e not in used]
    for code in (chr(ord('A') + i) for i in range(26)):
        if code not in mapping:
            mapping[code] = remaining.pop(0) if remaining else 'X'
    return mapping

def applySubstitution(text: str, mapping: dict):
    out = []
    for ch in text:
        if ch.isalpha():
            up = ch.upper()
            dec = mapping.get(up, up)
            out.append(dec if ch.isupper() else dec.lower())
        else:
            out.append(ch)
    return ''.join(out)

def prettyMapping(mapping: dict):
    keys = [chr(ord('A') + i) for i in range(26)]
    top = "Cipher: " + " ".join(keys)
    bot = "Plain: " + " ".join(mapping[k] for k in keys)
    return top + '\n' + bot


def caesarShift(text: str, shift_back: int) -> str:
    out = []
    for ch in text:
        if 'A' <= ch <= 'Z':
            out.append(chr((ord(ch) - ord('A') - shift_back) % 26 + ord('A')))
        elif 'a' <= ch <= 'z':
            out.append(chr((ord(ch) - ord('a') - shift_back) % 26 + ord('a')))
        else:
            out.append(ch)
    return ''.join(out)

def EnglishFreq(text: str) -> int:
    low = text.lower()
    return sum(low.count(w) for w in common_words)


def main():
    print("Paste or type your ciphertext. End input with Ctrl+Z then Enter.")
    try:
        cipher_text = sys.stdin.read()
    except Exception:
        cipher_text = input("Enter ciphertext: ")

    if not cipher_text.strip():
        print("No input provided. Exiting.")
        sys.exit(0)

    counts, total = countFrequencies(cipher_text)
    print("\nLETTER FREQUENCY (ciphertext):")
    for lt, cnt in sorted(counts.items(), key=lambda kv: (-kv[1], kv[0])):
        print(f" {lt}: {cnt:3d} ({cnt/total*100:6.3f}%)")
    print(f" Total: {total}\n")

    cipher_rank = rankByFrequency(counts)
    mapping = buildMapping(cipher_rank, freq_order)
    print("Initial Mapping (cipher -> guessed plain):")
    print(prettyMapping(mapping))

    guess_plain = applySubstitution(cipher_text, mapping)
    print("\nProbable Plaintext (frequency mapping guess):\n")
    print(guess_plain)
    print("-"*72 + "\n")

    candidates = []
    for k in range(26):
        dec = caesarShift(cipher_text, k)
        candidates.append((k, EnglishFreq(dec), dec))

    candidates.sort(key=lambda t: (-t[1], t[0]))
    best_k, best_score, best_text = candidates[0]

    print(f"Caesar Scan Best: shift back {best_k} (score={best_score})\n")
    print(best_text)

    print("\nCaesar Mapping (cipher -> plain) for best shift:")
    caesar_map = {
        chr(ord("A") + i): chr((i - best_k) % 26 + ord("A"))
        for i in range(26)
    }
    print(prettyMapping(caesar_map))

    print("\n=== End ===")


if __name__ == "__main__":
    main()