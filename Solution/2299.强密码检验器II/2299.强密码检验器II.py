class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        
        specials = set("!@#$%^&*()-+")
        hasLower = hasUpper = hasDigit = hasSpecial = False

        for i, ch in enumerate(password):
            if i != len(password) - 1 and password[i] == password[i + 1]:
                return False

            if ch.islower():
                hasLower = True
            elif ch.isupper():
                hasUpper = True
            elif ch.isdigit():
                hasDigit = True
            elif ch in specials:
                hasSpecial = True

        return hasLower and hasUpper and hasDigit and hasSpecial
