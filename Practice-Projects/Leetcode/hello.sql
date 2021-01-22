select COUNT(id) from animals
where (date_admitted = '18 April 2000') And (type = 'dog');

select name from adopter
where sin in (select sin from adoption, animals where animals.type
         in (select DISTINCT type from animals) );



select sin from adopter where sin not in(
select sin from (select DISTINCT type from animals
cross join (SELECT sin from adopter);
MINUS
select type, sin from animals a, adoption ad
where ad.animalID = a.id))
