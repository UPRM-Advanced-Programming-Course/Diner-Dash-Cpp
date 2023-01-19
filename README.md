## Phase 1 (WarmUp): Implement additional minor features. 

- [x] Add and draw decorations in the restaurant by loading images and drawing them
from the Restaurant class. Add at least 3 noticeable decorations. (Example: Chairs,
tables, plants, kitchen utilities). 

- [x] Implement a Start Screen which displays the game instructions. The basic
instructions are that you pickup ingredients by pressing ‘e’ when the player is in front
of the counter and you serve clients with ‘s’. Any other functionalities or special
instructions should be added as implemented. 

- [x] Make clients slowly turn red as they lose their patience (from waiting too long to be
served), they should look more red the closer they are to leaving. Hint: By using the
OpenFrameworks method OfSetColor() before drawing an image, the image is
slightly tinted 

- [x] Implement a LoseState that is triggered whenever 10 clients leave the restaurant. 

- [x] Implement WinState that is triggered when the money reaches $100. 

- [x] Add background music to the Restaurant.

## Phase 2: Intermediate Features: 

- [x] Create the burger equals() method which checks that the target burger has the same ingredients and quantities as the parameter burger. The order of the ingredients is irrelevant. 

- [x] Create an Undo button 'u' that removes the last added ingredient from the Burger. 

- [x] Refactor Burger class so that the ingredients vector is a stack instead of a vector.
Hint: The hardest part of this spec might be iterating over a stack. You can do this
easily by moving elements from one stack to another. (This includes refactoring the
other two methods created for Burger in these specs. You may get credit for those
specs even if you do not do this one, so long as they’re in a working state). 

- [x] Make the burger for each client generate a random set of 5 ingredients (there can
be duplicate ingredients) bottom bun and top bun should always be the first and last
respectively.

## Phase 3: Main Features: 

- [x] The game currently only supports serving the first client in line. Refactor the method
serve(Burger* ) inside of the Client class so that it recursively tries to serve any
client with a matching order. When serve() is called on a client, he should compare
the parameter burger to the client’s attribute burger using the equals() method, if there
is a match, mark him as isLeaving and take his payment, otherwise he should call the
serve() method of the next client (there is an attribute in client called nextClient).
Note: For design purposes, the Client will not leave until he is the first in line,
this is not a problem, so long as the correct client is served. 

- [x] Create a subclass of BaseCounter, called StoveCounter, instead of giving you the
burger directly, on first interaction the stove counter will begin to “cook” the burger
patty, after a certain amount of ticks, the burger will become available to pick up from
the counter. The item flying above the stove should clearly indicate if on interaction it
will begin cooking or give you a burger. 

- [x] Create a subclass of Client, called the Inspector, if he doesn't get his order before
losing his patience, you will lose half of your earnings (money) to a bad review.
