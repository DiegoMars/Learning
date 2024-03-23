// 1. Import utilities from `astro:content`
import { defineCollection, z } from 'astro:content';
// 2. Define your collection(s)
const postsCollection = defineCollection({ 
    schema: ({image})=> 
      z.object({
          author: z.string(),
          date: z.string(),
          image: image(),
          title: z.string()
      })
 });
// 3. Export a single `collections` object to register your collection(s)
//    This key should match your collection directory name in "src/content"
export const collections = {
  posts: postsCollection,
};